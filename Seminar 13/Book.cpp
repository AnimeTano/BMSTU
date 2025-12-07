#include "Book.h"
#include <iostream>


Book::Book(std::string t, std::string a, short y) : title(t), author(a), year(y) {}


void Book::displayInfo() {
    std::cout << "Title: " << title << ", author: " << author << ", year: " << year << "\n";
}