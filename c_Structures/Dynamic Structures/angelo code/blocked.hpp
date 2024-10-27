// Create another class for the blocked courses
// Optional to create but I like to do it this way - PEPS

#include <iostream>

class Blocked {
public:
    std::string program;
    int yearLevel;

    Blocked(const std::string& program, const int yearLevel) : program(program), yearLevel(yearLevel) {}
};