//
//  Function.h
//  OOP32
//
//  Created by morad sabbah on 20/06/2020.
//  Copyright © 2020 morad sabbah. All rights reserved.
//

#pragma once
#include "SharedPtr.h"
#include <map>
#include <list>

namespace OOP_Hw3{

class Function
{
    // Represents a node of any type in an expression tree.
    // This is an "abstract" class, since it contains an undefined
    // function, Evaluate(), that must be defined in subclasses.
    // The word "virtual" says that the defintion can change
    // in a subclass.  The "= 0" says that this function has
    // no definition in this class.
public:
    virtual ~Function();
    virtual double Evaluate(const std::map<std::string, double>& variables) const=0;
    virtual std::list<std::string> Variables() const=0;
    virtual SharedPtr<Function> DeriveBy(const std::string& variable) const=0;
    std::map<std::string, std::map<std::string, SharedPtr<Function>>> Hessian() const;
};
}
