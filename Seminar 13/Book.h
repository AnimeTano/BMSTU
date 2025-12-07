#ifndef BOOK_H
#define BOOK_H


#include <string>


class Book {
    private:
        std::string title;
        std::string author;
        short year;
    
    public:
        Book(std::string t, std::string a, short y);
        void displayInfo();
};

#endif