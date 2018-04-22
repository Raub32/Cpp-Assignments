//
//  Perishable.hpp
//  MS5
//
//  Created by Robert A on 2018-04-15.
//  Copyright © 2018 Robert A. All rights reserved.
//

#ifndef Perishable_h
#define Perishable_h
#include "Product.h"
#include "Date.h"
namespace AMA{
    class Perishable: public Product{
        Date ExpiryDate;  //Holds Expiration date of the product
    public:
        Perishable(); //Default constructor
        std::fstream& store(std::fstream& file, bool newline = true) const; //Store data using fstream object and return object
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear = false) const; //Ostream object to ouput data
        std::istream& read(std::istream& is); //Istream object to read data from console.
    };
}

#endif /* Perishable_h */
