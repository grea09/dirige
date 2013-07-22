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

#ifndef DEF_TOOLBAR_ROBOT_H
#define DEF_TOOLBAR_ROBOT_H

#include "libdevcpp.h"
#include <QSpinBox>
#include <QSlider>
#include <QDial>
#include <QToolBar>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ihm
{
	class ToolBarRobot : public QToolBar
	{
		Q_OBJECT
		
		public :
		//Attributes
		//{
			
			//Constants
			//{
				
				static const int WidthTickInterval;
				
				static const int WidthMax;
				static const int WidthMin;
				static const int WidthDef;
				static const QString WidthSuffix;
				
				static const int RotationMax;
				static const int RotationMin;
				static const int RotationDef;
				static const QString RotationSuffix;
				
				static const int CostHalfTurnTickInterval;
				
				static const int CostHalfTurnMax;
				static const int CostHalfTurnMin;
				static const int CostHalfTurnDef;
				static const QString CostHalfTurnSuffix;
				
				static const QSize Size;
				
			//}
			
		//}
		
		//Builders
		//{
			
			ToolBarRobot(QWidget* parent = NULL);
			
		//}
		
		//Destroyers
		//{
			
			//~ ~ToolBarRobot();
			
		//}
		
		//Methods
		//{
			
			//Getters
			//{
				
				int getWidth() const;
				int getRotation() const;
				double getCostHalfTurn() const;
				
			//}
			
			//Setters
			//{
				
				
				
			//}
			
			//Processing
			//{
				
				
				
			//}
			
			//Operators
			//{
				
				
				
			//}
			
			//Display
			//{
				
				
				
			//}
			
		//}
		
		//Slots
		//{
			
			public slots:
				
				//~ void setOrientationSize( Qt::Orientation orientation);
				
		//}
		
		//Signals
		//{
			
			signals:
				
				
				
		//}
			
		protected :
		//Attributes
		//{
			
			//Variables
			//{
				
				QSpinBox* width_;
				QSlider* widthSlider_;
				QSpinBox* rotation_;
				QDial* rotationDial_;
				QSlider* costHalfTurnSlider_;
				QSpinBox* costHalfTurn_;
				
			//}
			
		//}
		
		//Methods
		//{
			//Processing
			//{
				
				void build();
				
			//}
		//}
	};
}

#endif


