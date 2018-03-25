#ifndef _ERROR_STATE_H
#define _ERROR_STATE_H

namespace AMA {
    class ErrorState{
        char * message;
        
    public:
        explicit ErrorState(const char* errorMessage = nullptr);
        ErrorState(const ErrorState& em) = delete; 
    }
}

#endif
