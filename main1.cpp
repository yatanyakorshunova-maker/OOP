#include <iostream>
#include <random>
#include <string>





namespace Modify{
	int area(int a) {
		int rand_num = std::random_device{}()%100+1;
		return a * rand_num;

	}
}