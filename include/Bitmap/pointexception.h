/** Titre
 *      @project DiRIGe
 *      @class PointException
 *      @description : Classe permet de lever une exception si aucun point ou plusieurs
 *      point de départ ou de point d'arrivé sont détectés.
 *	@author Alex-Mehdi ZAHID
 */

#ifndef POINTEXCEPTION_H
#define POINTEXCEPTION_H

#include <exception>
namespace Bitmap
{
	class PointException : public std::exception
	{
	    public :
	    //Builder
	    PointException() throw();
	    PointException( const PointException& pointException ) throw();
	    PointException( int typeOfPointException ) throw();
	    //Destroyer
	    ~PointException() throw();
	
	    //Operator
	    PointException& operator=( const PointException& pointException );
	
	    //Method
	        //Accesseur
	        int getTypeOfException() const;
	
	    private :
	    //Attribute
	        //Inconstant
	        int typeOfPointException_;
	};
}

#endif // POINTEXCEPTION_H
