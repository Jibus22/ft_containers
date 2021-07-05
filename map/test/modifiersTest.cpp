#include "map.hpp"
#include "resources.hpp"
#include <map>

///////INSERT
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	insertOne(Container<Element, Allocator> & lst,
				typename Container<Element, Allocator>::iterator it)
{lst.insert(it, 42);}

template <template <typename, typename> class Container,
		typename Allocator>
void	insertOne(Container<std::string, Allocator> & lst,
				typename Container<std::string, Allocator>::iterator it)
{lst.insert(it, "blo");}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	insertTwo(Container<Element, Allocator> & lst, size_t n,
				typename Container<Element, Allocator>::iterator it)
{lst.insert(it, n, 42);}

template <template <typename, typename> class Container,
		typename Allocator>
void	insertTwo(Container<std::string, Allocator> & lst, size_t n,
				typename Container<std::string, Allocator>::iterator it)
{lst.insert(it, n, "blo");}

template <typename Container>
void	insertTest(Container lst)
{
	Container						lst2;
	typename Container::iterator	it1;
	typename Container::iterator	it2;
	typename Container::iterator	it3;

	_THISTESTIS_("insert one value at it pos in a x16 container__", ENDL);
	_THISTESTIS_("value at pos=5:     ", NOENDL);
	fillContainer(lst, 16);
	it1 = lst.begin();
	for (size_t i = 0; i < 5; i++)
		it1++;
	insertOne(lst, it1);
	_PRINT_LST_(lst);
	_THISTESTIS_("print of content:", ENDL);
	_PRINT_LST_CONTENT_(lst);

	_THISTESTIS_("value at the end:   ", NOENDL);
	it1 = lst.end();
	insertOne(lst, it1);
	_PRINT_LST_(lst);
	_THISTESTIS_("print of content:   ", ENDL);
	_PRINT_LST_CONTENT_(lst);

	lst.clear();

	_SPLIT_LINE_();
	_THISTESTIS_("insert many values at it pos 5 in a x16 container__", ENDL);
	_THISTESTIS_("5 values from pos 5:", NOENDL);
	fillContainer(lst, 16);
	it1 = lst.begin();
	for (size_t i = 0; i < 5; i++)
		it1++;
	insertTwo(lst, 5, it1);
	_PRINT_LST_(lst);
	_THISTESTIS_("print of content:", ENDL);
	_PRINT_LST_CONTENT_(lst);

	_THISTESTIS_("12 values from end: ", NOENDL);
	it1 = lst.end();
	insertTwo(lst, 12, it1);
	_PRINT_LST_(lst);
	_THISTESTIS_("print of content:", ENDL);
	_PRINT_LST_CONTENT_(lst);

	_THISTESTIS_("194 values from end:", NOENDL);
	it1 = lst.end();
	insertTwo(lst, 194, it1);
	_PRINT_LST_(lst);

	lst.clear();

	_SPLIT_LINE_();
	_THISTESTIS_("third insert: from container it range, at a pos___", ENDL);
	fillContainer(lst2, 20);
	it1 = lst2.begin();
	for (size_t i = 0; i < 5; i++)
		it1++;
	it2 = it1;
	for (size_t i = 0; i < 10; i++)
		it2++;
	fillContainer(lst, 10);
	_THISTESTIS_("10 values at end-2 of cont(10):", NOENDL);
	it3 = lst.end();
	for (size_t i = 0; i < 2; i++)
		it3--;
	lst.insert(it3, it1, it2);
	_PRINT_LST_(lst);
	for (size_t i = 0; i < 5; i++)
		it1++;
	for (size_t i = 0; i < 3; i++)
		it2++;
	_THISTESTIS_("8 values at end-8 of cont(20): ", NOENDL);
	it3 = lst.end();
	for (size_t i = 0; i < 2; i++)
		it3--;
	lst.insert(it3, it1, it2);
	_PRINT_LST_(lst);

	_THISTESTIS_("print of content:", ENDL);
	_PRINT_LST_CONTENT_(lst);
}

