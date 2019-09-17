#include "Tmaths.hpp"
#include "Computor.hpp"
#include <iostream>

int main(int argv, char **args)
{
	if (argv > 1)
	{
		Computor computor(args[1]);
		computor.compute();

		// std::cout.precision(12);
		// std::cout << "add: 10 + 2.7 = " << Tmaths::add(10, 2.7) << std::endl;
		// std::cout << "sub: 10 - 2.7 = " << Tmaths::sub(10, 2.7) << std::endl;
		// std::cout << "mul: 10 * 2.7 = " << Tmaths::mul(10, 2.7) << std::endl;
		// std::cout << std::endl;
		// std::cout << "div: 10 / -3 = " << Tmaths::div(10, -3) << std::endl;
		// std::cout << "actual div: 10 / -3 = " << 10.0 / -3 << std::endl;
		// std::cout << std::endl;
		// std::cout << "power: -2 ^ 3 = " << Tmaths::pow(-2, 3) << std::endl;
		// std::cout << std::endl;
		// std::cout << "sqrt: 10 ^ 0.5 = " << Tmaths::sqrt(10) << std::endl;
		// std::cout << "sqrt: 1 ^ 0.5 = " << Tmaths::sqrt(1) << std::endl;
		// std::cout << "sqrt: 0.1 ^ 0.5 = " << Tmaths::sqrt(0.1) << std::endl;
		// std::cout << "sqrt: 0.01 ^ 0.5 = " << Tmaths::sqrt(0.01) << std::endl;
		// std::cout << "sqrt: -5 ^ 0.5 = " << Tmaths::sqrt(0.00000000000000000000000000000000000000000000000000000000000001) << std::endl;
		// std::cout << std::endl;
		// // x intercepts
		// intercept_st intercept = Tmaths::calcIntercept(-1, 0, 1);
		// std::cout << "roots -x2 + 1:" << std::endl;
		// std::cout << "num intercepts: " << intercept.numIntercepts << std::endl << "intercepts: " << intercept.intercepts[0] << " " << intercept.intercepts[1] << std::endl;
		// std::cout << std::endl;
		// intercept = Tmaths::calcIntercept(0, 1, 1);
		// std::cout << "roots 1x + 1:" << std::endl;
		// std::cout << "num intercepts: " << intercept.numIntercepts << std::endl << "intercepts: " << intercept.intercepts[0] << std::endl;
		// std::cout << std::endl;
		// intercept = Tmaths::calcIntercept(1, 0, 1);
		// std::cout << "roots x2 + 1:" << std::endl;
		// std::cout << "num intercepts: " << intercept.numIntercepts << std::endl;
		// std::cout << std::endl;
	}
}