#include <iostream>
#include <string>

using namespace std;

//GLOBAL VARIABLES
int money =0;
string pin, name;

int menu()
{
    int choice = -1;
    do
    {
    cout <<"\nEnter your choice:\n";
    cout<<"1) Check account\n";
    cout<<"2) Withdraw\n";
    cout<<"3) Deposit\n";
    cout<<"4) Quit\n\n";
    cin>>choice;

         if(choice > 4 || choice < 1)
         {
             //keep the loop
             choice = -1;
         }
    }
    while(choice == -1);

    return choice;
}

void account()
{
    cout<<"\nAccount Information\n";
    cout<<"Name: " + name + "\n";
    cout<<"Private Pin: " + pin + "\n";
    cout<<"Currency: $"<<money<<endl;

    cout<<"------------------------\n";
}


int user_input()
{
    cout<<"ATM\n";
    cout<<"------------------------\n";

    cout<<"Enter your Name: ";
    getline(cin,name);
    do
    {
    cout<<"Enter your 6 digit pin: ";
    cin>>pin;
    }
    while(pin.length() > 6 || pin.length()!= 6);

    int choice = menu();

}
void withdraw_money()
{
    int withdraw;
    cout<<"Enter the value you want to withdraw: ";
    cin>>withdraw;
    if(withdraw>money)
    {
        cout<<"\nYou don't have enough money to withdraw\n";
        cout<<"Please try to deposit some money\n";
    }
    else
    {
    money -=withdraw;
    cout<<withdraw<<"$ was withdrawn succesfully\n";
    cout<<endl<<"Your balance now is: $"<<money<<endl;
    }
    cout<<"------------------------\n";
}

void deposit_money()
{
    int deposit;
    cout<<"Enter the value you want to deposit: ";
    cin>>deposit;
    money +=deposit;
    cout<<endl<<"Your balance now is: $"<<money<<endl;
    cout<<"------------------------\n";
}


void ATM_System()
{
    int choice = user_input();

    while(true)
    {
        if (choice == 1)
            account();
        else if (choice == 2)
            withdraw_money();
        else if (choice == 3)
            deposit_money();
        else
            break;


        choice = menu();
    }
}

int main()
{
    ATM_System();

   return 0;
}

