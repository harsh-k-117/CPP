#include<iostream>
#include<string>
using namespace std;

// ---------------------- Base Class: Vehicle ----------------------
class Vehicle {
protected:
    string Company, Model, FuelType;
    double Mileage, Price;

public:
    // ----------- Nested Class for Registration Details -----------
    class Registration {
    private:
        string RegNo, Owner, Date;

    public:
        void Input() {
            cout << "Enter Registration Number: ";
            cin >> RegNo;
            cout << "Enter Owner Name: ";
            cin >> Owner;
            cout << "Enter Registration Date (DD/MM/YYYY): ";
            cin >> Date;
        }

        void Display() {
            cout << "Registration Number: " << RegNo << endl;
            cout << "Owner: " << Owner << endl;
            cout << "Date of Registration: " << Date << endl;
        }
    } reg; // Object of Nested Class

    Vehicle() {
        cout << "Vehicle Constructor Called." << endl;
    } // Constructor

    virtual ~Vehicle() {
        cout << "Vehicle Destructor Called." << endl;
    } // Virtual Destructor

    void Input() {
        cout << "Enter Company Name: ";
        cin >> Company;
        cout << "Enter Model Name: ";
        cin >> Model;
        cout << "Enter Fuel Type: ";
        cin >> FuelType;
        cout << "Enter Mileage (km/l): ";
        cin >> Mileage;
        cout << "Enter Price: ";
        cin >> Price;
        reg.Input(); // Call Nested Class Function
    }

    void Display() {
        cout << "----- Vehicle Details -----" << endl;
        cout << "Company: " << Company << endl;
        cout << "Model: " << Model << endl;
        cout << "Fuel Type: " << FuelType << endl;
        cout << "Mileage: " << Mileage << " km/l" << endl;
        cout << "Price: $" << Price << endl;
        reg.Display();
    }

    friend class Service; // Friend Class Declaration
};

// ---------------------- Virtual Base Class: Engine ----------------------
class Engine : virtual public Vehicle {
protected:
    string EngineNo;
    int HorsePower;

public:
    Engine() {
        cout << "Engine Constructor Called." << endl;
    }

    ~Engine() {
        cout << "Engine Destructor Called." << endl;
    }

    void InputEngine() {
        cout << "Enter Engine Number: ";
        cin >> EngineNo;
        cout << "Enter Horsepower (HP): ";
        cin >> HorsePower;
    }

    void DisplayEngine() {
        cout << "Engine Number: " << EngineNo << endl;
        cout << "Horsepower: " << HorsePower << " HP" << endl;
    }
};

// ---------------------- Class: Battery ----------------------
class Battery {
protected:
    double Capacity;      // in kWh
    double ChargeTime;    // in hours

public:
    Battery() {
        cout << "Battery Constructor Called." << endl;
    }

    ~Battery() {
        cout << "Battery Destructor Called." << endl;
    }

    void InputBattery() {
        cout << "Enter Battery Capacity (kWh): ";
        cin >> Capacity;
        cout << "Enter Charging Time (hours): ";
        cin >> ChargeTime;
    }

    void DisplayBattery() {
        cout << "Battery Capacity: " << Capacity << " kWh" << endl;
        cout << "Charging Time: " << ChargeTime << " hours" << endl;
    }
};

// ---------------------- Derived Class: Car ----------------------
class Car : public Engine {
protected:
    int SeatingCapacity;
    string Transmission;

public:
    Car() {
        cout << "Car Constructor Called." << endl;
    }

    ~Car() {
        cout << "Car Destructor Called." << endl;
    }

    void InputCar() {
        Input();          // From Vehicle
        InputEngine();    // From Engine
        cout << "Enter Seating Capacity: ";
        cin >> SeatingCapacity;
        cout << "Enter Transmission Type (Manual/Automatic): ";
        cin >> Transmission;
    }

    void DisplayCar() {
        cout << "----- Car Details -----" << endl;
        Display();
        DisplayEngine();
        cout << "Seating Capacity: " << SeatingCapacity << endl;
        cout << "Transmission: " << Transmission << endl;
    }
};

// ---------------------- Multiple Inheritance: ElectricCar ----------------------
class ElectricCar : public Car, public Battery {
public:
    ElectricCar() {
        cout << "Electric Car Constructor Called." << endl;
    }

    ~ElectricCar() {
        cout << "Electric Car Destructor Called." << endl;
    }

    void InputElectricCar() {
        InputCar();       // From Car (Vehicle + Engine)
        InputBattery();   // From Battery
    }

    void DisplayElectricCar() {
        cout << "----- Electric Car Details -----" << endl;
        DisplayCar();
        DisplayBattery();
    }
};

// ---------------------- Friend Class: Service ----------------------
class Service {
public:
    void UpdateService(Vehicle &v) {
        cout << "\nService Update: Vehicle Model '" << v.Model << "' has been serviced successfully." << endl;
    }
};

// ---------------------- Main Function ----------------------
int main() {
    ElectricCar e;
    e.InputElectricCar();
    e.DisplayElectricCar();

    Service s;
    s.UpdateService(e);

    cout << "\nProgram Completed Successfully." << endl;
    return 0;
}


