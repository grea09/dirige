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

#ifndef DEF_TOOLBAR_COLOR_H
#define DEF_TOOLBAR_COLOR_H

#include "libdevcpp.h"
#include <QToolBar>
#include <map>
#include "colorline.h"

namespace Ihm
{
	class MainWindow;
	
	class ToolBarColor : public QToolBar
	{
		Q_OBJECT
		
		public :
		//Attributes
		//{
			
			//Constants
			//{
				
				//~ static const QString Title;
				
			//}
			
		//}
		
		//Builders
		//{
			
			ToolBarColor(QWidget* parent =NULL);
			
		//}
		
		//Destroyers
		//{
			
			~ToolBarColor();
			
		//}
		
		//Methods
		//{
			
			//Getters
			//{
				
				std::vector<Bitmap::ColorCost> getcolorCost();
				QAction* getActionAddColor();
				
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
				
				void addColor(ColorLine* colorLine = NULL);
				void acceptColor(QColor color, QEvent* event = NULL, ColorLine* colorLine = NULL);
				void resetColor();
				void delColor(ColorLine* colorline);
				void emitColor(QColor color);
				
		//}
		
		//Signals
		//{
			
			signals:
				
				void colorIt(QColor color);
				
		//}
			
		protected :
		//Attributes
		//{
			
			//Variables
			//{
				
				std::map<unsigned int, ColorLine*> colorLines_;
				QAction* actionAddColor_;
				QAction* actionResetColor_;
				
			//}
			
		//}
		
		//Methods
		//{
			//Processing
			//{
				
				void build();
				void removeColor(ColorLine* colorline);
				
			//}
		//}
	};
}

#endif


