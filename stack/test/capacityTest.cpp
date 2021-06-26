#include "stack.hpp"
#include "resources.hpp"
#include <stack>

//SIZE TEST
template <typename Container>
void	sizeTest(Container vec)
{
	_THISTESTIS_("size of empty container:             ", NOENDL);
	std::cout << vec.size() << std::endl;

	_THISTESTIS_("5 print of size after 5 fill (5*i++):", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainr(vec, i + 1);
		std::cout << vec.size() << ", ";
	}
	std::cout << std::endl;

	_THISTESTIS_("print of size after a pop:           ", NOENDL);
	vec.pop();
	std::cout << vec.size() << std::endl;
}

//EMPTY TEST
template <typename Container>
void	emptyTest(Container vec)
{
	_THISTESTIS_("empty of empty container:    ", NOENDL);
	std::cout << vec.empty() << std::endl;

	_THISTESTIS_("empty of container of 1 elem:", NOENDL);
	fillContainr(vec, 1);
	std::cout << vec.empty() << std::endl;
}

void	capacityTest()
{
	_STITLE_("CAPACITY TEST");

	std::stack<int>			stdvec;
	ft::stack<int>			ftvec;
	std::stack<std::string>	stdvec2;
	ft::stack<std::string>	ftvec2;

	_SSTITLE_("'SIZE' TEST");
	_STD_TITLE_("(int)"); sizeTest(stdvec);
	_FT_TITLE_("(int)"); sizeTest(ftvec);
	_STD_TITLE_("(str)"); sizeTest(stdvec2);
	_FT_TITLE_("(str)"); sizeTest(ftvec2);

	_SSTITLE_("'EMPTY' TEST");
	_STD_TITLE_("(int)"); emptyTest(stdvec);
	_FT_TITLE_("(int)"); emptyTest(ftvec);
	_STD_TITLE_("(str)"); emptyTest(stdvec2);
	_FT_TITLE_("(str)"); emptyTest(ftvec2);
}

/*
 * size()
 * empty()
*/
