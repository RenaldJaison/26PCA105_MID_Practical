#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;

    void getPersonDetails() {
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
    }
};

class Superhero : public Person {
public:
    string superpower;

    void getSuperheroDetails() {
        cout << "Enter superpower: ";
        getline(cin, superpower);
    }

    void displaySuperheroDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Superpower: " << superpower << endl;
    }
};

int main() {
    Superhero h;

    h.getPersonDetails();
    h.getSuperheroDetails();

    cout << "\nSuperhero Details:" << endl;
    h.displaySuperheroDetails();

    return 0;
}
