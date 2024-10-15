/*Basic Class with Getter and Setter Methods and Default Constructors:Create a class named Vehicle with private members: id (integer), brand (string),
mode,(string), year (integer), and mileage (double).Implement a default constructor that initializes these members to default values (id to 0, brand and
model to "Unknown", year to 2000, and mileage to 0.0).Provide getter and setter methods for each private member to allow access and modification.
Implement a method named display that prints the details of a Vehicle object.*/

#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
   class Vehicle{
      private:
         int id;
         string brand;
         string model;
         int year;
         double mileage;
      public:
         Vehicle():id(0),brand("Unknown"),model("Unknown"),year(2000),mileage(0.0){}
            int getid(){
                return id;
                }
            string getbrand(){
                return brand;
                }
            string getmodel(){
                return model;
                }
            int getyear(){
                return year;
                }
            double getmileage(){
                return mileage;
                }


         void setid(int I){
               id = I;
         }
         void setbrand(string B){
               brand = B;
         }
         void setmodel(string M){
               model = M;
         }
         void setyear(int Y){
               year = Y;
         }
         void setmileage(double Mileage){
               mileage = Mileage;
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
       Vehicle car;
       car.setid(1);
       car.setbrand("BMW");
       car.setmodel("M4");
       car.setyear(2022);
       car.setmileage(15000.50);


    car.display();
    getch();
   }
