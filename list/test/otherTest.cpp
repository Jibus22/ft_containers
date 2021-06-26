#include "list.hpp"
#include "resources.hpp"
#include <list>

///////CONSTRUCTORS
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	constructorsTest(Container<Element, Allocator> lst)
{
	typedef Container<Element, Allocator>	container;

	container		l1(200, 42);
	fillContainer(lst, 500);
	container		l2(lst.begin(), lst.end());

	_THISTESTIS_("show fill constructor l(200,42):", NOENDL);
	_PRINT_LST_(l1);
	_THISTESTIS_("show iterator constructor      :", NOENDL);
	_PRINT_LST_(l2);
}
template <template <typename, typename> class Container,
		typename Allocator>
void	constructorsTest(Container<std::string, Allocator> lst)
{
	typedef Container<std::string, Allocator>	container;

	container		l1(200, "bla");
	fillContainer(lst, 500);
	container		l2(lst.begin(), lst.end());

	_THISTESTIS_("show fill constructor l(200,bla):", NOENDL);
	_PRINT_LST_(l1);
	_THISTESTIS_("show iterator constructor       :", NOENDL);
	_PRINT_LST_(l2);
}

///////RELATIONAL OPERATORS
template <typename Container>
void	relationaloperatorsTest(Container lst)
{
	Container	a;
	Container	b;
	Container	c;

	fillContainer(a, 400);
	fillContainer(b, 400);
	fillContainer(c, 500);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";
	(void)lst;
}

///////SWAP OVERLOAD
template <typename Container>
void	swapOverloadTest(Container lst)
{
	Container	lst2;

	fillContainer(lst, 400);
	fillContainer(lst2, 4000);

	_THISTESTIS_("lst before :", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("lst2 before:", NOENDL);
	_PRINT_LST_(lst2);

	ft::swap(lst, lst2);

	_THISTESTIS_("lst after  :", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("lst2 after :", NOENDL);
	_PRINT_LST_(lst2);
}

////////MAIN
void	otherTest()
{
	_STITLE_("MODIFIERS TEST");

	std::list<int>			stdlst;
	ft::list<int>			ftlst;
	std::list<std::string>	stdlst2;
	ft::list<std::string>	ftlst2;

	_SSTITLE_("'CONSTRUCTORS' TEST");
	_STD_TITLE_("(int)"); constructorsTest(stdlst);
	_FT_TITLE_("(int)"); constructorsTest(ftlst);
	_STD_TITLE_("(str)"); constructorsTest(stdlst2);
	_FT_TITLE_("(str)"); constructorsTest(ftlst2);

	_THISTESTIS_("", ENDL);
	_THISTESTIS_("Note: copy constructor and basic constructor are used ", ENDL);
	_THISTESTIS_("all along the tests", ENDL);
	_THISTESTIS_("", ENDL);

	_SSTITLE_("'RELATIONAL OPERATORS' TEST");
	_STD_TITLE_("(int)"); relationaloperatorsTest(stdlst);
	_FT_TITLE_("(int)"); relationaloperatorsTest(ftlst);
	_STD_TITLE_("(str)"); relationaloperatorsTest(stdlst2);
	_FT_TITLE_("(str)"); relationaloperatorsTest(ftlst2);

	_SSTITLE_("'SWAP OVERLOAD' TEST");
	_STD_TITLE_("(int)"); swapOverloadTest(stdlst);
	_FT_TITLE_("(int)"); swapOverloadTest(ftlst);
	_STD_TITLE_("(str)"); swapOverloadTest(stdlst2);
	_FT_TITLE_("(str)"); swapOverloadTest(ftlst2);
}

/*
 * constructors
 * relational operators
 * swap
*/
