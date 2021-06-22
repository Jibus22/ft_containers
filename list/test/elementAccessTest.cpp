#include "list.hpp"
#include "resources.hpp"
#include <list>

/////////FRONT
template <typename Container>
void	frontTest(Container lst)
{
	_THISTESTIS_("print of 5 front after 5 != push:", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainer(lst, i + 1);
		std::cout << lst.front();
	}
	std::cout << std::endl;
}

//////////BACK
template <typename Container>
void	backTest(Container lst)
{
	_THISTESTIS_("print of 5 back after 5 != push:", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainer(lst, i + 1);
		std::cout << lst.back();
	}
	std::cout << std::endl;
}

////////MAIN
void	elementAccessTest()
{
	_STITLE_("ELEMENT ACCESS TEST");

	std::list<int>			stdlst;
	ft::list<int>			ftlst;
	std::list<std::string>	stdlst2;
	ft::list<std::string>	ftlst2;

	_SSTITLE_("'FRONT' TEST");
	_STD_TITLE_("(int)"); frontTest(stdlst);
	_FT_TITLE_("(int)"); frontTest(ftlst);
	_STD_TITLE_("(str)"); frontTest(stdlst2);
	_FT_TITLE_("(str)"); frontTest(ftlst2);

	_SSTITLE_("'BACK' TEST");
	_STD_TITLE_("(int)"); backTest(stdlst);
	_FT_TITLE_("(int)"); backTest(ftlst);
	_STD_TITLE_("(str)"); backTest(stdlst2);
	_FT_TITLE_("(str)"); backTest(ftlst2);
}

/*
 * front()
 * back()
*/
