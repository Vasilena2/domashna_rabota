#include "Library.h"
#include <algorithm>
#include <sstream>

void Library::addBook(const Book& b) {
    if (!hasBook(b.getIsbn())) books.push_back(b);
}

void Library::addMember(const Member& m) {
    if (m.getMemberId().empty()) return;
    auto it = std::find_if(members.begin(), members.end(), [&](const Member& mm){ return mm.getMemberId() == m.getMemberId(); });
    if (it == members.end()) members.push_back(m);
}

bool Library::hasBook(const std::string& isbn) const {
    return std::any_of(books.begin(), books.end(), [&](const Book& b){ return b.getIsbn() == isbn; });
}

bool Library::isBookAvailable(const std::string& isbn) const {
    if (!hasBook(isbn)) return false;
    for (const auto& ln : loans) {
        if (ln.getIsbn() == isbn && !ln.isReturned()) return false;
    }
    return true;
}

bool Library::loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due) {
    if (!hasBook(isbn)) return false;
    if (!isBookAvailable(isbn)) return false;
    bool memberExists = std::any_of(members.begin(), members.end(), [&](const Member& m){ return m.getMemberId() == memberId; });
    if (!memberExists) return false;
    try {
        loans.emplace_back(isbn, memberId, start, due);
    } catch (...) {
        return false;
    }
    return true;
}

bool Library::returnBook(const std::string& isbn, const std::string& memberId) {
    for (auto& ln : loans) {
        if (ln.getIsbn() == isbn && ln.getMemberId() == memberId && !ln.isReturned()) {
            ln.markReturned();
            return true;
        }
    }
    return false;
}

std::vector<Book> Library::findByAuthor(const std::string& authorName) const {
    std::vector<Book> res;
    for (const auto& b : books) {
        if (b.getAuthor().getName().find(authorName) != std::string::npos) res.push_back(b);
    }
    return res;
}

std::string Library::to_string() const {
    std::ostringstream oss;
    int activeLoans = 0;
    for (const auto& ln : loans) if (!ln.isReturned()) ++activeLoans;
    oss << "Library: books=" << books.size() << ", members=" << members.size() << ", activeLoans=" << activeLoans;
    return oss.str();
}
