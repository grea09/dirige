/** Title
 *      @project DiRIGe
 *      @class Node
 *      @description : Une node représente un noeud dans un gaphe. Un graphe est composé de nodes.
 *	@author Alex-Mehdi ZAHID
 */

#include "graph.h"
#include "minimalcostfunction.h"
#include "basicdirectioncostfunction.h"
#include <iostream>
#include "libdevcpp.h"

#define DEFAULT_COST 100

using namespace Bitmap;
using Algorithm::Node;

//Constant
//{

//}

//Builder
//{
    Graph::Graph()
    {
        map_ = NULL;
    }
    Graph::Graph( QImage* map, QPoint startNode, QPoint endNode ) 
		: map_(map), startNode_(new Node(startNode)), endNode_(new Node(endNode))
    {

        width_ = map->width();
        height_ = map->height();

        graph_.resize(map->width());
        for( int i = 0; i<map->width(); ++i )
        {
            graph_[i].resize(map->height());
        }
        for( int i = 0; i<map->width(); ++i )
        {
            for( int j = 0; j<map->height(); ++j)
            {            
                graph_[i][j] = new Node( i, j );
            }
        }
        startNode_ = graph_[startNode.rx()][startNode.ry()];
        endNode_ = graph_[endNode.rx()][endNode.ry()];
    }
//}

//Destroyer
//{
    Graph::~Graph()
    {
        for( int i = 0; i<width_; ++i )
        {
            for( int j = 0; j<height_; ++j)
            {
                delete graph_[i][j];
            }
        }
    }
//{

//Accessor
//{
    QImage* Graph::getMap() const
    {
        return map_;
    }
    int Graph::getMapWitdh() const
    {
        return width_;
    }
    int Graph::getMapHeight() const
    {
        return height_;
    }
    std::vector< std::vector<Node*> > Graph::getGraph()
    {
        return graph_;
    }
    Node* Graph::getStartNode() const
    {
        return startNode_;
    }
    Node* Graph::getEndNode() const
    {
        return endNode_;
    }
//}

//Mutator
//{
    void Graph::setMap(QImage *map)
    {
        map_ = map;
    }
    void Graph::setGraph(std::vector< std::vector<Node*> > graph)
    {
        graph_ = graph;
    }
//}

//Processing
//{
    void Graph::setNodeCostFunction(std::vector<ColorCost> palette, int costFunctionType)
    {
        //Comment : la répétition du code est lourde mai permet d'éviter de faire un test en O(n)^3

        bool fill = false;
        std::vector<ColorCost>::iterator cursor;

        switch( costFunctionType )
        {
          case 1 :
            for(int i = 0; i<width_; ++i)
            {
                for( int j = 0; j<height_; ++j )
                {
                    for( cursor = palette.begin(); cursor != palette.end(); ++cursor )
                    {
                        if( (*cursor).getColor().rgb() == map_->pixel(i,j) )
                        {
                            graph_[i][j]->setNodeCost( new Algorithm::MinimalCostFunction( (*cursor).getCost(), graph_[i][j]) );
                            fill = true;
                        }
                    }
                    if( fill == false )
                    {
                        graph_[i][j]->setNodeCost( new Algorithm::MinimalCostFunction( DEFAULT_COST, graph_[i][j]) );
                    }
                    fill = false;

                }
            }
            break;
          case 2 :
            for( int i = 0; i<width_; ++i)
            {
                for( int j = 0; j<height_; ++j )
                {
                    for( cursor = palette.begin(); cursor != palette.end(); ++cursor )
                    {
                        if( (*cursor).getColor().rgb() == map_->pixel(i,j) )
                        {
                            graph_[i][j]->setNodeCost( new  Algorithm::BasicDirectionCostFunction( (*cursor).getCost(), graph_[i][j]) );
                            fill = true;
                        }
                    }
                    if( fill == false )
                    {
                        graph_[i][j]->setNodeCost( new  Algorithm::BasicDirectionCostFunction( DEFAULT_COST, graph_[i][j]) );
                    }
                    fill = false;
                }
            }
            break;

         default ://Par défaut, on applique la fonction de cout prenant en compte l'angle
            for( int i = 0; i<width_; ++i)
            {
                for( int j = 0; j<height_; ++j )
                {
                    for( cursor = palette.begin(); cursor != palette.end(); ++cursor )
                    {
                        if( (*cursor).getColor().rgb() == map_->pixel(i,j) )
                        {
                            graph_[i][j]->setNodeCost( new  Algorithm::BasicDirectionCostFunction( (*cursor).getCost(), graph_[i][j]) );
                            fill = true;
                        }
                    }
                    if( fill == false )
                    {
                        graph_[i][j]->setNodeCost( new  Algorithm::BasicDirectionCostFunction( DEFAULT_COST, graph_[i][j]) );
                    }
                    fill = false;
                }
            }
        }
    }
    
    //~ void Graph::drawPath()
    //~ {
        //~ Node* currentNode = endNode_;
        //~ int robotWidth = Robot::Instance()->getWidth();//Largeur du robot
        //~ int landMark = robotWidth/2;//Borne pour étudier les nodes faisant partie du robot. (Un robot peut être composé de plusieur node)
        //~ int readjustment = 0;//On ajuste les nodes à étudier en fonction de la parité de la largeur du robot.
        //~ if(Robot::Instance()->getWidth()%2 == 0)
        //~ {
            //~ readjustment = 1;
        //~ }
		//~ 
		//~ for (int i = 0; i < width_; i++)
		//~ {
			//~ for (int j = 0; j < height_; j++)
			//~ {
				//~ if (graph_[i][j]->getAntecedent())
				//~ {
					//~ debugV(graph_[i][j]->getCoordX());
					//~ debugV(graph_[i][j]->getCoordY());
				//~ }
			//~ }
			//~ 
		//~ }
		//~ 
		//~ QPixmap* pixmap = new QPixmap(width_, height_);
		//~ pixmap->fill(Qt::transparent);
		//~ 
        //~ if( endNode_->getAntecedent() == NULL )
        //~ {
            //~ throw Algorithm::NoPathException();
        //~ }
        //~ while( currentNode != startNode_ )
        //~ {
            //~ //map_->setPixel(currentNode->getCoordX(),currentNode->getCoordY(),QColor(255,0,0).rgb());
            //~ for( int k = -landMark + readjustment; k<(landMark+1); ++k )
            //~ {
                //~ for( int l = -landMark + readjustment; l<(landMark+1); ++l)
                //~ {                  
                    //~ pixmap->setPixel((currentNode->getCoordX()+k),(currentNode->getCoordY()+l),QColor(255,0,0).rgb());
                //~ }
            //~ }
            //~ currentNode = currentNode->getAntecedent();
        //~ }
        //~ map_->save("resultat.bmp");
    //~ }

//}
