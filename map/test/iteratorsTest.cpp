#include "map.hpp"
#include "resources.hpp"
#include <map>
#include <utility>

///////BEGIN
template <typename Container>
void	beginTest(Container mapp)
{
	typedef typename Container::iterator iterator;

	iterator			i;

	_THISTESTIS_("iterate begin to end thru a map of ~200 elements", ENDL);
	fillmap(mapp, 10);
	_PRINT_MAP_CONTENT_(mapp);

	_THISTESTIS_("print end() -1", ENDL);
	i = mapp.end();
	std::cout << (--i)->first << std::endl;
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
	reverse_iterator		it, it2;

	fillmap(mapp, 10);
	_THISTESTIS_("rbegin of ~x200:  ", NOENDL);
	it2 = mapp.rbegin();
	_DISPLAY_MAP_NODE_(it2);

	_THISTESTIS_("assignation '=' and comparison != :", NOENDL);
	it = it2;
	if (it != it2)
		std::cout << " it != it2" << std::endl;
	else
		std::cout << " it == it2" << std::endl;

	_THISTESTIS_("reverse print :    ", ENDL);
	for (reverse_iterator i = mapp.rbegin(); i != mapp.rend(); i++)
		std::cout << " " << i->first << ", ";
	std::cout << std::endl;

	_THISTESTIS_("begin iterator construction & print:", NOENDL);
	iterator	itt;
	itt = mapp.begin();
	reverse_iterator	bla(itt);
	std::cout << " " << itt->first << std::endl;
}

///////REND
template <typename Container>
void	rendTest(Container mapp)
{
	typedef typename Container::reverse_iterator	reverse_iterator;
	reverse_iterator		it;

	_THISTESTIS_("print rbegin to rend:", ENDL);
	fillmap(mapp, 5);
	for (reverse_iterator i = mapp.rbegin(); i != mapp.rend(); i++)
		std::cout << " " << i->first << " ";
	std::cout << std::endl;

	_THISTESTIS_("rend--:   ", NOENDL);
	it = mapp.rend();
	it--;
	_DISPLAY_MAP_NODE_(it);
}

void	iteratorsTest()
{
	_STITLE_("ITERATORS TEST");

	std::map<int, std::string>	stdmapp2;
	ft::map<int, std::string>	ftmapp2;

	_SSTITLE_("'BEGIN' TEST");
	_STD_TITLE_("(int, str)"); beginTest(stdmapp2);
	_FT_TITLE_("(int, str)"); beginTest(ftmapp2);

	_SSTITLE_("'END' TEST");
	_STD_TITLE_("(int, str)"); endTest(stdmapp2);
	_FT_TITLE_("(int, str)"); endTest(ftmapp2);

	_SSTITLE_("'RBEGIN' TEST");
	_STD_TITLE_("(int, str)"); rbeginTest(stdmapp2);
	_FT_TITLE_("(int, str)"); rbeginTest(ftmapp2);

	_SSTITLE_("'REND' TEST");
	_STD_TITLE_("(int, str)"); rendTest(stdmapp2);
	_FT_TITLE_("(int, str)"); rendTest(ftmapp2);
}

/*
 * begin()
 * end()
 * rbegin()
 * rend()
*/
