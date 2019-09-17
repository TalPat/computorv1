#include "Computor.hpp"

Computor::Computor(std::string strInput) : _strInput(strInput)
{
}

Computor::~Computor()
{
}

void Computor::parseString(void)
{
	std::regex rgxValidChar("[0-9 .^*-+X]+=");
	std::vector<std::string> strVec;
	int equalIndex;
	int highestDegree = 0;
	

	if (!std::regex_match(_strInput, rgxValidChar))
	{
		// throw ("Invalid input");
	}

	while (_strInput.find(" ") != std::string::npos)
	{
		strVec.push_back(_strInput.substr(0, _strInput.find(" ")));
		_strInput.erase(0, _strInput.find(" ") + 1);
	}
	strVec.push_back(_strInput);

	for (size_t i = 0; i < strVec.size(); i++)
	{
		if (strVec[i] == "=")
			equalIndex = i;
	}
	for (size_t i = 0; i < strVec.size(); i++)
	{
		int sign = ((i > equalIndex)? -1 : 1);
		double val;

		if (strVec[i].find("X^") != std::string::npos)
		{
			bool found = false;

			if (highestDegree < std::strtol(strVec[i].c_str() + 2, NULL, 10) && (i > 1 && strVec[i - 2] != "0"))
			{
				highestDegree = std::strtol(strVec[i].c_str() + 2, NULL, 10);
			}
			for (size_t j = 0; j < reducedVals.size(); j++)
			{
				if (reducedVals[j].first == std::strtol(strVec[i].c_str() + 2, NULL, 10))
				{
					sign = (i > 3 && strVec[i - 3] == "-")? -1 * sign: sign;
					std::stringstream(strVec[i - 2]) >> val;
					reducedVals[j].second += sign * val;
					found = true;
				}
			}
			if (!found)
			{
				sign = (i > 3 && strVec[i - 3] == "-")? -1 * sign: sign;
				std::stringstream(strVec[i - 2]) >> val;
				reducedVals.push_back(std::pair<int, float>(std::strtol(strVec[i].c_str() + 2, NULL, 10), sign * val));
			}
		}
	}
	_degree = highestDegree;
}

void Computor::setCoeficients(void)
{
	for (auto mypair : reducedVals)
	{
		if (mypair.first == 0) _c = mypair.second;
		if (mypair.first == 1) _b = mypair.second;
		if (mypair.first == 2) _a = mypair.second;
	}
}

void Computor::calcDiscriminant(void)
{
	_discriminant = Tmaths::sub(Tmaths::pow(_b, 2),4 * _a * _c);
}

void Computor::displayReduced(void)
{
	std::ostringstream convert;
	std::string output;
	
	for (size_t i = 0; i <= _degree; i++)
	{
		for (auto mypair : reducedVals)
		{
			if (mypair.first == i)
			{
				convert << Tmaths::abs(mypair.second);
				if (reducedVals[0] == mypair)
				{
					output += ((mypair.second > 0)? convert.str() : convert.str()) + " * X^" + std::to_string(i) + " ";
				} else {
					output += ((mypair.second > 0)? "+ " + convert.str() : "- " + convert.str()) + " * X^" + std::to_string(i) + " ";
				}
				convert.str("");
			}
		}	
	}

	if (reducedVals.size() > 0)
	{
		output += "= 0"; 
		std::cout << "Reduced form: " << output << std::endl;
	}
}

void Computor::displayDisc(void)
{
	if (_degree == 2)
	{
		std::cout << "Discriminant: " << _discriminant << std::endl;
	}
}

void Computor::displayDegree(void)
{
	if (reducedVals.size() > 0)
	{
		std::cout << "Polynomial degree: " << _degree << std::endl;
	}
}

void Computor::displaySolution(void)
{
	intercept_st intercept = Tmaths::calcIntercept(_a, _b, _c);
	if (intercept.numIntercepts == 1)
	{
		std::cout << "The solution is:" << std::endl << intercept.intercepts[0] << std::endl;
	}
	if (intercept.numIntercepts == 2)
	{
		std::cout << intercept.intercepts[0] << std::endl << intercept.intercepts[1] << std::endl;
	}
}

void Computor::compute(void)
{
	parseString();
	setCoeficients();
	calcDiscriminant();
	displayReduced();
	displayDisc();
	displayDegree();
	displaySolution();
}
