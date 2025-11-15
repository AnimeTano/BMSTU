#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


struct Book {
    std::string title;
    std::string author;
    short year;
};


void AddtoFile(const std::string& stroka){
    std::ofstream OutFile("output.txt", std::ios::app);

    if (OutFile.is_open()){
        OutFile << stroka << "\n";
    }

    OutFile.close();
}


short Opr(){
    short n = 0;

    std::cout << "Variants to choose\n";

    std::cout << "1. Add books\n";
    std::cout << "2. Search by title\n";
    std::cout << "3. Sort books\n";
    std::cout << "4. Add book to the end\n";
    std::cout << "5. Search by year\n";
    std::cout << "6. Exit\n";

    std::cout << "7. Show all books\n";
    std::cout << "8. Show output\n";

    std::cout << "Choose your variant: ";
    std::cin >> n;
    std::cin.ignore();

    return n;
}


void ShowAllBooks(){
    std::ifstream inFile("books.txt");

    if (inFile.fail()){
        std::cout << "Error\n";
        return;
    }

    std::string line;
    short count = 0;
    std::string output = "\n ===All books=== \n";

    while (std::getline(inFile, line)){
        count++;
        std::cout << count << ": " << line << std::endl;
        output += std::to_string(count) + ": " + line + "\n";
    }

    if (count == 0) {
        std::cout << "No books found\n";
        output += "No books found\n";
    }

    AddtoFile(output);
    inFile.close();
}


void ShowOutput(){
    std::ifstream inFile("output.txt");

    if (inFile.fail()){
        std::cout << "Error";
        return;
    }

    std::string line;

    while (std::getline(inFile, line)){
        std::cout << line << std::endl;
    }

    inFile.close();
}


void add(){
    std::ofstream outFile("books.txt", std::ios::app);

    if (outFile.fail()){
        std::cout << "Error with open\n";
        return;
    }
    
    std::string output = "\n ===Adding books=== \n";
    std::cout << output;

    AddtoFile(output);

    while (true){
        std::string title, author;
        short year = 0;

        std::cout << "Enter title of book (empty to exit): ";
        std::getline(std::cin, title);

        if (title.empty()){
            break;
        }

        std::cout << "Enter author of book: ";
        std::getline(std::cin, author);

        std::cout << "Enter year of release: ";
        std::cin >> year;

        std::cin.ignore();

        outFile << title << ":" << author << ", " << year << "\n";
        
        std::string added = "Added: " + title + ":" + author + ", " + std::to_string(year);
        std::cout << added << std::endl;

        AddtoFile(added);
    }

    outFile.close();
}


void SearchByTitle(){
    std::ifstream inFile("books.txt");

    if (inFile.fail()){
        std::cout << "Error with open\n";
        return;
    }

    std::string name, line;
    std::cout << "Enter title to search: ";
    std::getline(std::cin, name);

    bool found = false;
    std::string output = "\n    Search results for '" + name + "'    \n";

    while (std::getline(inFile, line)){
        size_t pos = line.find(':');

        if (pos != std::string::npos){
            std::string title = line.substr(0, pos);
            if (title == name){
                output += "Found: " + line + "\n";
                std::cout << "Result: " << line << "\n";
                found = true;
            }
        }
    } std::cout << "\n";

    if (!found) {
        output += "Book not found\n";
        std::cout << "Book not found\n";
    }

    AddtoFile(output);

    inFile.close();
}


void SortByPar(){
    std::ifstream inFile("books.txt");

    if (inFile.fail()){
        std::cout << "Error with open\n";
        return;
    }

    std::vector<Book> books;
    std::string line;

    while (std::getline(inFile, line)){
        
        size_t Pos = line.find(':');
        size_t commaPos = line.find(',', Pos + 1);

        if (Pos != std::string::npos && commaPos != std::string::npos){
            Book book;
            book.title = line.substr(0, Pos);
            book.author = line.substr(Pos + 1, commaPos - 1);
            book.year = std::stoi(line.substr(commaPos + 1));

            books.push_back(book);
        }
    }
    
    inFile.close();

    if (books.empty()) {
        std::cout << "No books to sort\n";
        return;
    }

    short type = 0;

    std::cout << "\nChoose type of sort:\n";
    std::cout << "Search by author(1)\n";
    std::cout << "Search by year of release(2)\n";
    std::cout << "Choose your variant: ";
    std::cin >> type;
    std::cin.ignore();

    switch(type){
        case 1:
            std::sort(books.begin(), books.end(), [](Book& x, Book& y){
                return x.author < y.author;
            });
            break;
        case 2:
            std::sort(books.begin(), books.end(), [](Book& x, Book& y){
                return x.year < y.year;
            });
            break;
        default:
            std::cout << "Invalid choice\n";
            return;
    }

    std::ofstream outFile("books.txt");

    if (outFile.fail()){
        std::cout << "Error with open\n";
        return;
    }

    std::string sorted = "\n ===Sorted books=== \n";
    
    for (auto& book : books){
        std::string bookEntry = book.title + ":" + book.author + ", " + std::to_string(book.year);
        outFile << bookEntry << "\n";
        sorted += bookEntry + "\n";
    }

    std::cout << sorted;

    AddtoFile(sorted);
    outFile.close();
}


void addtheend(){
    std::ofstream outFile("books.txt", std::ios::app);

    if (outFile.fail()){
        std::cout << "Error with open\n";
        return;
    }

    std::string title, author;
    short year = 0;

    std::cout << "\nEnter information about book:\n";
    
    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    std::cout << "Enter author: ";
    std::getline(std::cin, author);

    std::cout << "Enter year of release: ";
    std::cin >> year;
    std::cin.ignore();

    outFile << title << ":" << author << ", " << year << "\n";

    std::string stroka = "Added to end: " + title + ":" + author + ", " + std::to_string(year);
    std::cout << stroka << std::endl;
    AddtoFile(stroka);

    outFile.close();
}


void SearchByYear(){
    std::ifstream inFile("books.txt");

     if (inFile.fail()){
        std::cout << "Error with open\n";
        return;
    }

    short year = 0;

    std::cout << "\nEnter maximum year: ";
    std::cin >> year;
    std::cin.ignore();

    std::string line;
    bool found = false;
    std::string output = "\n ===Books released before " + std::to_string(year) + "=== \n";

    while (std::getline(inFile, line)){
        size_t pos = line.find_last_of(',');
        
        if (pos != std::string::npos){
            short year_of_book = std::stoi(line.substr(pos + 1));
            if (year_of_book <= year){
                output += line + "\n";
                found = true;
            }    
        }
    }

    if (!found) {
        output += "No books found\n";
    }

    std::cout << output;

    AddtoFile(output);
    inFile.close();
}


int main(){
    short n = 0;

    std::ofstream clearFile("output.txt");
    clearFile.close();

    do {
        n = Opr();

        switch(n){
            case 1:
                add();
                break;
            case 2:
                SearchByTitle();
                break;
            case 3:
                SortByPar();
                break;
            case 4:
                addtheend();
                break;
            case 5:
                SearchByYear();
                break;
            case 6:
                std::cout <<"The end!\n";
                AddtoFile("The end!");
                return 0;
            case 7:
                ShowAllBooks();
                break;
            case 8:
                ShowOutput();
                break;
            default:
                std::cout << "Invalid Value\n";
                break;
        }
    } while (n != 6);

    return 0;
}