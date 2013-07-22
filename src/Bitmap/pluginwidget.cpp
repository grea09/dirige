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

#include "pluginwidget.h"
#include "libdevcpp.h"

using namespace Bitmap;

/*! Titre
	\project DiRIGe
	\class PluginWidget
	\ingroup Bitmap
	\brief Une classe pour afficher le plugin
	\author Copyright 2010 Antoine GRÉA <grea09@gmail.com>
	\sa PluginInterface, PluginInterface, {Bitmap}
 */

//Constants
//{
	
	
	
//}

//Builders
//{
	
	
	PluginWidget::PluginWidget(QWidget* parent, int x, int y) 
		: QWidget(parent), 
		sizeX_(x), sizeY_(y)
	{
		debugsub(ENTER);
		//Création de l'image par défaut
		map_ = new QPixmap(sizeX_, sizeY_);
		map_->fill(Qt::white);
		
		//Initialisation des variables représentant l'arrivé et le départ
		startPoint_ = NULL;
		endPoint_ = NULL;
		
		build();
		debugsub(EXIT_SUCCESS);
	}
	
	PluginWidget::PluginWidget(QString fileName, QWidget* parent) 
		: QWidget(parent)
	{
		debugsub(ENTER);
		QPixmap* temp = new QPixmap(fileName);
		if (temp)
		{
			map_ = temp;
			
			//Initialisation de la taille de l'image
			sizeX_ = map_->width();
			sizeY_ = map_->height();
		}
		else
		{
			//Initialisation par défaut
			sizeX_ = 600;
			sizeY_ = 600;
			map_ = new QPixmap(sizeX_, sizeY_);
			map_->fill(Qt::white);
		}
		
		//Initialisation des variables représentant l'arrivé et le départ
		startPoint_ = NULL;
		endPoint_ = NULL;
		
		build();
		debugsub(EXIT_SUCCESS);
	}
	
	PluginWidget::PluginWidget(PluginWidget& plugin, QWidget* parent) 
                : QWidget(parent)
	{
		debugsub(ENTER);

                startPoint_ = new QPoint(*plugin.startPoint_);
                endPoint_ = new QPoint(*plugin.endPoint_);
                map_ = new QPixmap(*plugin.map_);

		build();
		
		debugsub(EXIT_SUCCESS);
	}
	
	
	
//}

//Destroyers
//{
	
	PluginWidget::~PluginWidget()
	{
		debugsub(ENTER);
		
		delete map_;
		delete start_;
		delete end_;
		delete color_;
		delete startFlagLabel_;
		delete pixmapStartFlag_;
		delete finishFlagLabel_;
		delete pixmapFinishFlag_;
		delete startPoint_;
		delete endPoint_;
		delete pen_;
		delete draftPen_;
		//~ delete resultLabel_;
		//~ delete result_;
		// Bug étrange
		//~ delete endNode_;
		//~ delete startNode_;
		
		debugsub(EXIT_SUCCESS);
	}
	
//{

//Getters
//{
	
	QPixmap PluginWidget::getMap()
	{
		debugsub(ENTER);
		debugsub(EXIT_SUCCESS);
		return *map_;
	}
	
	QPoint* PluginWidget::getStartPoint()
	{
		debugsub(ENTER);
		debugsub(EXIT_SUCCESS);
		return startPoint_;
	}
	
	QPoint* PluginWidget::getEndPoint()
	{
		debugsub(ENTER);
		debugsub(EXIT_SUCCESS);
		return endPoint_;
	}
	
	QColor PluginWidget::getResultColor()
	{
		debugsub(ENTER);
		debugsub(EXIT_SUCCESS);
		return resultColor_;
	}
	
//}

