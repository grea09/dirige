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

#ifndef DEF_PLUGIN_INTERFACE_H
#define DEF_PLUGIN_INTERFACE_H

#include "colorcost.h"
#include "libdevcpp.h"
#include <QWidget>

namespace Ihm
{
	class PluginInterface : public QWidget
	{
		Q_OBJECT
		
		public :
		//Attributes
		//{
			
			//Constants
			//{
				
				enum Figure
				{
					START_POINT,
					END_POINT,
					HANDFREE,
					LINE,
					RECTANGLE,
					ELLIPSE,
					ERRASER,
					VOID
				};
				
				
				
			//}
			
		//}
		
		//Builders
		//{
			
			PluginInterface(QWidget* parent = NULL)
				: QWidget(parent)
			{
				debugsub(ENTER);
				
				debugsub(EXIT_SUCCESS);
			}
			
			PluginInterface(PluginInterface& plugin, QWidget* parent = NULL);
			
		//}
		
		//Destroyers
		//{
			
			//virtual ~PluginInterface() {}
			
		//}
		
		//Methods
		//{
			public:
			//Getters
			//{
				
				//~ virtual int getDrawFigure() =0;
				//~ virtual bool getBooleanFill() =0;
				//~ virtual int getMapWidth() =0;
				//~ virtual int getMapHeight() =0;
				virtual QPixmap getMap() =0;
				//~ virtual QColor& getColor() =0;
				
				//~ virtual QPixmap& getResult() =0;
				
				virtual QPoint getStartPoint() =0;
				virtual QPoint getEndPoint() =0;
				
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
				
				//~ virtual void setMapWidth( int width) =0;
				//~ virtual void setMapHeight( int height) =0;
				
				virtual void setMap(QPixmap pixmap) =0;
				
				virtual void setStartPoint( QPoint start) =0;
				virtual void setEndPoint( QPoint end) =0;
				
				virtual void setDrawFigure( Figure figure) =0;
				virtual void setDrawFigure( QAction* action) =0;
				
				virtual void setBooleanFill( bool fill) =0;
				
				virtual void setRobotParameters (double costHalfTurn, double initialDirection, int width, std::vector<Bitmap::ColorCost> colorCost) =0;
				
				virtual void setColorPen( QColor color) =0;
				virtual void setZoomValue(float zoom) =0;
				virtual void setSizePen(int size) =0;
				
				virtual void loadMap (QString filename = "") =0;
				virtual void saveMap (QString filename = "") =0;
				virtual void run () =0;
				
		//}
		
		//Signals
		//{
			
			signals:
				
				virtual void drawFigureChanged(Ihm::PluginInterface::Figure figure );
				virtual void booleanFillChanged(bool fill);
				
		//}
			
		protected :
		//Attributes
		//{
			
			//Variables
			//{
				
				
				
			//}
			
		//}
	};
}

//~ Le truc pour dire Ã  Qt qu'on fait une interface qui doit Ãªtre accessible de partout
//~ Ne marche pas Ã  cause d'une erreur dans Qt.
//~ Q_DECLARE_INTERFACE( PluginInterface, "com.trolltech.Plugin.PluginInterface/1.0");

#endif


