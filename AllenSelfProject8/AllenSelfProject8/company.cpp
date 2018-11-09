// CS1300 Spring 2018
// Allen Fu:
// Recitation: 204 – Favorite TA: Chelsea Chandler
// Cloud9 Workspace Editor Link: https://ide.c9.io/AllenFu
// Homework8 Project Company cpp and use this as a driver to run whole program
#include "company.h"
#include <iostream>
#include <fstream>
#include "employee.cpp"
#include "office.cpp"
#include <math.h>
using namespace std;
//constructor- Intialize bookNumbers and userNumbers to 0
Company::Company()//call library class and intialize to 0
{
   employeeNumbers=0;
   officeNumbers=0;

}
void Company::sortYearsWorked()
{
    bool b1=false;
    int comparison=0;
    int swaps=0;
    int num= employeeNumbers -1; 
    while(b1==false)
    {
        b1=true;//array sorted
        Employee tempv;
        
        for(int i=0;i<num;i++)
        {
            if(employees[i].getYearsWorked()>employees[i+1].getYearsWorked())
            {
                temp=employees[i];//store array[i] in temp
                
                employees[i]=employees[i+1];//swap
                
                employees[i+1]=temp; //sign bigger value to i+1 index
                b1=false;
                swaps++;
                
                
                // string tempName=employees[i].getname;
                // empoyees[i].setnNme(emp[i+1].getname);
            }
            comparison++;
        }
        num--;
    }
    for(int j=0;j<employeeNumbers;j++)
    {
        cout<<employees[j].getName()<<"----"<<employees[j].getYearsWorked()<<" years of work experience at the company"<<endl;
    }
    cout<<endl;
      
    cout<<"Number of comparisons: "<<comparison<<endl;
    cout<<"Number of swaps: "<<swaps<<endl;
        
}
void Company::saveData()
{
    ofstream outfile;
    outfile.open("newEmployees.txt",ios::app);
    if(outfile.fail())
    {
      return;
    }
    int count=0;
     
        for(int j=0;j<employeeNumbers;j++)
        {
            outfile<<"Employees: "<<employees[j].getName()<<"Salary: "<<employees[j].getSalary()<<endl;
            count++;
        }
        outfile<<endl;
}
//created a helper function that takes a string input and lowers the string and returns a string back. I will call it later in other methods
string toLower(string input)
{
    string lower="";
    char l;
    for(int i=0;i<input.length();i++)
    {
        if (input[i]>='a'&&input[i]<='z'||input[i]>='A'&&input[i]<='Z')
        {
            input[i]=tolower(input[i]);
        }
    }
     return input;
}
//Created helper function split which will be used in dataLoad function to split each word and fill the array
int Split(string str, char sepChar, string words[], int max)
{
    int count=0;

    string substring="";
    if(str=="")
    {
        return 0;
    }
    str=str+sepChar;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==sepChar)
        {
            substring=str.substr(0,i);
            str.erase(0,i+1);
            i = 0;
            if (count == max) return count;
            words[count]=substring;
            count++;
        }
    }
    return count;
}