//Setters
//{
	
	void PluginWidget::setRobotParameters (double costHalfTurn, double initialDirection, int width, std::vector<ColorCost> colorCost)
	{
		debugsub(ENTER);
		Robot::Instance()->delRobot();
		for (unsigned int i = 0; i < colorCost.size(); i++)
		{
			colorCost_.push_back( colorCost[i]);
		}
		
		Robot::Instance( costHalfTurn, initialDirection, width,colorCost_);
		debugV(Robot::Instance()->getWidth());
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::setDrawFigure(QAction* action)
	{
		debugsub(ENTER);
		
		if (action->objectName() == "actionHandFree_")
		{
			setDrawFigure(HANDFREE);//Ihm::PluginInterface::
		}
		else if (action->objectName() == "actionErraser_")
		{
			setDrawFigure(ERRASER);//Ihm::PluginInterface::
		}
		else if (action->objectName() == "actionLine_")
		{
			setDrawFigure(LINE);//Ihm::PluginInterface::
		}
		else if (action->objectName() == "actionRectangle_")
		{
			setDrawFigure(RECTANGLE);//Ihm::PluginInterface::
		}
		else if (action->objectName() == "actionEllipse_")
		{
			setDrawFigure(ELLIPSE);//Ihm::PluginInterface::
		}
		else if (action->objectName() == "actionStart_")
		{
			setDrawFigure(START_POINT);//Ihm::PluginInterface::
		}
		else if (action->objectName() == "actionEnd_")
		{
			setDrawFigure(END_POINT);//Ihm::PluginInterface::
		}
		else
		{
			setDrawFigure(VOID);//Ihm::PluginInterface::
		}
		
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::setDrawFigure(Figure figure)//Ihm::PluginInterface::Figure
	{
		debugsub(ENTER);
		drawFigure_ = figure;
		
		//La fonction MouseMoveEvent s'effectue que lorsqu'on appuie sur un bouton
		setMouseTracking(false);
		
		switch (drawFigure_)
		{
			case HANDFREE:
				setCursor(QCursor(QPixmap(":/images/handfree-cursor.png"), 20, 32));
			break;
			
			case ERRASER:
				setCursor(Qt::ArrowCursor);
				//La fonction MouseMoveEvent s'effectue lorsqu'on bouge la souris
				setMouseTracking(true);
			break;
			
			case VOID:
				setCursor(Qt::ArrowCursor);
				//La fonction MouseMoveEvent s'arrête
				setMouseTracking(false);
			break;
			default:
				setCursor(Qt::CrossCursor);
			break;
		}
		
		update();
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::setStartPoint(QPoint* start)
	{
		debugsub(ENTER);
		startPoint_ = start;
		update();
		repaint();
		debugsub(!!startPoint_);
	}
	
	void PluginWidget::setEndPoint(QPoint* end)
	{
		debugsub(ENTER);
		endPoint_ = end;
		update();
		repaint();
		debugsub(!!endPoint_);
	}
	
	void PluginWidget::setResultColor()
	{
		debugsub(ENTER);
		QColorDialog colorDialog;
		QColor color = colorDialog.getColor();
		if(color.isValid())
		{
				setResultColor(color);
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::setResultColor(QColor color)
	{
		debugsub(ENTER);
		resultColor_ = color;
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::setBooleanFill(bool fill)
	{
		debugsub(ENTER);
		booleanFill_ = fill;
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::setMap(QPixmap pixmap)
	{
		debugsub(ENTER);
		delete map_;
		map_ = new QPixmap(pixmap);
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::setZoomValue(float zoom)
	{
		debugsub(ENTER);
		zoomValue_ = zoom;
		
		float sizeX = sizeX_ * zoomValue_;
		float sizeY = sizeY_ * zoomValue_;
		setFixedSize(sizeX, sizeY);
		
		//~ if (resultLabel_ && result_)
		//~ {
			//~ resultLabel_->setPixmap(result_->scaled(sizeX_*(zoomValue_),sizeY_*(zoomValue_),Qt::KeepAspectRatio));
			//~ resultLabel_->move(0,-1*(zoomValue_));
		//~ }
		
		update();
		repaint();
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::setSizePen(int size)
	{
		debugsub(ENTER);
		debugV(size);
		sizePen_ = size;
		pen_->setWidth((uint)sizePen_);
		repaint();
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::setColorPen(QColor color)
	{
		debugsub(ENTER);
		if (color_ != NULL)
		{
			delete color_;
		}
		
		color_ = new QColor(color);
		pen_->setColor(*color_);
		debugsub(EXIT_SUCCESS);
	}
	
//}

//Processing
//{
	
	void PluginWidget::run()
	{
		debugsub(ENTER);
		
		if (startPoint_ && endPoint_)
		{
			debugV(map_);
			Graph graph(new QImage(map_->toImage()), *startPoint_, *endPoint_);
			graph.setNodeCostFunction(colorCost_,2);
			Algorithm::Dijkstra dijkstra(graph.getGraph(), graph.getStartNode(), graph.getEndNode());
			
			dijkstra.findThePath();
			
			endNode_ = graph.getEndNode();
			startNode_ = graph.getStartNode();
			
			if( endNode_->getAntecedent() == NULL )
	        {
	            QMessageBox::critical(this, "Pas de chemin", QString::fromUtf8("Le robot n'as pas pu atteindre le point d'arrivée."));
	        }
			
			//~ delete result_;
			//~ delete resultLabel_;
			
			//~ result_ = new QPixmap(sizeX_, sizeY_);
			//~ resultLabel_ = new QLabel(this);
			
			if (endNode_->getAntecedent())
			{
				Algorithm::Node* currentNode = endNode_;
				//~ result_->fill(Qt::transparent);
				QPainter painter (map_);
				
				painter.setPen(QPen(resultColor_, (unsigned int)Robot::Instance()->getWidth())) ;
				
		        while( currentNode != startNode_ )
		        {
		            painter.drawLine((currentNode->getCoordX()),(currentNode->getCoordY()), (currentNode->getCoordX()),(currentNode->getCoordY()));
		            currentNode = currentNode->getAntecedent();
		        }
				
				//~ resultLabel_ = new QLabel(this);
				//~ resultLabel_->setPixmap(result_->scaled(sizeX_*(zoomValue_),sizeY_*(zoomValue_)));
				//~ resultLabel_->move(QPoint(0,0));
				//~ resultLabel_->setVisible(true);
				//~ result_->save("Result.png");
			}
			//~ else
			//~ {
				//~ resultLabel_->setVisible(false);
			//~ }
			update();
			repaint();
		}
		else
		{
			QMessageBox::information(this, "Hum, hum !", QString::fromUtf8("Avez-vous pensé à mettre un point de départ et d'arrivé ?"));
		}
		debugsub(EXIT_SUCCESS);
	}
	
	
	void PluginWidget::loadMap (QString filename)
	{
		debugsub(ENTER);
		QPixmap* temp = new QPixmap(filename);
		if (temp)
		{
			delete map_;
			map_ = temp;
			sizeX_ = map_->width();
			sizeY_ = map_->height();
		}
		update();
		repaint();
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::saveMap (QString filename)
	{
		debugsub(ENTER);
		map_->save(filename);
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::build()
	{
		debugsub(ENTER);
		
		//~ result_ = NULL;
		//~ resultLabel_ = NULL;

		//Initialisation des variables représentant la position de la souris début et fin
		start_ = NULL;
		end_ = NULL;
		
		//Initialisation des labels
		startFlagLabel_ = new QLabel(this);
		pixmapStartFlag_ = new QPixmap(":/images/start_p.png");
		startFlagLabel_->setPixmap(*pixmapStartFlag_);
		startFlagLabel_->setVisible(false);
		
		finishFlagLabel_ = new QLabel(this);
		pixmapFinishFlag_ = new QPixmap(":/images/end_p.png");
		finishFlagLabel_->setPixmap(*pixmapFinishFlag_);
		finishFlagLabel_->setVisible(false);
		
		//Par défaut, la valeur du zoom est à 100%
		//~ TODO : mettre une constante
		zoomValue_ = Ihm::ToolBarZoom::ZoomSpinBoxDef / 100;
		
		//Par défaut, le bouton Fill est initialisé à true
		booleanFill_ = true;
		
		//Par défaut, la forme de dessin est vide
		setDrawFigure(VOID);//(Ihm::PluginInterface::Figure)
		
		//Création de la couleur
		color_ = new QColor(Qt::black);
		
		//Taille du stylo par défaut à 1
		sizePen_ = 1;//Ihm::ToolBarDraw::SizeSpinBoxDef;
		
		//Style du dessin
		pen_ = new QPen();
		pen_->setColor(*color_);
		pen_->setWidth((uint)sizePen_);
		pen_->setStyle(Qt::SolidLine);
		
		//Style pour voir la forme que le dessin aura
		draftPen_ = new QPen();
		draftPen_->setColor(Qt::black);
		draftPen_->setWidth((uint)sizePen_);
		draftPen_->setStyle(Qt::DashLine);
		
		setFixedSize(sizeX_ * zoomValue_, sizeY_ * zoomValue_);
		
		// Les couleurs pour le robot
		//~ TODO : mettre une constante
		colorCost_.push_back(ColorCost(Qt::white,100));//mettre le blanc devant pour plus de rapidité
		
		update();
		repaint();
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::paintToPixmap()
	{
		debugsub(ENTER);
                if(map_->height() != 0 && map_->width() != 0)
                {
                    //Dessin sur le pixmap
                    QPainter painter;
                    painter.begin(this->map_);


                    //En fonction de la forme choisie
                    //Forme choisie dessinée

                    switch (drawFigure_)
                    {
                            case RECTANGLE:
                                    //Le stylo pixmap prend les caractéristiques du stylo choisi (couleur, forme ...)
                                    painter.setPen(*pen_);
                                    paintRect(painter);
                            break;
                            case ELLIPSE:
                                    //Le stylo pixmap prend les caractéristiques du stylo choisi (couleur, forme ...)
                                    painter.setPen(*pen_);
                                    paintEllipse(painter);
                            break;
                            case ERRASER:
                                    paintPoint(painter);
                            break;
                            case HANDFREE:
                                    paintLine(painter);
                            break;
                            case START_POINT:
                            break;
                            case END_POINT:
                            break;
                            case VOID:
                            break;
                            default:
                                    //Le stylo pixmap prend les caractéristiques du stylo choisi (couleur, forme ...)
                                    painter.setPen(*pen_);
                                    paintLine(painter);
                            break;
                    }

                    painter.end();

                    //Pixmap de l'écran mis à jour
                    update();
                }
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::paintPoint(QPainter& painter)
	{
		debugsub(ENTER);
		if (start_)
		{
			QPoint p = *start_;
			p.setX((p.x()-(sizePen_*(zoomValue_)/2))/(zoomValue_));
			p.setY((p.y()-(sizePen_*(zoomValue_)/2))/(zoomValue_));
			painter.fillRect(QRect(p, QSize(sizePen_, sizePen_)), Qt::white);
		}
		debugsub(EXIT_SUCCESS);
	}

	void PluginWidget::paintLine(QPainter& painter)
	{
		debugsub(ENTER);
		//Dessin plein ou vide
		if (drawFigure_ == HANDFREE)
		{
			painter.setPen(*pen_);
		}
		
		if (start_ && end_)
		{
			painter.drawLine(start_->x()/zoomValue_, start_->y()/zoomValue_, end_->x()/zoomValue_, end_->y()/zoomValue_);
		}
		else if (start_)
		{
			painter.drawLine(start_->x()/zoomValue_, start_->y()/zoomValue_, start_->x()/zoomValue_, start_->y()/zoomValue_);
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::paintRect(QPainter& painter)
	{
		debugsub(ENTER);
		if (drawFigure_ == ERRASER)
		{
			debugV(start_);
			debugV(sizePen_);
			int x = (start_->x()-sizePen_*(zoomValue_)/2)/zoomValue_;
			int y = (start_->y()-sizePen_*(zoomValue_)/2)/zoomValue_;
			painter.drawRect(x, y, sizePen_, sizePen_);
		}
		else if (end_ && drawFigure_ != VOID)
		{
			debugV(start_);
			debugV(end_);
			int w = (end_->x() - start_->x())/zoomValue_;
			int h = (end_->y() - start_->y())/zoomValue_;
			
			//Dessin plein ou vide
			if (booleanFill_)
			{
				debugV(start_);
				debugV(pen_);
				painter.fillRect(start_->x()/zoomValue_, start_->y()/zoomValue_, w, h, pen_->color());
			}
			else
			{
				debugV(start_);
				painter.drawRect(start_->x()/zoomValue_, start_->y()/zoomValue_, w, h);
			}
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::paintEllipse(QPainter& painter)
	{
		debugsub(ENTER);
		if (end_)
		{
			int w = (end_->x() - start_->x())/zoomValue_;
			int h = (end_->y() - start_->y())/zoomValue_;
			QPoint c = QPoint( (start_->x()+w/2) / zoomValue_, (start_->y()+h/2) / zoomValue_);
			
			//Dessin plein ou vide
			if (booleanFill_ == true)
			{
                                painter.setBrush(pen_->color());
                                int sizeTemp = pen_->width();
                                pen_->setWidth(1);
                                painter.setPen(*pen_);
                                painter.drawEllipse(c, w, h);
                                painter.setBrush(Qt::NoBrush);
                                pen_->setWidth(sizeTemp);
			}
                        else
                        {
                                painter.drawEllipse(c, w, h);
                        }
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::paintAll(QPainter& painter)
	{
		debugsub(ENTER);
		//Dessin d'un carré blanc pour représenter la gomme
		painter.fillRect(0, 0, sizeX_, sizeY_, Qt::white);
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::mousePressEvent(QMouseEvent *event)
	{
		debugsub(ENTER);
		//Position du curseur début récupérée
		start_ = new QPoint(event->pos());
		end_ = NULL;
		setMouseTracking(false);
		
		//Enregistrement de l'image pour le retour en arrière
		//saveForUndo();
		
		
		switch (drawFigure_)
		{
			case START_POINT:
				//Enregistrement des coordonnées du point de départ dans les variables
				startPoint_ = start_;
				update();
				repaint();
			break;
			
			case END_POINT:
				//Enregistrement des coordonnées du point d'arrivée dans les variables
				endPoint_ = start_;
				update();
				repaint();
			break;
			
			case VOID:
			break;
			
			default:
				if (drawFigure_ == HANDFREE || drawFigure_ == ERRASER)
				{
					//Peinture dans map_ et ensuite dans map_ sur l'écran
					paintToPixmap();
				}
			break;
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::mouseMoveEvent(QMouseEvent *event)
	{
		debugsub(ENTER);
		switch(drawFigure_)
		{
			case HANDFREE:
				//Stylo ou gomme directement dessiné sur la map
				if (!end_)
				{
					end_ = new QPoint(event->pos());
				}
				else
				{
					if(!start_)
					{
						delete start_;
					}
					start_ = end_;
					end_ = new QPoint(event->pos());
				}
				// Peinture dans map_ et ensuite dans map_ sur l'écran
				paintToPixmap();
			break;
			
			case ERRASER:
				start_ = new QPoint(event->pos());
				end_ = new QPoint(event->pos());
				update();
				
				if(hasMouseTracking() == false)
				{
					paintToPixmap();
				}
			break;
		}
		
		if ((drawFigure_ != START_POINT) && (drawFigure_ != END_POINT))
		{
			//Modification de la position fin du curseur
			delete end_;
			end_ = new QPoint(event->pos());
			
			// Mise à jour du screen
			update();
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::mouseReleaseEvent(QMouseEvent *)
	{
		debugsub(ENTER);
		// Fin du dessin. Mise à jour de l'image.
		// Peinture dans la map et ensuite de la map sur l'écran
		paintToPixmap();
		switch(drawFigure_)
		{
			case ERRASER:
				setMouseTracking(true);
			break;
			
			case VOID:
				
			break;
			
			default:
				//Réinitialisation des coordonnées début et fin du curseur
				start_ = NULL;
				end_ = NULL;
			break;
		}
		debugsub(EXIT_SUCCESS);
	}
	
	void PluginWidget::paintEvent(QPaintEvent *)
	{
		debugsub(ENTER);
		//Le pixmap devient modifiable
		QPainter painter(this);
		
		//Mettre à jour le pixmap sur l'écran
		painter.scale(zoomValue_, zoomValue_);
		painter.drawPixmap(QPoint(0, 0), *map_);
		
		//~ if (resultLabel_ && result_)
		//~ {
			//~ resultLabel_->setPixmap(result_->scaled(sizeX_*(zoomValue_),sizeY_*(zoomValue_),Qt::KeepAspectRatio));
			//~ resultLabel_->move(QPoint(0,((int)(zoomValue_*100) - 100 )));
		//~ }
		
		if(startPoint_)
		{
			debugV(startFlagLabel_);
			startFlagLabel_->move( (startPoint_->x() * zoomValue_) - 6 , (startPoint_->y() * zoomValue_) - 29 );
			startFlagLabel_->setVisible(true);
		}
		
		if(endPoint_)
		{
			debugV(finishFlagLabel_);
			finishFlagLabel_->move( (endPoint_->x() * zoomValue_) - 6 , (endPoint_->y() * zoomValue_) - 29 );
			finishFlagLabel_->setVisible(true);
		}
		
		
		if ((drawFigure_ > HANDFREE) && start_)
		{
			//Dessin en pointillé pour la forme que prendra le dessin
			painter.setPen(*draftPen_);
			
			switch(drawFigure_)
			{
				case LINE:
					paintLine(painter);
				break;
				
				case RECTANGLE:
					paintRect(painter);
				break;
				
				case ELLIPSE:
					paintEllipse(painter);
				break;
				
				case ERRASER:
					paintRect(painter);
				break;
			}
		}
		
		
		debugsub(EXIT_SUCCESS);
	}
	
	
//}

//Operators
//{
	
	
	
//}

//Display
//{
	
	
	
//}
