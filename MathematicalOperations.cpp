//
//  MathematicalOperations.cpp
//  OOP32
//
//  Created by morad sabbah on 20/06/2020.
//  Copyright © 2020 morad sabbah. All rights reserved.
//

#include "MathematicalOperations.h"

namespace OOP_Hw3 {
SharedPtr<OOP_Hw3::Function> operator+(SharedPtr<OOP_Hw3::Function> f1,SharedPtr<OOP_Hw3::Function> f2){
    return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Op(f1,f2,'+'));
}
SharedPtr<OOP_Hw3::Function> operator-(SharedPtr<OOP_Hw3::Function> f1,SharedPtr<OOP_Hw3::Function> f2){
    return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Op(f1,f2,'-'));
}
SharedPtr<OOP_Hw3::Function> operator*(SharedPtr<OOP_Hw3::Function> f1, SharedPtr<OOP_Hw3::Function> f2){
    return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Op(f1,f2,'*'));
}
SharedPtr<OOP_Hw3::Function> operator/(SharedPtr<OOP_Hw3::Function> f1, SharedPtr<OOP_Hw3::Function> f2){
    return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Op(f1,f2,'/'));
}
SharedPtr<OOP_Hw3::Function> var(const std::string& variableName){
    return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Var(variableName));
}
SharedPtr<OOP_Hw3::Function> cnst(double num){
    return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Const(num));
}

}
