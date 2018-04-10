#define _CRT_SECIRE_N0_WARNINGS_

#include <iostream>
#include "ErrorState.h"
#include <cstring>
namespace AMA{

    ErrorState::ErrorState(const char* errorMessage){
        if(errorMessage == nullptr){
            msg = 0;
		}
		else {
			msg = new char[strlen(errorMessage + 1)];
			strncpy(msg, errorMessage, strlen(errorMessage));
		}
    }
    
    ErrorState::~ErrorState(){
        clear();
    }
    
    void ErrorState::clear(){
        if(!isClear()){
			delete msg;
			this->msg = 0;
		}
    }
    
    bool ErrorState::isClear() const{
        if(msg == 0){
            return true;
        }else{
            return false;
        }
    }

    void ErrorState::message(const char* str){
        clear();
        msg = new char[strlen(str)];
        strncpy(msg, str, strlen(str));
    }
    
    const char* ErrorState::message()const{
        return msg;
    }
    
    std::ostream& operator<<(std::ostream& ostr, ErrorState& error){
        if(!error.isClear() ){
            ostr << error.message();
            return ostr;
        }else{
            return ostr;
        }
    }
    
}
