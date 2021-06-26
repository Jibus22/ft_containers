#include "queue.hpp"
#include "resources.hpp"
#include <queue>

//////////BACK
template <template <typename, typename> class Container,
		typename Element, typename Containr>
void	backTest(Container<Element, Containr> vec)
{
	_THISTESTIS_("print of 5 back after 5 != push:", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainr(vec, i + 1);
		std::cout << vec.back();
	}
	std::cout << std::endl;
}

//////////FRONT
template <template <typename, typename> class Container,
		typename Element, typename Containr>
void	frontTest(Container<Element, Containr> vec)
{
	_THISTESTIS_("print of 5 front after 5 pop:", NOENDL);
	fillContainr(vec, 5);
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << vec.front();
		vec.pop();
	}
	std::cout << std::endl;
}

////////MAIN
void	elementAccessTest()
{
	_STITLE_("ELEMENT ACCESS TEST");

	std::queue<int>			stdvec;
	ft::queue<int>			ftvec;
	std::queue<std::string>	stdvec2;
	ft::queue<std::string>	ftvec2;

	_SSTITLE_("'BACK' TEST");
	_STD_TITLE_("(int)"); backTest(stdvec);
	_FT_TITLE_("(int)"); backTest(ftvec);
	_STD_TITLE_("(str)"); backTest(stdvec2);
	_FT_TITLE_("(str)"); backTest(ftvec2);

	_SSTITLE_("'FRONT' TEST");
	_STD_TITLE_("(int)"); frontTest(stdvec);
	_FT_TITLE_("(int)"); frontTest(ftvec);
	_STD_TITLE_("(str)"); frontTest(stdvec2);
	_FT_TITLE_("(str)"); frontTest(ftvec2);
}

/*
 * back()
 * front()
*/
