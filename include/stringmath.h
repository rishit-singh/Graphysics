#pragma once

#define STRINGMATH_H
#define STRINGMATH_H

#include <iostream>
#include <stack>

namespace Math
{
	enum Operations //to make it accessible to all classes
	{
		Sum,
		Difference,
		Product, 
		Quetient,
		Exponential,
		Trigonometric,
		Derivative,
		Integral 
	};

	enum SolutionProperty
	{
		Distributive, 
		Associative
	};

	typedef char* Term;

	typedef struct {
		stack <Term> Terms; 
		stack <Operations> Operation;
		char* ExpressionString;
	} Expression;

	typedef struct {
		stack <Expression> LHS, RHS;
		char* EquationString;		
	} Equation;

	class MathAlgorithms
	{
	private:
		enum DerivativeRule 
		{
			Product, 
			Quetient
		};

	public:
		static DerivativeRule GetDervitaiveRule(Expression);
		static Equation GetDerivatve(Equation equation);
	};
	
	class ExpressionOperations
	{
	public:
		static Operations GetOperationType(Expression);
		static Expression Solve(Expression, Operations);
		static char* GenerateExpressionString(Expression);
	};

	class EquationOperations
	{
	public:
		static char* GenerateEquationString(Equation);
		static char* Solve(char* RawEquationString);
	}
};