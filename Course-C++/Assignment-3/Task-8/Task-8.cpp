/*8. Static Member: Add a static member in the Vehicle class to keep track of the number of Vehicle objects created. Implement a static method to return this count.*/
#include <iostream>
using namespace std;


class Vehicle {
private:
    static int vehicleCount;
public:
    Vehicle() {
        vehicleCount++;
            }
    static int getVehicleCount() {
        return vehicleCount;
    }
};
int Vehicle::vehicleCount = 0;


int main() {
    Vehicle v1;
    Vehicle v2;
    Vehicle v3;


    cout << "Number of Vehicle objects created: " << Vehicle::getVehicleCount() << endl;


    return 0;
}
