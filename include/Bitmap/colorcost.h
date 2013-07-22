/** Titre
 *      @project DiRIGe
 *      @class Palette
 *      @description : Classe associe à une couleur un coût de traversé propre au robot.
 *	@author Alex-Mehdi ZAHID
 */

#ifndef COLORCOST_H
#define COLORCOST_H

#include <QColor>

namespace Bitmap
{
	class ColorCost
	{
	    public :
	    //Builder
	        ColorCost();
	        ColorCost( QColor color, double cost);
	    //Destroyer
	        ~ColorCost();
	
	    //Method
	        //Accesseur
	        QColor getColor();
	        double getCost();
	
	        //Mutateur
	        void setColor( QColor color );
	        void setCost( double cost );
	
	    private :
	    //Method
	
	    //Attribute
	        //Inconstant
	        QColor color_;
	        double cost_;
	};
}

#endif // COLORCOST_H
