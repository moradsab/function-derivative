//
//  Operation.cpp
//  OOP32
//
//  Created by morad sabbah on 20/06/2020.
//  Copyright © 2020 morad sabbah. All rights reserved.
//

#include "Operation.h"
#include "Constant.h"

OOP_Hw3::Op::Op(SharedPtr<Function> f1, SharedPtr<Function> f2, char op) :f1(f1), f2(f2), op(op) {}

OOP_Hw3::Op::~Op(){}

double OOP_Hw3::Op::Evaluate(const std::map<std::string, double>& variables) const{
    double f1eval=f1->Evaluate(variables);
    double f2eval=f2->Evaluate(variables);
    switch(op){
        case '+': return f1eval+f2eval;
        case '-': return f1eval-f2eval;
        case '*': return f1eval*f2eval;
        case '/': return f1eval/f2eval;
    }
    return 0;
}

std::list<std::string> OOP_Hw3::Op::Variables() const{
    std::list<std::string> l1=this->f1->Variables();
    std::list<std::string> l2=this->f2->Variables();
    std::list<std::string> l;
    l1.sort();l2.sort();
    l.merge(l1);
    l.merge(l2);
    l.unique();
    return l;
}

SharedPtr<OOP_Hw3::Function> OOP_Hw3::Op::DeriveBy(const std::string& variable) const{
    SharedPtr<OOP_Hw3::Function> f1=this->f1->DeriveBy(variable);
    SharedPtr<OOP_Hw3::Function> f2=this->f2->DeriveBy(variable);
    SharedPtr<OOP_Hw3::Function> f3(new OOP_Hw3::Op(f1,this->f2,'*'));
    SharedPtr<OOP_Hw3::Function> f4(new OOP_Hw3::Op(this->f1,f2,'*'));
    switch(op){
        case '+': return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Op(f1,f2,'+'));
        case '-': return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Op(f1,f2,'-'));
        case '*':
            return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Op(f3,f4,'+'));
        case '/':
            SharedPtr<OOP_Hw3::Function> f5(new OOP_Hw3::Op(f3,f4,'-'));
            SharedPtr<OOP_Hw3::Function> f6(new OOP_Hw3::Op(this->f2,this->f2,'*'));
            return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Op(f5,f6,'/'));
    }
    return SharedPtr<OOP_Hw3::Function>(new OOP_Hw3::Const(0));
}
