#include "vector.hpp"
#include "resources.hpp"
#include <vector>

///////ASSIGN
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	assignTest(Container<Element, Allocator> vec)
{
	typedef Container<Element, Allocator>	container;
	container						vec2;
	typename container::iterator	first;
	typename container::iterator	last;

	_THISTESTIS_("fill assign 10x21 in a vector which has already 20x40:", ENDL);
	for (int i = 0; i < 20; i++)
		vec.push_back(42);
	vec.assign(10, 21);
	_PRINT_VEC_(vec);

	_THISTESTIS_("iterator assign 10x21 vector to a vector which has already\
 20x40:", ENDL);
	first = vec.begin();
	last = vec.end();
	for (int i = 0; i < 20; i++)
		vec2.push_back(42);
	_PRINT_VEC_(vec2);
	vec2.assign(first, last);
	_PRINT_VEC_(vec2);
}

///////PUSH_BACK
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	pushbackTest(Container<Element, Allocator> vec)
{
	_THISTESTIS_("10 push_back:      ", NOENDL);
	fillContainer(vec, 10);
	_PRINT_VEC_(vec);

	_THISTESTIS_("50 more push_back: ", NOENDL);
	fillContainer(vec, 50);
	_PRINT_VEC_(vec);

	_THISTESTIS_("print of content:  ", ENDL);
	_PRINT_CONTENT_(vec);

	_THISTESTIS_("500 more push_back:", NOENDL);
	fillContainer(vec, 500);
	_PRINT_VEC_(vec);
}

///////POP_BACK
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	popbackTest(Container<Element, Allocator> vec)
{
	_THISTESTIS_("State of current container", ENDL);
	_THISTESTIS_("with 500 elem:   ", NOENDL);
	fillContainer(vec, 500);
	_PRINT_VEC_(vec);

	_THISTESTIS_("pop 10 elements: ", NOENDL);
	for (size_t i = 0; i < 10; i++)
		vec.pop_back();
	_PRINT_VEC_(vec);

	_THISTESTIS_("pop 200 elements:", NOENDL);
	for (size_t i = 0; i < 200; i++)
		vec.pop_back();
	_PRINT_VEC_(vec);

	_THISTESTIS_("pop 290 elements:", NOENDL);
	for (size_t i = 0; i < 290; i++)
		vec.pop_back();
	_PRINT_VEC_(vec);

	_THISTESTIS_("print of content:  ", ENDL);
	_PRINT_CONTENT_(vec);
}

////////MAIN
void	modifiersTest()
{
	_STITLE_("MODIFIERS TEST");

	std::vector<int>			stdvec;
	ft::vector<int>				ftvec;
	std::vector<std::string>	stdvec2;
	ft::vector<std::string>		ftvec2;

	_SSTITLE_("'ASSIGN' TEST");
	_STD_TITLE_("(int)"); assignTest(stdvec);
	//_FT_TITLE_("(int)"); assignTest(ftvec);

	_SSTITLE_("'PUSH_BACK' TEST");
	_STD_TITLE_("(int)"); pushbackTest(stdvec);
	_FT_TITLE_("(int)"); pushbackTest(ftvec);
	_STD_TITLE_("(str)"); pushbackTest(stdvec2);
	_FT_TITLE_("(str)"); pushbackTest(ftvec2);

	_SSTITLE_("'POP_BACK' TEST");
	_STD_TITLE_("(int)"); popbackTest(stdvec);
	_FT_TITLE_("(int)"); popbackTest(ftvec);
	_STD_TITLE_("(str)"); popbackTest(stdvec2);
	_FT_TITLE_("(str)"); popbackTest(ftvec2);
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
