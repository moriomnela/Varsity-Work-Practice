/*5. This Pointer: Extend the Vehicle class to include a member function named compare that uses this pointer to compare two Vehicle objects and prints if they are similar or
not (two Vehicle objects are considered similar if their id, brand, model, year, and mileage are the same).*/
#include <iostream>
#include <string>
using namespace std;
class Vehicle {
private:
    int id;
    string brand;
    string model;
    int year;
    double mileage;
public:
    Vehicle(int id, string brand, string model, int year, double mileage) {
              this->id = id;
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->mileage = mileage;
    }
    void compare(const Vehicle& other) {
        if (this->id == other.id &&
            this->brand == other.brand &&
            this->model == other.model &&
            this->year == other.year &&
            this->mileage == other.mileage) {
            cout << "The vehicles are similar." << endl;
        } else {
            cout << "The vehicles are not similar." << endl;
        }
    }
    void printDetails() {
        cout << "ID: " << id
             << ", Brand: " << brand
             << ", Model: " << model
             << ", Year: " << year
             << ", Mileage: " << mileage << endl;
    }
};
int main() {
    Vehicle vehicle1(1, "BMW", "M4", 2022, 15000.0);
    Vehicle vehicle2(1, "BMW", "M4", 2022, 15000.0);
    Vehicle vehicle3(2, "Honda", "Accord", 2019, 20000.0);
//    Vehicle 1.compare(vehicle2);
    vehicle1.compare(vehicle3);
    return 0;
}
