//
// Created by ferit on 15/12/2020.
//

#include "../Include/Transformation.h"

Transformation::Transformation() = default;

/**
 * Instance = nullptr 
 */
Transformation* Transformation::instance = nullptr;

/**
 * Instance initialized on demand 
 */
Transformation* Transformation::getInstance() {
    if(instance == nullptr){
        instance = new Transformation();
    }
    return instance;
}