#include <iostream>


struct Date {
    short day = 0;
    short month = 0;
    short year = 0;
};


struct Time {
    int second = 0;
    int minute = 0;
    int hour = 0;
};


union DateTime {
    struct {
        short day;
        short month;
        short year;
        int second;
        int minute;
        int hour;
    } datetime;
};

int main() {
    DateTime dt;

    std::cout << "Enter day: ";
    std::cin >> dt.datetime.day;

    std::cout << "Enter month: ";
    std::cin >> dt.datetime.month;

    std::cout << "Enter year: ";
    std::cin >> dt.datetime.year;

    std::cout << "Enter seconds: ";
    std::cin >> dt.datetime.second;

    std::cout << "Enter minutes: ";
    std::cin >> dt.datetime.minute;
    
    std::cout << "Enter hours: ";
    std::cin >> dt.datetime.hour;
    
    std::cout << "Date and time: " 
              << dt.datetime.month << "-"
              << dt.datetime.day << "-"
              << dt.datetime.year << " "
              << dt.datetime.hour << ":"
              << dt.datetime.minute << ":"
              << dt.datetime.second << "\n";

    return 0;
}