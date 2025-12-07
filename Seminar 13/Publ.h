#ifndef PUBL_H
#define PUBL_H


#include <string>
#include <iostream>


class Publication {
    protected:
        std::string title;

    public:
        Publication(const std::string& t) : title(t) {}

        virtual ~Publication() {}

        virtual void displayInfo() const {
            std::cout << "Title: " << title << "\n";
        }

        std::string getTitle() const { return title; }

        void setTitle(const std::string& t) { title = t; }
};

#endif