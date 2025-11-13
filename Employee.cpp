#include<iostream>
#include<string>
using namespace std;

class Employee {
protected:
    string Name;
    int EmpID;

public:

    Employee() {
        Name = "Unknown";
        EmpID = 0;
    } // Default Constructor

    Employee(string name, int id) {
        Name = name;
        EmpID = id;
    } // Parameterized Constructor

    virtual void Display() = 0; // Pure Virtual Function

    virtual ~Employee() {
        cout << "Destructor called for Employee: " << Name << endl;
    } // Virtual Destructor
};

class FullTimeEmployee : public Employee {
private:
    double MonthlySalary;

public:
    FullTimeEmployee() : Employee() {
        MonthlySalary = 0.0;
    }

    FullTimeEmployee(string name, int id, double salary) : Employee(name, id) {
        MonthlySalary = salary;
    }

    void Display() override {
        cout << "----- Full-Time Employee -----" << endl;
        cout << "Name: " << Name << endl;
        cout << "Employee ID: " << EmpID << endl;
        cout << "Monthly Salary: $" << MonthlySalary << endl;
    }

    ~FullTimeEmployee() {
        cout << "Destructor called for Full-Time Employee: " << Name << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    double HourlyRate;
    int HoursWorked;

public:
    PartTimeEmployee() : Employee() {
        HourlyRate = 0.0;
        HoursWorked = 0;
    }

    PartTimeEmployee(string name, int id, double rate, int hours) : Employee(name, id) {
        HourlyRate = rate;
        HoursWorked = hours;
    }

    void Display() override {
        cout << "----- Part-Time Employee -----" << endl;
        cout << "Name: " << Name << endl;
        cout << "Employee ID: " << EmpID << endl;
        cout << "Hourly Rate: $" << HourlyRate << endl;
        cout << "Hours Worked: " << HoursWorked << endl;
        cout << "Total Pay: $" << HourlyRate * HoursWorked << endl;
    }

    ~PartTimeEmployee() {
        cout << "Destructor called for Part-Time Employee: " << Name << endl;
    }
};

class Intern : public Employee {
private:
    double Stipend;
    int Duration; // in months

public:
    Intern() : Employee() {
        Stipend = 0.0;
        Duration = 0;
    }

    Intern(string name, int id, double stipend, int duration) : Employee(name, id) {
        Stipend = stipend;
        Duration = duration;
    }

    void Display() override {
        cout << "----- Intern -----" << endl;
        cout << "Name: " << Name << endl;
        cout << "Employee ID: " << EmpID << endl;
        cout << "Stipend: $" << Stipend << endl;
        cout << "Duration: " << Duration << " months" << endl;
    }

    ~Intern() {
        cout << "Destructor called for Intern: " << Name << endl;
    }
};

int main() {
    Employee* emp[3];

    emp[0] = new FullTimeEmployee("Alice", 101, 50000);
    emp[1] = new PartTimeEmployee("Bob", 102, 25, 100);
    emp[2] = new Intern("Charlie", 103, 3000, 6);

    int choice;
    do {
        cout << "\n1. Display All Employees" << endl;
        cout << "2. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < 3; i++) {
                    emp[i]->Display();
                }
                break;

            case 2:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 2);

    for (int i = 0; i < 3; i++) {
        delete emp[i];
    }

    return 0;
}
