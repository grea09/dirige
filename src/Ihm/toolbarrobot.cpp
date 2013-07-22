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

#include "toolbarrobot.h"

using namespace Ihm;

/*! Titre
	\project DiRIGe
	\class ToolBarRobot
	\ingroup Ihm
	\brief Une classe pour régler les paramètres du robot avant lancement
	\author Copyright 2010 Antoine GRÉA <grea09@gmail.com>
	\sa MainWindow, Bitmap::Robot, {Ihm}
 */

//Constants
//{
	
	const int ToolBarRobot::WidthTickInterval = 16;
	
	const int ToolBarRobot::WidthMax = 48;
	const int ToolBarRobot::WidthMin = 1;
	const int ToolBarRobot::WidthDef = 2;
	const QString ToolBarRobot::WidthSuffix = "px";
	
	const int ToolBarRobot::RotationMax = 359;
	const int ToolBarRobot::RotationMin = 0;
	const int ToolBarRobot::RotationDef = 90;
	const QString ToolBarRobot::RotationSuffix = QString::fromUtf8("°");
	
	const int ToolBarRobot::CostHalfTurnTickInterval = 50;
	
	const int ToolBarRobot::CostHalfTurnMax = 200;
	const int ToolBarRobot::CostHalfTurnMin = 0;
	const int ToolBarRobot::CostHalfTurnDef = 100;
	const QString ToolBarRobot::CostHalfTurnSuffix = "%";
	
	const QSize ToolBarRobot::Size = QSize(48 * 8,48);
	
//}

//Builders
//{
	
	ToolBarRobot::ToolBarRobot(QWidget* parent)
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
	
	int ToolBarRobot::getWidth() const
	{
		debugsub(ENTER);
		
		return width_->value();
		
		debugsub(EXIT_SUCCESS);
	}
	
	int ToolBarRobot::getRotation() const
	{
		debugsub(ENTER);
		
		return rotation_->value();
		
		debugsub(EXIT_SUCCESS);
	}
	
	double ToolBarRobot::getCostHalfTurn() const
	{
		debugsub(ENTER);
		
		return (double)(costHalfTurn_->value());
		
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Setters
//{
	
	//~ void ToolBarRobot::setOrientationSize( Qt::Orientation orientation)
	//~ {
		//~ debugsub(ENTER);
		//~ 
		//~ if (orientation == Qt::Horizontal)
		//~ {
			//~ this->setMaximumSize(Size);
		//~ }
		//~ else
		//~ {
			//~ this->setMaximumSize(QSize(Size.height(),Size.width()));
		//~ }
		//~ 
		//~ debugsub(EXIT_SUCCESS);
	//~ }
	
//}

//Processing
//{
	
	void ToolBarRobot::build()
	{
		debugsub(ENTER);
		width_ = new QSpinBox();
		width_->setRange ( WidthMin, WidthMax );
		width_->setValue ( WidthDef );
		width_->setSuffix ( WidthSuffix );
		
		widthSlider_ = new QSlider(Qt::Horizontal,this);
		widthSlider_->setRange ( WidthMin, WidthMax );
		widthSlider_->setTickInterval(WidthTickInterval);
		widthSlider_->setTickPosition( QSlider::TicksBothSides );
		widthSlider_->setValue( WidthDef );
		
		rotation_ = new QSpinBox();
		rotation_->setRange ( RotationMin, RotationMax );
		rotation_->setValue ( RotationDef );
		rotation_->setSuffix ( RotationSuffix );
		
		rotationDial_  = new QDial();
		rotationDial_->setNotchesVisible(true);
		rotationDial_->setRange ( RotationMin, RotationMax );
		rotationDial_->setSliderPosition ( RotationDef );
		//~ rotationDial_->setFixedSize ( QSize(48,48) );
		
		costHalfTurn_ = new QSpinBox();
		costHalfTurn_->setRange ( CostHalfTurnMin, CostHalfTurnMax );
		costHalfTurn_->setValue ( CostHalfTurnDef );
		costHalfTurn_->setSuffix ( CostHalfTurnSuffix );
		
		costHalfTurnSlider_ = new QSlider(Qt::Horizontal,this);
		costHalfTurnSlider_->setRange ( CostHalfTurnMin, CostHalfTurnMax );
		costHalfTurnSlider_->setTickInterval(CostHalfTurnTickInterval);
		costHalfTurnSlider_->setTickPosition( QSlider::TicksBothSides );
		costHalfTurnSlider_->setValue( CostHalfTurnDef );
		
		
		connect(widthSlider_, SIGNAL(valueChanged(int)), width_, SLOT(setValue(int)));
		connect(width_, SIGNAL(valueChanged(int)), widthSlider_, SLOT(setValue(int)));
		
		
		
		connect(rotationDial_, SIGNAL(valueChanged(int)), rotation_, SLOT(setValue(int)));
		connect(rotation_, SIGNAL(valueChanged(int)), rotationDial_, SLOT(setValue(int)));
		
		connect(costHalfTurn_, SIGNAL(valueChanged(int)), costHalfTurnSlider_, SLOT(setValue(int)));
		connect(costHalfTurnSlider_, SIGNAL(valueChanged(int)), costHalfTurn_, SLOT(setValue(int)));
		
		QGroupBox* widthGroupBox = new QGroupBox(this);
		widthGroupBox->setTitle(QString::fromUtf8("Taille du robot"));
		
		QVBoxLayout* widthLayout = new QVBoxLayout();
		widthLayout->addWidget(width_);
		widthLayout->addWidget(widthSlider_);
		widthGroupBox->setLayout(widthLayout);
		
		QGroupBox* rotationGroupBox = new QGroupBox(this);
		rotationGroupBox->setTitle(QString::fromUtf8("Angle initial du robot"));
		
		QHBoxLayout* rotationLayout = new QHBoxLayout();
		rotationLayout->addWidget(rotationDial_);
		rotationLayout->addWidget(rotation_);
		rotationGroupBox->setLayout(rotationLayout);
		
		QGroupBox* costHalfTurnGroupBox = new QGroupBox(this);
		costHalfTurnGroupBox->setTitle(QString::fromUtf8("Coût de demi-tour"));
		
		QVBoxLayout* costHalfTurnLayout = new QVBoxLayout();
		costHalfTurnLayout->addWidget(costHalfTurn_);
		costHalfTurnLayout->addWidget(costHalfTurnSlider_);
		costHalfTurnGroupBox->setLayout(costHalfTurnLayout);
		
		
		this->addWidget(widthGroupBox);
		this->addSeparator();
		this->addWidget(rotationGroupBox);
		this->addSeparator();
		this->addWidget(costHalfTurnGroupBox);
		
		//~ this->setMaximumSize(Size);
		this->setObjectName(QString::fromUtf8("Robot"));
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
