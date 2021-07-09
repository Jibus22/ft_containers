#include "map.hpp"
#include "resources.hpp"
#include <map>

///////CONSTRUCTORS
template <typename Container>
void	constructorsTest(Container mapp)
{
	Container				mapp2(mapp.begin(), mapp.end());
	typename Container::iterator		it1;

	_THISTESTIS_("mapp1. copy constructor mapp (x20):    ", NOENDL);
	_PRINT_MAP_(mapp);
	_PRINT_MAP_CONTENT_(mapp);
	_THISTESTIS_("mapp2. fill iterator constructor (x20):", NOENDL);
	_PRINT_MAP_(mapp2);
	_PRINT_MAP_CONTENT_(mapp2);
	it1 = mapp2.begin();
	for (size_t i = 0; i < 10; i++, it1++);
	mapp2.erase(it1, mapp2.end());
	_THISTESTIS_("mapp1 then mapp2 after deleting half of mapp2:", ENDL);
	_PRINT_MAP_(mapp);
	_PRINT_MAP_(mapp2);
}

///////OBERVERS
template <typename Container>
void	observersTest(Container mapp)
{
	typename Container::key_compare	mycomp = mapp.key_comp();
	typename Container::iterator	it1, it2;

	it1 = mapp.end();
	it2 = mapp.begin();
	for (size_t i = 0; i < 5; i++, it1--);
	while (mycomp(it2->first, it1->first))
		it2++;
	_THISTESTIS_("testing to stop iteration to end-5 with key_comp():", ENDL);
	_DISPLAY_MAP_NODE_(it2);

	_THISTESTIS_("same but with value_comp():", ENDL);
	it2 = mapp.begin();
	while (mapp.value_comp()(*it2, *it1))
		it2++;
	_DISPLAY_MAP_NODE_(it2);
}

////////MAIN
void	otherTest()
{
	_STITLE_("MODIFIERS TEST");

	std::map<int, std::string>			stdmapp;
	ft::map<int, std::string>			ftmapp;

	fillmap(stdmapp, 1);
	fillmap(ftmapp, 1);

	_SSTITLE_("'CONSTRUCTORS' TEST");
	_STD_TITLE_("(int, std::string)"); constructorsTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); constructorsTest(ftmapp);

	_SSTITLE_("'OBSERVERS' TEST");
	_STD_TITLE_("(int, std::string)"); observersTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); observersTest(ftmapp);
}

/*
 * constructors
*/
