#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Author.h"

class Book {
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;
    static int totalBooks;
public:
    Book();
    Book(const std::string& title, const Author& author, int year, double price, const std::string& isbn);
    Book(const Book& other);
    Book(Book&& other) noexcept;
    Book& operator=(const Book& other);
    Book& operator=(Book&& other) noexcept;
    ~Book();

    std::string getTitle() const;
    Author getAuthor() const;
    int getYear() const;
    double getPrice() const;
    std::string getIsbn() const;

    void setPrice(double p);
    void setYear(int y);

    std::string to_string() const;
    static int getTotalBooks();
};

#endif
