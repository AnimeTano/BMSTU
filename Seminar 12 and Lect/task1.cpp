#include <iostream>
#include <string>
#include <vector>


struct Student{
    std::string name;
    int age;
    double average;
    int number;
};


void addStudent(std::vector<Student>& student){
    Student newstudent;

    std::cin.ignore();
    std::cout << "Enter FIO of student: ";
    std::getline(std::cin, newstudent.name);

    std::cout << "Enter age of student: ";
    std::cin >> newstudent.age;

    std::cout << "Enter average score: ";
    std::cin >> newstudent.average;

    std::cout << "Enter number: ";
    std::cin >> newstudent.number;

    student.push_back(newstudent);
}


void showStudent(const std::vector<Student>& student){
    std::cout << "-----------\n";

    for (const auto& stud : student){
        std::cout << "FIO:" << stud.name << "\n";
        std::cout << "Age:" << stud.age << "\n";
        std::cout << "Average:" << stud.average << "\n";
        std::cout << "Number:" << stud.number << "\n"; 
    }

    std::cout << "-----------\n";
}


void FindStudentByNumber(const std::vector<Student>& student){
    int n = 0;
    std::cout << "Enter number to search:";
    std::cin >> n;

    bool found = false;

    std::cout << "-----------\n";
    for (const auto& stud : student){
        if (stud.number == n){
            found = true;
            std::cout << "FIO:" << stud.name << "\n";
            std::cout << "Age:" << stud.age << "\n";
            std::cout << "Average:" << stud.average << "\n";
            std::cout << "Number:" << stud.number << "\n";
            break;
        }
    } 
    std::cout << "-------------\n";

    if (!found) std::cout << "Didn't find";
}


void ShowHighestScore(const std::vector<Student>& student){
    double point = 0;
    bool found = false;

    std::cout << "Enter score to search:";
    std::cin >> point;

    std::cout << "---------------\n";
    for (const auto& stud : student){
        if (stud.average > point){
            found = true;
            std::cout << "FIO:" << stud.name << "\n";
            std::cout << "Age:" << stud.age << "\n";
            std::cout << "Average:" << stud.average << "\n";
            std::cout << "Number:" << stud.number << "\n";
        }
    }
    std::cout << "-----------------\n";

    if (!found) std::cout << "Didn't find";
}


void Opr(){
    std::cout << "Add new student: 1\n";
    std::cout << "Show all students: 2\n";
    std::cout << "Find student by number: 3\n";
    std::cout << "Show students with average score higher than point: 4\n";
    std::cout << "The end!: 5\n";
    std::cout << "Enter your variant:";
}


int main(){
    std::vector<Student> student;
    short n = 0;

    do {
        Opr();
        std::cin >> n;

        switch(n) {
            case 1:
                addStudent(student);
                break;
            case 2:
                showStudent(student);
                break;
            case 3:
                FindStudentByNumber(student);
                break;
            case 4:
                ShowHighestScore(student);
                break;
            case 5:
                std::cout << "The end!\n";
                break;
            default:
                std::cout << "Error\n";
        }
    } while (n != 5);

    return 0;
}