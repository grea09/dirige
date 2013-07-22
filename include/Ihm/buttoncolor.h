#ifndef BUTTONCOLOR_H
#define BUTTONCOLOR_H

#include "libdevcpp.h"
#include <QtGui>
namespace Ihm
{
	class ButtonColor : public QToolButton
	{
	    Q_OBJECT
	
	public:
	    ButtonColor(QWidget *parent = 0);
	    ButtonColor(QColor color, QWidget *parent = 0);
	    //~ ~ButtonColor();
	
	    void setColor(QColor value);
	
	    //~ QColor& getColor();
	
	private:
	    //~ QColor* color_;
	};
}

#endif // BUTTONCOLOR_H
