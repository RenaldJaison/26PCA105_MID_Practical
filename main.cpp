#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string> customers;
    string name;

    cout << "Enter customer name: ";
    getline(cin, name);
    customers.push(name);

    cout << "Enter another customer name: ";
    getline(cin, name);
    customers.push(name);

    cout << "\nCustomers in queue:\n";

    queue<string> temp = customers;

    while (!temp.empty())
    {
        cout << temp.front() << endl;
        temp.pop();
    }

    if (!customers.empty())
    {
        cout << "\nTaxi assigned to: " << customers.front() << endl;
        customers.pop();
    }

    cout << "\nRemaining customers:\n";

    while (!customers.empty())
    {
        cout << customers.front() << endl;
        customers.pop();
    }

    if (customers.empty())
        cout << "Queue is empty." << endl;

    return 0;
}
