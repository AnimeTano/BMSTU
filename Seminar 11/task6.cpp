#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>


struct Product {
    int id;
    std::string name;
    std::string category;
    double price;
    int quantity;
};


std::string RandomName(unsigned int curtime){
    std::vector<std::string> names = {"Laptop", "Smartphone", "Tablet", "Monitor", "Keyboard",
        "Mouse", "Headphones", "Printer", "Scanner", "Flash Drive",
        "Hard Drive", "Processor", "Graphics Card", "Motherboard",
        "Power Supply", "RAM", "Computer Case", "Cooler", "SSD", "Router",
        "Webcam", "Microphone", "Speakers", "USB Hub", "External Battery",
        "Smart Watch", "Fitness Tracker", "E-Reader", "Gaming Console",
        "Camera", "Action Camera", "Drone", "Smart Home Hub", "TV",
        "Soundbar", "Projector", "Bluetooth Speaker", "Wireless Earbuds",
        "Gaming Chair", "Standing Desk", "Monitor Arm", "Docking Station",
        "Network Switch", "Wireless Adapter", "Cable Management", "Desk Lamp",
        "Office Chair", "Document Scanner", "Label Maker", "Paper Shredder"
    };
    
    std::vector<std::string> brands = {
        "Dell", "HP", "Lenovo", "Asus", "Acer", "Apple", "Samsung",
        "Sony", "LG", "Toshiba", "MSI", "Razer", "Corsair", "Logitech",
        "SteelSeries", "HyperX", "Western Digital", "Seagate", "SanDisk",
        "Kingston", "Crucial", "Intel", "AMD", "NVIDIA", "EVGA", "Gigabyte",
        "ASRock", "Cooler Master", "be quiet!", "Noctua", "Thermaltake",
        "TP-Link", "Netgear", "Linksys", "D-Link", "Google", "Amazon",
        "Bose", "JBL", "Sennheiser", "Audio-Technica", "Shure", "Blue",
        "Canon", "Nikon", "GoPro", "DJI", "Fitbit", "Garmin", "Xiaomi"
    };

    std::vector<std::string> models = {
        "Pro", "Elite", "Ultra", "Max", "Plus", "Premium", "Advanced",
        "Gaming", "Workstation", "Business", "Home", "Office", "Student",
        "Travel", "Portable", "Wireless", "Bluetooth", "USB-C", "Thunderbolt",
        "4K", "HD", "Full HD", "Ultra HD", "OLED", "LED", "IPS", "TN",
        "Mechanical", "Membrane", "Optical", "Laser", "Ergonomic", "RGB",
        "Silent", "Performance", "Extreme", "Turbo", "Boost", "Core", "Nano"
    };

    return names[curtime % 50] + " " + brands[curtime % 50] + " " + models[curtime % 41];
}


auto RandomCategory(unsigned int curtime){

    std::vector<std::string> categories = {
        "Computers & Laptops", "Mobile Phones & Tablets", "Computer Components",
        "Computer Peripherals", "Networking Equipment", "Audio & Video",
        "Cameras & Photography", "Gaming Equipment", "Wearable Technology",
        "Smart Home Devices", "Office Equipment", "Storage Devices",
        "Accessories", "Software", "Home Appliances", "Car Electronics",
        "Health & Fitness", "Toys & Hobbies", "Tools & Home Improvement"
    };

    return categories[curtime % 19];
}


auto RandomPrice(unsigned int curtime){
    return curtime % 12345;
}


auto RandomQuantity(unsigned int curtime){
    return curtime % 1234;
}


void CreareProducts(const std::string& name, short amount){
    std::ofstream file(name);

    if (file.fail()){
        std::cout << "Error";
        return;
    }

    file << "id,name,category,price,quantity\n";

    std::time_t currenttime = std::time(nullptr);

    for (short i = 1; i <= amount; i++){
        Product prod;

        unsigned int seed = static_cast<unsigned int>(currenttime + i * 12345);

        prod.id = i;
        prod.name = RandomName(seed);
        prod.category = RandomCategory(seed);
        prod.price = RandomPrice(seed);
        prod.quantity = RandomQuantity(seed);

        file << prod.id << ',' << prod.name << "," << prod.category << ',' <<
        prod.price << "," << prod.quantity << "\n";
    }

    file.close();
}


void Check(const std::string& name, short amount){
    std::ifstream file(name);

    if (file.fail()){
        std::cout << "Error";
        return;
    }

    std::string line;
    short count = 0;

    while (std::getline(file, line)){
        count++;
    }

    file.close();

    if (count == amount){
        std::cout << "Everything alright!\n";
    } else std::cout << "Some trouble with amounts of element\n";
}


void ShowProducts(const std::string& name, short n){
    std::ifstream file(name);

    if (file.fail()){
        std::cout << "Error";
        return;
    }

    std::string line;

    while (std::getline(file, line)){
        std::cout << line << "\n";
    }

    file.close();
}




int main(){
    const std::string name = "products.csv";
    short n = 0;

    std::cout << "Enter amount of elements:";
    std::cin >> n;

    CreareProducts(name, n);

    Check(name, n);

    ShowProducts(name, n / 10);

    return 0;
}