/****************************************************************************
**
** Copyright 2010 Antoine GRÉA <grea09@gmail.com>
**
** $QT_BEGIN_LICENSE:LGPL$
**      This program is free software; you can redistribute it and/or modify
**      it under the terms of the GNU General Public License as published by
**      the Free Software Foundation; either version 2 of the License, or
**      (at your option) any later version.
**      
**      This program is distributed in the hope that it will be useful,
**      but WITHOUT ANY WARRANTY; without even the implied warranty of
**      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**      GNU General Public License for more details.
**      
**      You should have received a copy of the GNU General Public License
**      along with this program; if not, write to the Free Software
**      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
**      MA 02110-1301, USA.
** $QT_END_LICENSE$
**
****************************************************************************/

#include "toolbarcolor.h"

using namespace Ihm;

/*! Titre
	\project DiRIGe
	\class ToolBarColor
	\ingroup Ihm
	\brief Une classe pour la gestion et l'affichage des couleurs
	\author Copyright 2010 Antoine GRÉA <grea09@gmail.com>
	\sa ColorLine, {Ihm}
 */

//Constants
//{
	
	//~ const QString ToolBarColor::Title = "Barre d'outils couleurs";
	
//}

//Builders
//{
	
	ToolBarColor::ToolBarColor(QWidget* parent)
		: QToolBar(parent)
	{
		debugsub(ENTER);
		
		build();
		
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Destroyers
//{
	
	ToolBarColor::~ToolBarColor()
	{
		std::map<unsigned int, ColorLine*>::iterator first = colorLines_.begin();
		for ( ; first!=colorLines_.end(); ++first )
		{
			delete (*first).second;
		}
		colorLines_.clear();
	}
	
//{

//Getters
//{
	
	std::vector<Bitmap::ColorCost> ToolBarColor::getcolorCost()
	{
		debugsub(ENTER);
		std::vector<Bitmap::ColorCost> vector_tmp;
		std::map<unsigned int, ColorLine*>::iterator first = colorLines_.begin();
		for ( ; first!=colorLines_.end(); ++first )
		{
			vector_tmp.push_back(*(((*first).second)->getColorCost()));
		}
		return vector_tmp;
		debugsub(EXIT_SUCCESS);
	}
	
	QAction* ToolBarColor::getActionAddColor()
	{
		debugsub(ENTER);
		
		return actionAddColor_;
		
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Setters
//{
	
	
	
//}

//Processing
//{
	
	void ToolBarColor::build()
	{
		debugsub(ENTER);
		actionAddColor_ = new QAction(QIcon(":/images/color-add.png"),"Ajouter une nouvelle couleur",this);
		actionResetColor_ = new QAction(QIcon(":/images/color-delete.png"),"Supprimer toutes les couleurs",this);
		
		connect(actionAddColor_,SIGNAL(triggered()),this,SLOT(addColor()));
		connect(actionResetColor_,SIGNAL(triggered()),this,SLOT(resetColor()));
		
		QToolBar* toolBarButton = new QToolBar(this);
		toolBarButton->addAction(actionAddColor_);
		toolBarButton->addAction(actionResetColor_);
		
		this->addWidget(toolBarButton);
		addColor( new ColorLine(this, new Bitmap::ColorCost(Qt::black,-1)));
		
		this->setObjectName(QString::fromUtf8("Couleurs"));
		this->setVisible(true);
		
		debugsub(EXIT_SUCCESS);
	}
	
	void ToolBarColor::addColor(ColorLine* colorLine)
	{
		debugsub(ENTER);
		if (!colorLine)
		{
			colorLine = new ColorLine(this);
		}
		QEvent* event = new QEvent(QEvent::None);
		acceptColor(colorLine->getColor(),event, colorLine);
		if (event->isAccepted())
		{
			colorLines_[colorLine->getColor().rgb()] = colorLine;
            connect(colorLine,SIGNAL(colorIt(QColor)),this,SLOT(emitColor(QColor)));
			connect(colorLine,SIGNAL(deleteMe(ColorLine*)),this,SLOT(delColor(ColorLine*)));
			connect(colorLine,SIGNAL(colorAuthorization(QColor,QEvent*,ColorLine*)),this,SLOT(acceptColor(QColor,QEvent*,ColorLine*)));
			//~ this->insertSeparator(actionAddColor_);
			//~ this->insertWidget(actionAddColor_,colorLine);
			this->addWidget(colorLine);
		}
		else
		{
			delete colorLine;
		}
		delete event;
		debugsub(EXIT_SUCCESS);
	}
	
	void ToolBarColor::acceptColor(QColor color, QEvent* event, ColorLine* colorLine)
	{
		debugsub(ENTER);
		debugV(color.rgb());
		debugV(colorLines_[color.rgb()]);
		if (colorLines_[color.rgb()])
		{
			event->ignore();
			QMessageBox::warning(this, "Couleur en double", QString::fromUtf8("Cette couleur existe déjà. \nÉditez-la plutôt."));
		}
		else
		{
			event->accept();
			 //~ TODO trouver comment faire
			colorLines_.erase(colorLine->getColor().rgb());
			colorLines_[colorLine->getColor().rgb()] = NULL;
			colorLines_[color.rgb()] = colorLine;
		}
		
		debugsub(EXIT_SUCCESS);
	}
	
	void ToolBarColor::resetColor()
	{
		debugsub(ENTER);
		if (QMessageBox::question(this, QString::fromUtf8("Réinitialisé les couleurs"), "Voulez-vous vraiment supprimer toutes couleurs ?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
		{
			std::map<unsigned int, ColorLine*>::iterator first = colorLines_.begin();
			for ( ; first!=colorLines_.end(); ++first )
			{
				removeColor((*first).second);
			}
			colorLines_.clear();
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void ToolBarColor::removeColor(ColorLine* colorLine)
	{
		debugsub(ENTER);
		if (colorLine)
		{
			debugV(colorLine->getColor().rgb());
			layout()->removeWidget(colorLine);
			colorLines_.erase(colorLine->getColor().rgb());
			colorLines_[colorLine->getColor().rgb()] = NULL;
			delete colorLine;
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void ToolBarColor::delColor(ColorLine* colorLine)
	{
		debugsub(ENTER);
		if (QMessageBox::question(this, "Supprimer une couleur", "Voulez-vous vraiment supprimer cette couleur ?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
		{
			
			layout()->removeWidget(colorLine);
			//~ layout()->removeSeparator();
			colorLines_.erase(colorLine->getColor().rgb());
			delete colorLine;
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void ToolBarColor::emitColor(QColor color)
	{
		debugsub(ENTER);
		
		emit colorIt(color);
		
		debugsub(EXIT_SUCCESS);
	}
	
	
//}

//Operators
//{
	
	
	
//}

//Display
//{
	
	
	
//}
