/** Titre
 *      @project DiRIGe
 *      @class Robot
 *      @description : Classe trouve le chemin le plus opitmizé à partir d'un tableau de node.
 *      Elle modifira les couleurs de nodes faisant partie du chemin.
 *	@author Alex-Mehdi ZAHID
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H


#include <vector>
#include <float.h>
#include <iostream>
#include "node.h"
#include "robot.h"

namespace Algorithm
{
	class Dijkstra
	{
	
	    public :
	    //Builder
	        Dijkstra();
	        Dijkstra( std::vector< std::vector<Node*> > graph, Node* start, Node* end );
	
	    //Destroyer
	        ~Dijkstra();
	    //Method
	        //Accesseur
	        std::vector< std::vector<Node*> > getGraph() const;
	        Node* getStartNode() const;
	        Node* getEndNode() const;
	
	        //Mutateur
	        void setGraph(std::vector< std::vector<Node*> > graph);
	        void setStartNode( Node* start );
	        void setEndNode( Node* end );
	
	        //Processing
	        //Comment : cette fonction trouve le chemin.
	        void findThePath();
	        //Comment : cette fonction reconstruit le chemin. Elle modifie les couleurs des
	        //node faisant partie du chemin.
	        std::vector< std::vector<Node*> > buildThePath();
	
	
	    private :
	    //Attribute
	        //Inconstant
	        std::vector< std::vector<Node*> > graph_;
	        Node* startNode_;
	        Node* endNode_;
	        int mapWidth_;
	        int mapHeight_;
	
	};
}

#endif // DIJKSTRA_H
