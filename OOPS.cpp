#include <iostream>
#include <string>
using namespace std;

class Teacher{
    // Attributes or properties

private:
    float salary;

public:

    string name;
    string dept;
    string subject;
    

    // Methods or behaviors or member functions
    void ChangeDept(string newdept){
        dept = newdept;
    }

    // Setter for salary
    void setSalary(float s){
        salary = s;
    }

    // Getter for salary
    float getSalary(){
        return salary;
    }

};

int main(){
    // Create an object of Teacher class
    Teacher t1;
    t1.name = "Mr. Kulkarni";
    t1.dept = "Computer Science";
    t1.subject = "Data Structures";

    cout << "Teacher Name: " << t1.name << endl;
    cout << "Department: " << t1.dept << endl;
    cout << "Subject: " << t1.subject << endl;  

    t1.ChangeDept("Information Technology");
    cout << "After Department Change: " << t1.dept << endl; 

    t1.setSalary(60000);
    cout << "Salary: " << t1.getSalary() << endl;   

    return 0;
}