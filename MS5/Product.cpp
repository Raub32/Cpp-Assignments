
//  Product.cpp
//  MS3
//
//  Created by Robert A on 2018-04-09.
//  Copyright © 2018 Robert A. All rights reserved.

//#include "ErrorState.h"
#include "Product.h"
#include <cstring>
#include "ErrorState.h"
#include <iomanip>

namespace AMA{
    void Product::message() const{ if( !Error.isClear() ) std::cout << Error.message();}//returns error message
    const char* Product::name() const{ return productName == 0 || productName == nullptr ? nullptr : productName;}/*Get name of product*/
    const char* Product::sku() const{ return _productSku;}/*Product id*/
    const char* Product::unit() const{  return productUnits;}/*Get Units of products in stock */
    bool Product::taxed() const{ return isTaxable;}/* return true if product is taxable */
    double Product::price() const{ return productPrice;}/*return price*/
    double Product::cost() const{ return taxed() ? ((TAX_RATE * productPrice) / 100 ) + productPrice : productPrice;}/*Get cost of product*/
    void Product::message(const char * msg){  Error.message(msg);} /* Set error message*/
    bool Product::isClear() const{ return Error.isClear();}/*Check for errors*/
    Product::Product(const Product& product){ *this = product;}/*deep copy this product*/
    double operator+=(double & price, const Product& product ){ return product.total_cost() + price;}
    bool Product::operator==(const char*sku) const{ return strcmp(sku, this->sku()) ? true : false;}/* Compatre sku recieved with product sku*/
    double Product::total_cost() const{return inStock * cost(); } /*Return cost including tax*/
    void Product::quantity(int q){  inStock = q;}/* Set quantity on hand */
    bool Product::isEmpty() const{ return name() == 0 && sku() == 0 && unit() == 0 && price() == 0 && cost() == 0 && isClear() == 0 ? true : false;}/* Check if object is in safe empty state*/
    int Product::qtyNeeded() const{ return this->productsRequired;}/* Return the quantity of products needed */
    int Product::quantity() const{ return this->inStock;}/* Return the quantity in store*/
    bool Product::operator>(const char* sku ) const{ return strlen(this->sku()) > strlen(sku) ? true : false;}
    bool Product::operator>(const iProduct& product) const{ return strlen(product.name()) > strlen(this->name()) ? true : false;}/* return the greater name length*/
    void Product::name(const char* name){ /* Get and store product name*/
        productName = new char[max_name_length];
        if(name != nullptr) strncpy(productName, name, max_name_length);
        productName[max_name_length] = '\0';
        message(0);
    };
    Product::Product(char prodtype){ /*Get the product type and stor*/
        _productType = prodtype;
        _productSku[0] =  '\0';
        productUnits[0] = '\0';
        productName = nullptr;
        inStock = 0;
        productsRequired  = 0;
        productPrice = 0;
        isTaxable = false;
        message(0);
    }
    Product::Product(const char* sku, const char* name, const char* units, int quantity, bool taxable, double price, int prodNeeded){
        strncpy(_productSku, sku,max_sku_length);
        strncpy(productUnits, units, max_unit_length);
        this->name(name);
        inStock = quantity;
        productsRequired  =  prodNeeded;
        isTaxable = taxable;
        productPrice = price;
        message(0);
    }
    void Product::operator=(const Product& product){ /* Perform deep copy*/
        strncpy(_productSku, product._productSku, max_sku_length);
        strncpy(productUnits, product.productUnits, max_unit_length);
        name(product.productName);
        inStock = product.inStock;
        productsRequired = product.productsRequired;
        productPrice = product.productPrice;
        isTaxable = product.isTaxable;
        Error.message(product.Error.message());
    }
    Product::~Product(){/*Product object destructor*/
        delete [] productName;
        productName  = nullptr;
    }
    std::fstream& Product::store(std::fstream& file, bool newline) const{
        if(file.is_open()){
            file << _productType << ","
            << sku() << ","
            << name() << ","
            << unit() << ","
            << ( isTaxable ?  1 : 0) << ","
            << productPrice  << ","
            << quantity()  << ","
            << productsRequired;
            if(newline){
                file << '\n';
            }else{
                file  << ",";
            }
        }

        return file;
    }
    std::fstream& Product::load(std::fstream& file){
        char delim;
        double price = 0.0;
        int taxable = 0;
        char productSku[max_sku_length];
        char _productName[max_name_length];
        char productUnit[max_unit_length];
        int _productsRequired = 0;
        int _inStock = 0;
        
        if(file.is_open()){
            file.get(productSku, max_sku_length, ',');
            file.ignore(1);
            file.get(_productName, max_name_length, ',');
            file.ignore(1);
            file.get(productUnit , max_unit_length, ',');
            file.ignore(1);
            file >> taxable >> delim
            >> price >> delim
            >> _inStock >> delim
            >> _productsRequired >> delim;
        }
        Product temp(productSku,_productName,productUnit,_inStock, taxable, price,_productsRequired);

    *this = temp;
        return file;
    }
    std::ostream& Product::write(std::ostream& os, bool linear) const{

        
        if(Error.isClear()){
            if ( !linear){
                os << " Sku: "<< sku() << std::endl
                << " Name (no spaces): " << name() << std::endl
                << " Price: " << price() << std::endl
                <<  " Price after tax: ";
                if(isTaxable){
                    os << cost() << std::endl;
                }else {
                    os << "N/A" << std::endl;
                }
                os << " Quantity on Hand: " << quantity() << " "<< unit() << std::endl
                << " Quantity needed: " << productsRequired;
            }else{
                
                os << std::left << std::setw(max_sku_length)<< std::setfill(' ') << sku() << "|"
                << std::left << std::setw(20) << std::setfill(' ') << name() << "|";
                os << std::right << std::fixed << std::setw(7)  << std::setprecision(2) << std::setfill(' ') << cost() << "|";
                os << std::right << std::setw(4) << std::fixed <<  std::setfill(' ') << quantity() << "|"
                << std::left << std::setw(10) <<  std::setfill(' ') << unit() << "|"
                << std::right << std::setw(4) << std::fixed << std::setfill(' ') <<  productsRequired << "|";
            }
        }else{
            std::cout << Error.message();
        }
        
        return os;
    }
    std::istream& Product::read(std::istream& is){
        char answer;
        char _productName[max_name_length];
        
        std::cout << " Sku: " ;
        is >> _productSku;
        is.ignore();
        std::cout << " Name (no spaces): ";
        is >> _productName;
        name(_productName);
        is.ignore();
        std::cout << " Unit: " ;
        is >> productUnits;
        std::cout << " Taxed? (y/n): " ;
        is >> answer;
        
        if(answer == 'y' || answer == 'Y') { isTaxable = true;}
        else if(answer == 'n' || answer == 'N' ){ isTaxable = false;}
        else{ is.setstate(std::ios::failbit);}
        
        if(is.fail()){
            message("Only (Y)es or (N)o are acceptable");
            is.setstate(std::ios::failbit);
            is.ignore(2000);
        }
         if (is.good()) std::cout << " Price: " ;
        is >> productPrice;
        if(is.fail() && isClear()){
            message("Invalid Price Entry");
            is.setstate(std::ios::failbit);
            is.ignore(2000);
        }
        
        if (is.good())  std::cout <<" Quantity on hand: " ;
        is >>  inStock;
        if(is.fail() && isClear()){
            message("Invalid Quantity Entry");
            is.setstate(std::ios::failbit);
            is.ignore(2000);
        }
        if (is.good())  std::cout << " Quantity needed: " ;
            is >> productsRequired;
            if(is.fail() && isClear()){
                message("Invalid Quantity Needed Entry");
                is.setstate(std::ios::failbit);
                is.ignore(2000);
            }
        
        return is;
    }
    int Product::operator+=(int units){return units >= 0 ? inStock += units : inStock;}
    std::istream& operator>>(std::istream& is,  iProduct& product ){
        product.read(is);
        return is;
    }
    std::ostream& operator<<(std::ostream& os, const iProduct& product ){
        product.write(os, true);
        return os;
    }
}
