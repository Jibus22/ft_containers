#include "list.hpp"
#include "resources.hpp"
#include <list>

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

//RESERVE TEST
template <typename Container>
void	reserveTest(Container lst)
{
	_THISTESTIS_("capacity & size of empty container:          ", NOENDL);
	std::cout << lst.capacity() << " & " << lst.size() << std::endl;

	_THISTESTIS_("capacity & size of reserved x10 container:   ", NOENDL);
	lst.reserve(10);
	std::cout << lst.capacity() << " & " << lst.size() << std::endl;

	_THISTESTIS_("capacity & size of filled x5 container:      ", NOENDL);
	fillContainer(lst, 5);
	std::cout << lst.capacity() << " & " << lst.size() << std::endl;

	_THISTESTIS_("capacity & size after reserved x4 container: ", NOENDL);
	lst.reserve(4);
	std::cout << lst.capacity() << " & " << lst.size() << std::endl;

	_THISTESTIS_("capacity & size of filled x15 more container:", NOENDL);
	fillContainer(lst, 15);
	std::cout << lst.capacity() << " & " << lst.size() << std::endl;

	_THISTESTIS_("capacity & size of reserved x40 container:   ", NOENDL);
	lst.reserve(40);
	std::cout << lst.capacity() << " & " << lst.size() << std::endl;

	_THISTESTIS_("try to reserve way too much:                 ", NOENDL);
	try {lst.reserve(4611686018427387909);}
	catch (std::length_error & e) {std::cout << e.what() << std::endl;}

	_THISTESTIS_("print of content:", ENDL);
	_PRINT_LST_CONTENT_(lst);
}

void	capacityTest()
{
	_STITLE_("CAPACITY TEST");

	std::list<int>			stdlst;
	ft::list<int>			ftlst;
	std::list<std::string>	stdlst2;
	ft::list<std::string>	ftlst2;

	_SSTITLE_("'SIZE' TEST");
	_STD_TITLE_("(int)"); sizeTest(stdlst);
	_FT_TITLE_("(int)"); sizeTest(ftlst);
	_STD_TITLE_("(str)"); sizeTest(stdlst2);
	_FT_TITLE_("(str)"); sizeTest(ftlst2);

	_SSTITLE_("'MAX_SIZE' TEST");
	_STD_TITLE_("(int)"); maxsizeTest(stdlst);
	_FT_TITLE_("(int)"); maxsizeTest(ftlst);
	_STD_TITLE_("(str)"); maxsizeTest(stdlst2);
	_FT_TITLE_("(str)"); maxsizeTest(ftlst2);

	_SSTITLE_("'EMPTY' TEST");
	_STD_TITLE_("(int)"); emptyTest(stdlst);
	_FT_TITLE_("(int)"); emptyTest(ftlst);
	_STD_TITLE_("(str)"); emptyTest(stdlst2);
	_FT_TITLE_("(str)"); emptyTest(ftlst2);
}

/*
 * size()
 * max_size()
 * resize()
 * capacity()
 * empty()
 * reserve()
*/
