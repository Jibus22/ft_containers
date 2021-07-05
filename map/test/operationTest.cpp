#include "map.hpp"
#include "resources.hpp"
#include <map>

///////REVERSE
template <typename Container>
void	reverseTest(Container lst)
{
	lst.clear();
	fillContainer(lst, 20);
	_THISTESTIS_("reverse a x20 container. before/after:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	lst.reverse();
	_PRINT_LST_CONTENT_(lst);
}

////////MAIN
void	operationTest()
{
	_STITLE_("OPERATION TEST");

	std::map<int>			stdlst;
	ft::map<int>			ftlst;
	std::map<std::string>	stdlst2;
	ft::map<std::string>	ftlst2;

	_SSTITLE_("'REVERSE' TEST");
	/*_STD_TITLE_("(int)"); reverseTest(stdlst);
	_FT_TITLE_("(int)"); reverseTest(ftlst);
	_STD_TITLE_("(str)"); reverseTest(stdlst2);
	_FT_TITLE_("(str)"); reverseTest(ftlst2);*/
}

/*
*/
