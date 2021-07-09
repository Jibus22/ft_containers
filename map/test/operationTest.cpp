#include "map.hpp"
#include "resources.hpp"
#include <map>

///////FIND
template <typename Container>
void	findTest(Container mapp)
{
	typedef typename Container::iterator			iterator;
	typedef typename Container::const_iterator		const_iterator;
	iterator		ret, fin;

	fillmap(mapp, 1);
	fin = mapp.end();
	_THISTESTIS_("find(key) -> 50, 62, 30, 120:", ENDL);
	ret = mapp.find(50);
	_THISTESTIS_("return of find:         ", NOENDL);
	if (ret != fin)
		_DISPLAY_MAP_NODE_(ret);
	ret = mapp.find(62);
	_THISTESTIS_("return of find:         ", NOENDL);
	if (ret != fin)
		_DISPLAY_MAP_NODE_(ret);
	ret = mapp.find(30);
	_THISTESTIS_("return of find:         ", NOENDL);
	if (ret != fin)
		_DISPLAY_MAP_NODE_(ret);
	_THISTESTIS_("", ENDL);
	const_iterator ret2 = mapp.find(120);
	_THISTESTIS_("const return of find:   ", NOENDL);
	if (ret2 != fin)
		_DISPLAY_MAP_NODE_(ret2);
}

///////COUNT
template <typename Container>
void	countTest(Container mapp)
{
	typedef typename Container::size_type	size_type;

	size_type	ret;

	fillmap(mapp, 1);
	_THISTESTIS_("count(key) -> 50, 62, 30, 120:", ENDL);
	ret = mapp.count(50);
	_THISTESTIS_("return of count:         ", NOENDL);
	std::cout << "ret:\t" << ret << std::endl;
	ret = mapp.count(62);
	_THISTESTIS_("return of count:         ", NOENDL);
	std::cout << "ret:\t" << ret << std::endl;
	ret = mapp.count(30);
	_THISTESTIS_("return of count:         ", NOENDL);
	std::cout << "ret:\t" << ret << std::endl;
	ret = mapp.count(120);
	_THISTESTIS_("const return of count:   ", NOENDL);
	std::cout << "ret:\t" << ret << std::endl;
}

///////LOWERBOUND
template <typename Container>
void	lbound(Container & mapp, int n)
{
	typedef typename Container::iterator	iterator;
	iterator		ret, fin;

	fin = mapp.end();
	ret = mapp.lower_bound(n);
	_THISTESTIS_("return of lower_bound:         ", NOENDL);
	if (ret != fin)
		_DISPLAY_MAP_NODE_(ret);
}
template <typename Container>
void	lowerboundTest(Container mapp)
{
	typedef typename Container::iterator			iterator;
	typedef typename Container::const_iterator		const_iterator;
	iterator		ret, fin;

	fillmap(mapp, 1);
	fin = mapp.end();
	_THISTESTIS_("lower_bound(key) ->0, 5, 7, 49, 50, 51, 30, 120, 130:", ENDL);
	lbound(mapp, 0);
	lbound(mapp, 5);
	lbound(mapp, 7);
	lbound(mapp, 49);
	lbound(mapp, 50);
	lbound(mapp, 51);
	lbound(mapp, 30);
	_THISTESTIS_("", ENDL);
	const_iterator ret2 = mapp.lower_bound(120);
	_THISTESTIS_("const return of lower_bound:   ", NOENDL);
	if (ret2 != fin)
		_DISPLAY_MAP_NODE_(ret2);
	lbound(mapp, 130);
	_THISTESTIS_("", ENDL);
}

///////UPPERBOUND
template <typename Container>
void	ubound(Container & mapp, int n)
{
	typedef typename Container::iterator	iterator;
	iterator		ret, fin;

	fin = mapp.end();
	ret = mapp.upper_bound(n);
	_THISTESTIS_("return of lower_bound:         ", NOENDL);
	if (ret != fin)
		_DISPLAY_MAP_NODE_(ret);
}
template <typename Container>
void	upperboundTest(Container mapp)
{
	typedef typename Container::iterator			iterator;
	typedef typename Container::const_iterator		const_iterator;
	iterator		ret, fin;

	fillmap(mapp, 1);
	fin = mapp.end();
	_THISTESTIS_("upper_bound(key) ->0, 5, 7, 49, 50, 51, 30, 120, 130:", ENDL);
	ubound(mapp, 0);
	ubound(mapp, 5);
	ubound(mapp, 7);
	ubound(mapp, 49);
	ubound(mapp, 50);
	ubound(mapp, 51);
	ubound(mapp, 30);
	_THISTESTIS_("", ENDL);
	const_iterator ret2 = mapp.upper_bound(120);
	_THISTESTIS_("const return of upper_bound:   ", NOENDL);
	if (ret2 != fin)
		_DISPLAY_MAP_NODE_(ret2);
	ubound(mapp, 130);
	_THISTESTIS_("", ENDL);
}

