#include "Author.h"
#include <sstream>

Author::Author() : name("Unknown"), birthYear(1900) {}

Author::Author(const std::string& name, int birthYear)
    : name(name), birthYear(birthYear) {}

std::string Author::getName() const { return name; }
int Author::getBirthYear() const { return birthYear; }

void Author::setBirthYear(int year) {
    if (year < 1850 || year > 2025) return;
    birthYear = year;
}

std::string Author::to_string() const {
    std::ostringstream oss;
    oss << name << " (" << birthYear << ")";
    return oss.str();
}
