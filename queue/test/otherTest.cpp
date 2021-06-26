#include "queue.hpp"
#include "resources.hpp"
#include <queue>

///////RELATIONAL OPERATORS
template <typename Container>
void	relationaloperatorsTest(Container lst)
{
	Container	a;
	Container	b;
	Container	c;

	fillContainr(a, 400);
	fillContainr(b, 400);
	fillContainr(c, 500);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";
	(void)lst;
}

////////MAIN
void	otherTest()
{
	_STITLE_("MODIFIERS TEST");

	std::queue<int>			stdlst;
	ft::queue<int>			ftlst;
	std::queue<std::string>	stdlst2;
	ft::queue<std::string>	ftlst2;

	_SSTITLE_("'RELATIONAL OPERATORS' TEST");
	_STD_TITLE_("(int)"); relationaloperatorsTest(stdlst);
	_FT_TITLE_("(int)"); relationaloperatorsTest(ftlst);
	_STD_TITLE_("(str)"); relationaloperatorsTest(stdlst2);
	_FT_TITLE_("(str)"); relationaloperatorsTest(ftlst2);
}

/*
 * relational operators
 * swap
*/
