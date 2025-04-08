#ifndef __IOSTREAM_LIB_H__
#define __IOSTREAM_LIB_H__

#include <ostream>
#include <sstream>
#include <vector>

// #define DEBUG

#ifdef DEBUG
    #define DEBUG_COUT(OUT) std::cout << OUT
    #define DEBUG_CERR(ERR) std::cerr << ERR
#else
    #define DEBUG_COUT(OUT)
    #define DEBUG_CERR(ERR)
#endif

namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_YELLOW   = 33,
        FG_BLUE     = 34,
        FG_MAGENTA  = 35,
        FG_CYAN     = 36,
        FG_WHITE    = 37,

        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_YELLOW   = 43,
        BG_BLUE     = 44,
        BG_MAGENTA  = 45,
        BG_CYAN     = 46,
        BG_WHITE    = 47,
        BG_DEFAULT  = 49,

        BOLD_ON = 1,
        BOLD_OFF = 21
    };
    class Modifier {
        Code code;
        Code bold_char;
    public:
        Modifier(Code pCode, Code bold) : code(pCode), bold_char(bold) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod)
        {
            return os << "\033[" << mod.code << ";" << mod.bold_char << "m";
        }
    };
}

template<typename T>
std::string printStdVectorRow(const std::vector<T>& vec, const std::string& separator = " ") {
    std::ostringstream oss;
    for (size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if (i != vec.size() - 1) oss << separator;
    }
    return oss.str();
}
#endif