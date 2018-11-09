#include "employee.h"
#include <iostream>
using namespace std;
Employee::Employee()
{
    name="";
    yearsWorked=0;
    salary=0.0;
}
Employee::Employee(string Newname, int newYearsworked )
{
    name=Newname;
    yearsWorked=newYearsworked;
    calculateSalary();
    
}
string Employee:: getName()
{
    return name;
}
void Employee::setName(string newName)
{
    name=newName;
}
void Employee:: setYearsWorked(int newYearsWorked)
{
    yearsWorked=newYearsWorked;
}
int Employee::getYearsWorked()
{
    return yearsWorked;
}
float Employee::calculateSalary()
{
    const int anualAmount=81400;
    const int chelseaYearlyTax=100;
    salary=(yearsWorked*anualAmount)-(yearsWorked*chelseaYearlyTax);

}
void Employee::setSalary(float newSalary )
{
    salary=newSalary;
}


float sortYearsWorked()
{
    
}
float Employee::getSalary()
{
    return salary;
}
void Employee::Jobposition()
{
    int userInput=0;
    cout<<"Please re-enter your years worked at the company see what positions you qualify for: "<<endl;
    cin>>userInput;
    if(userInput<2)
    {
        cout<<"You worked less than 2 years and can only be a part time employee in the company"<<endl;
        return;
        
    }
    if(userInput>=2)
    {
        bool b1=false;
        while(b1==false)
        {
            int newInput=0;
            cout<<"You worked for 2 yearsor more, you can be a full time employee"<<endl;
            cout<<"Here is a list of jobs position you can choose in the company"<<endl;
            cout<<"Enter 1 to get the position of Web developer"<<endl;
            cout<<"Enter 2 to get the position of Systems analyst"<<endl;
            cout<<"Enter 3 to get the position of Database Administrator"<<endl;
            cin>>newInput;
            
            if(newInput==1)
            {
                cout<<"Your role is now a Web developer"<<endl;
                b1=true;
            }
            else if(newInput==2)
            {
                cout<<"Your role is now a system analyst"<<endl;
                b1=true;
            }
            else if(newInput==3)
            {
                cout<<"Your role is now a Database Administrator"<<endl;
                b1=true;
            }
            else
            {
                b1=false;
            }
        
        }

        
    }
}
