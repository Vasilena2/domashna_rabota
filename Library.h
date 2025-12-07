#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library {
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;
public:
    Library() = default;

    void addBook(const Book& b);
    void addMember(const Member& m);
    bool hasBook(const std::string& isbn) const;
    bool isBookAvailable(const std::string& isbn) const;
    bool loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due);
    bool returnBook(const std::string& isbn, const std::string& memberId);
    std::vector<Book> findByAuthor(const std::string& authorName) const;
    std::string to_string() const;
};

#endif
