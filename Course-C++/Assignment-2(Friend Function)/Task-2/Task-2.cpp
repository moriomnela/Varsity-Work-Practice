/*Question 2:
Create a Box class that:
Stores the dimensions of a box (length, width, height) as private members.
Provides a constructor to initialize the dimensions.
Declares a friend function to print the dimensions.
Declares a friend class to calculate the volume.
Create a VolumeCalculator class that:
Uses the Box class to calculate and return the volume of a box.
Implement a main function to demonstrate the usage of these classes and the friend function.*/
#include <iostream>
#include <string>
using namespace std;
class Box {
private:
double length;
double width;
double height;
public:
Box(double l, double w, double h) : length(l), width(w), height(h) {}
friend void printDeimension(Box b1);
friend class volumeCalculator;
};
void printDeimension(Box b1) {
cout << "Length: " << b1.length << endl;
cout << "Width: " << b1.width << endl;
cout << "Height: " << b1.height << endl;
}
class volumeCalculator {
public:
double calculateVolume(Box b1) {
double volume = b1.length * b1.width * b1.height;
return volume;
}
};
int main() {
Box b1(8.0, 5.0, 3.0);
volumeCalculator v1;
printDeimension(b1);
double volume = v1.calculateVolume(b1);
cout << "Volume of box: " << volume << endl;
return 0;
}
