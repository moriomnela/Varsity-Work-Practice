/*Question 4: Inline Functions
Question: What is an inline function in C++? How do you define an inline function, and what are its advantages? Provide an example of an inline function.*/


#include <iostream>
using namespace std;


class Math {
public:


    inline int square(int x) {
        return x * x;
    }
};


int main() {
    Math math;
    int number = 8;


    cout << "The square of " << number << " is " << math.square(number) << endl;


    return 0;
}
