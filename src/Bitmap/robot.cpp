/** Titre
 *      @project DiRIGe
 *      @class Robot
 *      @description : Classe contient toute la configuration du robot
 *	@author Alex-Mehdi ZAHID
 */

#define DEFAULT_COST_HALF_TURN 500
#define DEFAUTLT_INITIAL_DIRECTION 90

#include "robot.h"
#include "libdevcpp.h"

using namespace Bitmap;

//Attribute
//{
    Robot* Robot::robotInstance_ = NULL;
//}

//Builder
//{
    Robot::Robot():costHalfTurn_(DEFAULT_COST_HALF_TURN), initialDirection_(DEFAUTLT_INITIAL_DIRECTION),width_(1)
    {
    }
    Robot::Robot( double costHalfTurn, double initialDirection, int width ,std::vector<ColorCost> palette ) : costHalfTurn_(costHalfTurn), initialDirection_(initialDirection), width_(width)
    {
         /*     90°
         135°    |     45°
                 |
      180° ------|------ 0 ou 360°
                 |
         -135°   |     -45°
                -90°
        Voilà pourquoi une transformation de l'angle initial est nécessaire, pour que l'angle à effectué soit <= 180
        */
        if( initialDirection > 180 )
        {
            initialDirection_ = -1*(360 - initialDirection);
        }
        
        palette_ = palette;
        
        for (unsigned int i = 0; i < palette.size(); i++)
		{
			debugV(palette[i].getCost());
			debugV(palette_[i].getCost());
		}
        
    }
    Robot* Robot::Instance()
    {
        if( robotInstance_ == NULL )
        {
            robotInstance_ = new Robot();
        }
        return robotInstance_;
    }
    Robot* Robot::Instance( double costHalfTurn, double initialDirection, int width, std::vector<ColorCost> palette )
    {
        if( robotInstance_ == NULL )
        {
            robotInstance_ = new Robot( costHalfTurn, initialDirection, width, palette );
        }
        return robotInstance_;
    }
//}

//Destroyer
//{
    Robot::~Robot()
    {
    }
   void Robot::delRobot()
   {
        if( robotInstance_ != NULL )
        {
            delete robotInstance_;
            robotInstance_ = NULL;
        }
   }
//{

//Accessor
//{
    double Robot::getCostHalfTurn() const
    {
        return costHalfTurn_;
    }
    double Robot::getInitialDirection() const
    {
        return initialDirection_;
    }
    std::vector<ColorCost> Robot::getColorCost() const
    {
        return palette_;
    }
    QColor Robot::getColor( int i )
    {
        return palette_[i].getColor();
    }
    double Robot::getCost( int i )
    {
        return palette_[i].getCost();
    }
    int Robot::getWidth()
    {
        return width_;
    }

//}

//Mutator
//{
    void Robot::setCostHalfTurn( double costHalfTurn )
    {
        costHalfTurn_ = costHalfTurn;
    }
    void Robot::setInitialDirection( double initialDirection )
    {
        initialDirection_ = initialDirection;
    }
    void Robot::setColorCost( std::vector<ColorCost> palette)
    {
        palette_ = palette;
    }
//}
