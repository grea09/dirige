/** Titre
 *      @project DiRIGe
 *      @class Palette
 *      @description : Classe foncteur permettant d'associer le coût d'un node à sa couleur et à l'angle du robot
 *      lorsque celui ci est arrivé sur la node.
 *	@author Alex-Mehdi ZAHID
 */

#include "basicdirectioncostfunction.h"
#include <iostream>

using namespace Algorithm;

//Builder
//{
BasicDirectionCostFunction::BasicDirectionCostFunction() : Cost()
{
}
//Comment : l'angle est mit à 0 s'il ne s'agit pas de la node de départ
BasicDirectionCostFunction::BasicDirectionCostFunction( double crossedCost, Node* node ) : Cost(crossedCost, node)
{
}
//}

//Destroyer
//{
BasicDirectionCostFunction::~BasicDirectionCostFunction()
{
}
//}

//Operator
//{
double BasicDirectionCostFunction::calculateCost( int x, int y, double crossedCostEndNode )
{   
    /*          90°
         135°    |    45°
                 |
      180° ------|------ 0 ou 360°
                 |
         225°    |    315°
                270°
    */
        double angleToDo = 0;
        double currentAngle = 0;//node_->angle_;
        double distance = 1;
        int static lll=0;

        //On garde son angle (Qd aucun prédécessseu ex node départ) ou on regarde d'où vient son prédécesseur pour connaitre son angle
        if( node_->antecedent_ != NULL )
        {
            if( (node_->antecedent_->coordX_ == (node_->coordX_)-1) && (node_->antecedent_->coordY_ == (node_->coordY_)-1) )
            {
                //Node antécédente : supérieur gauche
                currentAngle = 315;
            }
            else if( (node_->antecedent_->coordX_ == (node_->coordX_) -1) && (node_->antecedent_->coordY_ == (node_->coordY_) ) )
            {
                //Node antécédente : supérieur
                currentAngle = 270;
            }
            else if( (node_->antecedent_->coordX_ == (node_->coordX_)-1) && (node_->antecedent_->coordY_ == (node_->coordY_)+1) )
            {
                //Node antécédente : supérieur droite
                currentAngle = 225;
            }
            else if( (node_->antecedent_->coordX_ == (node_->coordX_)) && (node_->antecedent_->coordY_ == (node_->coordY_)-1) )
            {
                //Node antécédente : gauche
                currentAngle = 0;
            }
            else if( (node_->antecedent_->coordX_ == (node_->coordX_)) && (node_->antecedent_->coordY_ == (node_->coordY_)+1) )
            {
                //Node antécédente : droite
                currentAngle = 180;
            }
            else if( (node_->antecedent_->coordX_ == (node_->coordX_)+1) && (node_->antecedent_->coordY_ == (node_->coordY_)-1) )
            {
                //Node antécédente : inférieur gauche
                currentAngle = 45;
            }
            else if( (node_->antecedent_->coordX_ == (node_->coordX_)+1) && (node_->antecedent_->coordY_ == (node_->coordY_)) )
            {
                //Node antécédente : inférieur
                currentAngle = 90;
            }
            else
            {
                //Node antécédente : inférieur droite
                currentAngle = 135;
            }

        }
        if(  node_->antecedent_ == NULL )
        {
            currentAngle = Bitmap::Robot::Instance()->getInitialDirection();
        }
        if( x == ( ((node_->coordX_)) - 1) && y == ( ((node_->coordY_)) - 1))
        {
            //Node d'arrivé : supérieur gauche
            distance = sqrt(2);
            angleToDo = abs( currentAngle - 135 );
            if( angleToDo > 180 )
            {
                angleToDo = 360 - angleToDo;
            }
        }
        else if( x == ( (node_->coordX_) -1) && y == ( (node_->coordY_) ))
        {
            //Node d'arrivé : supérieur
            angleToDo = abs( currentAngle - 90 );
            if( angleToDo > 180 )
            {
                angleToDo = 360 - angleToDo;
            }
        }
        else if( x == ( (node_->coordX_) - 1) && y == ( (node_->coordY_) + 1))
        {
            //Node d'arrivé : supérieur droite
            distance = sqrt(2);
            angleToDo = abs( currentAngle - 45 );
            if( angleToDo > 180 )
            {
                angleToDo = 360 - angleToDo;
            }
        }
        else if( x == ( (node_->coordX_)) && y == ( (node_->coordY_)-1 ) )
        {
            //Node d'arrivé : gauche
            angleToDo = abs( currentAngle - 180 );
            if( angleToDo > 180 )
            {
                angleToDo = 360 - angleToDo;
            }
        }
        else if( x == ( (node_->coordX_)) && y == ( (node_->coordY_) + 1 ))
        {
            //Node d'arrivé : droite
            angleToDo = node_->angle_;
        }
        else if( x == ( (node_->coordX_) + 1) && y == ( (node_->coordY_) - 1))
        {
            //Node d'arrivé : inférieur gauche
            distance = sqrt(2);
            angleToDo = abs( currentAngle - 225 );
            if( angleToDo > 180 )
            {
                angleToDo = 360 - angleToDo;
            }
        }
        else if( x == ((node_->coordX_)+1)  && y == ( (node_->coordY_)))
        {
            //Node d'arrivé : inférieur
            angleToDo = abs( currentAngle - 270 );
            if( angleToDo > 180 )
            {
                angleToDo = 360 - angleToDo;
            }
        }
        else
        {
            //Node d'arrivé : inférieur droite
            distance = sqrt(2);
            angleToDo = abs( currentAngle - 315 );
            if( angleToDo > 180 )
            {
                angleToDo = 360 - angleToDo;
            }
        }
        return distance + crossedCostEndNode + angleToDo*(Bitmap::Robot::Instance()->getCostHalfTurn()/180);
}
//}
