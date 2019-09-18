#include "Computor.hpp"

Computor::Computor(std::string strInput) : _strInput(strInput)
{
	_a = 0;
	_b = 0;
	_c = 0;
}

Computor::~Computor()
{
}

void Computor::parseString(void)
{
	std::regex rgxValidChar("[0-9 .^*+X=\\-]+");
	std::vector<std::string> strVec;
	int equalIndex;
	int highestDegree = 0;
	

	if (!std::regex_match(_strInput, rgxValidChar))
	{
		throw ("Invalid input");
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
					if (i < 2 || strVec[i - 1] != "*")
					{
						val = 1;
						if (i > 0 && strVec[i - 1] == "-")
							sign *= -1;
					}
					else
						std::stringstream(strVec[i - 2]) >> val;
					reducedVals[j].second += sign * val;
					found = true;
				}
			}
			if (!found)
			{
				sign = (i > 3 && strVec[i - 3] == "-")? -1 * sign: sign;
				if (i < 2 || strVec[i - 1] != "*")
				{
					val = 1;
					if (i > 0 && strVec[i - 1] == "-")
						sign *= -1;
				}
				else
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
	int highestDegree = 0;

	for (auto red : reducedVals)
	{
		if (red.first > highestDegree && red.second != 0.0)
			highestDegree = red.first;
	}
	_degree = highestDegree;
	
	for (size_t i = 0; i <= _degree; i++)
	{
		for (auto mypair : reducedVals)
		{
			if (mypair.first == i && mypair.second != 0.0)
			{
				convert << Tmaths::abs(mypair.second);
				output += ((mypair.second > 0)? "+ " + convert.str() : "- " + convert.str()) + " * X^" + std::to_string(i) + " ";
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
		if (_discriminant >= 0)
			std::cout << "The discriminant is positive" << std::endl;
		else
			std::cout << "The discriminant is negative" << std::endl;
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
	if (_degree == 0)
	{
		if (_c == 0)
			std::cout << "The solution is:" << std::endl << "X is an element of all Real numbers" << std::endl;
		else
			std::cout << "The solution is:" << std::endl << "X is unsolveable" << std::endl;
		
	} else if (_degree <= 2)
	{
		intercept_st intercept = Tmaths::calcIntercept(_a, _b, _c);
		if (intercept.numIntercepts == 0)
		{
			std::cout << "The solution is complex:" << std::endl;
			std::cout << Tmaths::div(-1 * _b, 2 * _a) << " + " << Tmaths::div(Tmaths::sqrt(_discriminant * -1), 2 * _a) << " * i" << std::endl;
			std::cout << Tmaths::div(-1 * _b, 2 * _a) << " - " << Tmaths::div(Tmaths::sqrt(_discriminant * -1), 2 * _a) << " * i" << std::endl;
		} else if (intercept.numIntercepts == 1 || _discriminant == 0)
		{
			std::cout << "The solution is:" << std::endl << intercept.intercepts[0] << std::endl;
		} else if (intercept.numIntercepts == 2)
		{
			std::cout << intercept.intercepts[0] << std::endl << intercept.intercepts[1] << std::endl;
		}
	} else
	{
		std::cout << "The polynomial degree is stricly greater than 2, I can't solve." << std::endl;
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
