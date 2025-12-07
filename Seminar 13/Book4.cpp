#include "Book4.h"
#include <iostream>


Book::Book(const std::string& t, const std::string& a, short y) : Publication(t), author(a), year(y) {}


void Book::displayInfo() const {
    std::cout << "Title: " << title << ", author: " << author << ", year: " << year << "\n";
}