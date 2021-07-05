#include "map.hpp"
#include "resources.hpp"
#include <map>

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

////////MAIN
void	otherTest()
{
	_STITLE_("MODIFIERS TEST");

	std::map<int>			stdlst;
	ft::map<int>			ftlst;
	std::map<std::string>	stdlst2;
	ft::map<std::string>	ftlst2;

	_SSTITLE_("'CONSTRUCTORS' TEST");
	/*_STD_TITLE_("(int)"); constructorsTest(stdlst);
	_FT_TITLE_("(int)"); constructorsTest(ftlst);
	_STD_TITLE_("(str)"); constructorsTest(stdlst2);
	_FT_TITLE_("(str)"); constructorsTest(ftlst2);

	_THISTESTIS_("", ENDL);
	_THISTESTIS_("Note: copy constructor and basic constructor are used ", ENDL);
	_THISTESTIS_("all along the tests", ENDL);
	_THISTESTIS_("", ENDL);*/
}

/*
 * constructors
 * relational operators
 * swap
*/
