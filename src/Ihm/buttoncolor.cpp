#include "buttoncolor.h"

using namespace Ihm;

ButtonColor::ButtonColor(QWidget *parent) : QToolButton(parent)
{
	debugsub(ENTER);
    //~ color_ = NULL;
    debugsub(EXIT_SUCCESS);
}

ButtonColor::ButtonColor(QColor color, QWidget *parent) 
	: QToolButton(parent)
{
	debugsub(ENTER);
	//~ color_ = NULL;
	setColor(color);
	debugsub(EXIT_SUCCESS);
}

//~ ButtonColor::~ButtonColor()
//~ {
	//~ debugsub(ENTER);
    //~ delete color_;
    //~ debugsub(EXIT_SUCCESS);
//~ }

void ButtonColor::setColor(QColor value)
{
	debugsub(ENTER);
    setStyleSheet("* { background-color: rgb("+QString::number(value.red())+","+QString::number(value.green())+","+QString::number(value.blue())+") }");
    debugsub(EXIT_SUCCESS);
}

//~ QColor& ButtonColor::getColor()
//~ {
	//~ debugsub(ENTER);
    //~ return *color_;
    //~ debugsub(EXIT_SUCCESS);
//~ }
