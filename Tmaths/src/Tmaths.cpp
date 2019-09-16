#include "Tmaths.hpp"

Tmaths::Tmaths(/* args */)
{
}

Tmaths::~Tmaths()
{
}

double Tmaths::add(double val1, double val2)
{
	return (val1 + val2);
}

double Tmaths::sub(double val1, double val2)
{
	return (val1 + (-1 * val2));
}

double Tmaths::mul(double val1, double val2)
{
	return (val1 * val2);
}

double Tmaths::div(double dividend, double divisor, int accuracy)
{
	double quotient = 0.0;
	int sign = 1;

	if (dividend * divisor < 0)
		sign = -1;
	dividend = abs(dividend);
	divisor = abs(divisor);

	if (divisor == 0)
	{
		throw("div by 0");
	}

	while (dividend > divisor)
	{
		dividend = sub(dividend, divisor);
		quotient += 1;
	}

	if (accuracy > 0 && dividend != 0)
	{
		quotient += div(dividend * 10, divisor, sub(accuracy ,1)) * 0.1;
	}

	return (quotient * sign);
}

double Tmaths::pow(double base, int exponent)
{
	double val = 1;
	
	if (exponent > 0)
	{
		for (unsigned int i = 0; i < exponent; i++)
		{
			val *= base;
		}
	}
	else
	{
		for (int i = exponent; i < 0; i++)
		{
			val *= div(1, base);
		}
	}
	return (val);
}

double Tmaths::sqrt(double val, double seed, int accuracy)
{
	double high = seed;
	double low = 0;
	double average;

	while (high * high < val)
	{
		low = high;
		high = high * 2;
	}
	
	for (unsigned int i = 0; i < accuracy; i++)
	{
		average = div(low + high, 2);
		if ((average * average) > val)
		{
			high = average;
		} else if (average * average < val)
		{
			low = average;
		}
		else
			return (average);
	}

	return (average);
}

double Tmaths::abs(double val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}
