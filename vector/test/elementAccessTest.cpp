#include "vector.hpp"
#include "resources.hpp"
#include <vector>

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	atTest(Container<Element, Allocator> vec)
{
	//typedef Container<Element, Allocator>	container;

	_THISTESTIS_("making wrong 'at': try to reach 30th in empty vector:");
	try {vec.at(30);}
	catch (std::out_of_range & e) {std::cout << e.what() << std::endl;}
	std::cout << "NORMAL" << std::endl;
}

template <template <typename, typename> class Container,
		typename Allocator>
void	atTest(Container<std::string, Allocator> vec)
{
	//typedef Container<Element, Allocator>	container;

	_THISTESTIS_("making wrong 'at': try to reach 30th in empty vector:");
	try {vec.at(30);}
	catch (std::out_of_range & e) {std::cout << e.what() << std::endl;}
	std::cout << "STRING" << std::endl;
}

void	elementAccessTest()
{
	_STITLE_("ELEMENT ACCESS TEST");

	std::vector<int>			stdvec;
	ft::vector<int>				ftvec;
	std::vector<std::string>	stdvec2;
	ft::vector<std::string>		ftvec2;

	_SSTITLE_("'AT' TEST");
	_STD_TITLE_("(int)"); atTest(stdvec);
	_FT_TITLE_("(int)"); atTest(ftvec);
	_STD_TITLE_("(str)"); atTest(stdvec2);
	_FT_TITLE_("(str)"); atTest(ftvec2);
}

/*
 * operator []
 * at()
 * front()
 * back()
*/
