//
//  Perishable.cpp
//  MS5
//
//  Created by Robert A on 2018-04-20.
//  Copyright © 2018 Robert A. All rights reserved.
//
#include "Perishable.h"

namespace AMA{
    Perishable::Perishable(): Product('P') {}//no arg constructor
    std::fstream& Perishable::store(std::fstream& file, bool newline) const{
         //Store data using fstream object and return object
        Product::store(file, false);
        file << ExpiryDate;
        file.close();
        return file;
    }
    std::fstream& Perishable::load(std::fstream& file){
        //Loads data from file including perishable expiry date
        Product::load(file);
        ExpiryDate.read(file);
        return file;
    }
    std::ostream& Perishable::write(std::ostream& os, bool linear) const{//Ostream object to ouput data
        if(Product::isClear()){
            Product::write(os, linear);
            if(linear){
                ExpiryDate.write(os);
            }
            else{
                os << " ExpiryDate: " ;
                ExpiryDate.write(os);
            }
        }else{
            Product::message();
        }
        return os;
    }
    std::istream& Perishable::read(std::istream& is){
        //Istream object to read data from console.
        Product::read(is);
        if( Product::isClear()){
            Date temp;
            std::cout <<" Expiry date (YYYY/MM/DD): ";
            is >> temp;
            if(temp.bad()){
                switch (temp.errCode()) {
                    case 1:
                        Product::message("Invalid Date Entry");
                        break;
                    case 2:
                        Product::message("Invalid Year in Date Entry");
                        break;
                    case 3:
                        Product::message("Invalid Month in Date Entry");
                        break;
                    case 4:
                        Product::message("Invalid Day in Date Entry");
                        break;
                    default:
                        break;
                }
                std::cin.setstate(std::ios::failbit);
            }else{
                ExpiryDate = temp;
            }
        }
        return is;
    }
}

