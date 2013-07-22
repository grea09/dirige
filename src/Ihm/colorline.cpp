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

#include "colorline.h"

using namespace Ihm;

/*! Titre
	\project DiRIGe
	\class ColorLine
	\ingroup Ihm
	\brief Une classe pour afficher une ligne de gestion de couleur.
	\author Copyright 2010 Antoine GRÉA <grea09@gmail.com>
	\sa ToolBarColor, BitMap::ColorCost, {IHM}
 */

//Constants
//{
	
	const int ColorLine::SliderTickInterval = 50;
	
    const int ColorLine::SpinBoxMax = 400;
	const int ColorLine::SpinBoxMin = 0;
	const int ColorLine::SpinBoxDef = 100;
	const QString ColorLine::SpinBoxSuffix = "%";
	
	const QString ColorLine::CheckBoxText = "Passante";
	
	const QSize ColorLine::FixedSize = QSize(32,32 * 3);
	
//}

//Builders
//{
	
	ColorLine::ColorLine(QWidget* parent, Bitmap::ColorCost* colorCost)
		: QToolBar(parent), colorCost_(colorCost), buttonColor_(this)
	{
		debugsub(ENTER);
		
		if(!colorCost_)
		{
			colorCost_ = new Bitmap::ColorCost(Qt::black,-1);
			editColor();
		}
		
		build();
	}
	
//}

//Destroyers
//{
	
	
	
//{

//Getters
//{
	
	//~ QAction* ColorLine::getActionDelColor()
	//~ {
		//~ 
		//~ return actionDelColor_;
		//~ 
	//~ }
	//~ 
	//~ QAction* ColorLine::getActionEditColor()
	//~ {
		//~ 
		//~ return actionEditColor_;
		//~ 
	//~ }
	
	Bitmap::ColorCost* ColorLine::getColorCost()
	{
		debugsub(ENTER);
		debugV(colorCost_);
		
		debugsub(EXIT_SUCCESS);
		return colorCost_;
	}
	
	QColor ColorLine::getColor()
	{
		debugsub(ENTER);
		debugV(colorCost_);
		
		debugsub(EXIT_SUCCESS);
		return colorCost_->getColor();
	}
	
//}

//Setters
//{
	
	void ColorLine::setColorCost(Bitmap::ColorCost colorCost)
	{
		debugsub(ENTER);
		
		delete colorCost_;
		colorCost_ = new Bitmap::ColorCost(colorCost);
		
		debugsub(EXIT_SUCCESS);
	}
	
	void ColorLine::setPassable(bool state)
	{
		debugsub(ENTER);
		
		colorCost_->setCost((state)?(spinBox_->value()):(-1));
		passable_->setChecked(state);
		
		debugsub(EXIT_SUCCESS);
	}
	
	void ColorLine::setCost(int cost)
	{
		debugsub(ENTER);
		
		passable_->setChecked(true);
		colorCost_->setCost(cost);
		
		debugsub(EXIT_SUCCESS);
	}
	
	
	void ColorLine::setColor(QColor color)
	{
		debugsub(ENTER);
		
		QEvent* event = new QEvent(QEvent::None);
		emit colorAuthorization(color,event,this);
		if (event->isAccepted())
		{
			colorCost_->setColor(color);
			emit colorIt(color);
			buttonColor_.setColor(color);
		}
		delete event;
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Processing
//{
	
	void ColorLine::build()
	{
		debugsub(ENTER);
		
		buttonColor_.setColor(colorCost_->getColor());
		
		
		slider_ = new QSlider(Qt::Horizontal,this);
		slider_->setRange ( SpinBoxMin, SpinBoxMax );
		slider_->setTickInterval(SliderTickInterval);
		slider_->setTickPosition( QSlider::TicksBothSides );
		slider_->setValue( SpinBoxDef );
		
		spinBox_ = new QSpinBox(this);
		spinBox_->setRange ( SpinBoxMin, SpinBoxMax );
		spinBox_->setValue ( SpinBoxDef );
		spinBox_->setSuffix ( SpinBoxSuffix );
		
		passable_ = new QGroupBox(CheckBoxText,this);
		passable_->setCheckable(true);
		passable_->setChecked(colorCost_->getCost() == -1);
		passable_->setFlat(true);
		passable_->setVisible(true);
		
		QVBoxLayout* passableLayout = new QVBoxLayout;
		passableLayout->addWidget(spinBox_);
		passableLayout->addWidget(slider_);
		passable_->setLayout(passableLayout);
		
		
		actionDelColor_ = new QAction(QIcon(":/images/color-delete.png"),"Supprimer la couleur",(QWidget*)this);
		actionEditColor_ = new QAction(QIcon(":/images/color-edit.png"),QString::fromUtf8("Éditer la couleur"),this);
		
		connect(slider_, SIGNAL(valueChanged(int)), spinBox_, SLOT(setValue(int)));
		connect(spinBox_, SIGNAL(valueChanged(int)), slider_, SLOT(setValue(int)));
		
        connect(passable_,SIGNAL(toggled(bool)),this,SLOT(setPassable(bool)));
		connect(slider_,SIGNAL(valueChanged(int)),this,SLOT(setCost(int)));
		connect(&buttonColor_,SIGNAL(clicked()),this,SLOT(emitColor()));
		connect(actionDelColor_,SIGNAL(triggered()),this,SLOT(delColor()));
		connect(actionEditColor_,SIGNAL(triggered()),this,SLOT(editColor()));
		
		
		this->addWidget(&buttonColor_);
		this->addWidget(passable_);
		this->addAction(actionEditColor_);
		this->addAction(actionDelColor_);
		
		//~ this->setFixedSize(FixedSize);
		this->setPassable(colorCost_->getCost()>0);
		this->setVisible(true);
		
		debugsub(EXIT_SUCCESS);
	}
	
	void ColorLine::delColor()
	{
		debugsub(ENTER);
		
		emit deleteMe(this);
		
		debugsub(EXIT_SUCCESS);
	}
	
	void ColorLine::editColor()
	{
		debugsub(ENTER);
		
		QColorDialog colorDialog;
		QColor color = colorDialog.getColor();
		if(color.isValid())
		{
				setColor(color);
		}
		
		debugsub(EXIT_SUCCESS);
	}
	
	void ColorLine::emitColor()
	{
		debugsub(ENTER);
		
		emit colorIt(colorCost_->getColor());
		
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Operators
//{
	
	
	
//}

//Display
//{
	
	
	
//}
