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

#ifndef DEF_COLORLINE_H
#define DEF_COLORLINE_H

#include "libdevcpp.h"
#include "buttoncolor.h"
#include "colorcost.h"
#include <QGroupBox>
#include <QToolBar>
#include <QSlider>
#include <QPushButton>
#include <QCheckBox>
#include <QString>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QColorDialog>

namespace Ihm
{
	class ColorLine : public QToolBar
	{
		Q_OBJECT
		
		public :
		//Attributes
		//{
			
			//Constants
			//{
				
				static const int SliderTickInterval;
				
				static const int SpinBoxMax;
				static const int SpinBoxMin;
				static const int SpinBoxDef;
				static const QString SpinBoxSuffix;
				
				static const QString CheckBoxText;
				
				static const QSize FixedSize;
				
				
			//}
			
		//}
		
		//Builders
		//{
			
			ColorLine(QWidget* parent = NULL, Bitmap::ColorCost* colorCost = NULL);
			
		//}
		
		//Destroyers
		//{
			
			//~ ~ColorLine();
			
		//}
		
		//Methods
		//{
			
			//Getters
			//{
				
				//~ QAction* getActionDelColor();
				//~ QAction* getActionEditColor();
				Bitmap::ColorCost* getColorCost();
				QColor getColor();
				
			//}
			
			//Setters
			//{
				
				void setColorCost(Bitmap::ColorCost colorCost);
				
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
				
				void setPassable(bool state);
				void setCost(int cost);
				void setColor(QColor color);
				void delColor();
				void editColor();
				void emitColor();
				
		//}
		
		//Signals
		//{
			
			signals:
				
				void deleteMe(ColorLine* colorLine);
				void colorIt(QColor color);
				void colorAuthorization(QColor color, QEvent* event, ColorLine* colorLine);
				
		//}
			
		protected :
		//Attributes
		//{
			
			//Variables
			//{
				
				ButtonColor buttonColor_;
				QSlider* slider_;
				QSpinBox* spinBox_;
				QToolButton* close_;
				QGroupBox* passable_;
				
				QAction* actionDelColor_;
				QAction* actionEditColor_;
				
				//~ Et l'essentiel
				Bitmap::ColorCost* colorCost_;
				
				
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


