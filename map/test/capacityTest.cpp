#include "map.hpp"
#include "resources.hpp"
#include <map>

//EMPTY TEST
template <typename Container>
void	emptyTest(Container mapp)
{
	_THISTESTIS_("empty of empty container:      ", NOENDL);
	std::cout << mapp.empty() << std::endl;

	_THISTESTIS_("empty of container of 20 elem: ", NOENDL);
	fillmap(mapp, 1);
	std::cout << mapp.empty() << std::endl;

	_THISTESTIS_("empty of container after clear:", NOENDL);
	mapp.clear();
	std::cout << mapp.empty() << std::endl;
}

//SIZE TEST
template <typename Container>
void	sizeTest(Container mapp)
{
	typedef typename Container::const_iterator	const_iterator;

	_THISTESTIS_("size of empty container:             ", NOENDL);
	_PRINT_MAP_(mapp);

	_THISTESTIS_("5 print of size after 5 fill (5*i++):", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillmap(mapp, i + 1);
		std::cout << mapp.size() << ", ";
	}
	std::cout << std::endl;

	_THISTESTIS_("print of size after a erase:         ", NOENDL);
	mapp.erase(const_iterator(mapp.begin()));
	_PRINT_MAP_(mapp);

	_THISTESTIS_("size of container after clear:       ", NOENDL);
	mapp.clear();
	std::cout << mapp.size() << std::endl;
}

//MAX_SIZE TEST
template <typename Container>
void	maxsizeTest(Container mapp)
{
	_THISTESTIS_("max_size of container:", NOENDL);
	std::cout << mapp.max_size() << std::endl;
}

void	capacityTest()
{
	_STITLE_("CAPACITY TEST");

	std::map<int, std::string>			stdmapp;
	ft::map<int, std::string>			ftmapp;

	_SSTITLE_("'EMPTY' TEST");
	_STD_TITLE_("(int, std::string)"); emptyTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); emptyTest(ftmapp);

	_SSTITLE_("'SIZE' TEST");
	_STD_TITLE_("(int, std::string)"); sizeTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); sizeTest(ftmapp);

	_SSTITLE_("'MAX_SIZE' TEST");
	_STD_TITLE_("(int, std::string)"); maxsizeTest(stdmapp);
	_FT_TITLE_("(int, std::string)"); maxsizeTest(ftmapp);
}

/*
 * size()
 * max_size()
 * resize()
 * capacity()
 * empty()
 * reserve()
*/
