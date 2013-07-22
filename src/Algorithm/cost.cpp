/** Titre
 *      @project DiRIGe
 *      @class Cost
 *      @description : Classe abstraite permettant d'associer une fonction de calcul de coût à une node.
 *	@author Alex-Mehdi ZAHID
 */

#include "cost.h"
#include <iostream>

using namespace Algorithm;

//Builder
//{
Cost::Cost()
{
    crossedCost_ = FLT_MAX;
    node_ = NULL;
}
Cost::Cost( double crossedCost, Node* node ) : crossedCost_(crossedCost), node_(node)
{

}
//}

//Destroyer
//{
Cost::~Cost()
{
}
//}

//Accessor
//{
double Cost::getCrosseCost()
{
    return crossedCost_;
}
//}

