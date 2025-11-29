#include <iostream>
#include <fstream>
#include <vector>


struct Student {
    int id;
    char name[50];
    int age;
    double average_grade;
};


void addStudents(const std::string& name){
    std::ofstream file(name, std::ios::binary);
    
    if (file.fail()){
        std::cout << "Error";
        return;
    }

    Student students[3] = {
        {1, "Иван Петров", 20, 4.5},
        {2, "Мария Сидорова", 19, 4.8},
        {3, "Алексей Иванов", 21, 4.2}
    };

    for (short i = 0; i < 3; i++){
        file.write(reinterpret_cast<const char*>(&students[i]), sizeof(Student));
    }

    file.close();
}


void showStudents(const std::string& name){
    std::ifstream file(name, std::ios::binary);
    
    if (file.fail()){
        std::cout << "Error";
        return;
    }

    Student students;

    while (file.read(reinterpret_cast<char*>(&students), sizeof(Student))){
        std::cout << "ID:" << students.id << "\n" << "Name:" << students.name << "\n" <<
        "Age:" << students.age << "\n" << "Avg:" << students.average_grade << "\n";
    }

    file.close();
}


int main(){

    addStudents("students.dat");
    showStudents("students.dat");

    return 0;
}