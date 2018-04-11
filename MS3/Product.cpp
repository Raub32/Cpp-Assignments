//
//  Product.cpp
//  MS3
//
//  Created by Robert A on 2018-04-09.
//  Copyright © 2018 Robert A. All rights reserved.

//#include "ErrorState.h"
#include "Product.h"
#include <cstring>

namespace AMA{
    
    const char* Product::name() const{ /*Get name of product*/return productName == 0 || productName == nullptr ? nullptr : productName;}
    const char* Product::sku() const{/*Product id*/return _productSku;}
    const char* Product::unit() const{ /*Get Units of products in stock */ return productUnits;}
    bool Product::taxed() const{ /* return true if product is taxable */ return isTaxable;}
    double Product::price() const{ /*return price*/return productPrice;}
    double Product::cost() const{ /*Get cost of product*/return (TAX_RATE * productPrice ) + productPrice;}
    void Product::message(const char * msg) const{ /* Set error message*/ ;}
    bool Product::isClear() const{ /*Check for errors*/return Error.isClear();}
    Product::Product(const Product& product){ /*deep copy this product*/*this = product;}
    double operator+=(double & price, const Product& product ){ return product.total_cost() + price;}
    Product::Product(char prodtype ){ /*Get the product type*/_productType = &prodtype;}
    bool Product::operator==(const char*sku) const{ /* Compatre sku recieved with product sku*/return strcmp(sku, this->sku()) ? true : false;}
    double Product::total_cost() const{/*Return cost including tax*/ return productPrice * TAX_RATE;}
    void Product::quantity(int q){ /* Set quantity on hand */ inStock = q;}
    bool Product::isEmpty() const{ /* Check if object is in safe empty state*/return name() == 0 && sku() == 0 && unit() == 0 && price() == 0 && cost() == 0 && isClear() == 0 ? true : false;}
    int Product::qtyNeeded() const{ /* Return the quantity of products needed */return this->productsRequierd;}
    int Product::quantity() const{ /* Return the quantity in store*/ return this->inStock;}
    bool Product::operator>(const char* sku ) const{ return strlen(this->sku()) > strlen(sku) ? true : false;}
    bool Product::operator>(const Product& product) const{ /* return the greater name length*/ return strlen(product.name()) > strlen(this->name()) ? true : false;}
    Product::Product(){ //set object to safe empty state;
        _productType = 0;
        _productSku[0] =  0;
        productName = 0;
        inStock = 0;
        productsRequierd  = 0;
        productPrice = 0;
        isTaxable = false;
        Error.message(0);
    }
    Product::Product(const char* sku, const char* name, const char* units, int quantity, bool taxable, double price, int prodNeeded){
        strncpy(_productSku, sku, strlen(sku));
        strncpy(productName, name, strlen(name));
        strncpy(productUnits, units, strlen(units));
        inStock = quantity;
        productsRequierd  =  quantity;
        isTaxable = taxable;
        productPrice = price;
        Error.message(0);
    }
    void Product::operator=(const Product& product){ /* Perform deep copy*/
        _productType = product._productType;
        strcpy(_productSku, product._productSku);
        strcpy(productUnits, product.productUnits);
        strcpy(productName, product.productName);
        inStock = product.inStock;
        productsRequierd = product.productsRequierd;
        productPrice = product.productPrice;
        isTaxable = product.isTaxable;
        Error.message(product.Error.message());
    }
    Product::~Product(){/*Product object destructor*/
        delete [] productName;
        productName  = nullptr;
    }
    std::fstream& Product::store(std::fstream& file, bool newline) const{
        
        return file;
    }
    std::fstream& Product::load(std::fstream& file){
        store(file);
        return file;
    }
    std::ostream& Product::write(std::ostream& os, bool linear) const{
        os << "Sku - ( " << max_sku_length  << " )" << std::endl
        << "Name - (" << productName << " )" << std::endl
        << "Cost - (" << cost() <<" )" << std::endl
        << "quantity needed - ( " << productsRequierd <<" )" << std::endl;
        
        if ( linear == false){
            os << "Slu: "<< sku() << std::endl
            << "Name: " << name() << std::endl
            << "Price: " << price() << std::endl
            << "Either of:" << std::endl
            << os.width(10) << os.setf(std::ios::right) <<  "- Price After Tax: " << cost() <<  std::endl
            << os.setf(std::ios::left) << "Quantity on hand: " << unit() << std::endl
            << "Quantity needed: " << productsRequierd << std::endl;
        }
        return os;
    }
    std::istream& Product::read(std::istream& is){
            is >> _productSku;
            is >> productName;
            is >> productUnits;
            is >> isTaxable;
            if(is.fail()){
//                Error = is.setstate(std::ios::failbit);
            }
            is >> productPrice;
            if(is.fail() && isClear()){
//                message(is.std::istream::setstate(std::ios::failbit));
            }
            is >>  inStock;
            if(is.fail() && isClear()){
//                message(is.std::istream::setstate(std::ios::failbit));
            }
            is >> productsRequierd;
            if(is.fail() && isClear()){
//            message(is.std::istream::setstate(std::ios::failbit));
        }
        return is;
    }
    int Product::operator+=(int units){
        inStock += units;
        return inStock;
    }
    std::ostream& operator<<(std::ostream& os, const Product& product ){
        product.write(os, true);
        return os;
    }
    std::istream& operator>>(std::istream& is, const Product& product ){
       product.read(is, true);
        return is;
    }
}
