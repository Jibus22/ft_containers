#include "list.hpp"
#include "resources.hpp"
#include <list>

///////BEGIN
/*
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
*/
///////UTILS
template <template <typename, typename> class Container,
		typename Element, typename Allocator, typename Iterator>
void	itchg(Container<Element, Allocator>& vec, Iterator it)
{
	_THISTESTIS_("change value thru iterator:  ", NOENDL);
	*it = 1234567890;
	std::cout << " " << *it << std::endl;
	(void)vec;
}

template <template <typename, typename> class Container,
		typename Allocator, typename Iterator>
void	itchg(Container<std::string, Allocator>& vec, Iterator it)
{
	_THISTESTIS_("change value thru iterator:  ", NOENDL);
	*it = std::string("BLIBLOUBLA");
	std::cout << " " << *it << std::endl;
	(void)vec;
}

///////BEGIN
template <typename Container>
void	beginTest(Container vec)
{
	typedef Container								container;
	typedef typename container::const_iterator		const_iterator;
	typedef typename container::iterator			iterator;

	const_iterator		cit;
	iterator			it;
	iterator			it2;

	fillContainer(vec, 20);

	_THISTESTIS_("begin of x20, const iterator:  ", NOENDL);
	cit = vec.begin();
	std::cout << " " << *(vec.begin()) << std::endl;

	_THISTESTIS_("begin of x20:  ", NOENDL);
	std::cout << " " << *(vec.begin()) << std::endl;
	fillContainer(vec, 20);
	_THISTESTIS_("begin of x40:  ", NOENDL);
	std::cout << " " << *(vec.begin()) << std::endl;

	itchg(vec, vec.begin());

	it = vec.begin();
	it2 = vec.begin();
	for (int i=0; i < 3; i++, it2++);
	_THISTESTIS_("comparison !=/== : ", NOENDL);
	if (it != it2)
		std::cout << " it != it2" << std::endl;
	else
		std::cout << " it == it2" << std::endl;

	_THISTESTIS_("assignation '=' and", ENDL);
	it = it2;
	_THISTESTIS_("comparison !=/== : ", NOENDL);
	if (it != it2)
		std::cout << " it != it2" << std::endl;
	else
		std::cout << " it == it2" << std::endl;

	_THISTESTIS_("iterator construction:", NOENDL);
	iterator	bla(it2);
	std::cout << " " << *bla << std::endl;

	_THISTESTIS_("const_iterator constructed with iterator:   ", NOENDL);
	const_iterator	cit2(it);
	std::cout << " " << *cit2 << std::endl;
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

	itchg(lst, it);
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

	std::list<int>			stdlst;
	ft::list<int>			ftlst;
	std::list<std::string>	stdlst2;
	ft::list<std::string>	ftlst2;

	_SSTITLE_("'BEGIN' TEST");
	_STD_TITLE_("(int)"); beginTest(stdlst);
	_FT_TITLE_("(int)"); beginTest(ftlst);
	_STD_TITLE_("(str)"); beginTest(stdlst2);
	_FT_TITLE_("(str)"); beginTest(ftlst2);

	_SSTITLE_("'END' TEST");
	_STD_TITLE_("(int)"); endTest(stdlst);
	_FT_TITLE_("(int)"); endTest(ftlst);
	_STD_TITLE_("(str)"); endTest(stdlst2);
	_FT_TITLE_("(str)"); endTest(ftlst2);

	_SSTITLE_("'RBEGIN' TEST");
	_STD_TITLE_("(int)"); rbeginTest(stdlst);
	_FT_TITLE_("(int)"); rbeginTest(ftlst);
	_STD_TITLE_("(str)"); rbeginTest(stdlst2);
	_FT_TITLE_("(str)"); rbeginTest(ftlst2);

	_SSTITLE_("'REND' TEST");
	_STD_TITLE_("(int)"); rendTest(stdlst);
	_FT_TITLE_("(int)"); rendTest(ftlst);
	_STD_TITLE_("(str)"); rendTest(stdlst2);
	_FT_TITLE_("(str)"); rendTest(ftlst2);
}

/*
 * begin()
 * end()
 * rbegin()
 * rend()
*/
