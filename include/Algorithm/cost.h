/** Titre
 *      @project DiRIGe
 *      @class Cost
 *      @description : Classe abstraite permettant d'associer une fonction de calcul de coût à une node.
 *	@author Alex-Mehdi ZAHID
 */

#ifndef COST_H
#define COST_H

#include <float.h>
#include <cmath>
#include "node.h"
#include "robot.h"
#include <iostream>
namespace Algorithm
{
	class Node;
	
	class Cost
	{
	    public:        
	        friend class Node;
	        friend class Robot;
	        friend class Dijkstra;
	        //Builder
	        Cost();
	        Cost( double crossedCost , Node* node);
	
	        //Destroyer
	        virtual ~Cost();
	
	        //Accessor
	        double getCrosseCost();
	
	        //Operator
	         virtual double calculateCost( int x, int y, double crossedCostEndNode ) = 0;
	
	    protected :
	            double crossedCost_;
	            Node* node_;
	
	};
}

#endif // COST_H
