#include <iostream>
#include <string>


class Book{
    private:
        std::string title;
        std::string author;
        int year;
    
    public:
        Book(std::string str, std::string st, int y) :
        title(str), author(st), year(y) {}

        std::string getTitle() { return title;}
        std::string getAuthor() { return author;}
        int getYear() { return year;}

        void setTitle(std::string str) { title = str;}
        void setAuthor(std::string st) { author = st;}
        void setYear(int y) { year = y;}

        void ShowInf(){
            std::cout << "Title: " << title << ", Author: " << author << ", year: " << year << "\n";
        }
};


int main(){
    Book book("The Witcher: The Tower of Swallows", "Andrzej Sapkowski", 1997);

    book.ShowInf();
    
    return 0;
}