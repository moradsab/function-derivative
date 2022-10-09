//
//  Constant.h
//  OOP32
//
//  Created by morad sabbah on 20/06/2020.
//  Copyright © 2020 morad sabbah. All rights reserved.
//

#pragma once
#include "Function.h"

namespace OOP_Hw3 {
class Const : public Function
{
    // Represents a node that holds a number.  (The
    // ": public Function" says that this class is
    // a subclass of Function.)
    double cnst;  // The number in the node.
public:
    Const(double value);
    double Evaluate(const std::map<std::string, double>& variables) const;
    std::list<std::string> Variables() const;
    SharedPtr<Function> DeriveBy(const std::string& variable) const;
};
}
