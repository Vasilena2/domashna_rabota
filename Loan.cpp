#include "Loan.h"
#include <stdexcept>
#include <sstream>

Loan::Loan(const std::string& isbn, const std::string& memberId, const std::string& startDate, const std::string& dueDate)
    : isbn(isbn), memberId(memberId), startDate(startDate), dueDate(dueDate), returned(false) {
    if (dueDate < startDate) {
        throw std::invalid_argument("dueDate must be >= startDate");
    }
}

std::string Loan::getIsbn() const { return isbn; }
std::string Loan::getMemberId() const { return memberId; }
std::string Loan::getStartDate() const { return startDate; }
std::string Loan::getDueDate() const { return dueDate; }
bool Loan::isReturned() const { return returned; }

void Loan::markReturned() { returned = true; }

bool Loan::isOverdue(const std::string& today) const {
    if (returned) return false;
    return dueDate < today;
}

std::string Loan::to_string() const {
    std::ostringstream oss;
    oss << "Loan[" << isbn << ", " << memberId << ", " << startDate << " -> " << dueDate << ", returned=" << (returned?"yes":"no") << "]";
    return oss.str();
}
