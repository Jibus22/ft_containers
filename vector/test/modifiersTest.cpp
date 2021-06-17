#include "vector.hpp"
#include "resources.hpp"
#include <vector>
#include <typeinfo>

///////ASSIGN
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	testAssignSFINAE(Container<Element, Allocator> vec)
{
	_THISTESTIS_("testing sfinae__", ENDL);
	_THISTESTIS_("assign 50x21             ", NOENDL);
	vec.assign(50, 21);
	_PRINT_VEC_(vec);
}

template <template <typename, typename> class Container,
		typename Allocator>
void	testAssignSFINAE(Container<std::string, Allocator> vec)
{
	_THISTESTIS_("testing sfinae__", ENDL);
	_THISTESTIS_("assign 50x\"blo\"          ", NOENDL);
	vec.assign(50, "blo");
	_PRINT_VEC_(vec);
}

template <typename Container>
void	assignTest(Container vec)
{
	Container								vec2;
	Container								vec3;
	typename Container::iterator			it1;
	typename Container::iterator			it2;

	_THISTESTIS_("iterator assign from a container x42__", ENDL);
	_THISTESTIS_("assign from begin to b+5:", NOENDL);
	fillContainer(vec, 42);
	it1 = vec.begin();
	it2 = vec.begin() + 5;
	vec2.assign(it1, it2);
	_PRINT_VEC_(vec2);

	_THISTESTIS_("assign from b+10 to b+25:", NOENDL);
	it1 += 10;
	it2 += 20;
	vec2.assign(it1, it2);
	_PRINT_VEC_(vec2);

	_THISTESTIS_("assign from b+40 to b+42:", NOENDL);
	it1 += 30;
	it2 += 17;
	vec2.assign(it1, it2);
	_PRINT_VEC_(vec2);

	_THISTESTIS_("size & value assignment__", ENDL);
	_THISTESTIS_("assign x7                ", NOENDL);
	sizeAssign(vec3, 7);
	_PRINT_VEC_(vec3);

	_THISTESTIS_("assign x907              ", NOENDL);
	sizeAssign(vec3, 907);
	_PRINT_VEC_(vec3);

	testAssignSFINAE(vec3);
}

///////PUSH_BACK
template <typename Container>
void	pushbackTest(Container vec)
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
template <typename Container>
void	popbackTest(Container vec)
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

///////INSERT
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	insertOne(Container<Element, Allocator> & vec,
				typename Container<Element, Allocator>::iterator it)
{
	vec.insert(it, 42);
}

template <template <typename, typename> class Container,
		typename Allocator>
void	insertOne(Container<std::string, Allocator> & vec,
				typename Container<std::string, Allocator>::iterator it)
{
	vec.insert(it, "blo");
}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	insertTwo(Container<Element, Allocator> & vec, size_t n,
				typename Container<Element, Allocator>::iterator it)
{
	vec.insert(it, n, 42);
}

template <template <typename, typename> class Container,
		typename Allocator>
void	insertTwo(Container<std::string, Allocator> & vec, size_t n,
				typename Container<std::string, Allocator>::iterator it)
{
	vec.insert(it, n, "blo");
}

template <typename Container>
void	insertTest(Container vec)
{
	typename Container::iterator		it1;

	_THISTESTIS_("insert one value at it pos in a x16 container__", ENDL);
	_THISTESTIS_("value at pos=5:     ", NOENDL);
	fillContainer(vec, 16);
	it1 = vec.begin() + 5;
	insertOne(vec, it1);
	_PRINT_VEC_(vec);
	_THISTESTIS_("print of content:", ENDL);
	_PRINT_CONTENT_(vec);

	_THISTESTIS_("value at the end:   ", NOENDL);
	it1 = vec.end();
	insertOne(vec, it1);
	_PRINT_VEC_(vec);
	_THISTESTIS_("print of content:   ", ENDL);
	_PRINT_CONTENT_(vec);

	vec.clear();

	_THISTESTIS_("insert many values at it pos 5 in a x16 container__", ENDL);
	_THISTESTIS_("5 values from pos 5:", NOENDL);
	fillContainer(vec, 16);
	it1 = vec.begin() + 5;
	insertTwo(vec, 5, it1);
	_PRINT_VEC_(vec);
	_THISTESTIS_("print of content:", ENDL);
	_PRINT_CONTENT_(vec);

	_THISTESTIS_("12 values from end: ", NOENDL);
	it1 = vec.end();
	insertTwo(vec, 12, it1);
	_PRINT_VEC_(vec);
	_THISTESTIS_("print of content:", ENDL);
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
	_FT_TITLE_("(int)"); assignTest(ftvec);
	_STD_TITLE_("(str)"); assignTest(stdvec2);
	_FT_TITLE_("(str)"); assignTest(ftvec2);

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

	_SSTITLE_("'INSERT' TEST");
	_STD_TITLE_("(int)"); insertTest(stdvec);
	_FT_TITLE_("(int)"); insertTest(ftvec);
	_STD_TITLE_("(str)"); insertTest(stdvec2);
	_FT_TITLE_("(str)"); insertTest(ftvec2);

	_SSTITLE_("'ERASE' TEST");
	/*_STD_TITLE_("(int)"); eraseTest(stdvec);
	_FT_TITLE_("(int)"); eraseTest(ftvec);
	_STD_TITLE_("(str)"); eraseTest(stdvec2);
	_FT_TITLE_("(str)"); eraseTest(ftvec2);*/

	_SSTITLE_("'SWAP' TEST");
	/*_STD_TITLE_("(int)"); swapTest(stdvec);
	_FT_TITLE_("(int)"); swapTest(ftvec);
	_STD_TITLE_("(str)"); swapTest(stdvec2);
	_FT_TITLE_("(str)"); swapTest(ftvec2);*/

	_SSTITLE_("'CLEAR' TEST");
	/*_STD_TITLE_("(int)"); clearTest(stdvec);
	_FT_TITLE_("(int)"); clearTest(ftvec);
	_STD_TITLE_("(str)"); clearTest(stdvec2);
	_FT_TITLE_("(str)"); clearTest(ftvec2);*/
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
