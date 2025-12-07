#include <string>
#include <iostream>
#include "Book.h"


int main(){
    Book book("The Witcher: The Tower of Swallows", "Andrzej Sapkowski", 1997);
    book.displayInfo();

    Book book1("The Witcher: The Last Wish", "Andrzej Sapkowski", 1992);
    book1.displayInfo();

    return 0;
}