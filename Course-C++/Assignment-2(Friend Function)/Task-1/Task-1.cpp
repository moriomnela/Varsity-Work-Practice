/*Question 1: Friend Class and Friend Function
Question: Explain what a friend class and a friend function are in C++. Provide an example where a friend class and a friend function are used.*/

#include <iostream>
 #include<string>
 using namespace std;
 class Y;
 class X {
 private:
     int valueX;
 public:
     X(int val) : valueX(val) {}
     friend void showValues(const X&, const Y&);
     friend class Z;
 };
 class Y {
 private:
     int valueY;
 public:
     Y(int val) : valueY(val) {}
     friend void showValues(const X&, const Y&);
 };
 void showValues(const X& x, const Y& y) {
     cout << "Value in X: " << x.valueX << endl;
     cout << "Value in Y: " << y.valueY << endl;
 }
 class Z {
 public:
     void display(const X& x) {
         cout << "Value in X from class Z: " << x.valueX << endl;
     }
 };

 int main() {
     X objX(10);
     Y objY(20);
     Z objZ;
     showValues(objX, objY);
     objZ.display(objX);

     return 0;
 }
