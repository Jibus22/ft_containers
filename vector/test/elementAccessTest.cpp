#include "vector.hpp"
#include "resources.hpp"
#include <vector>

void	atTest()
{
	_SSTITLE_("'AT' TEST");
	std::vector<int>	stdvec;
	ft::vector<int>		ftvec;

	_THISTESTIS_("making wrong 'at': try to reach 30th in empty vector:");
	_STD_BOX_();
	try {stdvec.at(30);}
	catch (std::out_of_range & e) {std::cout << e.what() << std::endl;}
	_FT_BOX_();
	try {ftvec.at(30);}
	catch (std::out_of_range & e) {std::cout << e.what() << std::endl;}
}

void	elementAccessTest()
{
	_SSTITLE_("ELEMENT ACCESS TEST");
	atTest();
}

/*
 * operator []
 * at()
 * front()
 * back()
*/
