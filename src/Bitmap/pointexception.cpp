/** Titre
 *      @project DiRIGe
 *      @class PointException
 *      @description : Classe permet de lever une exception si aucun point ou plusieurs
 *      point de départ ou de point d'arrivé sont détectés.
 *	@author Alex-Mehdi ZAHID
 */

#include "pointexception.h"

using namespace Bitmap;

//Builder
//{
    PointException::PointException() throw() : std::exception()
    {
    }
    PointException::PointException( const PointException& pointException ) throw(): std::exception()
    {
        typeOfPointException_ = pointException.typeOfPointException_;
    }
    PointException::PointException( int typeOfPointException ) throw(): std::exception()
    {
        typeOfPointException_ = typeOfPointException;
    }
//}

//Destroyer
//{
    PointException::~PointException() throw()
    {
    }
//{

//Operator
//{
    PointException&  PointException::operator=( const PointException& pointException )
    {
        if( this != &pointException )
        {
            typeOfPointException_ = pointException.typeOfPointException_;
        }
        return *this;
    }
//}

//Accessor
//{
    int PointException::getTypeOfException() const
    {
        return typeOfPointException_;
    }
//}
