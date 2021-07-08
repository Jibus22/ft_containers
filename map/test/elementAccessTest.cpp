#include "map.hpp"
#include "resources.hpp"
#include <map>

///////BRACKET
template <typename Container>
void	bracketTest(Container mapp)
{
	fillmap(mapp, 2);
	_THISTESTIS_("before:", ENDL);
	_PRINT_MAP_CONTENT_(mapp);
	_THISTESTIS_("reaching & printing keys 20 to 40:", ENDL);
	_PRINT_MAP_(mapp);
	for (size_t i = 20; i < 40; i++)
		std::cout << "key " << i <<": " << mapp[i] << ", ";
	std::cout << std::endl;
	_PRINT_MAP_(mapp);
	_THISTESTIS_("after:", ENDL);
	_PRINT_MAP_CONTENT_(mapp);
}

////////MAIN
void	elementAccessTest()
{
	_STITLE_("ELEMENT ACCESS TEST");

	std::map<int, std::string>			stdmapp;
	ft::map<int, std::string>			ftmapp;

	_SSTITLE_("'[]' TEST");
	_STD_TITLE_("(int, std::string)"); bracketTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); bracketTest(ftmapp);
}

/*
 * bracket()
*/
