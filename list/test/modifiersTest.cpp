#include "list.hpp"
#include "resources.hpp"
#include <list>

///////ASSIGN
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	testAssignSFINAE(Container<Element, Allocator> lst)
{
	_THISTESTIS_("testing sfinae__", ENDL);
	_THISTESTIS_("assign 50x21             ", NOENDL);
	lst.assign(50, 21);
	_PRINT_LST_(lst);
}

template <template <typename, typename> class Container,
		typename Allocator>
void	testAssignSFINAE(Container<std::string, Allocator> lst)
{
	_THISTESTIS_("testing sfinae__", ENDL);
	_THISTESTIS_("assign 50x\"blo\"          ", NOENDL);
	lst.assign(50, "blo");
	_PRINT_LST_(lst);
}

template <typename Container>
void	assignTest(Container lst)
{
	Container								lst2;
	Container								lst3;
	typename Container::iterator			it1;
	typename Container::iterator			it2;

	_THISTESTIS_("iterator assign from a container x42__", ENDL);
	_THISTESTIS_("assign from begin to b+5:", NOENDL);
	fillContainer(lst, 42);
	it1 = lst.begin();
	it2 = lst.begin();
	for (size_t i = 0; i < 5; i++)
		it2++;
	lst2.assign(it1, it2);
	_PRINT_LST_(lst2);

	_THISTESTIS_("assign from b+10 to b+25:", NOENDL);
	for (size_t i = 0; i < 10; i++)
		it1++;
	for (size_t i = 0; i < 20; i++)
		it2++;
	lst2.assign(it1, it2);
	_PRINT_LST_(lst2);

	_THISTESTIS_("assign from b+40 to b+42:", NOENDL);
	for (size_t i = 0; i < 30; i++)
		it1++;
	for (size_t i = 0; i < 17; i++)
		it2++;
	lst2.assign(it1, it2);
	_PRINT_LST_(lst2);

	_SPLIT_LINE_();
	_THISTESTIS_("size & value assignment__", ENDL);
	_THISTESTIS_("assign x7                ", NOENDL);
	sizeAssign(lst3, 7);
	_PRINT_LST_(lst3);

	_THISTESTIS_("assign x907              ", NOENDL);
	sizeAssign(lst3, 907);
	_PRINT_LST_(lst3);

	testAssignSFINAE(lst3);
}

///////PUSH_FRONT
template <typename Container>
void	pushfrontTest(Container lst)
{
	_THISTESTIS_("10 push_front:      ", NOENDL);
	fillfrontContainer(lst, 10);
	_PRINT_LST_(lst);

	_THISTESTIS_("50 more push_front: ", NOENDL);
	fillfrontContainer(lst, 50);
	_PRINT_LST_(lst);

	//_THISTESTIS_("print of content:  ", ENDL);
	//_PRINT_LST_CONTENT_(lst);

	_THISTESTIS_("500 more push_front:", NOENDL);
	fillfrontContainer(lst, 500);
	_PRINT_LST_(lst);
}

///////POP_FRONT
template <typename Container>
void	popfrontTest(Container lst)
{
	_THISTESTIS_("State of current container", ENDL);
	_THISTESTIS_("with 500 elem:   ", NOENDL);
	fillfrontContainer(lst, 500);
	_PRINT_LST_(lst);

	_THISTESTIS_("pop 10 elements: ", NOENDL);
	for (size_t i = 0; i < 10; i++)
		lst.pop_front();
	_PRINT_LST_(lst);

	_THISTESTIS_("pop 200 elements:", NOENDL);
	for (size_t i = 0; i < 200; i++)
		lst.pop_front();
	_PRINT_LST_(lst);

	_THISTESTIS_("pop 290 elements:", NOENDL);
	for (size_t i = 0; i < 290; i++)
		lst.pop_front();
	_PRINT_LST_(lst);

	//_THISTESTIS_("print of content:  ", ENDL);
	//_PRINT_LST_CONTENT_(lst);
}

///////PUSH_BACK
template <typename Container>
void	pushbackTest(Container lst)
{
	_THISTESTIS_("10 push_back:      ", NOENDL);
	fillContainer(lst, 10);
	_PRINT_LST_(lst);

	_THISTESTIS_("50 more push_back: ", NOENDL);
	fillContainer(lst, 50);
	_PRINT_LST_(lst);

	//_THISTESTIS_("print of content:  ", ENDL);
	//_PRINT_LST_CONTENT_(lst);

	_THISTESTIS_("500 more push_back:", NOENDL);
	fillContainer(lst, 500);
	_PRINT_LST_(lst);
}

///////POP_BACK
template <typename Container>
void	popbackTest(Container lst)
{
	_THISTESTIS_("State of current container", ENDL);
	_THISTESTIS_("with 500 elem:   ", NOENDL);
	fillContainer(lst, 500);
	_PRINT_LST_(lst);

	_THISTESTIS_("pop 10 elements: ", NOENDL);
	for (size_t i = 0; i < 10; i++)
		lst.pop_back();
	_PRINT_LST_(lst);

	_THISTESTIS_("pop 200 elements:", NOENDL);
	for (size_t i = 0; i < 200; i++)
		lst.pop_back();
	_PRINT_LST_(lst);

	_THISTESTIS_("pop 290 elements:", NOENDL);
	for (size_t i = 0; i < 290; i++)
		lst.pop_back();
	_PRINT_LST_(lst);
}

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

