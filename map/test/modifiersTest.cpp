#include "map.hpp"
#include "resources.hpp"
#include <map>

///////INSERT
template <template <typename, typename, typename, typename> class Container,
		typename Key, typename T, typename Compare, typename Allocator>
std::pair<Key, T>	mkpair(Container<Key, T, Compare, Allocator> & mapp,
							int n, std::string s)
{
	(void)mapp;
	return std::make_pair(n, s);
}

template <template <typename, typename, typename, typename> class Container,
		typename Key, typename T, typename Allocator>
ft::pair<Key, T>	mkpair(Container<Key, T, ft::less<Key>, Allocator> & mapp,
							int n, std::string s)
{
	(void)mapp;
	return ft::make_pair(n, s);
}

template <template <typename, typename, typename, typename> class Container,
		typename Key, typename T, typename Compare, typename Allocator>
void	printreturn(Container<Key, T, Compare, Allocator> & mapp,
							int n, std::string s)
{
	typedef typename Container<Key, T, Compare, Allocator>::iterator iterator;
	std::pair<iterator, bool>		ret = mapp.insert(mkpair(mapp, n, s));
	_THISTESTIS_("return of insert(value). iterator:", NOENDL);
	_DISPLAY_MAP_NODE_(ret.first);
	_THISTESTIS_("bolean:  ", NOENDL);
	std::cout << ret.second << std::endl;
}

template <template <typename, typename, typename, typename> class Container,
		typename Key, typename T, typename Allocator>
void	printreturn(Container<Key, T, ft::less<Key>, Allocator> & mapp,
							int n, std::string s)
{
	typedef typename
		Container<Key, T, ft::less<Key>, Allocator>::iterator iterator;
	ft::pair<iterator, bool>		ret = mapp.insert(mkpair(mapp, n, s));
	_THISTESTIS_("return of insert(value). iterator:", NOENDL);
	_DISPLAY_MAP_NODE_(ret.first);
	_THISTESTIS_("bolean:  ", NOENDL);
	std::cout << ret.second << std::endl;
}

template <typename Container>
void	insertTest(Container mapp)
{
	typedef typename Container::iterator iterator;
	
	Container		mapp2;
	iterator		it1, ret;

	_THISTESTIS_("MAP1. test of insert(iterator, value_type): ", ENDL);
	fillmap(mapp, 1);
	_THISTESTIS_("before: ", ENDL);
	_PRINT_MAP_CONTENT_(mapp);
	_THISTESTIS_("", ENDL);
	_THISTESTIS_("insert one value (26, \"Z\") at it pos (beg+5) in a x20\
container__", ENDL);
	it1 = mapp.begin();
	for (size_t i = 0; i < 5; i++)
		it1++;
	ret = mapp.insert(it1, mkpair(mapp, 26, "Z"));
	_THISTESTIS_("print of content after:", ENDL);
	_PRINT_MAP_CONTENT_(mapp);
	_THISTESTIS_("return of insert(iterator, value):", NOENDL);
	_DISPLAY_MAP_NODE_(ret);
	_THISTESTIS_("", ENDL);

	_THISTESTIS_("insert value with wrong it position (beg+5) & existing key\
(78, \"X\"): ", ENDL);
	ret = mapp.insert(it1, mkpair(mapp, 78, "X"));
	_THISTESTIS_("print of content after:", ENDL);
	_PRINT_MAP_CONTENT_(mapp);
	_THISTESTIS_("return of insert(iterator, value):", NOENDL);
	_DISPLAY_MAP_NODE_(ret);
	_THISTESTIS_("", ENDL);

	_THISTESTIS_("insert value (79, \"X\") with wrong it position \
(beg+5): ", ENDL);
	ret = mapp.insert(it1, mkpair(mapp, 79, "X"));
	_THISTESTIS_("print of content after:", ENDL);
	_PRINT_MAP_CONTENT_(mapp);
	_THISTESTIS_("return of insert(iterator, value):", NOENDL);
	_DISPLAY_MAP_NODE_(ret);

	_SPLIT_LINE_();
	_THISTESTIS_("MAP2. test of insert(value_type). insert 3 new values \
then a duplicate: ", ENDL);
	_THISTESTIS_("", ENDL);
	printreturn(mapp2, 52, "BLA");
	printreturn(mapp2, 22, "ZOU");
	printreturn(mapp2, 69, "PAF");
	printreturn(mapp2, 22, "TCHIN!");
	_THISTESTIS_("print of content after:", ENDL);
	_PRINT_MAP_CONTENT_(mapp2);

	_SPLIT_LINE_();
	_THISTESTIS_("test of insert(it first, it last). \
MAP1 into MAP2", ENDL);
	mapp2.insert(mapp.begin(), mapp.end());
	_THISTESTIS_("print of content after:", ENDL);
	_PRINT_MAP_CONTENT_(mapp2);
}

