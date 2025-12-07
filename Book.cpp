#include "Book.h"
#include <sstream>

int Book::totalBooks = 0;

Book::Book()
    : title(""), author(), year(1900), price(0.0), isbn("") {
    ++totalBooks;
}

Book::Book(const std::string& title, const Author& author, int year, double price, const std::string& isbn)
    : title(title), author(author), year(year), price(price), isbn(isbn) {
    ++totalBooks;
}

Book::Book(const Book& other)
    : title(other.title), author(other.author), year(other.year), price(other.price), isbn(other.isbn) {
    ++totalBooks;
}

Book::Book(Book&& other) noexcept
    : title(std::move(other.title)), author(std::move(other.author)), year(other.year), price(other.price), isbn(std::move(other.isbn)) {
    ++totalBooks;
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        title = other.title;
        author = other.author;
        year = other.year;
        price = other.price;
        isbn = other.isbn;
    }
    return *this;
}

Book& Book::operator=(Book&& other) noexcept {
    if (this != &other) {
        title = std::move(other.title);
        author = std::move(other.author);
        year = other.year;
        price = other.price;
        isbn = std::move(other.isbn);
    }
    return *this;
}

Book::~Book() {
    --totalBooks;
}

std::string Book::getTitle() const { return title; }
Author Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
double Book::getPrice() const { return price; }
std::string Book::getIsbn() const { return isbn; }

void Book::setPrice(double p) {
    if (p < 0) return;
    price = p;
}

void Book::setYear(int y) {
    if (y < 1450 || y > 2025) return;
    year = y;
}

std::string Book::to_string() const {
    std::ostringstream oss;
    oss << "'" << title << "' by " << author.to_string() << " (" << year << ") " << "ISBN:" << isbn << " price=" << price;
    return oss.str();
}

int Book::getTotalBooks() { return totalBooks; }
