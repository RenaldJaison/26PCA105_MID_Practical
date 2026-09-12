#include <iostream>
#include <string>
using namespace std;

class Payment
{
public:
    float amount;

    Payment(float a)
    {
        amount = a;
    }

    virtual void process()
    {
        cout << "Success";
    }
};

class CreditCard : public Payment
{
public:
    CreditCard(float a) : Payment(a) {}

    void process()
    {
        if (amount > 5000)
            cout << "Failed - Credit limit exceeded";
        else
            cout << "Success";
    }
};

class UPI : public Payment
{
public:
    UPI(float a) : Payment(a) {}

    void process()
    {
        if (amount > 100000)
            cout << "Failed - UPI limit exceeded";
        else
            cout << "Success :)";
    }
};

class Cash : public Payment
{
public:
    Cash(float a) : Payment(a) {}

    void process()
    {
        cout << "Success - Collected Rs." << amount + 10;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int choice, method, count = 0, failed = 0;
    float amount, credit = 0, upi = 0, cash = 0;

    string historyMethod[50];
    float historyAmount[50];
    string historyStatus[50];

    do
    {
        cout << "\n\n===== Payment Gateway =====";
        cout << "\n 1. New Payment";
        cout << "\n 2. History";
        cout << "\n 3. Totals";
        cout << "\n 4. Failed Count";
        cout << "\n 5. Exit";

        cout << "\nEnter choice :) ----->: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "\n 1-Credit Card ";
             cout << "\n 2-UPI ";
              cout << "\n 3-Cash :) -----> :";
            cin >> method;

            cout << "Amount: Rs.";
            cin >> amount;

            Payment *p;

            if(method == 1)
            {
                p = new CreditCard(amount);
                historyMethod[count] = "Credit Card";
            }
            else if(method == 2)
            {
                p = new UPI(amount);
                historyMethod[count] = "UPI";
            }
            else
            {
                p = new Cash(amount);
                historyMethod[count] = "Cash";
            }

            cout << "Status: ";
            p->process();

            historyAmount[count] = amount;

            if(method == 1 && amount <= 50000)
            {
                historyStatus[count] = "Success :)";
                credit += amount;
            }
            else if(method == 2 && amount <= 100000)
            {
                historyStatus[count] = "Success :)";
                upi += amount;
            }
            else if(method == 3)
            {
                historyStatus[count] = "Success :)";
                cash += amount + 10;
            }
            else
            {
                historyStatus[count] = "Failed :(";
                failed++;
            }

            count++;

            delete p;
            break;

        case 2:
            cout << "\n===== History =====";

            for(int i = 0; i < count; i++)
            {
                cout << "\n" << i + 1 << ". "
                     << historyMethod[i]
                     << " Rs." << historyAmount[i]
                     << " " << historyStatus[i];
            }

            break;

        case 3:
            cout << "\nCredit Card: Rs." << credit;
            cout << "\nUPI: Rs." << upi;
            cout << "\nCash: Rs." << cash;
            break;

        case 4:
            cout << "\nFailed Transactions: " << failed;
            break;

        case 5:
            cout << "\nExiting...";
            break;

        default:
            cout << "\nInvalid choice";
        }

    } while(choice != 5);

    return 0;
}
