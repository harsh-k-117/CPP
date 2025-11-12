#include <iostream>
#include <string>
using namespace std;

class Product{
private:

    static int count;
    string ID, name;
    double price, quantity;

public:

    Product(){
        ID = "0000";
        name = "Unnamed";
        price = 0.0;
        quantity = 0.0;
        count++;
    }

    Product(string id, string n, double p, double qty){
        ID = id;
        name = n;
        price = p;
        quantity = qty;
        count++;
    }

    void Input(){
        cout << "Enter Product ID: ";
        cin >> ID;
        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Product Price: ";
        cin >> price;
        cout << "Enter Product Quantity: ";
        cin >> quantity;
    }

    void Display(){
        cout << "Product ID: " << ID << endl;
        cout << "Product Name: " << name << endl;
        cout << "Product Price: " << price << endl;
        cout << "Product Quantity: " << quantity << endl;
    }

    static void Showcount(){
        cout << "Total Products: " << count << endl;
    }

    friend void Compare(Product p1, Product p2);

};

int Product::count = 0;

void Compare(Product p1, Product p2){
    if(p1.price > p2.price){
        cout<<p1.name<<" is costlier than "<<p2.name<<endl;   
    }
    else if(p1.price < p2.price){
        cout<<p2.name<<" is costlier than "<<p1.name<<endl;
    }
    else{
        cout<<p1.name<<" and "<<p2.name<<" have the same price."<<endl;
    }
}

int main(){
    Product p1;
    Product p2;
    p1.Input();
    p2.Input();
    p1.Display();
    p2.Display();

    Product::Showcount();
    Compare(p1, p2);

    return 0;
}

