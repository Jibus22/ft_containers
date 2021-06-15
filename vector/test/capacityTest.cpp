#include "vector.hpp"
#include "resources.hpp"
#include <vector>

//SIZE TEST
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	sizeTest(Container<Element, Allocator> vec)
{
	_THISTESTIS_("size of empty container:             ", NOENDL);
	std::cout << vec.size() << std::endl;

	_THISTESTIS_("5 print of size after 5 fill (5*i++):", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainer(vec, i + 1);
		std::cout << vec.size() << ", ";
	}
	std::cout << std::endl;

	_THISTESTIS_("print of size after a pop:           ", NOENDL);
	vec.pop_back();
	std::cout << vec.size() << std::endl;
}

//MAX_SIZE TEST
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	maxsizeTest(Container<Element, Allocator> vec)
{
	_THISTESTIS_("max_size of container:", NOENDL);
	std::cout << vec.max_size() << std::endl;
}

//CAPACITY TEST
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	capacityTest(Container<Element, Allocator> vec)
{
	_THISTESTIS_("capacity of empty container:             ", NOENDL);
	std::cout << vec.capacity() << std::endl;

	_THISTESTIS_("5 print of capacity after 5 fill (5*i++):", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainer(vec, i + 1);
		std::cout << vec.capacity() << ", ";
	}
	std::cout << std::endl;

	_THISTESTIS_("print of capacity after a pop:           ", NOENDL);
	vec.pop_back();
	std::cout << vec.capacity() << std::endl;
}

//EMPTY TEST
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	emptyTest(Container<Element, Allocator> vec)
{
	_THISTESTIS_("empty of empty container:    ", NOENDL);
	std::cout << vec.empty() << std::endl;

	_THISTESTIS_("empty of container of 1 elem:", NOENDL);
	fillContainer(vec, 1);
	std::cout << vec.empty() << std::endl;
}

//RESERVE TEST
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	reserveTest(Container<Element, Allocator> vec)
{
	_THISTESTIS_("capacity & size of empty container:          ", NOENDL);
	std::cout << vec.capacity() << " & " << vec.size() << std::endl;

	_THISTESTIS_("capacity & size of reserved x10 container:   ", NOENDL);
	vec.reserve(10);
	std::cout << vec.capacity() << " & " << vec.size() << std::endl;

	_THISTESTIS_("capacity & size of filled x5 container:      ", NOENDL);
	fillContainer(vec, 5);
	std::cout << vec.capacity() << " & " << vec.size() << std::endl;

	_THISTESTIS_("capacity & size after reserved x4 container: ", NOENDL);
	vec.reserve(4);
	std::cout << vec.capacity() << " & " << vec.size() << std::endl;

	_THISTESTIS_("capacity & size of filled x15 more container:", NOENDL);
	fillContainer(vec, 15);
	std::cout << vec.capacity() << " & " << vec.size() << std::endl;

	_THISTESTIS_("capacity & size of reserved x40 container:   ", NOENDL);
	vec.reserve(40);
	std::cout << vec.capacity() << " & " << vec.size() << std::endl;

	_THISTESTIS_("try to reserve way too much:                 ", NOENDL);
	try {vec.reserve(4611686018427387909);}
	catch (std::length_error & e) {std::cout << e.what() << std::endl;}

	_THISTESTIS_("print of content:", ENDL);
	_PRINT_CONTENT_(vec);
}

void	capacityTest()
{
	_STITLE_("CAPACITY TEST");

	std::vector<int>			stdvec;
	ft::vector<int>				ftvec;
	std::vector<std::string>	stdvec2;
	ft::vector<std::string>		ftvec2;

	_SSTITLE_("'SIZE' TEST");
	_STD_TITLE_("(int)"); sizeTest(stdvec);
	_FT_TITLE_("(int)"); sizeTest(ftvec);
	_STD_TITLE_("(str)"); sizeTest(stdvec2);
	_FT_TITLE_("(str)"); sizeTest(ftvec2);

	_SSTITLE_("'MAX_SIZE' TEST");
	_STD_TITLE_("(int)"); maxsizeTest(stdvec);
	_FT_TITLE_("(int)"); maxsizeTest(ftvec);
	_STD_TITLE_("(str)"); maxsizeTest(stdvec2);
	_FT_TITLE_("(str)"); maxsizeTest(ftvec2);

	_SSTITLE_("'RESIZE' TEST");
	/*_STD_TITLE_("(int)"); resizeTest(stdvec);
	_FT_TITLE_("(int)"); resizeTest(ftvec);
	_STD_TITLE_("(str)"); resizeTest(stdvec2);
	_FT_TITLE_("(str)"); resizeTest(ftvec2);*/

	_SSTITLE_("'CAPACITY' TEST");
	_STD_TITLE_("(int)"); capacityTest(stdvec);
	_FT_TITLE_("(int)"); capacityTest(ftvec);
	_STD_TITLE_("(str)"); capacityTest(stdvec2);
	_FT_TITLE_("(str)"); capacityTest(ftvec2);

	_SSTITLE_("'EMPTY' TEST");
	_STD_TITLE_("(int)"); emptyTest(stdvec);
	_FT_TITLE_("(int)"); emptyTest(ftvec);
	_STD_TITLE_("(str)"); emptyTest(stdvec2);
	_FT_TITLE_("(str)"); emptyTest(ftvec2);

	_SSTITLE_("'RESERVE' TEST");
	_STD_TITLE_("(int)"); reserveTest(stdvec);
	_FT_TITLE_("(int)"); reserveTest(ftvec);
	_STD_TITLE_("(str)"); reserveTest(stdvec2);
	_FT_TITLE_("(str)"); reserveTest(ftvec2);
}

/*
 * size()
 * max_size()
 * resize()
 * capacity()
 * empty()
 * reserve()
*/
