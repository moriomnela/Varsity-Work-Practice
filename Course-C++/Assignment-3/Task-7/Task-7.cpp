/*7. Operator Overloading:Overload the == operator to allow comparison between two Vehicle objects to check if they are equal
(i.e., have the same brand, model, year,and mileage).*/
#include <iostream>
#include <string>
using namespace std;


class Vehicle {
private:
    string brand;
    string model;
    int year;
    double mileage;


public:
    Vehicle(string b, string m, int y, double mi){
        brand=b;
        model=m;
        year=y;
        mileage=mi;
    }
    bool operator==(const Vehicle& other) {
        return (brand == other.brand &&
                model == other.model &&
                year == other.year &&
                mileage == other.mileage);
    }
    void display() {
        cout << "Brand: " << brand << ", Model: " << model
             << ", Year: " << year << ", Mileage: " << mileage << endl;
    }
};
int main() {
    Vehicle v1("BMW", "M4", 2022, 15000.0);
    Vehicle v2("BMW", "M4", 2022, 15000.0);
    Vehicle v3("Toyota", "Camry", 2020, 15000);


    v1.display();
    v2.display();
    v3.display();


    if (v1 == v2) {
        cout << "v1 and v2 are the same." << endl;
    } else {
        cout << "v1 and v2 are different." << endl;
    }


    if (v1 == v3) {
        cout << "v1 and v3 are the same." << endl;
    } else {
        cout << "v1 and v3 are different." << endl;
    }


    return 0;
}
