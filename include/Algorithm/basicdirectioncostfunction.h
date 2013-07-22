/** Titre
 *      @project DiRIGe
 *      @class Palette
 *      @description : Classe foncteur permettant d'associer le coût d'un node à sa couleur et à l'angle du robot
 *      lorsque celui ci est arrivé sur la node.
 *	@author Alex-Mehdi ZAHID
 */

#ifndef BASICDIRECTIONCOSTFUNCTION_H
#define BASICDIRECTIONCOSTFUNCTION_H

#include "cost.h"

namespace Algorithm
{
	class BasicDirectionCostFunction : public Cost
	{
	    public:
	
	        //Builder
	        BasicDirectionCostFunction();
	        BasicDirectionCostFunction( double crossedCost, Node* node );
	
	        //Destroyer
	        ~BasicDirectionCostFunction();
	
	        //Operator
	        double calculateCost( int x, int y, double crossedCost );
	
	};
}

#endif // BASICDIRECTIONCOSTFUNCTION_H
