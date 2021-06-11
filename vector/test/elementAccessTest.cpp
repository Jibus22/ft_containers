#include "vector.hpp"
#include "resources.hpp"
#include <vector>

void	atTest()
{
	subsubTitle("'AT' TEST");
	std::vector<int>	stdvec;
	ft::vector<int>		ftvec;

	thisTestIs("making wrong 'at': try to reach 30th in empty vector:");
	_STD_;
	try {stdvec.at(30);}
	catch (std::out_of_range & e) {std::cout << e.what() << std::endl;}
	_FT_;
	try {ftvec.at(30);}
	catch (std::out_of_range & e) {std::cout << e.what() << std::endl;}
}

void	elementAccessTest()
{
	subTitle("ELEMENT ACCESS TEST");
	atTest();
}

/*
 * operator []
 * at()
 * front()
 * back()
*/
