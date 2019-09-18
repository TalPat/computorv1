#include "Tmaths.hpp"
#include "Computor.hpp"
#include <iostream>

int main(int argv, char **args)
{
	if (argv > 1)
	{
		Computor computor(args[1]);

		try
		{
			computor.compute();
		}
		catch(const char* e)
		{
			std::cerr << e << std::endl;;
		}
		
	}
}