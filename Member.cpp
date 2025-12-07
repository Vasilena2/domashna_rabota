#include "Member.h"
#include <sstream>

Member::Member() : name(""), memberId(""), yearJoined(1900) {}

Member::Member(const std::string& name, const std::string& memberId, int yearJoined)
    : name(name), memberId(memberId), yearJoined(yearJoined) {}

std::string Member::getName() const { return name; }
std::string Member::getMemberId() const { return memberId; }
int Member::getYearJoined() const { return yearJoined; }

std::string Member::to_string() const {
    std::ostringstream oss;
    oss << name << " [" << memberId << "] joined: " << yearJoined;
    return oss.str();
}
