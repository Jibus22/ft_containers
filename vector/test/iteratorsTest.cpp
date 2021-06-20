#include "vector.hpp"
#include "resources.hpp"
#include <vector>

///////BEGIN
template <typename Container>
void	beginTest(Container vec)
{
	fillContainer(vec, 20);
	_THISTESTIS_("begin of x20:  ", NOENDL);
	std::cout << " " << *(vec.begin()) << std::endl;
	fillContainer(vec, 20);
	_THISTESTIS_("begin of x40:  ", NOENDL);
	std::cout << " " << *(vec.begin()) << std::endl;
}

///////END
template <typename Container>
void	endTest(Container vec)
{
	fillContainer(vec, 20);
	_THISTESTIS_("end-1 of x20:  ", NOENDL);
	std::cout << " " << *(vec.end() - 1) << std::endl;
	fillContainer(vec, 10);
	_THISTESTIS_("end-1 of x30:  ", NOENDL);
	std::cout << " " << *(vec.end() - 1) << std::endl;
}

///////RBEGIN
template <typename Container>
void	rbeginTest(Container vec)
{
	typedef typename Container::reverse_iterator	reverse_iterator;
	typedef typename Container::iterator			iterator;
	reverse_iterator		it;
	reverse_iterator		it2;

	fillContainer(vec, 20);
	_THISTESTIS_("rbegin of x20:  ", NOENDL);
	it = vec.rbegin();
	std::cout << " " << *it << std::endl;
	fillContainer(vec, 10);
	it2 = vec.rbegin();
	_THISTESTIS_("begin of x30:   ", NOENDL);
	std::cout << " " << *it << std::endl;

	_THISTESTIS_("comparison < :  ", NOENDL);
	if (it < it2)
		std::cout << " it < it2" << std::endl;
	else
		std::cout << " it > it2" << std::endl;
	_THISTESTIS_("comparison <= : ", NOENDL);
	if (it <= it2)
		std::cout << " it <= it2" << std::endl;
	else
		std::cout << " it >= it2" << std::endl;
	it = it2;

	_THISTESTIS_("assignation '=' and", ENDL);
	_THISTESTIS_("comparison <= : ", NOENDL);
	if (it <= it2)
		std::cout << " it <= it2" << std::endl;
	else
		std::cout << " it >= it2" << std::endl;

	vec.clear();
	fillContainer(vec, 10);
	_THISTESTIS_("reverse print : ", NOENDL);
	for (reverse_iterator i = vec.rbegin(); i != vec.rend(); i++)
		std::cout << " " << *i << ", ";
	std::cout << std::endl;

	_THISTESTIS_("assignation '+='", NOENDL);
	it = vec.rbegin();
	it++;
	it += 1;
	std::cout << " " << *it << std::endl;

	_THISTESTIS_("iterator construction:", NOENDL);
	iterator	itt;
	itt = vec.begin();
	reverse_iterator	bla(itt);
	std::cout << " " << *itt << std::endl;

	_THISTESTIS_("'+' operator:   ", NOENDL);
	it = vec.rbegin() + 4;
	std::cout << " " << *it << std::endl;
}

///////REND
template <typename Container>
void	rendTest(Container vec)
{
	(void)vec;
}

void	iteratorsTest()
{
	_STITLE_("ITERATORS TEST");

	std::vector<int>			stdvec;
	ft::vector<int>				ftvec;
	std::vector<std::string>	stdvec2;
	ft::vector<std::string>		ftvec2;

	_SSTITLE_("'BEGIN' TEST");
	_STD_TITLE_("(int)"); beginTest(stdvec);
	_FT_TITLE_("(int)"); beginTest(ftvec);
	_STD_TITLE_("(str)"); beginTest(stdvec2);
	_FT_TITLE_("(str)"); beginTest(ftvec2);

	_SSTITLE_("'END' TEST");
	_STD_TITLE_("(int)"); endTest(stdvec);
	_FT_TITLE_("(int)"); endTest(ftvec);
	_STD_TITLE_("(str)"); endTest(stdvec2);
	_FT_TITLE_("(str)"); endTest(ftvec2);

	_SSTITLE_("'RBEGIN' TEST");
	_STD_TITLE_("(int)"); rbeginTest(stdvec);
	_FT_TITLE_("(int)"); rbeginTest(ftvec);
	_STD_TITLE_("(str)"); rbeginTest(stdvec2);
	_FT_TITLE_("(str)"); rbeginTest(ftvec2);

	_SSTITLE_("'REND' TEST");
	/*_STD_TITLE_("(int)"); rendTest(stdvec);
	_FT_TITLE_("(int)"); rendTest(ftvec);
	_STD_TITLE_("(str)"); rendTest(stdvec2);
	_FT_TITLE_("(str)"); rendTest(ftvec2);*/
}

/*
 * begin()
 * end()
 * rbegin()
 * rend()
*/
