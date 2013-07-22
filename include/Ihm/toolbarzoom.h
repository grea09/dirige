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

#ifndef DEF_TOOLBAR_ZOOM_H
#define DEF_TOOLBAR_ZOOM_H

#include "libdevcpp.h"
#include <QToolBar>
#include <QAction>
#include <QActionGroup>
#include <QSpinBox>
#include <QHBoxLayout>

namespace Ihm
{
	class ToolBarZoom : public QToolBar
	{
		Q_OBJECT
		
		public :
		//Attributes
		//{
			
			//Constants
			//{
				
				static const int ZoomSpinBoxMax;
				static const int ZoomSpinBoxMin;
				static const int ZoomSpinBoxDef;
				static const int ZoomInc;
				static const QString ZoomSpinBoxSuffix;
				
				static const QSize FixedSize;
				
			//}
			
		//}
		
		//Builders
		//{
			
			ToolBarZoom(QWidget* parent = NULL);
			
		//}
		
		//Destroyers
		//{
			
			//~ ~ToolBarZoom();
			
		//}
		
		//Methods
		//{
			
			//Getters
			//{
				
				QAction* getActionZoomPlus();
				QAction* getActionZoomMinus();
				QAction* getActionZoomDef();
				
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
				
				void zoomIn();
				void zoomOut();
                                void setZoom(int zoom = ZoomSpinBoxDef);
				
		//}
		
		//Signals
		//{
			
			signals:
				
				void zoomChanged(float zoom);
				
		//}
			
		protected :
		//Attributes
		//{
			
			//Variables
			//{
				
				QAction* actionZoomPlus_;
				QAction* actionZoomMinus_;
				QAction* actionZoomDef_;
				QSpinBox* zoomSpinBox_;
				
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


