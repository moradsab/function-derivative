//
//  Constant.cpp
//  OOP32
//
//  Created by morad sabbah on 20/06/2020.
//  Copyright © 2020 morad sabbah. All rights reserved.
//

#include "Constant.h"

OOP_Hw3::Const::Const(double value):cnst(value){}

double OOP_Hw3::Const::Evaluate(const std::map<std::string, double>& variables) const{
    return cnst;
}

std::list<std::string> OOP_Hw3::Const::Variables() const{
    std::list<std::string> empty;
    return empty;
}

SharedPtr<OOP_Hw3::Function> OOP_Hw3::Const::DeriveBy(const std::string& variable) const{return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Const(0));}
