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

void Write(const std::vector<Product>& prod, const std::string& name) {
    std::ofstream file(name);

    if (file.fail()) {
        std::cout << "Error";
        return;
    }

    file << "name,category,price,quantity\n";

    for (const auto& cs : prod) {
        file << cs.name << "," << cs.category << "," << cs.price <<
        "," << cs.quantity << "\n";
    }

    file.close();
}

void print(const std::vector<Product>& prod) {
    for (const auto& cs : prod) {
        std::cout << "Name: " << cs.name << " Category: " << cs.category <<
        " Price: " << cs.price << " Quantity: " << cs.quantity << "\n";
    }
}

int Opr() {
    short n = 0;

    std::cout << "\n=== Product Filtering Menu ===" << std::endl;
    std::cout << "1. Filter by price (above threshold)" << std::endl;
    std::cout << "2. Filter by price (below threshold)" << std::endl;
    std::cout << "3. Filter by category" << std::endl;
    std::cout << "4. Filter by quantity (in stock)" << std::endl;
    std::cout << "5. Filter by quantity (out of stock)" << std::endl;
    std::cout << "6. Show all products" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Choose filtering option (1-7): ";
    std::cin >> n;

    return n;
}

int main() {
    auto prod = ReadFile("products.csv");

    short n = 0;
    std::vector<Product> filtered;

    do {
        n = Opr();

        switch (n) {
            case 1: {
                double threshold;
                std::cout << "Enter min price: ";
                std::cin >> threshold;

                auto priceFilter = [threshold](const Product& p) {
                    return p.price > threshold;
                };

                filtered.clear();
                std::copy_if(prod.begin(), prod.end(), std::back_inserter(filtered), priceFilter);

                print(filtered);
                Write(filtered, "filtered_products.csv");
                break;
            }

            case 2: {
                double threshold;
                std::cout << "Enter max price: ";
                std::cin >> threshold;

                auto priceFilter = [threshold](const Product& p) {
                    return p.price < threshold;
                };

                filtered.clear();
                std::copy_if(prod.begin(), prod.end(), std::back_inserter(filtered), priceFilter);

                print(filtered);
                Write(filtered, "filtered_products.csv");
                break;
            }

            case 3: {
                std::string category;
                std::cout << "Enter category name: ";
                std::cin.ignore();
                std::getline(std::cin, category);

                auto categoryFilter = [category](const Product& p) {
                    return (p.category == category);
                };

                filtered.clear();
                std::copy_if(prod.begin(), prod.end(), std::back_inserter(filtered), categoryFilter);

                print(filtered);
                Write(filtered, "filtered_products.csv");
                break;
            }

            case 4: {
                auto inStockFilter = [](const Product& p) {
                    return p.quantity > 0;
                };

                filtered.clear();
                std::copy_if(prod.begin(), prod.end(), std::back_inserter(filtered), inStockFilter);

                print(filtered);
                Write(filtered, "filtered_products.csv");
                break;
            }

            case 5: {
                auto outOfStockFilter = [](const Product& p) {
                    return p.quantity == 0;
                };

                filtered.clear();
                std::copy_if(prod.begin(), prod.end(), std::back_inserter(filtered), outOfStockFilter);

                print(filtered);
                Write(filtered, "filtered_products.csv");
                break;
            }

            case 6: {
                filtered = prod; 
                print(filtered);
                break;
            }

            case 7: {
                std::cout << "The end!" << std::endl;
                break;
            }

            default: {
                std::cout << "Invalid choice!" << std::endl;
                break;
            }
        }
    } while (n != 7);

    return 0;
}