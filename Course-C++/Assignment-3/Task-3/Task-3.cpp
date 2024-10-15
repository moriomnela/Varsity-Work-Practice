/*3. Copy Constructor:
Implement a copy constructor in the Vehicle class that initializes a new Vehicle object using the values of an existing Vehicle object.*/
#include<iostream>
#include<conio.h>
using namespace std;
    class Vehicle{
        string brand;
        string model;
        int year;
        double mileage;
     public:
         Vehicle(string B,string M,int Y,double Mileage){
             brand = B;
             model = M;
             year = Y;
             mileage = Mileage;
         }
         Vehicle(Vehicle &obj){
            brand = obj.brand;
            model = obj.model;
            year = obj.year;
            mileage = obj.mileage;


         }
     void display(){
      cout << "Brand:" << brand <<endl;
      cout << "Model:" << model <<endl;
      cout << "Year:" << year <<endl;
      cout << "Mileage:" << mileage << endl;
     }
    };


  int main(){
     Vehicle car1("Toyota", "Corolla", 2020, 15000.5);
     car1.display();
     cout << endl;
     cout << "Copy Vehicle-" << endl;
     Vehicle car2=car1;
     car2.display();


   return 0;
  }
