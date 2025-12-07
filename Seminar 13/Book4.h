#ifndef BOOK_H
#define BOOK_H


#include "Publ.h"
#include <string>


class Book : public Publication {
    private:
        std::string author;
        short year;
    
    public:
        Book(const std::string& t, const std::string& a, short y);
        void displayInfo() const override;

        std::string getAuthor() const { return author; }
        short getYear() const { return year; }

        void setAuthor(const std::string& a) { author = a; }
        void setYear(short y) { year = y; }
};

#endif