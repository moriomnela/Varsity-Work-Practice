/*4. Destructor: Implement a destructor in the Vehicle class that prints a message when a Vehicle object is destroyed.*/
#include <iostream>
using namespace std;
int count = 0;
class Vehicle {
    string name;
public:
    Vehicle(const string& vehicleName) : name(vehicleName) {
        count++;
        cout << "Vehicle: " << name << " created." << endl;
    }
    ~Vehicle() {
        count--;
        cout << "Vehicle: " << name << " destroyed." << endl;
    }
};
int main() {
    Vehicle car("Toyota");
    return 0;
}
