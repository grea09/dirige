/** Titre
 *      @project DiRIGe
 *      @class Robot
 *      @description : Classe trouve le chemin le plus opitmizé à partir d'un tableau de node.
 *      Elle modifira les couleurs de nodes faisant partie du chemin.
 *	@author Alex-Mehdi ZAHID
 */
#include "fibonacciheap.h"
#include "dijkstra.h"
#include <algorithm>
#include "libdevcpp.h"

using namespace Algorithm;

//Builder
//{
    Dijkstra::Dijkstra()
    {
        startNode_ = NULL;
        endNode_ = NULL;
        mapWidth_ = graph_.size();
        mapHeight_ = graph_[1].size();
        //L'image étant un rectangle : graph_[0].size() = graph_[1].size() = graph_[2].size() ...
    }
    Dijkstra::Dijkstra( std::vector< std::vector<Node*> > graph, Node* start, Node* end )
    {
        graph_ = graph;
        startNode_ = start;
        endNode_ = end;
        mapWidth_ = graph_.size();
        mapHeight_ = graph_[1].size();
        //L'image étant un rectangle : graph_[0].size() = graph_[1].size() = graph_[2].size() ...
    }
//}

//Destroyer
//{
    Dijkstra::~Dijkstra()
    {
    }
//{

//Accessor
//{
    std::vector< std::vector<Node*> > Dijkstra::getGraph() const
    {
        return graph_;
    }
    Node* Dijkstra::getStartNode() const
    {
        return startNode_;
    }
    Node* Dijkstra::getEndNode() const
    {
        return endNode_;
    }
//}

//Mutator
//{
    void Dijkstra::setGraph( std::vector<std::vector<Node*> > graph )
    {
        graph_ = graph;
    }
    void Dijkstra::setStartNode( Node* start )
    {
        startNode_ = start;
    }
    void Dijkstra::setEndNode( Node* end )
    {
        endNode_ = end;
    }
//}

//Processing
//{
    void Dijkstra::findThePath()
    {
		debugsub(ENTER);
               FibonacciHeap* heap = new FibonacciHeap();
               debugV(heap);
               debugV(&graph_);
               debugV(startNode_);
               debugV(startNode_->getCoordX());
               debugV(startNode_->getCoordY());
               debugV(graph_[startNode_->getCoordX()][startNode_->getCoordY()]);
               heap->insertVertex(graph_[startNode_->getCoordX()][startNode_->getCoordY()]);
               int robotWidth = Bitmap::Robot::Instance()->getWidth();//Largeur du robot
               int landMark = robotWidth/2;//Borne pour étudier les nodes faisant partie du robot. (Un robot peut être composé de plusieur node)
               float costNode = 0;//On stock le coût dans une variable pour limiter le nombre d'appel de fonction.
               float sumCostNodeSide = 0;//On additionne le coût de chaque node pour connaître de manière plus exacte le coût de déplacement.
               bool impassable = false;//Booléen permettant d'indiquer que le robot ne peut pas passer, il y a un obstacle infranchissable.
               int readjustment = 0;//On ajuste les nodes à étudier en fonction de la parité de la largeur du robot.

               /* exemple des nodes à étudier dans le cas d'une largeur impaire.
                  |_|_|_|
                  |_|.|_|
                  |_|_|_|
                  exemple des nodes à étudier dans le cas d'une largeur paire.
                  |_||_|_|_|
                  |_||.|_|_|
                  |_||_|_|_|
                  |_||_|_|_|
                  Le "." représente la node suivant laquel l'angle est étudié.
               */
               
               if(Bitmap::Robot::Instance()->getWidth() == 1 )
				{
					robotWidth = 2;
					landMark = robotWidth/2;
				}
               
               if(Bitmap::Robot::Instance()->getWidth()%2 == 0)
               {
                   readjustment = 1;
               }
               do{

                   Node* currentNode = heap->deleteMin();
                   currentNode->state_ = SCANNED;
                   
                   for( int i = (currentNode->coordX_-1); i<(currentNode->coordX_+2); ++i )
                   {
                       for( int j = (currentNode->coordY_-1); j<(currentNode->coordY_+2); ++j )
                       {
sumCostNodeSide = 0;
                               impassable = false;
                           if( i > -1 && i<mapWidth_ && j > -1 && j<mapHeight_ && (!(i==currentNode->coordX_ && j==currentNode->coordY_)))
                           {
                               //Morceau permettant de prendre en compte une largeur du robot
                               
                               if( robotWidth == 1 )
                               {
                                   if( graph_[i][j]->cost_->crossedCost_ == -1)
                                   {
                                       impassable = true;
                                   }
                                   else
                                   {
                                       sumCostNodeSide = graph_[i][j]->cost_->crossedCost_;
                                   }
                               }
                               for( int k = -landMark + readjustment; k<(landMark+1); ++k )
                               {
                                   for( int l = -landMark + readjustment; l<(landMark+1); ++l)
                                   {
                                       if( (i+k) > -1 && (i+k)<(mapWidth_) && (j+l) > -1 && (j+l)<(mapHeight_) )
                                       {
                                            //std::cout<<" k = "<<k<<" l = "<<l<<std::endl;
                                            //std::cout<<" i = "<<i<<" k = "<<k<<" j = "<<j<<" l = "<<l<<std::endl;
                                            //std::cout<<" i+k "<< i+k <<" j+l "<<j+l<<std::endl;
                                            costNode = graph_[i+k][j+l]->cost_->crossedCost_;
                                            if( costNode == -1 )
                                            {
                                                impassable = true;
                                            }
                                            else
                                            {
                                                sumCostNodeSide += costNode;

                                            }
                                       }
                                       else
                                       {
                                           impassable = true; // car tous les bords ne sont pas includ dans la map
                                       }
                                   }
                               }
                               
                               if( impassable != true)
                               {
                                    double link = currentNode->cost_->calculateCost(i,j,sumCostNodeSide);
                                    if( graph_[i][j]->state_ == UNLABELED )
                                    {
                                        graph_[i][j]->state_ = LABELED;
                                        //On considère que si le cout est à moins un s'est infranchissable

                                       graph_[i][j]->antecedent_ = currentNode;
                                       graph_[i][j]->weight_ = currentNode->weight_ + link;
                                       heap->insertVertex(graph_[i][j]);

                                    }
                                    else if( currentNode->weight_ + link < graph_[i][j]->weight_ )
                                    {
                                        graph_[i][j]->antecedent_ = currentNode;
                                        heap->decreaseWeight( (currentNode->weight_ + link), graph_[i][j] );
                                    }
                               }
                           }
                       }
                   }

               }while (!heap->isEmpty());
               //~ delete heap;
        debugsub(EXIT_SUCCESS);
    }
//}
