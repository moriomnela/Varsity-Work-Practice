/*2. Constructor Overloading:Extend the Vehicle class to include a parameterized constructor that initializes its members
with the given values (id, brand, model, year, and mileage).*/



#include<iostream>
#include<conio.h>
using namespace std;


  class Vehicle{
      int id;
      string brand;
      string model;
      int year;
      double mileage;
    public:
        Vehicle(int I,string B,string M,int Y,double Mileage){
                id = I;
                brand = B;
                model = M;
                year = Y;
                mileage = Mileage;
        }
        Vehicle(int I,string B,string M){
                id = I;
                brand = B;
                model = M;
                year = 0;
                mileage = 0;
         }
       void display(){
        cout << "Vehicle Details:" << endl;
       cout << "Id:" << id << endl;
       cout << "Brand:" << brand << endl;
       cout << "Model:" << model << endl;
       cout << "Year:"  << year << endl;
       cout << "Mileage:" <<mileage << endl;
       }
   };
  int main(){
     Vehicle car1(1001, "Toyota", "Corolla", 2020, 15000.5);
     car1.display();
     Vehicle car2(1002, "BMW", "M4");
     car2.display();


   return 0;


  }