///////ERASE
template <typename Container>
void	eraseTest(Container mapp)
{
	typename Container::iterator	it, it2;
	typename Container::size_type	ret;

	fillmap(mapp, 1);
	_THISTESTIS_("test of erase(iterator): ", ENDL);
	_THISTESTIS_("before: ", ENDL);
	_PRINT_MAP_CONTENT_(mapp);
	_THISTESTIS_("", ENDL);
	_THISTESTIS_("erase begin: ", ENDL);
	mapp.erase(mapp.begin());
	_THISTESTIS_("after: ", ENDL);
	_PRINT_MAP_CONTENT_(mapp);

	_THISTESTIS_("erase end-1: ", ENDL);
	it2 = mapp.end();
	it2--;
	mapp.erase(it2);
	_THISTESTIS_("after: ", ENDL);
	_PRINT_MAP_CONTENT_(mapp);

	_SPLIT_LINE_();

	_THISTESTIS_("test of erase(value). 22, 75, 100, 75: ", ENDL);
	_THISTESTIS_("return: ", NOENDL);
	ret = mapp.erase(22);
	std::cout << ret << ", ";
	ret = mapp.erase(75);
	std::cout << ret << ", ";
	ret = mapp.erase(100);
	std::cout << ret << ", ";
	ret = mapp.erase(75);
	std::cout << ret << std::endl;
	_THISTESTIS_("after: ", ENDL);
	_PRINT_MAP_CONTENT_(mapp);

	_THISTESTIS_("test of erase(it first, it last). begin+3 to end-3: ", ENDL);
	it = mapp.begin();
	it2 = mapp.end();
	for (int i = 0; i < 3; i++, ++it, --it2);
	mapp.erase(it, it2);
	_THISTESTIS_("after: ", ENDL);
	_PRINT_MAP_CONTENT_(mapp);

	_THISTESTIS_("test of erase(it first, it last). begin to end: ", ENDL);
	mapp.erase(mapp.begin(), mapp.end());
	_THISTESTIS_("after: ", ENDL);
	_PRINT_MAP_CONTENT_(mapp);
}

///////SWAP
template <typename Container>
void	swapTest(Container mapp)
{
	Container			mapp2;
	typename Container::iterator	it;
	typename Container::iterator	it2;

	_THISTESTIS_("swap const mappx20 with var mappx53", ENDL);
	fillmap(mapp, 1);
	fillmap(mapp2, 3);
	it = mapp.begin();
	it++;
	it2 = mapp2.begin();
	_THISTESTIS_("mapp state before:     ", NOENDL);
	_PRINT_MAP_(mapp);
	_THISTESTIS_("mapp2 state before:    ", NOENDL);
	_PRINT_MAP_(mapp2);
	_THISTESTIS_("iterator 1 & 2 before:", ENDL);
	_DISPLAY_MAP_NODE_(it);
	_DISPLAY_MAP_NODE_(it2);
	mapp.swap(mapp2);
	_THISTESTIS_("mapp state after:      ", NOENDL);
	_PRINT_MAP_(mapp);
	_THISTESTIS_("mapp2 state after:     ", NOENDL);
	_PRINT_MAP_(mapp2);
	_THISTESTIS_("iterator 1 & 2 after: ", ENDL);
	_DISPLAY_MAP_NODE_(it);
	_DISPLAY_MAP_NODE_(it2);
}

///////CLEAR
template <typename Container>
void	clearTest(Container mapp)
{
	fillmap(mapp, 2000);
	_THISTESTIS_("clear container x25400", ENDL);
	_THISTESTIS_("mapp state before:     ", NOENDL);
	_PRINT_MAP_(mapp);
	mapp.clear();
	_THISTESTIS_("mapp state after:      ", NOENDL);
	_PRINT_MAP_(mapp);
	_THISTESTIS_("clear empty container: ", NOENDL);
	mapp.clear();
	_PRINT_MAP_(mapp);
}

////////MAIN
void	modifiersTest()
{
	_STITLE_("MODIFIERS TEST");

	std::map<int, std::string>			stdmapp;
	ft::map<int, std::string>			ftmapp;

	_SSTITLE_("'INSERT' TEST");
	_STD_TITLE_("(int, std::string)"); insertTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); insertTest(ftmapp);

	_SSTITLE_("'ERASE' TEST");
	_STD_TITLE_("(int, std::string)"); eraseTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); eraseTest(ftmapp);

	_SSTITLE_("'SWAP' TEST");
	_STD_TITLE_("(int, std::string)"); swapTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); swapTest(ftmapp);

	_SSTITLE_("'CLEAR' TEST");
	_STD_TITLE_("(int, std::string)"); clearTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); clearTest(ftmapp);
}

/*
 * insert()
 * erase()
 * swap()
 * clear()
*/
