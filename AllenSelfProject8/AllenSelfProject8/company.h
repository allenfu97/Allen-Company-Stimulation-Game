#ifndef COMPANY_H
#define COMPANY_H
#include "employee.h"
#include "office.h"
#include <iostream>
using namespace std;

class Company
{
    public:
    Company();
    void dataLoad();
    void login();
    void sortYearsWorked();
    void menu();
    void saveData();
    


    
    private:
    Employee employees[1000];//variables that will be used throughout in the methods
    Office offices[1000];
    int employeeNumbers;
    int officeNumbers;
    int employeeCurrent;
    int officeCurrent;
    
    
   
};
#endif
