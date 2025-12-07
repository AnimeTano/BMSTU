#include "Book4.h"
#include <iostream>


int main(){
    Book book("1984", "Orwell", 1949);
    book.displayInfo();

    Publication* pub = &book;
    pub -> displayInfo();

    Book book1("Master and Margarita", "Bulgakov", 1967);
    book1.displayInfo();

    return 0;
}