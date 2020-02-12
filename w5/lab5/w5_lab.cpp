// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;
using namespace std;

// ws books.txt
int main(int argc, char** argv)
{
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    // get the books
    sdds::Book library[7];
    {
        // TODO: load the collection of books from the file "argv[1]".
        //       - read one line at a time, and pass it to the Book constructor
        //       - store each book read into the array "library"
        //       - lines that start with "#" are considered comments and should be ignored
        ifstream book(argv[1]);
        string str;
        uint16_t i = 0u;
        if (!book) {
            cout << "The data file can not be opened!\n";
            return 0;
        }
        else
            while (book)
            {
                getline(book, str);
                if (str[0] != '#' && i<7) {
                    library[i] = Book(str);;
                    i++;
                }
            }

    }

    double usdToCadRate = 1.3;
    double gbpToCadRate = 1.5;

    // TODO: create a lambda expression that fixes the price of a book accoding to the rules
    //       - the expression should receive a single parameter of type "Book&"
    //       - if the book was published in US, multiply the price with "usdToCadRate"
    //            and save the new price in the book object
    //       - if the book was published in UK between 1990 and 1999 (inclussive),
    //            multiply the price with "gbpToCadRate" and save the new price in the book object
    auto f=[&](Book& book)->double {
        if (book.country() == "US")
            return book.price()*= usdToCadRate;
        else if(book.country() == "UK" && book.year()>=1990 && book.year() <= 1999) {
            return book.price()*= gbpToCadRate;
        }
    };

    std::cout << "-----------------------------------------\n";
    std::cout << "The library content\n";
    std::cout << "-----------------------------------------\n";
    for (auto& book : library)
        std::cout << book;
    std::cout << "-----------------------------------------\n\n";

    // TODO: iterate over the library and update the price of each book
    //         using the lambda defined above.
    for (auto& book : library)
        f(book);

    std::cout << "-----------------------------------------\n";
    std::cout << "The library content (updated prices)\n";
    std::cout << "-----------------------------------------\n";
    for (auto& book : library)
        std::cout << book;
    std::cout << "-----------------------------------------\n";

    return 0;
}
