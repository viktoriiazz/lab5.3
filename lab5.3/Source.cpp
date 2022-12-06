#include <iostream>
#include <cmath>
using namespace std;
double p(const double x);
int main()
{
	double qp, qk, z;
	int n;
	cout << "qp = "; cin >> qp;
	cout << "qk = "; cin >> qk;
	cout << "n = "; cin >> n;

	double dq = (qk - qp) / n;
	double q = qp;

	while (q <= qk)
	{
		z = (p(2 * q + 1) + p(q * q - 1) + sqrt(p(1)));
		cout << q << " " << z << endl;
		q += dq;
	}
	return 0;
}

double p(const double x)
{
	if (abs(x) >= 1)
		return ((sin(x) + cos(x)) / sin(x) * sin(x) + exp(x));
	else
	{
		double S = 0;
		int j = 0;
		double a = 1;
		S = a;
		do
		{
			j++;
			double R = -x * x / ((3 * j - 2) * (3 * j - 1) * 3 * j);
			a *= R;
			S += a;
		} while (j < 4);
		return S;
	}
}

