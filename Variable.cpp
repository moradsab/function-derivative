//
//  Variable.cpp
//  OOP32
//
//  Created by morad sabbah on 20/06/2020.
//  Copyright © 2020 morad sabbah. All rights reserved.
//

#include "Variable.h"

OOP_Hw3::Var::Var(std::string name):var(name){}

double OOP_Hw3::Var::Evaluate(const std::map<std::string, double>& variables) const{
return variables.at(var);}

std::list<std::string> OOP_Hw3::Var::Variables() const{
    std::list<std::string> l;
    l.push_back(var);
    return l;
}

SharedPtr<OOP_Hw3::Function> OOP_Hw3::Var::DeriveBy(const std::string& variable) const{
    if(this->var==variable){
        return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Const(1));
    }
    return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Const(0));
}
