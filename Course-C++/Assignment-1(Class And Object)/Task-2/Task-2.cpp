#include <iostream>
#include <string>


class Car {
private:
    std::string make;
    std::string model;
    int year;
    float price;


public:


    Car(std::string make, std::string model, int year, float price) {
        this->make = make;
        this->model = model;
        this->year = year;
        this->price = price;
    }


    void displayInformation() {
        std::cout << "Make: " << make << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }




    void applyDepreciation(float depreciation) {
        price -= price * (depreciation / 100);
    }




    bool isAntique(int currentYear) {
        return (currentYear - year) > 25;
    }
};


int main() {


    Car car1("Ford", "Model T", 1908,825);
    Car car2("Chevrolet", "Bel Air", 1950, 1741);
    Car car3("Rolls-Royce", "Silver Ghost", 1906,5400);


    std::cout << "Car 1 Information:" << std::endl;
    car1.displayInformation();
    std::cout << std::endl;


    std::cout << "Car 2 Information:" << std::endl;
    car2.displayInformation();
    std::cout << std::endl;


    std::cout << "Car 3 Information:" << std::endl;
    car3.displayInformation();
    std::cout << std::endl;




    car1.applyDepreciation(10); // 10% depreciation
    car2.applyDepreciation(15); // 15% depreciation
    car3.applyDepreciation(20); // 20% depreciation




    std::cout << "Car 1 Information after Depreciation:" << std::endl;
    car1.displayInformation();
    std::cout << std::endl;


    std::cout << "Car 2 Information after Depreciation:" << std::endl;
    car2.displayInformation();
    std::cout << std::endl;


    std::cout << "Car 3 Information after Depreciation:" << std::endl;
    car3.displayInformation();
    std::cout << std::endl;


    int currentYear = 2024;
    std::cout << "Is Car 1 Antique? " << (car1.isAntique(currentYear) ? "Yes" : "No") << std::endl;
    std::cout << "Is Car 2 Antique? " << (car2.isAntique(currentYear) ? "Yes" : "No") << std::endl;
    std::cout << "Is Car 3 Antique? " << (car3.isAntique(currentYear) ? "Yes" : "No") << std::endl;


    return 0;
}


