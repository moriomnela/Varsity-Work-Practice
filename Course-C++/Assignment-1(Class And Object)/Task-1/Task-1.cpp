
#include <iostream>
#include <string>


class Student {
private:
    std::string name;
    int rollNumber;
    float marks[10];
    float totalMarks;


public:


    Student(std::string studentName, int studentRollNumber, float studentMarks[10]) {
        name = studentName;
        rollNumber = studentRollNumber;
        totalMarks = 0.0;
        for (int i = 0; i < 10; ++i) {
            marks[i] = studentMarks[i];
        }
        calculateTotalMarks();
    }

    void calculateTotalMarks() {
        totalMarks = 0;
        for (int i = 0; i < 10; ++i) {
            totalMarks += marks[i];
        }
    }


    void displayInformation() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Roll Number: " << rollNumber << std::endl;
        std::cout << "Marks: ";
        for (int i = 0; i < 10; ++i) {
            std::cout << marks[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Total Marks: " << totalMarks << std::endl;
        std::cout << "Percentage: " << calculatePercentage() << "%" << std::endl;
    }


    float calculatePercentage() {
        return (totalMarks / 500) * 100;
    }
};


int main() {


    float marks1[10] = {85, 90, 78, 88, 92,90,65,70,80,50};
    float marks2[10] = {80, 85, 88, 90, 86,89,93,64,80,68};
    float marks3[10] = {75, 70, 80, 85, 78,60,78,96,64,70};


    Student student1("Nela", 101, marks1);
    Student student2("Raju", 102, marks2);
    Student student3("Moriom", 103, marks3);




    std::cout << "Student 1 Information:" << std::endl;
    student1.displayInformation();
    std::cout << std::endl;


    std::cout << "Student 2 Information:" << std::endl;
    student2.displayInformation();
    std::cout << std::endl;


    std::cout << "Student 3 Information:" << std::endl;
    student3.displayInformation();
    std::cout << std::endl;


    return 0;
}
