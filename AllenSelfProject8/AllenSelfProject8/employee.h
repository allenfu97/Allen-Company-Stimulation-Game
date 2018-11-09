#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>

using namespace std;

class Employee
{
   public:
    Employee();
    Employee(string, int);
    string getName();
    void setName(string);
    void setYearsWorked(int);
    int getYearsWorked();
    void setSalary(float);
    float sortYearsWorked();
    float getSalary();
    float calculateSalary();
    void Jobposition();

    private:
    string name;
    int yearsWorked;
    float salary;
   
};
#endif