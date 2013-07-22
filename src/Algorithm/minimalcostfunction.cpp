/** Titre
 *      @project DiRIGe
 *      @class Palette
 *      @description : Classe foncteur permettant d'associer le coût d'un node à sa couleur uniquement.
 *	@author Alex-Mehdi ZAHID
 */

#include "minimalcostfunction.h"
#include <iostream>

using namespace Algorithm;

//Builder
//{
MinimalCostFunction::MinimalCostFunction():Cost()
{
}
MinimalCostFunction::MinimalCostFunction( double crossedCost, Node* node ): Cost(crossedCost, node)
{
}
//}

//Destroyer
//{
MinimalCostFunction::~MinimalCostFunction()
{
}
//}

//Method
//{
double MinimalCostFunction::calculateCost( int x, int y, double crossedCostEndNode )
{
        double distance;

        if( (x == ( ((node_->coordX_)) - 1) && y == ( ((node_->coordY_)) - 1))
           || ( x == ( (node_->coordX_) - 1) && y == ( (node_->coordY_) + 1))
           || ( x == ( (node_->coordX_) + 1) && y == ( (node_->coordY_) - 1))
           || ( x == ( (node_->coordX_) + 1) && y == ( (node_->coordY_) + 1)))
        {
            distance = sqrt(2);
        }
        else
        {
            distance = 1;
        }
    return distance + crossedCostEndNode;
}
//}
