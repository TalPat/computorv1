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
};