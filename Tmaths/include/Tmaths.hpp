#ifndef TMATHS_HPP
#define TMATHS_HPP

#include <vector>

struct intercept_st
{
	int numIntercepts;
	std::vector<double> intercepts;
};

class Tmaths
{
private:
	/* data */
public:
	Tmaths(/* args */);
	~Tmaths();

	static double add(double val1, double val2);
	static double sub(double val1, double val2);
	static double mul(double val1, double val2);
	static double div(double dividend, double divisor, int accuracy = 128);
	static double pow(double base, int exponent);
	static double sqrt(double val, double seed = 1, int accuracy = 1024);
	static double abs(double val);

	static intercept_st calcIntercept(double a, double b, double c);
};

#endif