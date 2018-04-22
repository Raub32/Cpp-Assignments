//
//  iProduct.hpp
//  MS4
//
//  Created by Robert A on 2018-04-13.
//  Copyright © 2018 Robert A. All rights reserved.
//

#ifndef iProduct_hpp
#define iProduct_hpp
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

namespace AMA{
    class iProduct{
    public:
        virtual std::fstream& store(std::fstream& file, bool newline=true) const = 0;
        virtual std::fstream& load(std::fstream& file) = 0;
        virtual std::ostream& write(std::ostream& os , bool linear) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool operator==(const char*) const = 0;
        virtual double total_cost() const = 0;
        virtual const char* name() const = 0;
        virtual void quantity(int) = 0;
        virtual int qtyNeeded() const = 0;
        virtual int quantity() const = 0;
        virtual int operator+=(int) = 0;
        virtual bool operator>(const iProduct&) const = 0;
    };
    std::ostream& operator<<(std::ostream& ostr, const iProduct& mf);
    std::istream& operator>>(std::istream& is, iProduct&);
    double operator+=(double& , const iProduct& );
//    iProduct* CreateProduct();
    iProduct* CreatePerishable();
}

#endif /* iProduct_hpp */
