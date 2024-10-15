/*Question 3: Member Functions
Question: What is a member function in C++? How do you define and call a member function? Provide an example with a class definition, member function, and a demonstration of calling the member
 function.*/

#include <iostream>
 #include<string>
 using namespace std;
 class patient {
 private:
     int weight, height,bmi;
 public:
     patient(int w, int h, int BMI)  {
         weight=w;
         height=h;
         bmi=BMI;
     }
     void display() {
         cout << "weight: " << weight << endl;
         cout <<"Height: " << height << endl;
         cout <<"BMI: " << bmi << endl;
     }
 };
 int main() {
     patient pst(50,5,23 );
     pst.display();
     return 0;
 }
