#include "list.hpp"
#include "resources.hpp"
#include <list>

////////////AT
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	atTest(Container<Element, Allocator> lst)
{
	_THISTESTIS_("wrong 'at': try to reach 30th in empty list:   ", NOENDL);
	try {lst.at(30);}
	catch (std::out_of_range & e) {std::cout << e.what() << std::endl;}
	_THISTESTIS_("wrong 'at': try to reach 0th in empty list:    ", NOENDL);
	try {lst.at(30);}
	catch (std::out_of_range & e) {std::cout << e.what() << std::endl;}

	_THISTESTIS_("reaching & printing 5 first elem of a list(10):", NOENDL);
	fillContainer(lst, 10);
	std::cout << lst.at(0) << lst.at(1) << lst.at(2) << lst.at(3) << lst.at(4)
	<< std::endl;

	_THISTESTIS_("reaching & printing 5 last elem of a list(10): ", NOENDL);
	fillContainer(lst, 10);
	std::cout << lst.at(5) << lst.at(6) << lst.at(7) << lst.at(8) << lst.at(9)
	<< std::endl;
}

///////BRACKET
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	bracketTest(Container<Element, Allocator> lst)
{
	_THISTESTIS_("reaching & printing 5 first elem of a list(10):", NOENDL);
	fillContainer(lst, 10);
	std::cout << lst[0] << lst[1] << lst[2] << lst[3] << lst[4]
	<< std::endl;

	_THISTESTIS_("reaching & printing 5 last elem of a list(10): ", NOENDL);
	fillContainer(lst, 10);
	std::cout << lst[5] << lst[6] << lst[7] << lst[8] << lst[9]
	<< std::endl;
}

/////////FRONT
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	frontTest(Container<Element, Allocator> lst)
{
	_THISTESTIS_("print of 5 front after 5 != push:", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainer(lst, i + 1);
		std::cout << lst.front();
	}
	std::cout << std::endl;
}

//////////BACK
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	backTest(Container<Element, Allocator> lst)
{
	_THISTESTIS_("print of 5 back after 5 != push:", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainer(lst, i + 1);
		std::cout << lst.back();
	}
	std::cout << std::endl;
}

////////MAIN
void	elementAccessTest()
{
	_STITLE_("ELEMENT ACCESS TEST");

	std::list<int>			stdlst;
	ft::list<int>			ftlst;
	std::list<std::string>	stdlst2;
	ft::list<std::string>	ftlst2;

	_SSTITLE_("'AT' TEST");
	/*_STD_TITLE_("(int)"); atTest(stdlst);
	_FT_TITLE_("(int)"); atTest(ftlst);
	_STD_TITLE_("(str)"); atTest(stdlst2);
	_FT_TITLE_("(str)"); atTest(ftlst2);*/

	_SSTITLE_("'[]' TEST");
	/*_STD_TITLE_("(int)"); bracketTest(stdlst);
	_FT_TITLE_("(int)"); bracketTest(ftlst);
	_STD_TITLE_("(str)"); bracketTest(stdlst2);
	_FT_TITLE_("(str)"); bracketTest(ftlst2);*/

	_SSTITLE_("'FRONT' TEST");
	/*_STD_TITLE_("(int)"); frontTest(stdlst);
	_FT_TITLE_("(int)"); frontTest(ftlst);
	_STD_TITLE_("(str)"); frontTest(stdlst2);
	_FT_TITLE_("(str)"); frontTest(ftlst2);*/

	_SSTITLE_("'BACK' TEST");
	/*_STD_TITLE_("(int)"); backTest(stdlst);
	_FT_TITLE_("(int)"); backTest(ftlst);
	_STD_TITLE_("(str)"); backTest(stdlst2);
	_FT_TITLE_("(str)"); backTest(ftlst2);*/

	(void)stdlst;
	(void)stdlst2;
	(void)ftlst;
	(void)ftlst2;
}

/*
 * operator []
 * at()
 * front()
 * back()
*/
