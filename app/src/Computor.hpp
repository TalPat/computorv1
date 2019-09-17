#ifndef COMPUTOR_HPP
#define COMPUTOR_HPP

#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <sstream>
#include <utility>
#include "Tmaths.hpp"

class Computor
{
private:
	std::string _strInput;
	std::vector<std::pair<int, float>> reducedVals; //int is degree, float is reduced coeficcient
	int _degree;
	double _a, _b, _c;
	double _discriminant;
	void calcDiscriminant(void);
	void parseString(void);
	void displayReduced(void);
	void displayDisc(void);
	void displayDegree(void);
	void displaySolution(void);
	void setCoeficients(void);
public:
	Computor(std::string strInput);
	~Computor();

	void compute(void);
};

#endif
