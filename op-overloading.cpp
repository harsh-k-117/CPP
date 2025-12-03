#include<iostream>
using namespace std;

class Number{
public:

    int value;

    Number(int v = 0 ){
        value = v;
    }
    // classname operator operator_symbol (classname &obj){ parameters ad fucntion body  }

    Number operator + (const Number &obj){
        Number temp;
        temp.value = value + obj.value;
        return temp;
    }

    void display(){
        cout << "Value : "<< value<<endl;
    }
};

int main(){
    Number n1(10);
    Number n2(20);

    Number n3 = n1 + n2; // n1.operator+(n2);

    n3.display();

    return 0;

}
