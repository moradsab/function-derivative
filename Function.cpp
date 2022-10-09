//
//  Function.cpp
//  OOP32
//
//  Created by morad sabbah on 20/06/2020.
//  Copyright © 2020 morad sabbah. All rights reserved.
//

#include "Function.h"

std::map<std::string, std::map<std::string, SharedPtr<OOP_Hw3:: Function>>> OOP_Hw3::Function::Hessian() const{
    std::map<std::string, std::map<std::string, SharedPtr<OOP_Hw3::Function>>> hesmap;
    std::list<std::string>::iterator iter1, iter2;
    std::list<std::string> list=this->Variables();
    std::map<std::string, SharedPtr<OOP_Hw3:: Function>> derbymap;
    for(iter1 = list.begin(); iter1 != list.end(); iter1++){
        derbymap.clear();
        for(iter2 = list.begin(); iter2 != list.end(); iter2++){
            SharedPtr<OOP_Hw3::Function> derivative=this->DeriveBy(*iter1)->DeriveBy(*iter2);
            derbymap.insert ( std::pair<std::string, SharedPtr<OOP_Hw3:: Function>>(*iter2,derivative));
        }
        hesmap.insert ( std::pair<std::string, std::map<std::string, SharedPtr<OOP_Hw3:: Function>>> (*iter1,derbymap));
    }
    return hesmap;
}

OOP_Hw3::Function::~Function(){}







