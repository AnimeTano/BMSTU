#include <iostream>
#include <string>
#include <vector>


struct Employee{
    std::string name;
    std::string position;
    short age;
    double salary;
};


void ShowEmployers(const Employee& young, const Employee& old){
    std::cout << "The youngest employer:" << young.name << ", Age:" << young.age << ", Pos:" << young.position << ", Salary:" << young.salary << "\n";

    std::cout << "The oldest employer:" << old.name << ", Age:" << old.age << ", Pos:" << old.position << ", Salary:" << old.salary << "\n";
}


int main(){
    int number = 0;

    std::cout << "Enter amount of employers:";
    std::cin >> number;

    std::vector<Employee> emp(number);

    for (short i = 0; i <number; i++){
        std::cin.ignore();
        std::cout << "Enter name: ";
        std::getline(std::cin, emp[i].name);
        
        std::cout << "Enter age: ";
        std::cin >> emp[i].age;

        std::cin.ignore();
        std::cout << "Enter pos: ";
        std::getline(std::cin, emp[i].position);

        std::cout << "Enter salary: ";
        std::cin >> emp[i].salary;
    }

    Employee Emp[2] = {emp[0], emp[0]};
    double total = 0.0;

    for (const auto& employee : emp){
        if (employee.age < Emp[0].age) Emp[0] = employee;

        if (employee.age > Emp[1].age) Emp[1] = employee;

        total += employee.salary;
    }

    std::cout << "Average salary: " << total / number << "\n";

    ShowEmployers(Emp[0], Emp[1]);

    return 0;
}