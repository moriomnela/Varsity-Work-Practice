/*6. Function Overloading:Implement overloaded functions named drive in the Vehicle class that take either an integer or a double
parameter to simulate driving the vehicle by different distances.*/
#include <iostream>
using namespace std;
class Vehicle {
public:
    void drive(int distance) {
        cout << "Driving " << distance << " kilometers using integer distance." << endl;
    }
    void drive(double distance) {
        cout << "Driving " << distance << " kilometers using double distance." << endl;
    }
};
int main() {
    Vehicle car;
    car.drive(100);
    car.drive(150.5);
    return 0;
}
