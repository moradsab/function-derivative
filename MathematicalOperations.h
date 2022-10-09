#pragma once

#include "SharedPtr.h"
#include "Function.h"
#include "Constant.h"
#include "Variable.h"
#include "Operation.h"

namespace OOP_Hw3
{
	SharedPtr<Function> operator+(SharedPtr<Function> f1, SharedPtr<Function> f2);
	SharedPtr<Function> operator-(SharedPtr<Function> f1, SharedPtr<Function> f2);
	SharedPtr<Function> operator*(SharedPtr<Function> f1, SharedPtr<Function> f2);
	SharedPtr<Function> operator/(SharedPtr<Function> f1, SharedPtr<Function> f2);

	SharedPtr<Function> var(const std::string& variableName);
	SharedPtr<Function> cnst(double num);
}
