#ifndef COMPUTOR_HPP
#define COMPUTOR_HPP

#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include "Tmaths.hpp"

class Computor
{
private:
	std::string _strInput;
	double _a = 0;
	double _b = 0;
	double _c = 0;
	int _degree;
	double _discriminant;
public:
	Computor(std::string strInput);
	~Computor();

	void parseString(void);
	void calcDiscriminant(double a, double b, double c);
	double getDiscriminant(void);
};

#endif
