#include <iostream>
using namespace std;
class bankaccount
{
    /*private:
        string name;
        string number;
        int balance ;
    */
private:
    string name;
    string number;
    int balance;

public:
    bankaccount(string n, string ps)
    {
        n = name;
        ps = number;
        balance = 0;
    }

    void deposit(int give) { balance += give; }
    void withdraw(int take) { balance -= take; }

    int getBalance() { return balance; }

};

/*void pcc(bankaccount& account )
{

}*/
int main()
{
    string n, pas;
    cout << "Entre name of your account " << endl;
    cin >> n;
    cout << "Entre password of your account" << endl;
    cin >> pas;
    bankaccount account(n, pas);

      int choice, take, give;

    bool T = 1 ; 

while (T){
        cout << "select (1) if you want to withdraw" << endl
         << "select (2) if you want to deposit" << endl
         << "select (3) to show balance" << endl ; 
    cin >> choice;
    if (choice == 1)
    {
        cout << "withdrawal amount = " << endl;
        cin >> take;
        account.withdraw(take);
        cout << "your balance now is = " << account.getBalance() << endl ;
    }
    else if (choice == 2)
    {
        cout << "deposit amount = " << endl;
        cin >> give;
        account.deposit(give);
        cout << "your balance now is = " << account.getBalance() << endl ;
    }
    else
    {
        cout << "your balance now is = " << account.getBalance() << endl ;
    }
            cout << "select (1) to backe to the first page" << endl 
            << "select (0) if you  ";
        cin >> T ; 

}
    return 0;
}