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

#include "toolbardraw.h"

using namespace Ihm;

/*! Titre
	\project DiRIGe
	\class ToolBarDraw
	\ingroup Ihm
	\brief Une classe pour dessiner
	\author Copyright 2010 Antoine GRÉA <grea09@gmail.com>
	\sa MainWindow, Menu, {Ihm}
 */

//Constants
//{
	
	const int ToolBarDraw::SizeSpinBoxMax = 200;
	const int ToolBarDraw::SizeSpinBoxMin = 1;
	const int ToolBarDraw::SizeSpinBoxDef = 16;
	const QString ToolBarDraw::SizeSpinBoxSuffix = "px";
	
	const QSize ToolBarDraw::FixedSize = QSize(32,32 * 7);
	
//}

//Builders
//{
	
	ToolBarDraw::ToolBarDraw(QWidget* parent)
		: QToolBar(parent)
	{
		debugsub(ENTER);
		
		build();
		
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Destroyers
//{
	
	
	
//{

//Getters
//{
	
	QAction* ToolBarDraw::getActionRun()
	{
		debugsub(ENTER);
		
		return actionRun_;
		
		debugsub(EXIT_SUCCESS);
	}
	
	QAction* ToolBarDraw::getActionStart()
	{
		debugsub(ENTER);
		
		return actionStart_;
		
		debugsub(EXIT_SUCCESS);
	}
	
	QAction* ToolBarDraw::getActionEnd()
	{
		debugsub(ENTER);
		
		return actionEnd_;
		
		debugsub(EXIT_SUCCESS);
	}
	
	QAction* ToolBarDraw::getActionEllipse()
	{
		debugsub(ENTER);
		
		
		
		debugsub(EXIT_SUCCESS);
		return actionEllipse_;
	}
	
	QAction* ToolBarDraw::getActionRectangle()
	{
		debugsub(ENTER);
		
		
		
		debugsub(EXIT_SUCCESS);
		return actionRectangle_;
	}
	
	QAction* ToolBarDraw::getActionLine()
	{
		debugsub(ENTER);
		
		
		
		debugsub(EXIT_SUCCESS);
		return actionLine_;
	}
	
	QAction* ToolBarDraw::getActionHandFree()
	{
		debugsub(ENTER);
		
		
		
		debugsub(EXIT_SUCCESS);
		return actionHandFree_;
	}
	
	QAction* ToolBarDraw::getActionErraser()
	{
		debugsub(ENTER);
		
		
		
		debugsub(EXIT_SUCCESS);
		return actionErraser_;
	}
	
	QAction* ToolBarDraw::getActionFill()
	{
		debugsub(ENTER);
		
		
		
		debugsub(EXIT_SUCCESS);
		return actionFill_;
	}
	
	
	QActionGroup* ToolBarDraw::getActionGroupDraw()
	{
		debugsub(ENTER);
		
		
		
		debugsub(EXIT_SUCCESS);
		return actionGroupDraw_;
	}

        int ToolBarDraw::getSizeSpinBox()
        {
                debugsub(ENTER);



                debugsub(EXIT_SUCCESS);
                return sizeSpinBox_->value();
        }
	
//}

//Setters
//{
	
	void ToolBarDraw::setSize(int size)
	{
		debugsub(ENTER);
		
		emit sizeChanged(size);
		
		debugsub(EXIT_SUCCESS);
	}
	
	
//}

//Processing
//{
	
	void ToolBarDraw::build()
	{
		debugsub(ENTER);
		
		actionRun_ = new QAction(QIcon(":/images/run.png"),"Lancer", this);
		actionRun_->setIconVisibleInMenu(true);
		actionRun_->setObjectName(QString::fromUtf8("actionRun_"));
		actionRun_->setShortcut(Qt::Key_F5);
#ifndef QT_NO_TOOLTIP
		actionRun_->setToolTip("Trouver le chemin !");
#endif // QT_NO_TOOLTIP
		
		actionStart_ = new QAction(QIcon(":/images/start.png"),QString::fromUtf8("Point de départ"), this);
		actionStart_->setIconVisibleInMenu(true);
		actionStart_->setCheckable(true);
		actionStart_->setObjectName(QString::fromUtf8("actionStart_"));
		actionStart_->setShortcut(Qt::Key_F2);
#ifndef QT_NO_TOOLTIP
		actionStart_->setToolTip(QString::fromUtf8("Placer le point de départ"));
#endif // QT_NO_TOOLTIP
		
		actionEnd_ = new QAction(QIcon(":/images/end.png"),QString::fromUtf8("Point d'arrivé"), this);
		actionEnd_->setIconVisibleInMenu(true);
		actionEnd_->setCheckable(true);
		actionEnd_->setObjectName(QString::fromUtf8("actionEnd_"));
		actionEnd_->setShortcut(Qt::Key_F3);
#ifndef QT_NO_TOOLTIP
		actionEnd_->setToolTip(QString::fromUtf8("Placer le point d'arrivé"));
#endif // QT_NO_TOOLTIP
		
		sizeSpinBox_ = new QSpinBox(this);
		sizeSpinBox_->setRange ( SizeSpinBoxMin, SizeSpinBoxMax );
		sizeSpinBox_->setValue ( SizeSpinBoxDef );
		sizeSpinBox_->setSuffix ( SizeSpinBoxSuffix );
		
		actionGroupDraw_ = new QActionGroup(this);
		
		actionEllipse_ = new QAction(QIcon(":/images/ellipse.png"),"Ellipse",actionGroupDraw_);
		actionEllipse_->setIconVisibleInMenu(true);
		actionEllipse_->setCheckable(true);
		actionEllipse_->setObjectName(QString::fromUtf8("actionEllipse_"));
#ifndef QT_NO_TOOLTIP
		actionEllipse_->setToolTip("Tracer une ellipse");
#endif // QT_NO_TOOLTIP
		
		actionRectangle_ = new QAction(QIcon(":/images/rectangle.png"),"Rectangle",actionGroupDraw_);
		actionRectangle_->setIconVisibleInMenu(true);
		actionRectangle_->setCheckable(true);
		actionRectangle_->setObjectName(QString::fromUtf8("actionRectangle_"));
#ifndef QT_NO_TOOLTIP
		actionRectangle_->setToolTip("Tracer un rectangle");
#endif // QT_NO_TOOLTIP
		
		actionLine_ = new QAction(QIcon(":/images/line.png"),"Tracer une ligne",actionGroupDraw_);
		actionLine_->setIconVisibleInMenu(true);
		actionLine_->setCheckable(true);
		actionLine_->setObjectName(QString::fromUtf8("actionLine_"));
#ifndef QT_NO_TOOLTIP
		actionLine_->setToolTip("Tracer une ligne");
#endif // QT_NO_TOOLTIP
		
		actionHandFree_ = new QAction(QIcon(":/images/handfree.png"),"Main libre",actionGroupDraw_);
		actionHandFree_->setIconVisibleInMenu(true);
		actionHandFree_->setCheckable(true);
                actionHandFree_->setChecked(true);
		actionHandFree_->setObjectName(QString::fromUtf8("actionHandFree_"));
#ifndef QT_NO_TOOLTIP
		actionHandFree_->setToolTip("Dessiner avec le curseur");
#endif // QT_NO_TOOLTIP
		
		actionErraser_ = new QAction(QIcon(":/images/eraser.png"),"Gomme",actionGroupDraw_);
		actionErraser_->setIconVisibleInMenu(true);
		actionErraser_->setCheckable(true);
		actionErraser_->setObjectName(QString::fromUtf8("actionErraser_"));
#ifndef QT_NO_TOOLTIP
		actionErraser_->setToolTip("Effacer avec le curseur");
#endif // QT_NO_TOOLTIP
		
		
		actionGroupDraw_->addAction(actionStart_);
		actionGroupDraw_->addAction(actionEnd_);
		actionGroupDraw_->addAction(actionHandFree_);
		actionGroupDraw_->addAction(actionEllipse_);
		actionGroupDraw_->addAction(actionRectangle_);
		actionGroupDraw_->addAction(actionLine_);
		actionGroupDraw_->addAction(actionErraser_);
		
                actionGroupDraw_->setExclusive (true);
		actionGroupDraw_->setVisible (true);
		actionGroupDraw_->setObjectName(QString::fromUtf8("actionGroupDraw_"));
		//~ actionHandFree_->setChecked (true);
		
		actionFill_ = new QAction(QIcon(":/images/fill.png"),"Remplir",this);
		actionFill_->setIconVisibleInMenu(true);
		actionFill_->setCheckable(true);
                actionFill_->setChecked(true);
		actionFill_->setObjectName(QString::fromUtf8("actionFill_"));
#ifndef QT_NO_TOOLTIP
		actionFill_->setToolTip("Remplir les prochaines formes");
#endif // QT_NO_TOOLTIP
		
		
		connect(sizeSpinBox_,SIGNAL(valueChanged(int)),this,SLOT(setSize(int)));
		
		
		
		//~ Pour l'ordre modifiez ici
		this->addAction(actionStart_);
		this->addAction(actionEnd_);
		this->addAction(actionRun_);
		this->addSeparator();
		this->addAction(actionHandFree_);
		this->addWidget(sizeSpinBox_);
		this->addAction(actionEllipse_);
		this->addAction(actionRectangle_);
		this->addAction(actionLine_);
		this->addAction(actionErraser_);
		//~ this->addSeparator();
		
		this->addAction(actionFill_);
		
		//~ this->setFixedSize(FixedSize);
		this->setObjectName(QString::fromUtf8("Dessin"));
		this->setVisible(true);
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Operators
//{
	
	
	
//}

//Display
//{
	
	
	
//}
