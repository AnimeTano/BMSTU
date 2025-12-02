#include <iostream>
#include <queue>
#include <string>
#include <vector>


struct Product {
    std::string name;
    double price;
    int quantity;

    Product(std::string n, double p, int q) : name(n), price(p), quantity(q) {}
};


struct Order{
    std::string Name;
    std::string Id;
    std::vector<Product> prod;
    double total;

    Order(std::string name, std::string id) : Name(name), Id(id), total(0) {}
};


void addOrder(std::queue<Order>& orderQueue, const Order& new_order){
    orderQueue.push(new_order);
    std::cout << "Added " << new_order.Name << "\n";
}


void processOrder(std::queue<Order>& orderQueue){
    if (orderQueue.empty()){
        std::cout << "Empty\n";
        return;
    }

    Order cur = orderQueue.front();
    orderQueue.pop();

    std::cout << "Order for " << cur.Name << "\n";
    std::cout << "---Products---" << "\n";

    for (const auto& p : cur.prod){
        std::cout << "Name: " << p.name << ", Price:" << p.price << ", Quantity: " << p.quantity << "\n";
    }
}


void addProduct(Order& order, const Product& product){
    order.prod.push_back(product);
    order.total += (product.price * product.quantity);
}


int main(){
    std::queue<Order> order;

    Order order1("Will Byers", "01");
    Order order2("El", "02");

    addProduct(order1, Product("Map", 25.5, 1));
    addProduct(order1, Product("Coca-Cola", 3.5, 2));

    addProduct(order2, Product("DND game", 30.0, 3));
    addProduct(order2, Product("Cofe", 5.0, 4));

    addOrder(order, order1);
    addOrder(order, order2);

    processOrder(order);
    processOrder(order);
    processOrder(order);

    return 0;
}