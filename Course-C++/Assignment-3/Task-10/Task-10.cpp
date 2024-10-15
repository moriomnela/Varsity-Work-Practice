/*10. Driver Code: Write a main function to create instances of the Vehicle class and test all the features implemented. This should include creating
vehicles using different constructors, displaying their details, using getter and setter methods, comparing vehicles, driving vehicles with different
distances, comparing using the overloaded == operator, displaying the number of vehicles created, and comparing mileage using the friend function.*/
#include <iostream>
#include <string>


using namespace std;


class Vehicle {
private:
    string make;
    string model;
    int year;
    double mileage;
    static int vehicleCount;


public:
    Vehicle() : make("Unknown"), model("Unknown"), year(0), mileage(0.0) {
        vehicleCount++;
    }
    // Parameterized constructor
    Vehicle(string mk, string mdl, int yr, double mil){
        make=mk;
        model=mdl;
        year=yr;
        mileage=mil;
        vehicleCount++;
    }
    // Copy constructor
    Vehicle(Vehicle &v){
        make=v.make;
        model=v.model;
        year=v.year;
        mileage=v.mileage;
        vehicleCount++;
    }
    // Destructor
    ~Vehicle() {
        vehicleCount--;
    }


    // Getter methods
    string getMake(){ return make; }
    string getModel(){ return model; }
    int getYear(){ return year; }
    double getMileage(){ return mileage; }


    // Setter methods
    void setMake(string mk) { make = mk; }
    void setModel(string mdl) { model = mdl; }
    void setYear(int yr) { year = yr; }
    void setMileage(double mil) { mileage = mil; }


    // Method to display vehicle details
    void displayDetails() {
        cout << "Make: " << make << ", Model: " << model
             << ", Year: " << year << ", Mileage: " << mileage << " miles" << endl;
    }


    // Method to drive the vehicle and increase mileage
    void drive(double miles) {
        mileage += miles;
    }


    // Overloaded == operator for comparing two vehicles
    bool operator==(const Vehicle &v) const {
        return (make == v.make &&
                model == v.model &&
                year == v.year &&
                mileage == v.mileage);
    }
    // Static method to get the vehicle count
    static int getVehicleCount() {
        return vehicleCount;
    }


    // Friend function to compare mileage of two vehicles
    friend bool compareMileage(const Vehicle &v1, const Vehicle &v2);
};


// Initialize static member
int Vehicle::vehicleCount = 0;


// Friend function to compare mileage
bool compareMileage(const Vehicle &v1, const Vehicle &v2) {
    return v1.mileage > v2.mileage;
}
int main() {
    // Create instances using different constructors
    Vehicle v1;
    Vehicle v2("Toyota", "Camry", 2018, 25000);
    Vehicle v3("Honda", "Civic", 2020, 15000);
    Vehicle v4(v2);  // Copy constructor


    // Display details of the vehicles
    cout << "Vehicle Details:" << endl;
    v1.displayDetails();
    v2.displayDetails();
    v3.displayDetails();
    v4.displayDetails();


    // Use getter and setter methods
    v1.setMake("Ford");
    v1.setModel("Fusion");
    v1.setYear(2017);
    v1.setMileage(30000);
    cout << "\nUpdated v1 Details:" << endl;
    cout << "Make: " << v1.getMake() << ", Model: " << v1.getModel()
         << ", Year: " << v1.getYear() << ", Mileage: " << v1.getMileage() << " miles" << endl;


    // Drive vehicles and increase mileage
    v2.drive(500);
    v3.drive(1200);
    cout << "\nAfter Driving:" << endl;
    v2.displayDetails();
    v3.displayDetails();


    // Compare vehicles using overloaded == operator
    cout << "\nComparing Vehicles:" << endl;
    if (v2 == v4) {
        cout << "v2 and v4 are identical." << endl;
    } else {
        cout << "v2 and v4 are not identical." << endl;
    }
    if (v1 == v3) {
        cout << "v1 and v3 are identical." << endl;
    } else {
        cout << "v1 and v3 are not identical." << endl;
    }
    // Display the number of vehicles created
    cout << "\nTotal Vehicles Created: " << Vehicle::getVehicleCount() << endl;


    // Compare mileage using the friend function
    cout << "\nComparing Mileage:" << endl;
    if (compareMileage(v2, v3)) {
        cout << "v2 has more mileage than v3." << endl;
    } else {
        cout << "v3 has more mileage than v2." << endl;
    }


    return 0;
}
