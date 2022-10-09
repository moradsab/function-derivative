//
//  Variable.h
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
class Var : public Function {
    // Represents a node that holds a variable.  (The
    // ": public Function" says that this class is
    // a subclass of Function.)
    std::string var; //variable name
public:
    Var(std::string name);
    double Evaluate(const std::map<std::string, double>& variables) const;
    std::list<std::string> Variables() const;
    SharedPtr<Function> DeriveBy(const std::string& variable) const;
};
}



