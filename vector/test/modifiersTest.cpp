#include "vector.hpp"
#include "resources.hpp"
#include <vector>

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

	_SPLIT_LINE_();
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
{vec.insert(it, 42);}

template <template <typename, typename> class Container,
		typename Allocator>
void	insertOne(Container<std::string, Allocator> & vec,
				typename Container<std::string, Allocator>::iterator it)
{vec.insert(it, "blo");}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	insertTwo(Container<Element, Allocator> & vec, size_t n,
				typename Container<Element, Allocator>::iterator it)
{vec.insert(it, n, 42);}

template <template <typename, typename> class Container,
		typename Allocator>
void	insertTwo(Container<std::string, Allocator> & vec, size_t n,
				typename Container<std::string, Allocator>::iterator it)
{vec.insert(it, n, "blo");}

template <typename Container>
void	insertTest(Container vec)
{
	Container						vec2;
	typename Container::iterator	it1;
	typename Container::iterator	it2;

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

	_SPLIT_LINE_();
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

	_THISTESTIS_("194 values from end:", NOENDL);
	it1 = vec.end();
	insertTwo(vec, 194, it1);
	_PRINT_VEC_(vec);

	vec.clear();

	_SPLIT_LINE_();
	_THISTESTIS_("third insert: from container it range, at a pos___", ENDL);
	fillContainer(vec2, 20);
	it1 = vec2.begin() + 5;
	it2 = it1 + 10;
	fillContainer(vec, 10);
	_THISTESTIS_("10 values at end-2 of cont(10):", NOENDL);
	vec.insert(vec.end() - 2, it1, it2);
	_PRINT_VEC_(vec);
	it1 += 5;
	it2 += 3;
	_THISTESTIS_("8 values at end-8 of cont(20): ", NOENDL);
	vec.insert(vec.end() - 8, it1, it2);
	_PRINT_VEC_(vec);

	_THISTESTIS_("print of content:", ENDL);
	_PRINT_CONTENT_(vec);
}

///////ERASE
template <typename Container>
void	eraseTest(Container vec)
{
	typename Container::iterator	it;

	_THISTESTIS_("erase value pos 5 in a x10 container", ENDL);
	_THISTESTIS_("content displayed as : before, after", ENDL);
	fillContainer(vec, 10);
	_PRINT_CONTENT_(vec);
	it = vec.erase(vec.begin() + 5);
	_PRINT_CONTENT_(vec);

	_THISTESTIS_("print erase iterator return: ", NOENDL);
	std::cout << *it << std::endl;

	_THISTESTIS_("erase first value, display content & return:", ENDL);
	it = vec.erase(vec.begin());
	_PRINT_CONTENT_(vec);
	std::cout << *it << std::endl;

	_THISTESTIS_("erase last value, display content & return:", ENDL);
	it = vec.erase(vec.end() - 1);
	_PRINT_CONTENT_(vec);
	std::cout << *it << std::endl;

	_THISTESTIS_("finally print state:", NOENDL);
	_PRINT_VEC_(vec);

	_SPLIT_LINE_();
	_THISTESTIS_("second erase test: from it range", ENDL);
	_THISTESTIS_("erase begin to begin + 3, print content & return:", ENDL);
	it = vec.erase(vec.begin(), vec.begin() + 3);
	_PRINT_CONTENT_(vec);
	std::cout << *it << std::endl;

	_THISTESTIS_("erase begin+1 to end, print content & return:", ENDL);
	it = vec.erase(vec.begin() + 1, vec.end());
	_PRINT_CONTENT_(vec);
	std::cout << *it << std::endl;
}

///////SWAP
template <typename Container>
void	swapTest(Container vec)
{
	Container			vec2;
	typename Container::iterator	it;
	typename Container::iterator	it2;

	_THISTESTIS_("swap const vecx10 with var vecx20", ENDL);
	fillContainer(vec, 20);
	sizeAssign(vec2, 10);
	it = vec.begin();
	it2 = vec2.begin();
	_THISTESTIS_("vec state before:     ", NOENDL);
	_PRINT_VEC_(vec);
	_THISTESTIS_("vec2 state before:    ", NOENDL);
	_PRINT_VEC_(vec2);
	_THISTESTIS_("iterator 1 & 2 before:", NOENDL);
	std::cout << "   " << *it << "  " << *it2 << std::endl;
	vec.swap(vec2);
	_THISTESTIS_("vec state after:      ", NOENDL);
	_PRINT_VEC_(vec);
	_THISTESTIS_("vec2 state after:     ", NOENDL);
	_PRINT_VEC_(vec2);
	_THISTESTIS_("iterator 1 & 2 after: ", NOENDL);
	std::cout << "   " << *it << "  " << *it2 << std::endl;
}

///////CLEAR
template <typename Container>
void	clearTest(Container vec)
{
	fillContainer(vec, 2000);
	_THISTESTIS_("clear container x2000", ENDL);
	_THISTESTIS_("vec state before:     ", NOENDL);
	_PRINT_VEC_(vec);
	vec.clear();
	_THISTESTIS_("vec state after:      ", NOENDL);
	_PRINT_VEC_(vec);
	_THISTESTIS_("clear empty container:", NOENDL);
	vec.clear();
	_PRINT_VEC_(vec);
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
	_STD_TITLE_("(int)"); eraseTest(stdvec);
	_FT_TITLE_("(int)"); eraseTest(ftvec);
	_STD_TITLE_("(str)"); eraseTest(stdvec2);
	_FT_TITLE_("(str)"); eraseTest(ftvec2);

	_SSTITLE_("'SWAP' TEST");
	_STD_TITLE_("(int)"); swapTest(stdvec);
	_FT_TITLE_("(int)"); swapTest(ftvec);
	_STD_TITLE_("(str)"); swapTest(stdvec2);
	_FT_TITLE_("(str)"); swapTest(ftvec2);

	_SSTITLE_("'CLEAR' TEST");
	_STD_TITLE_("(int)"); clearTest(stdvec);
	_FT_TITLE_("(int)"); clearTest(ftvec);
	_STD_TITLE_("(str)"); clearTest(stdvec2);
	_FT_TITLE_("(str)"); clearTest(ftvec2);
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
