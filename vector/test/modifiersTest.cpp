#include "vector.hpp"
#include "resources.hpp"
#include <vector>

////////////////////////////////////ASSIGN
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	assignTest(Container<Element, Allocator> vec)
{
	typedef Container<Element, Allocator>	container;
	container						vec2;
	typename container::iterator	first;
	typename container::iterator	last;

	_THISTESTIS_("fill assign 10x 21 in a vector which has already 20x 40:");
	for (int i = 0; i < 20; i++)
		vec.push_back(42);
	vec.assign(10, 21);
	_PRINT_VEC_(vec);

	_THISTESTIS_("iterator assign 10x21 vector to a vector which has already\
 20x 40:");
	first = vec.begin();
	last = vec.end();
	for (int i = 0; i < 20; i++)
		vec2.push_back(42);
	_PRINT_VEC_(vec2);
	vec2.assign(first, last);
	_PRINT_VEC_(vec2);
}

/////////////////////////////////////MAIN
void	modifiersTest()
{
	_STITLE_("MODIFIERS TEST");

	std::vector<int>	stdvec;
	ft::vector<int>		ftvec;

	_SSTITLE_("'ASSIGN' TEST");
	_STD_TITLE_("(int)"); assignTest(stdvec);
	//_FT_TITLE_("(int)"); assignTest(ftvec);
	(void)ftvec;
}

/*
 * assign()
 * push_back()
 * pop_back()
 * insert()
 * erase()
 * swap()
 * clear()
*/
