#include "vector.hpp"
#include "resources.hpp"
#include <vector>

////////////AT
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	atTest(Container<Element, Allocator> vec)
{
	_THISTESTIS_("wrong 'at': try to reach 30th in empty vector:   ", NOENDL);
	try {vec.at(30);}
	catch (std::out_of_range & e) {std::cout << e.what() << std::endl;}
	_THISTESTIS_("wrong 'at': try to reach 0th in empty vector:    ", NOENDL);
	try {vec.at(30);}
	catch (std::out_of_range & e) {std::cout << e.what() << std::endl;}

	_THISTESTIS_("reaching & printing 5 first elem of a vector(10):", NOENDL);
	fillContainer(vec, 10);
	std::cout << vec.at(0) << vec.at(1) << vec.at(2) << vec.at(3) << vec.at(4)
	<< std::endl;

	_THISTESTIS_("reaching & printing 5 last elem of a vector(10): ", NOENDL);
	fillContainer(vec, 10);
	std::cout << vec.at(5) << vec.at(6) << vec.at(7) << vec.at(8) << vec.at(9)
	<< std::endl;
}

///////BRACKET

template <typename Container>
void	bracketTest(Container vec)
{
	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;

	_THISTESTIS_("reaching & printing 5 first elem of a vector(10):", NOENDL);
	fillContainer(vec, 10);
	std::cout << vec[0] << vec[1] << vec[2] << vec[3] << vec[4]
	<< std::endl;

	_THISTESTIS_("reaching & printing 5 last elem of a vector(10): ", NOENDL);
	fillContainer(vec, 10);
	std::cout << vec[5] << vec[6] << vec[7] << vec[8] << vec[9]
	<< std::endl;

	_THISTESTIS_("changing value in vec[8] to 42:                  ", NOENDL);
	reference		val = vec[8];
	val = 42;
	std::cout << val << std::endl;

	_THISTESTIS_("fetching const_reference from vec[2]:            ", NOENDL);
	const_reference		val2 = vec[2];
	std::cout << val2 << std::endl;
}

/////////FRONT
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	frontTest(Container<Element, Allocator> vec)
{
	_THISTESTIS_("print of 5 front after 5 != push:", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainer(vec, i + 1);
		std::cout << vec.front();
	}
	std::cout << std::endl;

	_THISTESTIS_("vec.front() = 120 (using reference): ", NOENDL);
	vec.front() = 120;
	std::cout << vec.front() << std::endl;
}

//////////BACK
template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	backTest(Container<Element, Allocator> vec)
{
	_THISTESTIS_("print of 5 back after 5 != push:", NOENDL);
	for (size_t i = 0; i < 5; i++)
	{
		fillContainer(vec, i + 1);
		std::cout << vec.back();
	}
	std::cout << std::endl;

	_THISTESTIS_("vec.back() = 100 (using reference): ", NOENDL);
	vec.back() = 100;
	std::cout << vec.back() << std::endl;
}

////////MAIN
void	elementAccessTest()
{
	_STITLE_("ELEMENT ACCESS TEST");

	std::vector<int>			stdvec;
	ft::vector<int>				ftvec;
	std::vector<std::string>	stdvec2;
	ft::vector<std::string>		ftvec2;

	_SSTITLE_("'AT' TEST");
	_STD_TITLE_("(int)"); atTest(stdvec);
	_FT_TITLE_("(int)"); atTest(ftvec);
	_STD_TITLE_("(str)"); atTest(stdvec2);
	_FT_TITLE_("(str)"); atTest(ftvec2);

	_SSTITLE_("'[]' TEST");
	_STD_TITLE_("(int)"); bracketTest(stdvec);
	_FT_TITLE_("(int)"); bracketTest(ftvec);
	_STD_TITLE_("(str)"); bracketTest(stdvec2);
	_FT_TITLE_("(str)"); bracketTest(ftvec2);

	_SSTITLE_("'FRONT' TEST");
	_STD_TITLE_("(int)"); frontTest(stdvec);
	_FT_TITLE_("(int)"); frontTest(ftvec);
	_STD_TITLE_("(str)"); frontTest(stdvec2);
	_FT_TITLE_("(str)"); frontTest(ftvec2);

	_SSTITLE_("'BACK' TEST");
	_STD_TITLE_("(int)"); backTest(stdvec);
	_FT_TITLE_("(int)"); backTest(ftvec);
	_STD_TITLE_("(str)"); backTest(stdvec2);
	_FT_TITLE_("(str)"); backTest(ftvec2);
}

/*
 * operator []
 * at()
 * front()
 * back()
*/
