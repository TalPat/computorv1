#include "Computor.hpp"

Computor::Computor(std::string strInput) : _strInput(strInput)
{
}

Computor::~Computor()
{
}

void Computor::parseString(void)
{
	std::string left, right;
	std::regex rgxValidChar("[0-9 .^*-+X]+=");
	std::regex rgxLeft("^([^=]*)=");
	std::regex rgxRight("=(.*)");
	std::vector<std::string> strVec;

	if (!std::regex_match(_strInput, rgxValidChar))
		throw ("Invalid input");
	while (_strInput.find(" ") == std::string::npos)
	{
		strVec.push_back(_strInput.substr(0, _strInput.find(" ")));
		_strInput.erase(0, _strInput.find(" ") + 1);
	}
	strVec.push_back(_strInput);
	/*-------------------------------*/
	for (std::string s : strVec)
	{
		std::cout << s << std::endl;
	}
	/*-------------------------------*/

}

void Computor::calcDiscriminant(double a, double b, double c)
{
	_discriminant = Tmaths::sub(Tmaths::pow(b, 2),4 * a * c);
}

double Computor::getDiscriminant(void)
{
	return (_discriminant);
}
