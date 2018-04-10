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

namespace AMA{
    #define MAX_SKU_NUM 7
    #define MAX_DECRIPTER_LENGTH 10
    #define MAX_PRODUCT_NAME_LENGTH 75
    #define TAX_RATE 13
    
    class Product{
        char * _productType;
        char _productSku[MAX_SKU_NUM];
        char productUnits[MAX_DECRIPTER_LENGTH];
        char * productName;
        int inStock;
        int productsRequierd;
        double productPrice;
        bool isTaxable;
        ErrorState Error;
    protected:
        void name(const char* _name);
        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double price() const;
        double cost() const;
        void message(const char * message) const;
        bool isClear() const;
        
    public:
        Product();
        Product(char prodtype = 'N' );
        Product(const char* sku, const char* name, const char* units, int quantity = 0, bool taxable = true, double price = 0, int prodNeeded = 0 );
        Product(const Product& product);
        void operator=(const Product& product);
        ~Product();
        std::fstream& store(std::fstream& file, bool newline = true) const;
    };
}

#endif /* Product_hpp */
