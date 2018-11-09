#ifndef OFFICE_H
#define OFFICE_H
#include<iostream>

using namespace std;

class Office
{
    public:
    Office();
    Office(float, float);
    int getLength();
    void setLength(float);
    void setWidth(float);
    int getWidth();
    float calculateOfficeArea();
    void setOfficeArea(float);
    float getOfficeArea();
    
    
    

    private:
    float officeArea;
    float length;
    float width;
   
};
#endif