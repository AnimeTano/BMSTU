#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct Book{
    std::string title;
    std::string author;
    std::string genre;
    int year = 0;
};


struct Library{
    std::vector<Book> books;
    int count = 0;
};


void AddBook(Library& lib){
    Book newbook;

    std::cin.ignore();
    std::cout << "Enter title: ";
    std::getline(std::cin, newbook.title);

    std::cout << "Enter author: ";
    std::getline(std::cin, newbook.author);

    std::cout << "Enter genre: ";
    std::getline(std::cin, newbook.genre);

    std::cout << "Enter release year: ";
    std::cin >> newbook.year;

    lib.books.push_back(newbook);
    lib.count = lib.books.size();
}


void ShowBooks(const Library& lib){
    std::cout << "Amount of books: " << lib.count << "\n";

    for (const auto& book : lib.books){
        std::cout << "Title: " << book.title << "\n";
        std::cout << "Author: " << book.author << "\n";
        std::cout << "Release year: " << book.year << "\n";
        std::cout << "Genre: " << book.genre << "\n";
    }
    std::cout << "\n";
}


void Opr(){
    std::cout << "Add a book: 1\n";
    std::cout << "Del a book: 2\n";
    std::cout << "Find a book by author: 3\n";
    std::cout << "Show all books: 4\n";
    std::cout << "The end!: 5\n";
    std::cout << "Enter choice:";
}


void FindByAuthor(const Library& lib){
    std::string name;
    bool found = false;

    std::cin.ignore();
    std::cout << "Enter author to search: ";
    std::getline(std::cin, name);

    for (const auto& book : lib.books){
        if (book.author == name) {
            found = true;

            std::cout << "Title: " << book.title << "\n";
            std::cout << "Author: " << book.author << "\n";
            std::cout << "Release year: " << book.year << "\n";
            std::cout << "Genre: " << book.genre << "\n";
        }
    }

    if (!found) std::cout << "Not found";
}


void RemoveByTitle(Library& lib){
    std::string name;
    bool found = false;

    std::cin.ignore();
    std::cout << "Enter title to remove: ";
    std::getline(std::cin, name);

    for (short i = 0; i < lib.books.size(); i++){
        if (lib.books[i].title == name){
            lib.books.erase(lib.books.begin() + i);

            found = true;
            break;
        }
    }

    if (found) lib.count = lib.books.size();
}

int main(){
    Library library;
    short n = 0;

    do {
        Opr();
        std::cin >> n;

        switch(n){
            case 1:
                AddBook(library);
                break;
            case 2:
                RemoveByTitle(library);
                break;
            case 3:
                FindByAuthor(library);
                break;
            case 4:
                ShowBooks(library);
                break;
            case 5:
                std::cout << "The end!\n";
                break;
            default:
                std::cout << "Unacceptable\n";
                std::cin.ignore();
        }
    } while (n != 5);

    return 0;
}