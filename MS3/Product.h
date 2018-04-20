//
//  Product.hpp
//  MS3
//
//  Created by Robert A on 2018-04-09.
//  Copyright © 2018 Robert A. All rights reserved.
//

#ifndef Product_hpp
#define Product_hpp

#include <stdio.h>
#include <iostream>
#include "ErrorState.h"
#include <fstream>

namespace AMA{
    #define max_sku_length 7
    #define max_unit_length 10
    #define max_name_length 75
    #define TAX_RATE 13
    
    class Product{
        char  _productType;
        char _productSku[max_sku_length];
        char productUnits[max_unit_length];
        char * productName;
        int inStock;
        int productsRequired;
        double productPrice;
        bool isTaxable;
        char * err;
        ErrorState Error;
    protected:
        void name(const char* _name);
        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double price() const;
        double cost() const;
        void message(const char *) const;
        bool isClear() const;
        
    public:
        Product();
        Product(char prodtype = 'N' );
        Product(const char* sku, const char* name, const char* units, int quantity = 0 , bool taxable = true, double price = 0, int prodNeeded = 0 );
        Product(const Product& product);
        void operator=(const Product& product);
        ~Product();
        std::fstream& store(std::fstream& file, bool newline = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        bool operator==(const char*) const;
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char* ) const;
        bool operator>(const Product& ) const;
        int operator+=(int);
    };
    std::ostream& operator<<( std::ostream&, const Product& );
    std::istream& operator>>(std::istream&, Product& );
    double operator+=(double &, const Product&);
}

#endif /* Product_hpp */
