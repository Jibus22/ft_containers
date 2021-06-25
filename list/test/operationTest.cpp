#include "list.hpp"
#include "resources.hpp"
#include <list>

///////SPLICE
template <typename Container>
void	spliceTest(Container lst)
{
	Container						lst2;
	typename Container::iterator	it;
	typename Container::iterator	it2;
	typename Container::iterator	it3;

	_THISTESTIS_("splice x20 in x10 at pos 5:", ENDL);
	fillContainer(lst, 10);
	fillContainer(lst2, 20);
	_THISTESTIS_("list1 before:", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("list2 before:", NOENDL);
	_PRINT_LST_(lst2);
	it = lst.begin();
	for (size_t i = 0; i < 5; i++)
		it++;
	lst.splice(it, lst2);
	_THISTESTIS_("list1 after: ", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("list2 after: ", NOENDL);
	_PRINT_LST_(lst2);
	_PRINT_LST_CONTENT_(lst);

	_SPLIT_LINE_();
	_THISTESTIS_("splice 3th value at pos 5:", ENDL);
	fillContainer(lst2, 10);
	it2 = lst2.begin();
	for (size_t i = 0; i < 3; i++)
		it2++;
	it = lst.begin();
	for (size_t i = 0; i < 5; i++)
		it++;
	_THISTESTIS_("list1 before:", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("list2 before:", NOENDL);
	_PRINT_LST_(lst2);
	lst.splice(it, lst2, it2);
	_THISTESTIS_("list1 after: ", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("list2 after: ", NOENDL);
	_PRINT_LST_(lst2);
	_THISTESTIS_("list content after:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list2 content after:", ENDL);
	_PRINT_LST_CONTENT_(lst2);

	_SPLIT_LINE_();
	_THISTESTIS_("splice 6th value at pos 1-7:", ENDL);
	it = lst2.begin();
	for (size_t i = 0; i < 1; i++)
		it++;
	it2 = lst2.end();
	for (size_t i = 0; i < 1; i++)
		it2--;
	it3 = lst.begin();
	for (size_t i = 0; i < 6; i++)
		it3++;
	_THISTESTIS_("list1 before:", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("list2 before:", NOENDL);
	_PRINT_LST_(lst2);
	lst.splice(it3, lst2, it, it2);
	_THISTESTIS_("list1 after: ", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("list2 after: ", NOENDL);
	_PRINT_LST_(lst2);
	_THISTESTIS_("list content after:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list2 content after:", ENDL);
	_PRINT_LST_CONTENT_(lst2);

	_SPLIT_LINE_();
	_THISTESTIS_("splice begin from begin-end:", ENDL);
	it = lst2.begin();
	it2 = lst2.end();
	it3 = lst.begin();
	_THISTESTIS_("list1 before:", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("list2 before:", NOENDL);
	_PRINT_LST_(lst2);
	lst.splice(it3, lst2, it, it2);
	_THISTESTIS_("list1 after: ", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("list2 after: ", NOENDL);
	_PRINT_LST_(lst2);
	_THISTESTIS_("list content after:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list2 content after:", ENDL);
	_PRINT_LST_CONTENT_(lst2);
}

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

///////REMOVE_IF
bool single_digit (const int& value) {return (value<3);}
bool single_digit2 (const int& value) {return (value>4);}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	remove_ifTest(Container<Element, Allocator> & lst)
{
	_THISTESTIS_("Remove values <3. Print before/after:", ENDL);
	fillContainer(lst, 9);
	for (size_t i = 0; i < 5; i++)
		lst.push_back(4);
	fillContainer(lst, 7);
	_PRINT_LST_CONTENT_(lst);
	lst.remove_if(single_digit);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list :", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("Remove values >4.", ENDL);
	lst.remove_if(single_digit2);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list :", NOENDL);
	_PRINT_LST_(lst);
}

bool single_str (const std::string& value) {return (value<"d");}
bool single_str2 (const std::string& value) {return (value>"g");}

template <template <typename, typename> class Container,
		typename Allocator>
void	remove_ifTest(Container<std::string, Allocator> & lst)
{
	_THISTESTIS_("Remove values <\"d\". Print before/after:", ENDL);
	fillContainer(lst, 9);
	for (size_t i = 0; i < 5; i++)
		lst.push_back("d");
	fillContainer(lst, 7);
	_PRINT_LST_CONTENT_(lst);
	lst.remove_if(single_str);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list :", NOENDL);
	_PRINT_LST_(lst);
	_THISTESTIS_("Remove values >\"g\":", ENDL);
	lst.remove_if(single_str2);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list :", NOENDL);
	_PRINT_LST_(lst);
}

///////UNIQUE

bool pouet1(const int value, const int value2)
{return (value + value2 > 5);}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	uniqueTest(Container<Element, Allocator> & lst)
{
	_THISTESTIS_("unique. Print before/after:", ENDL);
	fillContainer(lst, 9);
	for (size_t i = 0; i < 5; i++)
		lst.push_back(4);
	fillContainer(lst, 7);
	for (size_t i = 0; i < 5; i++)
		lst.push_back(6);
	_PRINT_LST_CONTENT_(lst);
	lst.unique();
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list :", NOENDL);
	_PRINT_LST_(lst);

	_SPLIT_LINE_();
	_THISTESTIS_("unique if value + value2 > 5. Print before/after:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	lst.unique(pouet1);
	_PRINT_LST_CONTENT_(lst);
}

bool pouet(const std::string& value, const std::string& value2)
{return (value > value2);}

template <template <typename, typename> class Container,
		typename Allocator>
void	uniqueTest(Container<std::string, Allocator> & lst)
{
	_THISTESTIS_("unique. Print before/after:", ENDL);
	fillContainer(lst, 9);
	for (size_t i = 0; i < 5; i++)
		lst.push_back("d");
	fillContainer(lst, 7);
	for (size_t i = 0; i < 5; i++)
		lst.push_back("f");
	_PRINT_LST_CONTENT_(lst);
	lst.unique();
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("list :", NOENDL);
	_PRINT_LST_(lst);

	_SPLIT_LINE_();
	_THISTESTIS_("unique if value > value2. Print before/after:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	lst.unique(pouet);
	_PRINT_LST_CONTENT_(lst);
}

///////SORT
bool bang(const int& val, const int& val2) {return (val > val2);}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	sortTest(Container<Element, Allocator> & lst)
{
	fillContainer(lst, 10);
	_THISTESTIS_("sort container. before/after:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	lst.sort();
	_PRINT_LST_CONTENT_(lst);

	_SPLIT_LINE_();
	fillContainer(lst, 10);
	_THISTESTIS_("sort with comp. before/after:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	lst.sort(bang);
	_PRINT_LST_CONTENT_(lst);
}

bool bang2(const std::string& val, const std::string& val2) {return (val > val2);}

template <template <typename, typename> class Container,
		typename Allocator>
void	sortTest(Container<std::string, Allocator> & lst)
{
	fillContainer(lst, 10);
	_THISTESTIS_("sort container. before/after:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	lst.sort();
	_PRINT_LST_CONTENT_(lst);

	_SPLIT_LINE_();
	fillContainer(lst, 10);
	_THISTESTIS_("sort with comp. before/after:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	lst.sort(bang2);
	_PRINT_LST_CONTENT_(lst);
}

///////MERGE

bool paf(const int& val, const int& val2) {return (val + 5 < val2);}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	youpi(Container<Element, Allocator> & lst)
{
	Container<Element, Allocator>	lst2;

	fillContainer(lst2, 20);
	_THISTESTIS_("merge with comp: val+5<val2. lst2 before/lst after:", ENDL);
	_THISTESTIS_("lst2 (merging lst):", ENDL);
	_PRINT_LST_CONTENT_(lst2);
	lst.merge(lst2, paf);
	_THISTESTIS_("lst (merged lst):", ENDL);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("lst state after:      ", NOENDL);
	_PRINT_LST_(lst);
}

bool paf2(const std::string& val, const std::string& val2) {return (val > val2);}

template <template <typename, typename> class Container,
		typename Allocator>
void	youpi(Container<std::string, Allocator> & lst)
{
	Container<std::string, Allocator>	lst2;

	fillContainer(lst2, 20);
	_THISTESTIS_("merge with comp. lst2 before/lst after:", ENDL);
	_THISTESTIS_("lst2 (merging lst):", ENDL);
	_PRINT_LST_CONTENT_(lst2);
	lst.merge(lst2, paf2);
	_THISTESTIS_("lst (merged lst):", ENDL);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("lst state after:      ", NOENDL);
	_PRINT_LST_(lst);
}

template <typename Container>
void	mergeTest(Container & lst)
{
	Container				lst2;

	lst.sort();
	fillContainer(lst2, 20);
	_THISTESTIS_("merge. before/after:", ENDL);
	_THISTESTIS_("merging list:", ENDL);
	_PRINT_LST_CONTENT_(lst2);
	_THISTESTIS_("list to be merged:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	lst.merge(lst2);
	_THISTESTIS_("list to be merged after the merge:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("merging list after the merge:", ENDL);
	_PRINT_LST_CONTENT_(lst2);

	fillContainer(lst2, 70);
	lst2.sort();
	_THISTESTIS_("merge taller list into smaller one. before/after:", ENDL);
	_THISTESTIS_("merging list:", ENDL);
	_PRINT_LST_CONTENT_(lst2);
	_THISTESTIS_("list to be merged:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	lst.merge(lst2);
	_THISTESTIS_("list to be merged after the merge:", ENDL);
	_PRINT_LST_CONTENT_(lst);
	_THISTESTIS_("merging list after the merge:", ENDL);
	_PRINT_LST_CONTENT_(lst2);

	youpi(lst);
}

///////REVERSE
template <typename Container>
void	reverseTest(Container lst)
{
	lst.clear();
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
	_STD_TITLE_("(int)"); spliceTest(stdlst);
	_FT_TITLE_("(int)"); spliceTest(ftlst);
	_STD_TITLE_("(str)"); spliceTest(stdlst2);
	_FT_TITLE_("(str)"); spliceTest(ftlst2);

	_SSTITLE_("'REMOVE' TEST");
	_STD_TITLE_("(int)"); removeTest(stdlst);
	_FT_TITLE_("(int)"); removeTest(ftlst);
	_STD_TITLE_("(str)"); removeTest(stdlst2);
	_FT_TITLE_("(str)"); removeTest(ftlst2);

	_SSTITLE_("'REMOVE_IF' TEST");
	_STD_TITLE_("(int)"); remove_ifTest(stdlst);
	_FT_TITLE_("(int)"); remove_ifTest(ftlst);
	_STD_TITLE_("(str)"); remove_ifTest(stdlst2);
	_FT_TITLE_("(str)"); remove_ifTest(ftlst2);

	_SSTITLE_("'UNIQUE' TEST");
	_STD_TITLE_("(int)"); uniqueTest(stdlst);
	_FT_TITLE_("(int)"); uniqueTest(ftlst);
	_STD_TITLE_("(str)"); uniqueTest(stdlst2);
	_FT_TITLE_("(str)"); uniqueTest(ftlst2);

	_SSTITLE_("'SORT' TEST");
	_STD_TITLE_("(int)"); sortTest(stdlst);
	_FT_TITLE_("(int)"); sortTest(ftlst);
	_STD_TITLE_("(str)"); sortTest(stdlst2);
	_FT_TITLE_("(str)"); sortTest(ftlst2);

	_SSTITLE_("'MERGE' TEST");
	_STD_TITLE_("(int)"); mergeTest(stdlst);
	_FT_TITLE_("(int)"); mergeTest(ftlst);
	_STD_TITLE_("(str)"); mergeTest(stdlst2);
	_FT_TITLE_("(str)"); mergeTest(ftlst2);

	_SSTITLE_("'REVERSE' TEST");
	_STD_TITLE_("(int)"); reverseTest(stdlst);
	_FT_TITLE_("(int)"); reverseTest(ftlst);
	_STD_TITLE_("(str)"); reverseTest(stdlst2);
	_FT_TITLE_("(str)"); reverseTest(ftlst2);
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
