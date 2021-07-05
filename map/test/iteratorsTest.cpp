#include "map.hpp"
#include "resources.hpp"
#include <map>

///////BEGIN
template <typename Container>
void	beginTest(Container lst)
{
	fillContainer(lst, 20);
	_THISTESTIS_("begin of x20:  ", NOENDL);
	std::cout << " " << *(lst.begin()) << std::endl;
	fillContainer(lst, 20);
	_THISTESTIS_("begin of x40:  ", NOENDL);
	std::cout << " " << *(lst.begin()) << std::endl;
}

///////END
template <typename Container>
void	endTest(Container lst)
{
	typedef typename Container::iterator			iterator;
	iterator		it;

	fillContainer(lst, 20);
	it = lst.end();
	it--;
	_THISTESTIS_("end-1 of x20:  ", NOENDL);
	std::cout << " " << *it << std::endl;
	fillContainer(lst, 10);
	_THISTESTIS_("end-1 of x30:  ", NOENDL);
	it = lst.end();
	it--;
	std::cout << " " << *it << std::endl;
}

///////RBEGIN
template <typename Container>
void	rbeginTest(Container lst)
{
	typedef typename Container::reverse_iterator	reverse_iterator;
	typedef typename Container::iterator			iterator;
	reverse_iterator		it;
	reverse_iterator		it2;

	fillContainer(lst, 20);
	_THISTESTIS_("rbegin of x20:  ", NOENDL);
	it = lst.rbegin();
	std::cout << " " << *it << std::endl;
	fillContainer(lst, 10);
	it2 = lst.rbegin();
	_THISTESTIS_("begin of x30:   ", NOENDL);
	std::cout << " " << *it2 << std::endl;

	_THISTESTIS_("assignation '=' and", ENDL);
	it = it2;
	_THISTESTIS_("comparison != : ", NOENDL);
	if (it != it2)
		std::cout << " it != it2" << std::endl;
	else
		std::cout << " it == it2" << std::endl;

	//lst.clear();
	fillContainer(lst, 10);
	_THISTESTIS_("reverse print : ", NOENDL);
	for (reverse_iterator i = lst.rbegin(); i != lst.rend(); i++)
		std::cout << " " << *i << ", ";
	std::cout << std::endl;

	_THISTESTIS_("iterator construction:", NOENDL);
	iterator	itt;
	itt = lst.begin();
	reverse_iterator	bla(itt);
	std::cout << " " << *itt << std::endl;
}

///////REND
template <typename Container>
void	rendTest(Container lst)
{
	typedef typename Container::reverse_iterator	reverse_iterator;
	reverse_iterator		it;

	_THISTESTIS_("print rbegin to rend:", NOENDL);
	fillContainer(lst, 10);
	for (reverse_iterator i = lst.rbegin(); i != lst.rend(); i++)
		std::cout << " " << *i << " ";
	std::cout << std::endl;
	_THISTESTIS_("print rend(), --    :", NOENDL);
	it = lst.rend();
	it--;
	std::cout << " " << *it << " " << std::endl;
}

void	iteratorsTest()
{
	_STITLE_("ITERATORS TEST");

	std::map<int>			stdlst;
	ft::map<int>			ftlst;
	std::map<std::string>	stdlst2;
	ft::map<std::string>	ftlst2;

	_SSTITLE_("'BEGIN' TEST");
	/*_STD_TITLE_("(int)"); beginTest(stdlst);
	_FT_TITLE_("(int)"); beginTest(ftlst);
	_STD_TITLE_("(str)"); beginTest(stdlst2);
	_FT_TITLE_("(str)"); beginTest(ftlst2);*/

	_SSTITLE_("'END' TEST");
	/*_STD_TITLE_("(int)"); endTest(stdlst);
	_FT_TITLE_("(int)"); endTest(ftlst);
	_STD_TITLE_("(str)"); endTest(stdlst2);
	_FT_TITLE_("(str)"); endTest(ftlst2);*/

	_SSTITLE_("'RBEGIN' TEST");
	/*_STD_TITLE_("(int)"); rbeginTest(stdlst);
	_FT_TITLE_("(int)"); rbeginTest(ftlst);
	_STD_TITLE_("(str)"); rbeginTest(stdlst2);
	_FT_TITLE_("(str)"); rbeginTest(ftlst2);*/

	_SSTITLE_("'REND' TEST");
	/*_STD_TITLE_("(int)"); rendTest(stdlst);
	_FT_TITLE_("(int)"); rendTest(ftlst);
	_STD_TITLE_("(str)"); rendTest(stdlst2);
	_FT_TITLE_("(str)"); rendTest(ftlst2);*/
}

/*
 * begin()
 * end()
 * rbegin()
 * rend()
*/
