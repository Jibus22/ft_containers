#include "list.hpp"
#include "resources.hpp"
#include <list>

///////REMOVE
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	removeTest(Container<Element, Allocator> & lst)
{
	_THISTESTIS_("Remove values 4. Print before/after:", ENDL);
	fillContainer(lst, 7);
	for (size_t i = 0; i < 5; i++)
		lst.push_back(4);
	fillContainer(lst, 7);
	_PRINT_LST_CONTENT_(lst);
	lst.remove(4);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list :", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("Remove values 6 then 0. Print after/after:", ENDL);
	lst.remove(6);
	_PRINT_LST_CONTENT_(lst);
	lst.remove(0);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list :", NOENDL);
	_PRINT_LST_(lst);
}

template <template <typename, typename> class Container,
		typename Allocator>
void	removeTest(Container<std::string, Allocator> & lst)
{
	_THISTESTIS_("Remove values \"d\". Print before/after:", ENDL);
	fillContainer(lst, 7);
	for (size_t i = 0; i < 5; i++)
		lst.push_back("d");
	fillContainer(lst, 7);
	_PRINT_LST_CONTENT_(lst);
	lst.remove("d");
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list :", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("Remove values \"g\" then \"a\". Print after/after:", ENDL);
	lst.remove("g");
	_PRINT_LST_CONTENT_(lst);
	lst.remove("a");
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list :", NOENDL);
	_PRINT_LST_(lst);
}

///////REVERSE
template <typename Container>
void	reverseTest(Container lst)
{
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

	std::list<int>			stdlst;
	ft::list<int>			ftlst;
	std::list<std::string>	stdlst2;
	ft::list<std::string>	ftlst2;

	_SSTITLE_("'SPLICE' TEST");
	/*_STD_TITLE_("(int)"); spliceTest(stdlst);
	_FT_TITLE_("(int)"); spliceTest(ftlst);
	_STD_TITLE_("(str)"); spliceTest(stdlst2);
	_FT_TITLE_("(str)"); spliceTest(ftlst2);*/

	_SSTITLE_("'REMOVE' TEST");
	_STD_TITLE_("(int)"); removeTest(stdlst);
	_FT_TITLE_("(int)"); removeTest(ftlst);
	_STD_TITLE_("(str)"); removeTest(stdlst2);
	_FT_TITLE_("(str)"); removeTest(ftlst2);

	_SSTITLE_("'REMOVE_IF' TEST");
	/*_STD_TITLE_("(int)"); remove_ifTest(stdlst);
	_FT_TITLE_("(int)"); remove_ifTest(ftlst);
	_STD_TITLE_("(str)"); remove_ifTest(stdlst2);
	_FT_TITLE_("(str)"); remove_ifTest(ftlst2);*/

	_SSTITLE_("'UNIQUE' TEST");
	/*_STD_TITLE_("(int)"); uniqueTest(stdlst);
	_FT_TITLE_("(int)"); uniqueTest(ftlst);
	_STD_TITLE_("(str)"); uniqueTest(stdlst2);
	_FT_TITLE_("(str)"); uniqueTest(ftlst2);*/

	_SSTITLE_("'MERGE' TEST");
	/*_STD_TITLE_("(int)"); mergeTest(stdlst);
	_FT_TITLE_("(int)"); mergeTest(ftlst);
	_STD_TITLE_("(str)"); mergeTest(stdlst2);
	_FT_TITLE_("(str)"); mergeTest(ftlst2);*/

	_SSTITLE_("'SORT' TEST");
	/*_STD_TITLE_("(int)"); sortTest(stdlst);
	_FT_TITLE_("(int)"); sortTest(ftlst);
	_STD_TITLE_("(str)"); sortTest(stdlst2);
	_FT_TITLE_("(str)"); sortTest(ftlst2);*/

	_SSTITLE_("'REVERSE' TEST");
	_STD_TITLE_("(int)"); reverseTest(stdlst);
	_FT_TITLE_("(int)"); reverseTest(ftlst);
	_STD_TITLE_("(str)"); reverseTest(stdlst2);
	_FT_TITLE_("(str)"); reverseTest(ftlst2);

	(void)stdlst;
	(void)stdlst2;
	(void)ftlst;
	(void)ftlst2;
}

/*
 * splice()
 * remove()
 * remove_if()
 * unique()
 * merge()
 * sort()
 * reverse()
*/