////////EQUALRANGE
template <template <typename, typename, typename, typename> class Container,
		typename Key, typename T, typename Allocator>
void	eq_range(Container<Key, T, ft::less<Key>, Allocator> & mapp, int n)
{
	typedef
		typename Container<Key, T, ft::less<Key>, Allocator>::iterator	iterator;
	ft::pair<iterator, iterator>			pr;

	pr = mapp.equal_range(n);
	_THISTESTIS_("it1, it2:   ", NOENDL);
	std::cout << " (" << n << ") " << std::endl;
	if (pr.first != mapp.end())
		_DISPLAY_MAP_NODE_(pr.first);
	else
		std::cout << "..X.." << std::endl;
	if (pr.second != mapp.end())
		_DISPLAY_MAP_NODE_(pr.second);
	else
		std::cout << "..X.." << std::endl;
}

template <template <typename, typename, typename, typename> class Container,
		typename Key, typename T, typename Compare, typename Allocator>
void	eq_range(Container<Key, T, Compare, Allocator> & mapp, int n)
{
	typedef typename Container<Key, T, Compare, Allocator>::iterator	iterator;
	std::pair<iterator, iterator>			pr;

	pr = mapp.equal_range(n);
	_THISTESTIS_("it1, it2:   ", NOENDL);
	std::cout << " (" << n << ") " << std::endl;
	if (pr.first != mapp.end())
		_DISPLAY_MAP_NODE_(pr.first);
	else
		std::cout << "..X.." << std::endl;
	if (pr.second != mapp.end())
		_DISPLAY_MAP_NODE_(pr.second);
	else
		std::cout << "..X.." << std::endl;
}

template <template <typename, typename, typename, typename> class Container,
		typename Key, typename T, typename Compare, typename Allocator>
void	consteq_range(Container<Key, T, Compare, Allocator> & mapp, int n)
{
	typedef typename Container<Key, T, Compare, Allocator>::const_iterator
		const_iterator;
	std::pair<const_iterator, const_iterator>		pr;

	pr = mapp.equal_range(n);
	_THISTESTIS_("it1, it2:   ", NOENDL);
	std::cout << " (" << n << ") " << std::endl;
	if (pr.first != mapp.end())
		_DISPLAY_MAP_NODE_(pr.first);
	else
		std::cout << "..X.." << std::endl;
	if (pr.second != mapp.end())
		_DISPLAY_MAP_NODE_(pr.second);
	else
		std::cout << "..X.." << std::endl;
}

template <template <typename, typename, typename, typename> class Container,
		typename Key, typename T, typename Allocator>
void	consteq_range(Container<Key, T, ft::less<Key>, Allocator> & mapp, int n)
{
	typedef typename Container<Key, T, ft::less<Key>, Allocator>::const_iterator
		const_iterator;
	ft::pair<const_iterator, const_iterator>		pr;

	pr = mapp.equal_range(n);
	_THISTESTIS_("it1, it2:   ", NOENDL);
	std::cout << " (" << n << ") " << std::endl;
	if (pr.first != mapp.end())
		_DISPLAY_MAP_NODE_(pr.first);
	else
		std::cout << "..X.." << std::endl;
	if (pr.second != mapp.end())
		_DISPLAY_MAP_NODE_(pr.second);
	else
		std::cout << "..X.." << std::endl;
}

template <typename Container>
void	equalrangeTest(Container mapp)
{
	fillmap(mapp, 1);
	_THISTESTIS_("equal_range(key) ->0, 5, 7, 49, 50, 51, 30, 120, 130:", ENDL);
	eq_range(mapp, 0);
	eq_range(mapp, 5);
	eq_range(mapp, 7);
	eq_range(mapp, 49);
	eq_range(mapp, 50);
	eq_range(mapp, 51);
	eq_range(mapp, 30);
	eq_range(mapp, 120);
	eq_range(mapp, 130);
	_THISTESTIS_("const equal_range(key) 78:", ENDL);
	consteq_range(mapp, 77);
}

////////MAIN
void	operationTest()
{
	_STITLE_("OPERATION TEST");

	std::map<int, std::string>			stdmapp;
	ft::map<int, std::string>			ftmapp;

	_SSTITLE_("'FIND' TEST");
	_STD_TITLE_("(int, std::string)"); findTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); findTest(ftmapp);

	_SSTITLE_("'COUNT' TEST");
	_STD_TITLE_("(int, std::string)"); countTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); countTest(ftmapp);

	_SSTITLE_("'LOWERBOUND' TEST");
	_STD_TITLE_("(int, std::string)"); lowerboundTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); lowerboundTest(ftmapp);

	_SSTITLE_("'UPPERBOUND' TEST");
	_STD_TITLE_("(int, std::string)"); upperboundTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); upperboundTest(ftmapp);

	_SSTITLE_("'EQUAL_RANGE' TEST");
	_STD_TITLE_("(int, std::string)"); equalrangeTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); equalrangeTest(ftmapp);
}

/*
 * find()
 * count()
 * lower_bound()
 * upper_bound()
 * equal_range()
*/
