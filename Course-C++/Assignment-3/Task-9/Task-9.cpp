/*9. Friend Function:Implement a friend function that compares the mileage of two Vehicle objects and returns the one with higher mileage.*/
#include <iostream>
using namespace std;


class Vehicle {
private:
    float mileage;
public:
    Vehicle(float m) : mileage(m) {}
    friend Vehicle compareMileage(const Vehicle &v1, const Vehicle &v2);


    void display() const {
        cout << "Mileage: " << mileage << " km/l" << endl;
    }
};
Vehicle compareMileage(const Vehicle &v1, const Vehicle &v2) {
    if (v1.mileage > v2.mileage) {
        return v1;
    } else {
        return v2;
    }
}
int main() {
    Vehicle car1(15.5);
    Vehicle car2(18.2);


    Vehicle betterMileageCar = compareMileage(car1, car2);
    cout << "The vehicle with higher mileage has: ";
    betterMileageCar.display();


    return 0;
}
