#include "stack.hpp"
#include "resources.hpp"
#include <stack>

//////////TOP
template <template <typename, typename> class Container,
		typename Element, typename Containr>
void	topTest(Container<Element, Containr> vec)
{
	_THISTESTIS_("print of 5 top after 5 != push:", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainr(vec, i + 1);
		std::cout << vec.top();
	}
	std::cout << std::endl;
}

////////MAIN
void	elementAccessTest()
{
	_STITLE_("ELEMENT ACCESS TEST");

	std::stack<int>			stdvec;
	ft::stack<int>			ftvec;
	std::stack<std::string>	stdvec2;
	ft::stack<std::string>	ftvec2;

	_SSTITLE_("'TOP' TEST");
	_STD_TITLE_("(int)"); topTest(stdvec);
	_FT_TITLE_("(int)"); topTest(ftvec);
	_STD_TITLE_("(str)"); topTest(stdvec2);
	_FT_TITLE_("(str)"); topTest(ftvec2);
}

/*
 * top()
*/
