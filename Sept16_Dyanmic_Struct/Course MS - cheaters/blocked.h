    #include <iostream>
    
    class Blocked {
    public:
        std::string program;
        int yearLevel;
    
        Blocked(const std::string& program, const int yearLevel) : program(program), yearLevel(yearLevel) {}
    };