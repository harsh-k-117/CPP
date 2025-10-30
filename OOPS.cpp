#include <iostream>
#include <string>
using namespace std;

class Teacher{    //Encapsulation
    // Attributes or properties

private:       //data hiding
    float salary;

public:
    string name;
    string dept;
    string subject;

    /*Teacher(){    // non parameterized constructor
        cout << "Teacher Object Created" << endl;
    }
    */ 

    Teacher(Teacher &orgObj){  // Copy Constructor
        cout<<"Copy Constructor Called" << endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;   
        this->subject = orgObj.subject; 
    }

    Teacher(string name, string dept, string subject){   // parameterized constructor
        this->name = name;
        this->dept = dept;
        this->subject = subject;
    }

    // Methods or behaviors or member functions
    void ChangeDept(string newdept){
        dept = newdept;
    }
/*
    // Setter for salary
    void setSalary(float s){
        salary = s;
    }

    // Getter for salary
    float getSalary(){
        return salary;
    }
*/
    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;

    }
};

int main(){
    // Create an object of Teacher class
    Teacher t1("Mr. Kulkarni", "Computer Science", "Data Structures"); //parameterized constructor called
/*
    cout << "Teacher Name: " << t1.name << endl;
    cout << "Department: " << t1.dept << endl;
    cout << "Subject: " << t1.subject << endl;  

    t1.ChangeDept("Information Technology");
    cout << "After Department Change: " << t1.dept << endl; 

    t1.setSalary(60000);
    cout << "Salary: " << t1.getSalary() << endl;   
*/
    //t1.getInfo();

    Teacher t2(t1); // Copy constructor called
    t2.getInfo();

    return 0;
}