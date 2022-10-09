//
//  Operation.h
//  OOP32
//
//  Created by morad sabbah on 20/06/2020.
//  Copyright © 2020 morad sabbah. All rights reserved.
//

#pragma once
#include "Function.h"
#include "Constant.h"
#include "Variable.h"
#include "Operation.h"

namespace OOP_Hw3 {

class Op : public Function
{
    // Represents a node that holds an operator.
    SharedPtr<Function> f1;
    SharedPtr<Function> f2;
    char op;
public:
    Op(SharedPtr<Function> f1, SharedPtr<Function> f2, char op);
    // Constructor.  Create a node to hold the given data.
    virtual ~Op();
    // To get the value, compute the value of the left and
    // right operands, and combine them with the operator.
    double Evaluate(const std::map<std::string, double>& variables) const;
    std::list<std::string> Variables() const;
    SharedPtr<Function> DeriveBy(const std::string& variable) const;
};

}
