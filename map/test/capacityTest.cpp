#include "map.hpp"
#include "resources.hpp"
#include <map>

//SIZE TEST
template <typename Container>
void	sizeTest(Container lst)
{
	_THISTESTIS_("size of empty container:             ", NOENDL);
	std::cout << lst.size() << std::endl;

	_THISTESTIS_("5 print of size after 5 fill (5*i++):", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainer(lst, i + 1);
		std::cout << lst.size() << ", ";
	}
	std::cout << std::endl;

	_THISTESTIS_("print of size after a pop:           ", NOENDL);
	lst.pop_back();
	std::cout << lst.size() << std::endl;
}

//MAX_SIZE TEST
template <typename Container>
void	maxsizeTest(Container lst)
{
	_THISTESTIS_("max_size of container:", NOENDL);
	std::cout << lst.max_size() << std::endl;
}

//EMPTY TEST
template <typename Container>
void	emptyTest(Container lst)
{
	_THISTESTIS_("empty of empty container:    ", NOENDL);
	std::cout << lst.empty() << std::endl;

	_THISTESTIS_("empty of container of 1 elem:", NOENDL);
	fillContainer(lst, 1);
	std::cout << lst.empty() << std::endl;
}

void	capacityTest()
{
	_STITLE_("CAPACITY TEST");

	std::map<int>			stdlst;
	ft::map<int>			ftlst;
	std::map<std::string>	stdlst2;
	ft::map<std::string>	ftlst2;

	_SSTITLE_("'SIZE' TEST");
	/*_STD_TITLE_("(int)"); sizeTest(stdlst);
	_FT_TITLE_("(int)"); sizeTest(ftlst);
	_STD_TITLE_("(str)"); sizeTest(stdlst2);
	_FT_TITLE_("(str)"); sizeTest(ftlst2);*/

	_SSTITLE_("'MAX_SIZE' TEST");
	/*_STD_TITLE_("(int)"); maxsizeTest(stdlst);
	_FT_TITLE_("(int)"); maxsizeTest(ftlst);
	_STD_TITLE_("(str)"); maxsizeTest(stdlst2);
	_FT_TITLE_("(str)"); maxsizeTest(ftlst2);*/

	_SSTITLE_("'EMPTY' TEST");
	/*_STD_TITLE_("(int)"); emptyTest(stdlst);
	_FT_TITLE_("(int)"); emptyTest(ftlst);
	_STD_TITLE_("(str)"); emptyTest(stdlst2);
	_FT_TITLE_("(str)"); emptyTest(ftlst2);*/
}

/*
 * size()
 * max_size()
 * resize()
 * capacity()
 * empty()
 * reserve()
*/
