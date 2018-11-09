#include "office.h"
#include <iostream>
using namespace std;
Office::Office()
{
    length=0;
    width=0;
    calculateOfficeArea();
}
Office::Office(float newLength , float newWidth)
{
    length=newLength;
    width=newWidth;
    calculateOfficeArea();
}
float Office::calculateOfficeArea()
{
    
    officeArea=length*width;
    return officeArea;

}
int Office::getLength()
{
    return length;
}
void Office::setLength(float newLength)
{
    length=newLength;
}
void Office::setWidth(float newWidth)
{
    width=newWidth;
}
int Office::getWidth()
{
    return width;
}
void Office::setOfficeArea(float newOfficeArea)
{
    officeArea=newOfficeArea;
}
float Office:: getOfficeArea()
{
    return officeArea;
}