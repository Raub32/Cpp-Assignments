#ifndef _ERROR_STATE_H
#define _ERROR_STATE_H

#include <iostream>
namespace AMA {
    
    class ErrorState{
        char * msg;
        ErrorState(const ErrorState& em) = delete;
        ErrorState& operator=(const ErrorState& em) = delete;
    public:
        explicit ErrorState(const char* errorMessage = nullptr);
        virtual ~ErrorState();
        void clear();
        bool isClear() const;
        void message(const char* str);
        const char* message() const;
        void setErr( char *);
    };
    std::ostream& operator<<(std::ostream& ostr, ErrorState& error);
}

#endif