//RESIZE TEST
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	tResize(Container<Element, Allocator> & lst, size_t n)
{lst.resize(n, 42);}

template <template <typename, typename> class Container,
		typename Allocator>
void	tResize(Container<std::string, Allocator> & lst, size_t n)
{lst.resize(n, "blo");}

template <typename Container>
void	resizeTest(Container lst)
{
	_THISTESTIS_("Container state before: ", NOENDL);
	fillContainer(lst, 5);
	_PRINT_LST_(lst);
	_THISTESTIS_("resize from x5 to x25:  ", NOENDL);
	lst.resize(25);
	_PRINT_LST_(lst);

	_THISTESTIS_("resize from x25 to x33: ", NOENDL);
	lst.resize(33);
	_PRINT_LST_(lst);

	_THISTESTIS_("resize from x33 to x5:  ", NOENDL);
	lst.resize(5);
	_PRINT_LST_(lst);

	_THISTESTIS_("resize from x5 to x10", ENDL);
	_THISTESTIS_("with value:             ", NOENDL);
	tResize(lst, 10);
	_PRINT_LST_(lst);
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

	std::list<int>			stdlst;
	ft::list<int>			ftlst;
	std::list<std::string>	stdlst2;
	ft::list<std::string>	ftlst2;

	_SSTITLE_("'ASSIGN' TEST");
	_STD_TITLE_("(int)"); assignTest(stdlst);
	_FT_TITLE_("(int)"); assignTest(ftlst);
	_STD_TITLE_("(str)"); assignTest(stdlst2);
	_FT_TITLE_("(str)"); assignTest(ftlst2);

	_SSTITLE_("'PUSH_FRONT' TEST");
	_STD_TITLE_("(int)"); pushfrontTest(stdlst);
	_FT_TITLE_("(int)"); pushfrontTest(ftlst);
	_STD_TITLE_("(str)"); pushfrontTest(stdlst2);
	_FT_TITLE_("(str)"); pushfrontTest(ftlst2);

	_SSTITLE_("'POP_FRONT' TEST");
	_STD_TITLE_("(int)"); popfrontTest(stdlst);
	_FT_TITLE_("(int)"); popfrontTest(ftlst);
	_STD_TITLE_("(str)"); popfrontTest(stdlst2);
	_FT_TITLE_("(str)"); popfrontTest(ftlst2);

	_SSTITLE_("'PUSH_BACK' TEST");
	_STD_TITLE_("(int)"); pushbackTest(stdlst);
	_FT_TITLE_("(int)"); pushbackTest(ftlst);
	_STD_TITLE_("(str)"); pushbackTest(stdlst2);
	_FT_TITLE_("(str)"); pushbackTest(ftlst2);

	_SSTITLE_("'POP_BACK' TEST");
	_STD_TITLE_("(int)"); popbackTest(stdlst);
	_FT_TITLE_("(int)"); popbackTest(ftlst);
	_STD_TITLE_("(str)"); popbackTest(stdlst2);
	_FT_TITLE_("(str)"); popbackTest(ftlst2);

	_SSTITLE_("'INSERT' TEST");
	_STD_TITLE_("(int)"); insertTest(stdlst);
	_FT_TITLE_("(int)"); insertTest(ftlst);
	_STD_TITLE_("(str)"); insertTest(stdlst2);
	_FT_TITLE_("(str)"); insertTest(ftlst2);

	_SSTITLE_("'ERASE' TEST");
	_STD_TITLE_("(int)"); eraseTest(stdlst);
	_FT_TITLE_("(int)"); eraseTest(ftlst);
	_STD_TITLE_("(str)"); eraseTest(stdlst2);
	_FT_TITLE_("(str)"); eraseTest(ftlst2);

	_SSTITLE_("'SWAP' TEST");
	_STD_TITLE_("(int)"); swapTest(stdlst);
	_FT_TITLE_("(int)"); swapTest(ftlst);
	_STD_TITLE_("(str)"); swapTest(stdlst2);
	_FT_TITLE_("(str)"); swapTest(ftlst2);

	_SSTITLE_("'RESIZE' TEST");
	_STD_TITLE_("(int)"); resizeTest(stdlst);
	_FT_TITLE_("(int)"); resizeTest(ftlst);
	_STD_TITLE_("(str)"); resizeTest(stdlst2);
	_FT_TITLE_("(str)"); resizeTest(ftlst2);

	_SSTITLE_("'CLEAR' TEST");
	_STD_TITLE_("(int)"); clearTest(stdlst);
	_FT_TITLE_("(int)"); clearTest(ftlst);
	_STD_TITLE_("(str)"); clearTest(stdlst2);
	_FT_TITLE_("(str)"); clearTest(ftlst2);
}

/*
 * assign()
 * push_front()
 * pop_front()
 * push_back()
 * pop_back()
 * insert()
 * erase()
 * swap()
 * clear()
*/
