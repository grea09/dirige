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

#ifndef DEF_PLUGIN_MANAGER_H
#define DEF_PLUGIN_MANAGER_H

//~ #include "plugininterface.h"
#include "toolbardraw.h"
#include "toolbarzoom.h"
#include "colorcost.h"
#include "graph.h"
#include "robot.h"
#include "dijkstra.h"
#include <QtGui>


#define UNDEF QPoint(-1, -1)

namespace Bitmap
{
	class PluginWidget : public QWidget//Ihm::PluginInterface
	{
		Q_OBJECT
		//~ Q_INTERFACES(Ihm::PluginInterface)
		
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
			
			PluginWidget(QWidget* parent = 0, int x = 600, int y = 600);
			PluginWidget(QString fileName, QWidget* parent = NULL);
			PluginWidget(PluginWidget& plugin, QWidget* parent = NULL);
			
		//}
		
		//Destroyers
		//{
			
			~PluginWidget();
			
		//}
		
		//Methods
		//{
			public:
			//Getters
			//{
				
				//~ int getDrawFigure();
				//~ bool getBooleanFill();
				//~ int getMapWidth();
				//~ int getMapHeight();
				QPixmap getMap();
				//~ QColor& getColor();
				
				//~ QPixmap& getResult();
				
				QPoint* getStartPoint();
				QPoint* getEndPoint();
				QColor getResultColor();
				
			//}
			
			//Setters
			//{
				
				
				
			//}
			
			//Processing
			//{
				
				void mouseMoveEvent(QMouseEvent *);
				void mousePressEvent(QMouseEvent *);
				void mouseReleaseEvent(QMouseEvent *);
				void paintEvent(QPaintEvent *);
				
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
				
				//~ void setMapWidth( int width);
				//~ void setMapHeight( int height);
				
				void setMap(QPixmap pixmap);
				
				void setStartPoint( QPoint* start);
				void setEndPoint( QPoint* end);
				
				void setDrawFigure( Figure figure); //Ihm::PluginInterface::
				void setDrawFigure( QAction* action);
				
				void setBooleanFill( bool fill);
				
				void setRobotParameters (double costHalfTurn, double initialDirection, int width, std::vector<ColorCost> colorCost);
				
				void setResultColor();
				void setResultColor( QColor color);
				void setColorPen( QColor color);
				void setZoomValue(float zoom);
				void setSizePen(int size);
				
				void loadMap (QString filename = "");
				void saveMap (QString filename = "");
				void run ();
				
		//}
		
		//Signals
		//{
			
			signals:
				
				void drawFigureChanged(Figure figure ); //Ihm::PluginInterface::
				void booleanFillChanged(bool fill);
				
				
				
		//}
		protected :
		//Attributes
		//{
			
			//Variables
			//{
				
				//Figure en cours
				int drawFigure_;
				
				//Variable pour tester si la figure doit être pleine ou vide
				bool booleanFill_;
				
				//Valeur du zoom
				float zoomValue_;
				
				//Taille de l'image
				int sizeX_;
				int sizeY_;
				
				//Labels qui vont contenir les images des drapeaux
				QLabel* startFlagLabel_;
				QPixmap* pixmapStartFlag_;
				QLabel* finishFlagLabel_;
				QPixmap* pixmapFinishFlag_;
				
				//Image
				QPixmap* map_;
				
				//Et résultat ...
				//~ QLabel* resultLabel_;
				//~ QPixmap* result_;
				
				//Points de départ et d'arrivé
				QPoint* startPoint_;
				QPoint* endPoint_;
				QColor resultColor_;
				
				//Positions de la souris
				Algorithm::Node* startNode_;
				Algorithm::Node* endNode_;
				
				//Positions de la souris
				QPoint* start_;
				QPoint* end_;
				
				//Style de l'encre du dessin
				QPen* pen_;
				int sizePen_;
				QPen* draftPen_;
				QColor* color_;
				
				std::vector<ColorCost> colorCost_;
				
				enum ColorIndex
				{
					UNBLOCK,
					START,
					END,
					BLOCK
				};
				
			//}
			
		//}
		
		//Methodes
		//{
			//Display
			//{
				
				void paintToPixmap();
				void paintPoint(QPainter& painter);
				void paintLine(QPainter& painter);
				void paintRect(QPainter& painter);
				void paintEllipse(QPainter& painter);
				void paintAll(QPainter& painter);
				void build();
				
			//}
		//}
	};
}

#endif


