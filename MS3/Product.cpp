//
//  Product.cpp
//  MS3
//
//  Created by Robert A on 2018-04-09.
//  Copyright © 2018 Robert A. All rights reserved.
//
#include "ErrorState.h"
#include "Product.h"
#include <cstring>

namespace AMA{
    void Product::name(const char* _name){
        if(_name == nullptr){
            delete[] productName;
        }else{
            productName = new char[strlen(_name)];
            strncpy(productName, _name, strlen(productName));
        }
    }
    const char* Product::name() const{
        return productName == 0 || productName == nullptr ? nullptr : productName;
    }
    const char* Product::sku() const{
        return _productSku;
    }
    const char* Product::unit() const{
        return productUnits;
    }
    bool Product::taxed() const{
        return isTaxable;
    }
    double Product::price() const{
        return productPrice;
    }
    double Product::cost() const{
        return productPrice;
    }
    void Product::message(const char * msg) const{
        Error.message(msg);
    }
    bool Product::isClear() const{
        return Error.isClear();
    }
    Product::Product(){
        _productType = 0;
        _productSku[0] =  0;
        productName = 0;
        inStock = 0;
        productsRequierd  = 0;
        productPrice = 0;
        isTaxable = false;
        Error.message(0);
    }
    Product::Product(char prodtype ){
        _productType = &prodtype;
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
    Product::Product(const Product& product){
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
    void Product::operator=(const Product& product){
        Product(product);
    }
    Product::~Product(){
        
    }
    std::fstream& Product::store(std::fstream& file, bool newline) const{
        
    }
    
}