//1. Load Employees and Office data from text files
void Company::dataLoad()
{
    ifstream employee2;
    ifstream office2;
    employee2.open("employees.txt");
    office2.open("offices.txt");
    //string bookTemp[2];
    string userTemp[2];//size is 2 since there is 2 columns in the write up
    if(employee2.fail())
    {
        cout<<"File failed to open"<<endl;
        return;
    }
    if(office2.fail())
    {
        cout<<"File failed to open"<<endl;
        return;
    }
    string line="";
    string lowerLine="";
    while(getline(employee2,line))
    {
        //line=toLower(line);
        //cout << line <<endl;
        string employeeTemp[2]={"",""};
        Split(line, ',', employeeTemp, 2);
        string employeeName; 
        int yearsWorked;
        yearsWorked=stoi(employeeTemp[1]);//lower it to lower case letter 
        employeeName = toLower(employeeTemp[0]);
        //yearsWorked = yearsWorked.substr(0,yearsWorked.length() - 1);//get rid of new line
        Employee newEmployee=Employee(employeeName,yearsWorked);//created a new object called newEmployee call constructor
        employees[employeeNumbers]=newEmployee;//assign the object which contains the two string and assign the object to book array which can only store book object.
        employeeNumbers++;//increment count
    }
    
    for(int i=0;i<employeeNumbers;i++){
        
        cout<<employees[i].getName()<<":-------Salary:"<<employees[i].getSalary()<<endl;

    }
    
    while(getline(office2,line))//now red from ratings and put into line
    {
        toLower(line);//lower the whole line
        string officeTemp[2];
        Split(line, ',', officeTemp, 2);
        float length, width;
        length=stof(officeTemp[0]);//lower it to lower case letter 
        width =stof(officeTemp[1]);
        // = stoi.substr(0,width.length() - 1);
        Office newOffice=Office(length,width);//created a new object called newOffice
        offices[officeNumbers]=newOffice;//assign it to the array of objects
        officeNumbers++;//increment


    }
    cout << "Employee Data Loaded successfully!" <<endl;
    //cin
    //name=user[i].getName
    //user[i].getName
    for(int i=0;i<officeNumbers;i++){
        
        cout<<employees[i].getName()<<":-------Size of office:"<<offices[i].getOfficeArea()<<endl;

    }
    cout << "Employee Office Areea Data Loaded successfully!" <<endl;
}
void Company::login()
{
    string name="";
    cout<<"Welcome to the Company, What is your name?:"<<endl;
    getline(cin,name);
    if(name=="")
    {
    
        cout<<"You provided an empty user name, Please provide a valid user name to login or register to the Company: "<<endl;
        cout<<"Enter your name again:"<<endl;
        getline(cin,name);
    }
    bool b1=false;
    string original = name;
    name = toLower(name);
    for(int i=0;i<employeeNumbers;i++)
    {
        if(name==employees[i].getName())
        {

            b1=true;
            employeeCurrent=i;//get the index
            cout<<"Welcome back to the company " <<name<<"-----your total salary from the years worked is: "<<employees[employeeCurrent].getSalary()<<endl;
            break;

        }
    
    }
    if(b1==false)
    {
        int years;
        cout<<"Please input the amount of years worked"<<endl;
        cin>>years;
        Employee newEmployee(name, years);
        employees[employeeNumbers]=newEmployee;
        employeeNumbers++;
        cout<<"Welcome to the Company, "<<original<<endl;

    }
    if(b1==true){// if b1 is true then the user is found and exisits in the user array
        //cout<<"Welcome back, "<<original<<endl;
        
    }
}
void Company::menu()
{
    string userInput="u";
    // cout<<"Would you like to (v)iew your work experience rankings in the company, (g)et office room, (r)equest job position , or (q)uit?:"<<endl;
    // cin>>userInput;
    
    while(userInput!="q")
    {
//         //Algorithim Description for if user enter v
//         //if b1==false then it is a new user since it is not in the user array and I cout the message.
         //else I cout the title, and ratings if the rating is not a 0
         cout<<"Would you like to (v)iew your work experience rankings in the company, (g)et office room, (r)equest job position , or (q)uit?:"<<endl;
        cin>>userInput;
        if(userInput=="v"||userInput=="V")
        {
            sortYearsWorked();
            
            
        }
        else if(userInput=="g"||userInput=="g")
        {
            float currentArea=offices[officeCurrent].calculateOfficeArea();
            cout<<"Dear employee, your current office size is: "<<currentArea<<endl;
            cout<<"As workers, you get to draw a random number from 1 to 6 and multiply it to your current office size to get your new office size!!!"<<endl;
            int randomNum=rand() %6;
            cout<<"The lucky number you draw is: "<<randomNum<<endl;
            cout<<"Your total office size after multiplying your office size by the lucky number your drew is: "<<randomNum*currentArea<<endl;
            
        }
        
        else if(userInput=="r"||userInput=="R")
        {
            employees[employeeCurrent].Jobposition();
        }
        else if(userInput=="q"||userInput=="Q")
        {
            //saveData();//call it to save the data and write to a newEmployees file
            saveData();
            cout << "Data successfully saved. Goodbye!" << endl;
          
        }
    }
}




int main()
{
    srand (time(NULL));//must seed it once so that random generator will provide different random numbers
    cout << "Welcome to Chandler Company!" << endl;
    Company myCompany;//created a object myLibrary from library class and call Librarary function
    myCompany.dataLoad();// call dataLoad()
    //myCompany.sortYearsWorked();
    myCompany.login();
    //myCompany.sortYearsWorked();

    myCompany.menu();



    //return 0;
}


