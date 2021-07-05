#include "map.hpp"
#include "resources.hpp"
#include <map>

///////BRACKET
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	bracketTest(Container<Element, Allocator> vec)
{
	_THISTESTIS_("reaching & printing 5 first elem of a vector(10):", NOENDL);
	fillContainer(vec, 10);
	std::cout << vec[0] << vec[1] << vec[2] << vec[3] << vec[4]
	<< std::endl;

	_THISTESTIS_("reaching & printing 5 last elem of a vector(10): ", NOENDL);
	fillContainer(vec, 10);
	std::cout << vec[5] << vec[6] << vec[7] << vec[8] << vec[9]
	<< std::endl;
}

////////MAIN
void	elementAccessTest()
{
	_STITLE_("ELEMENT ACCESS TEST");

	std::map<int>			stdlst;
	ft::map<int>			ftlst;
	std::map<std::string>	stdlst2;
	ft::map<std::string>	ftlst2;

	_SSTITLE_("'[]' TEST");
	/*_STD_TITLE_("(int)"); bracketTest(stdvec);
	_FT_TITLE_("(int)"); bracketTest(ftvec);
	_STD_TITLE_("(str)"); bracketTest(stdvec2);
	_FT_TITLE_("(str)"); bracketTest(ftvec2);*/
}

/*
 * bracket()
*/
