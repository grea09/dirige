/** Titre
 *      @project DiRIGe
 *      @class PointException
 *      @description : Classe permet de lever une exception si la destination n'est pas accessible.
 *	@author Alex-Mehdi ZAHID
 */
#ifndef NOPATHEXCEPTION_H
#define NOPATHEXCEPTION_H

#include <string>
#include <exception>
namespace Algorithm
{
	class NoPathException : public std::exception
	{
	    public:
	        //Builder
	        NoPathException() throw();
	        NoPathException( const NoPathException& noPathException ) throw();
	
	        //Destroyer
	        ~NoPathException() throw();
	
	        //Operator
	        NoPathException& operator=( const NoPathException& noPathException );
	
	        //Accessor
	        std::string getMessage();
	
	    private :
	        //Attribute
	            //Inconstant
	            std::string message;
	};
}

#endif // NOPATHEXCEPTION_H