///////ERASE
template <typename Container>
void	eraseTest(Container lst)
{
	typename Container::iterator	it;
	typename Container::iterator	it2;

	_THISTESTIS_("erase value pos 5 in a x10 container", ENDL);
	_THISTESTIS_("content displayed as : before, after", ENDL);
	fillContainer(lst, 10);
	_PRINT_LST_CONTENT_(lst);
	it2 = lst.begin();
	for (size_t i = 0; i < 5; i++)
		it2++;
	it = lst.erase(it2);
	_PRINT_LST_CONTENT_(lst);

	_THISTESTIS_("print erase iterator return: ", NOENDL);
	std::cout << *it << std::endl;

	_THISTESTIS_("erase first value, display content & return:", ENDL);
	it = lst.erase(lst.begin());
	_PRINT_LST_CONTENT_(lst);
	std::cout << *it << std::endl;

	_THISTESTIS_("erase end-1, display content & return-1:", ENDL);
	it2 = lst.end();
	it2--;
	it = lst.erase(it2);
	it--;
	_PRINT_LST_CONTENT_(lst);
	std::cout << *it << std::endl;

	_THISTESTIS_("finally print state:", NOENDL);
	_PRINT_LST_(lst);

	_SPLIT_LINE_();
	_THISTESTIS_("second erase test: from it range", ENDL);
	_THISTESTIS_("erase begin to begin + 3, print content & return:", ENDL);
	it2 = lst.begin();
	for (size_t i = 0; i < 3; i++)
		it2++;
	it = lst.erase(lst.begin(), it2);
	_PRINT_LST_CONTENT_(lst);
	std::cout << *it << std::endl;

	_THISTESTIS_("erase begin+1 to end, print content & return-1:", ENDL);
	it2 = lst.begin();
	it2++;
	it = lst.erase(it2, lst.end());
	_PRINT_LST_CONTENT_(lst);
	it--;
	std::cout << *it << std::endl;
}

///////SWAP
template <typename Container>
void	swapTest(Container lst)
{
	Container			lst2;
	typename Container::iterator	it;
	typename Container::iterator	it2;

	_THISTESTIS_("swap const lstx10 with var lstx20", ENDL);
	fillContainer(lst, 20);
	sizeAssign(lst2, 10);
	it = lst.begin();
	it2 = lst2.begin();
	_THISTESTIS_("lst state before:     ", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("lst2 state before:    ", NOENDL);
	_PRINT_LST_(lst2);
	_THISTESTIS_("iterator 1 & 2 before:", NOENDL);
	std::cout << "   " << *it << "  " << *it2 << std::endl;
	lst.swap(lst2);
	_THISTESTIS_("lst state after:      ", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("lst2 state after:     ", NOENDL);
	_PRINT_LST_(lst2);
	_THISTESTIS_("iterator 1 & 2 after: ", NOENDL);
	std::cout << "   " << *it << "  " << *it2 << std::endl;
}

///////CLEAR
template <typename Container>
void	clearTest(Container lst)
{
	fillContainer(lst, 2000);
	_THISTESTIS_("clear container x2000", ENDL);
	_THISTESTIS_("lst state before:     ", NOENDL);
	_PRINT_LST_(lst);
	lst.clear();
	_THISTESTIS_("lst state after:      ", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("clear empty container:", NOENDL);
	lst.clear();
	_PRINT_LST_(lst);
}

////////MAIN
void	modifiersTest()
{
	_STITLE_("MODIFIERS TEST");

	std::map<int>			stdlst;
	ft::map<int>			ftlst;
	std::map<std::string>	stdlst2;
	ft::map<std::string>	ftlst2;

	_SSTITLE_("'INSERT' TEST");
	/*_STD_TITLE_("(int)"); insertTest(stdlst);
	_FT_TITLE_("(int)"); insertTest(ftlst);
	_STD_TITLE_("(str)"); insertTest(stdlst2);
	_FT_TITLE_("(str)"); insertTest(ftlst2);*/

	_SSTITLE_("'ERASE' TEST");
	/*_STD_TITLE_("(int)"); eraseTest(stdlst);
	_FT_TITLE_("(int)"); eraseTest(ftlst);
	_STD_TITLE_("(str)"); eraseTest(stdlst2);
	_FT_TITLE_("(str)"); eraseTest(ftlst2);*/

	_SSTITLE_("'SWAP' TEST");
	/*_STD_TITLE_("(int)"); swapTest(stdlst);
	_FT_TITLE_("(int)"); swapTest(ftlst);
	_STD_TITLE_("(str)"); swapTest(stdlst2);
	_FT_TITLE_("(str)"); swapTest(ftlst2);*/

	_SSTITLE_("'CLEAR' TEST");
	/*_STD_TITLE_("(int)"); clearTest(stdlst);
	_FT_TITLE_("(int)"); clearTest(ftlst);
	_STD_TITLE_("(str)"); clearTest(stdlst2);
	_FT_TITLE_("(str)"); clearTest(ftlst2);*/
}

/*
 * insert()
 * erase()
 * swap()
 * clear()
*/
