#include <iostream>
#include "ErrorState.h"

namespace AMA{
    

    ErrorState::ErrorState(const char* errorMessage){
        if(errorMessage == nullptr){
            msg = 0;
        }
    }
    
    ErrorState::~ErrorState(){
        delete msg;
        msg = 0;
    }
    

    void ErrorState::clear(){
        this->msg = 0;
    }
    
    bool ErrorState::isClear() const{
        if( msg == 0){
            return true;
        }else{
            return false;
        }
    }

//    void ErrorState::message(const char* str){
//        delete smg;
//        str = new char[strlen(str.msg) + 1];
//    }
//    
//    const char* ErrorState::message()const{
//        return &message;
//    }
    

    std::ostream& operator<<(std::ostream& ostr, ErrorState& error){
        if(error.isClear()){
            ostr << error.message() << endl;
            return ostr;
        }else{
            return ostr;
        }
    }
}
