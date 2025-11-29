#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>


struct Product{
    std::string name;
    double price;
    int quantity;
};


std::vector<Product> ReadFile(const std::string& name_file){
    std::vector<Product> prod;
    std::ifstream file(name_file);

    if (file.fail()){
        std::cout << "Error";
        return prod;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)){
        Product cs;

        size_t first = line.find(',');
        size_t sec = line.find(',', first + 1);

        cs.name = line.substr(0, first);
        cs.price = std::stod(line.substr(first + 1, sec - first));
        cs.quantity = std::stoi(line.substr(sec + 1));
        
        prod.push_back(cs);
    }

    file.close();

    return prod;
}


void write(const std::vector<Product>& prod, const std::string& name){
    std::ofstream file(name);

    if (file.fail()){
        std::cout << "Error";
        return;
    }

    file << "name,price,quantity\n";

    for (const auto& cs : prod){
        file << cs.name << "," << cs.price << "," << cs.quantity << "\n";
    }

    file.close();
}


void print(const std::vector<Product>& prod){
    for (const auto& cs : prod){
        std::cout << "Name: " << cs.name << " Price: " << cs.price << " Quantity: " << cs.quantity << "\n";
    }
}


auto Choose(){
    short n = 0;

    std::cout << "\n=== Sorting Options ===" << std::endl;
    std::cout << "1. Sort by price (low to high)" << std::endl;
    std::cout << "2. Sort by price (high to low)" << std::endl;
    std::cout << "3. Sort by name (A-Z)" << std::endl;
    std::cout << "4. Sort by quantity (high to low)" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> n;

    return n;
}


int main(){
    auto prod = ReadFile("products.csv");

    auto price_asc = [](const Product& x, const Product& y){
        return x.price < y.price;
    };

    auto price_desc = [](const Product& x, const Product& y){
        return x.price > y.price;
    };

    auto name_asc = [](const Product& x, const Product& y){
        return x.price < y.price;
    };

    auto quantity_desc = [](const Product& x, const Product& y){
        return x.price > y.price;
    };

    short n = 0;

    do {
        n = Choose();

        switch(n){
            case 1:
                std::sort(prod.begin(), prod.end(), price_asc);
                std::cout << "Sorted by price (ascending)\n";
                print(prod);
                write(prod, "sorted_products.csv");
                break;
            case 2:
                std::sort(prod.begin(), prod.end(), price_desc);
                std::cout << "Sorted by price (descending)\n";
                print(prod);
                write(prod, "sorted_products.csv");
                break;
            case 3:
                std::sort(prod.begin(), prod.end(), name_asc);
                std::cout << "Sorted by name (alphabetical)\n";
                print(prod);
                write(prod, "sorted_products.csv");
                break;
            case 4:
                std::sort(prod.begin(), prod.end(), quantity_desc);
                std::cout << "Sorted by quantity (descending)\n";
                print(prod);
                write(prod, "sorted_products.csv");
                break;
            case 5:
                std::cout << "The end!\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                continue;
        }
    } while (n != 5);

    return 0;
}