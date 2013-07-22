/** Titre
 *      @project DiRIGe
 *      @class Palette
 *      @description : Classe foncteur permettant d'associer le coût d'un node à sa couleur uniquement.
 *	@author Alex-Mehdi ZAHID
 */

#ifndef MINIMALCOSTFUNCTION_H
#define MINIMALCOSTFUNCTION_H

#include "cost.h"

namespace Algorithm
{
	class MinimalCostFunction : public Cost
	{
	    public:
	        //Builder
	        MinimalCostFunction();
	        MinimalCostFunction( double crossedCost, Node* node );
	
	        //Destroyer
	        ~MinimalCostFunction();
	
	        //Operator
	        double calculateCost( int x, int y, double crossedCostEndNode );
	
	};
}

#endif // MINIMALCOSTFUNCTION_H
