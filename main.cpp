#include<iostream>
#include "area.h"
#include <random>
int main() {
	//int a, b;
	//std::cin >>  a;
	//std::cin >> b;
	//double c=0.1, d=1.4;
	//int res = just::area(a, b);
	//double res2 = just::area(c, d);
	//int res_rund = Modify::area(c);
	//std::cout << res << "\n";
	//std::cout << res2 << "\n";
	//std::cout << a << "\n";
	//std::cout << "rand " << res_rund <<std::endl;
	std::cout << just::area<double>(2, 3) << "\n";
	std::cout << Modify::area<int>(3, 4) << std::endl;

	return 0;
}