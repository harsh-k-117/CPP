#include<iostream>
#include<string>    
using namespace std;

class Vehicle {
protected:

    string company, model, Fueltype;
    double mileage, price;

public:

    void Input(){
        cout << "Enter Vehicle Company: ";
        cin >> company;
        cout << "Enter Vehicle Model: ";
        cin >> model;
        cout << "Enter Vehicle Fuel Type: ";
        cin >> Fueltype;
        cout << "Enter Vehicle Mileage: ";
        cin >> mileage;
        cout << "Enter Vehicle Price: ";
        cin >> price;
    }

    void Display(){
        cout << "Vehicle Company: " << company << endl;
        cout << "Vehicle Model: " << model << endl;
        cout << "Vehicle Fuel Type: " << Fueltype << endl;
        cout << "Vehicle Mileage: " << mileage << " km/l" << endl;
        cout << "Vehicle Price: $" << price << endl;
    }
};

class Car : public Vehicle{
    
}
