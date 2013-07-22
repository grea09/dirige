/** Titre
 *      @project DiRIGe
 *      @class Robot
 *      @description : Classe contient toute la configuration du robot
 *	@author Alex-Mehdi ZAHID
 */

#ifndef ROBOT_H
#define ROBOT_H

#include <cstdlib>
#include <QColor>
#include "colorcost.h"
#include "node.h"
//~ namespace Algorithm
//~ {
	//~ class Node;
//~ }
#include "vector"

namespace Bitmap
{
	class Robot
	{
		//Comment : Utilisation d'un robot
		// Robot::Instance()->maFonction();
		//    std::cout<<Robot::Instance()->getInitialDirection()<<std::endl;
		//    std::cout<<Robot::Instance( 15, 20 )->getInitialDirection()<<std::endl;
		//Attention : la deuxième deuxième ligne affiche la même chose que la première car
		//l'objet a déjà été construit !

		public :
			   
			//Method
				//Accesseur
				double getCostHalfTurn() const;
				double getInitialDirection() const;
				std::vector<ColorCost> getColorCost() const;
				QColor getColor( int i );
				double getCost( int i );
				int getWidth();

				//Mutateur
				void setCostHalfTurn( double costHalfTurn );
				void setInitialDirection( double intialDirection );
				void setColorCost( std::vector<ColorCost> palette );

				//Processing
				static Robot* Instance();
				static Robot* Instance( double costHalfTurn, double initialDirection, int width, std::vector<ColorCost> palette );
				static void delRobot();

		private :
		//Builder
			Robot();
			Robot( const Robot& ){}
			Robot( double costHalfTurn, double initialDirection, int width, std::vector<ColorCost> palette );

		//Destroyer
			~Robot();

		//Operator
			Robot& operator=( const Robot& ){ return *this; }

		//Attribute
			//Inconstant
			double costHalfTurn_;
			double initialDirection_ ;
			int width_;
			//Comment : cet attribut est un vecteur d'objets de type colorCost qui font l'association entre une couleur et un coût de traversé.
			std::vector<ColorCost> palette_;
			static Robot* robotInstance_;


	};
}


#endif // ROBOT_H


