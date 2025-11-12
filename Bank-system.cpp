#include<iostream>
#include<string>
using namespace std;

class BankAcc{
private:

    string Name, Address, AccType, IFSC, DOB;
    int AccNo, Balance;

public:

    BankAcc(){
        Balance = 0;
    } // Default Constructor

    BankAcc(string name, string addr, string acctype, string ifsc, string dob, int accno, int balance){
        Name = name;
        Address = addr;
        AccType = acctype;
        IFSC = ifsc;
        DOB = dob;
        AccNo = accno;
        Balance = balance;  
    }// Parameterized Constructor
    
    void CreateAcc(){
        cout<<"Enter Name: ";
        cin>>Name;
        cout<<"Enter Address: ";    
        cin>>Address;
        cout<<"Enter Account Type: ";
        cin>>AccType;
        cout<<"Enter IFSC Code: ";
        cin>>IFSC;
        cout<<"Enter Date of Birth (DD/MM/YYYY): ";
        cin>>DOB;
        cout<<"Enter Account Number: "; 
        cin>>AccNo;
        cout<<"Enter Initial Balance: ";
        cin>>Balance;   
    } // Function to create account by taking user input

    void Deposit(){
        int amount;
        cout<<"Enter amount to deposit: ";
        cin>>amount;
        Balance += amount;
        cout<<"Amount deposited successfully. New Balance: "<<Balance<<endl;
    } // Function to deposit money

    void Withdraw(){
        int amount;
        cout<<"Enter amount to withdraw: ";
        cin>>amount;
        if(amount <= Balance){
            Balance -= amount;
            cout<<"Amount withdrawn successfully. New Balance: "<<Balance<<endl;
        } 
        else {
            cout<<"Insufficient balance!"<<endl;
        }
    }

    void Display(){
        cout<<"-----Account Details-----"<<endl;
        cout<<"Account Holder Name: "<<Name<<endl;
        cout<<"Address: "<<Address<<endl;
        cout<<"Account Type: "<<AccType<<endl;
        cout<<"IFSC Code: "<<IFSC<<endl;
        cout<<"Date of Birth: "<<DOB<<endl;
        cout<<"Account Number: "<<AccNo<<endl;
        cout<<"Current Balance: "<<Balance<<endl;
    }

    ~BankAcc(){
        cout<<"Account closed for : "<<Name<<endl;
    }   // Destructor
};

int main(){
    BankAcc acc1;
    acc1.CreateAcc();
    int choice;
    do{
        cout<<"1.Deposit"<<endl;
        cout<<"2.Withdraw"<<endl;
        cout<<"3.Display Account Details"<<endl;  
        cout<<"4.Exit"<<endl;
        cout<<"Choose an option: ";
        cin>>choice;

        switch(choice){
            case 1: acc1.Deposit();
                    break;
            case 2: acc1.Withdraw();
                    break;
            case 3: acc1.Display();
                    break;      
            case 4: cout<<"Exiting..."<<endl;
                    break;
            default: cout<<"Invalid choice! Please try again."<<endl;
        }
    }
    while(choice != 4);

    return 0;
}