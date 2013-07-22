/** Titre
 *      @project DiRIGe
 *      @class Palette
 *      @description : Classe associe à une couleur un coût de traversé propre au robot.
 *	@author Alex-Mehdi ZAHID
 */

#include "colorcost.h"

using namespace Bitmap;

//Builder
//{
    ColorCost::ColorCost() : color_(Qt::white), cost_(0)
    {
    }
    ColorCost::ColorCost( QColor color, double cost) : color_(color.rgb()), cost_(cost)
    {
    }
//}

//Destroyer
//{
    ColorCost::~ColorCost()
    {
    }
//{

//Accessor
//{
    QColor ColorCost::getColor()
    {
        return color_;
    }
    double ColorCost::getCost()
    {
        return cost_;
    }
//}

//Mutator
//{
    void ColorCost::setColor( QColor color )
    {
        color_ = color;
    }
    void ColorCost::setCost( double cost )
    {
        cost_ = cost;
    }
//}
