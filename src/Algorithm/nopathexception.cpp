#include "nopathexception.h"

using namespace Algorithm;

//Builder
//{
NoPathException::NoPathException() throw() : std::exception()
{
    message = "Impossible d'atteindre la destination";
}
NoPathException::NoPathException( const NoPathException& noPathException ) throw() : std::exception()
{
    message = noPathException.message;
}
//}

//Destroyer
//{
NoPathException::~NoPathException() throw()
{
}
//}

//Operator
//{
NoPathException& NoPathException::operator=( const NoPathException& noPathException )
{
    if( this != &noPathException )
    {
        message = noPathException.message;
    }
    return *this;
}
//}

//
//Accessor
//{
std::string NoPathException::getMessage()
{
    return message;
}
//}
