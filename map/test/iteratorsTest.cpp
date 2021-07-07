#include "map.hpp"
#include "resources.hpp"
#include <map>
#include <utility>

///////BEGIN
template <typename Container>
void	beginTest(Container mapp)
{
	_THISTESTIS_("iterate begin to end thru a map of ~200 elements", ENDL);
	fillmap(mapp, 10);
	_PRINT_MAP_CONTENT_(mapp);
}

///////END
template <typename Container>
void	endTest(Container mapp)
{
	typedef typename Container::iterator			iterator;

	Container		mapp2;
	iterator		it;

	fillmap(mapp, 1);
	it = mapp.end();
	it--;
	_THISTESTIS_("end-1 of x20:   ", NOENDL);
	_DISPLAY_MAP_NODE_(it);
	fillmap(mapp2, 10);
	_THISTESTIS_("end-1 of x180:  ", NOENDL);
	it = mapp2.end();
	it--;
	_DISPLAY_MAP_NODE_(it);
}

///////RBEGIN
template <typename Container>
void	rbeginTest(Container mapp)
{
	typedef typename Container::reverse_iterator	reverse_iterator;
	typedef typename Container::iterator			iterator;
	reverse_iterator		it;
	reverse_iterator		it2;

	fillmap(mapp, 20);
	_THISTESTIS_("rbegin of x20:  ", NOENDL);
	it = mapp.rbegin();
	std::cout << " " << *it << std::endl;
	fillmap(mapp, 10);
	it2 = mapp.rbegin();
	_THISTESTIS_("begin of x30:   ", NOENDL);
	std::cout << " " << *it2 << std::endl;

	_THISTESTIS_("assignation '=' and", ENDL);
	it = it2;
	_THISTESTIS_("comparison != : ", NOENDL);
	if (it != it2)
		std::cout << " it != it2" << std::endl;
	else
		std::cout << " it == it2" << std::endl;

	//mapp.clear();
	fillmap(mapp, 10);
	_THISTESTIS_("reverse print : ", NOENDL);
	for (reverse_iterator i = mapp.rbegin(); i != mapp.rend(); i++)
		std::cout << " " << *i << ", ";
	std::cout << std::endl;

	_THISTESTIS_("iterator construction:", NOENDL);
	iterator	itt;
	itt = mapp.begin();
	reverse_iterator	bla(itt);
	std::cout << " " << *itt << std::endl;
}

///////REND
template <typename Container>
void	rendTest(Container mapp)
{
	typedef typename Container::reverse_iterator	reverse_iterator;
	reverse_iterator		it;

	_THISTESTIS_("print rbegin to rend:", NOENDL);
	fillmap(mapp, 10);
	for (reverse_iterator i = mapp.rbegin(); i != mapp.rend(); i++)
		std::cout << " " << *i << " ";
	std::cout << std::endl;
	_THISTESTIS_("print rend(), --    :", NOENDL);
	it = mapp.rend();
	it--;
	std::cout << " " << *it << " " << std::endl;
}

void	iteratorsTest()
{
	_STITLE_("ITERATORS TEST");

	//std::map<int, char>			stdmapp;
	//ft::map<int, char>			ftmapp;
	std::map<int, std::string>	stdmapp2;
	ft::map<int, std::string>	ftmapp2;

	_SSTITLE_("'BEGIN' TEST");
	_STD_TITLE_("(int, str)"); beginTest(stdmapp2);
	_FT_TITLE_("(int, str)"); beginTest(ftmapp2);
	/*_STD_TITLE_("(int)"); beginTest(stdmapp);
	_FT_TITLE_("(int)"); beginTest(ftmapp);*/

	_SSTITLE_("'END' TEST");
	_STD_TITLE_("(str)"); endTest(stdmapp2);
	//_FT_TITLE_("(str)"); endTest(ftmapp2);

	_SSTITLE_("'RBEGIN' TEST");
	/*_STD_TITLE_("(int)"); rbeginTest(stdmapp);
	_FT_TITLE_("(int)"); rbeginTest(ftmapp);
	_STD_TITLE_("(str)"); rbeginTest(stdmapp2);
	_FT_TITLE_("(str)"); rbeginTest(ftmapp2);*/

	_SSTITLE_("'REND' TEST");
	/*_STD_TITLE_("(int)"); rendTest(stdmapp);
	_FT_TITLE_("(int)"); rendTest(ftmapp);
	_STD_TITLE_("(str)"); rendTest(stdmapp2);
	_FT_TITLE_("(str)"); rendTest(ftmapp2);*/
}

/*
 * begin()
 * end()
 * rbegin()
 * rend()
*/
