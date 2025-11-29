#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>


struct Product {
    std::string name;
    std::string category;
    double price;
    int quantity;
};


std::vector<Product> ReadFile(const std::string& name) {
    std::vector<Product> prod;
    std::ifstream file(name);

    if (file.fail()) {
        std::cout << "Error";
        return prod;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        Product cs;

        size_t first = line.find(','); 
        size_t second = line.find(',', first + 1);
        size_t third = line.find(',', second + 1);

        if (first != std::string::npos && second != std::string::npos && third != std::string::npos) {
            cs.name = line.substr(0, first);
            cs.category = line.substr(first + 1, second - first - 1);
            cs.price = std::stod(line.substr(second + 1, third - second - 1));
            cs.quantity = std::stoi(line.substr(third + 1));
            
            prod.push_back(cs);
        }
    }

    file.close();
    return prod;
}


void Statisticks(const std::vector<Product>& prod){
    int amount = 0;
    double c = 0.0;

    const Product* expensive = &prod[0];
    const Product* cheapest = &prod[0];


    for (const auto& p : prod){
        amount += p.quantity;
        c += p.price * p.quantity;

        if (p.price > expensive -> price){
            expensive = &p;
        }

        if (p.price < cheapest -> price){
            cheapest = &p;
        }
    }

    std::cout << "Amount:" << amount << "\n";
    std::cout << "Summa:" << c << "\n";
    std::cout << "The most expensive:" << expensive -> name << "\n";
    std::cout << "The cheapest: " << cheapest -> name << "\n";
}


void ShowAll(const std::vector<Product>& prod){
    for (const auto& p : prod){
        std::cout << "Name: " << p.name << "\nCategory: " << p.category <<
        "\nPrice: " << p.price << "\nQuantity: " << p.quantity << "\n";
        std::cout << "--------------------------\n";
    }
}


int main(){
    const std::string name = "products.csv";

    std::vector<Product> prod = ReadFile(name);

    ShowAll(prod);
    Statisticks(prod);

    return 0;
}