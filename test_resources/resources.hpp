#ifndef RESOURCES_HPP
# define RESOURCES_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "colorResources.hpp"

//TESTING FUNCTIONS
void	iteratorsTest(void);
void	capacityTest(void);
void	elementAccessTest(void);
void	modifiersTest(void);
void	operationTest(void);
void	otherTest(void);

//PRINT PRESENTATION
void	_TITLE_(const std::string & title);
void	_STITLE_(const std::string & title);
void	_SSTITLE_(const std::string & title);
void	_THISTESTIS_(const std::string & title, int isendl);
void	_FT_TITLE_(const std::string & type);
void	_STD_TITLE_(const std::string & type);

void	_SPLIT_LINE_(void);
void	_FT_BOX_(void);
void	_STD_BOX_(void);

//PRINT OBJECTS
template <typename T>
void	_PRINT_VEC_(const T & vec)
{
	std::cout << std::setfill (' ') << "size:" << std::setw(5) << vec.size()
	<< "   " << "capacity:" << std::setw(5) << vec.capacity() << "  ";
	if (vec.size())
		std::cout << "front:" << std::setw(5) << vec.front() << "  "
		<< "back:" << std::setw(5) << vec.back();
	std::cout << std::endl;
}

template <typename T>
void	_PRINT_LST_(const T & vec)
{
	std::cout << std::setfill (' ') << "size:" << std::setw(5) << vec.size()
	<< "   ";
	if (vec.size())
		std::cout << "front:" << std::setw(5) << vec.front() << "  "
		<< "back:" << std::setw(5) << vec.back();
	std::cout << std::endl;
}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	_PRINT_CONTENT_(Container<Element, Allocator> & vec)
{
	std::cout << YELLOW_B;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << WHITE_C << "| " << BLACK_C << vec[i] << " ";
	std::cout << RED_C << "|" << RESET << std::endl;
}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	_PRINT_LST_CONTENT_(Container<Element, Allocator> & lst)
{
	typedef typename Container<Element, Allocator>::iterator	iterator;
	std::cout << YELLOW_B;
	for (iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << WHITE_C << "| " << BLACK_C << *i << " ";
	std::cout << RED_C << "|" << RESET << std::endl;
}

//MOD OBJECTS
//FILLCONTAINER
template <template <typename, typename> class Container,
		typename Allocator>
void	fillContainer(Container<std::string, Allocator> & vec, size_t n)
{
	char	buf[1];

	buf[0] = '`';
	for (size_t i = 0; i < n; i++)
	{
		if (buf[0] == 'z')
			buf[0] = 'a';
		else
			buf[0] += 1;
		vec.push_back(std::string(buf, 1));
	}
}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	fillContainer(Container<Element, Allocator> & vec, size_t n)
{
	int		j = 0;

	for (size_t i = 0; i < n; i++)
		vec.push_back(j++);
}

//FILLFRONTCONTAINER
template <template <typename, typename> class Container,
		typename Allocator>
void	fillfrontContainer(Container<std::string, Allocator> & vec, size_t n)
{
	char	buf[1];

	buf[0] = '`';
	for (size_t i = 0; i < n; i++)
	{
		if (buf[0] == 'z')
			buf[0] = 'a';
		else
			buf[0] += 1;
		vec.push_front(std::string(buf, 1));
	}
}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	fillfrontContainer(Container<Element, Allocator> & vec, size_t n)
{
	int		j = 0;

	for (size_t i = 0; i < n; i++)
		vec.push_front(j++);
}

//SIZEASSIGN
template <template <typename, typename> class Container,
		typename Allocator>
void	sizeAssign(Container<std::string, Allocator> & vec, size_t n)
{
	vec.assign(n, std::string("bla", 3));
}

template <template <typename, typename> class Container,
		typename Element, typename Allocator>
void	sizeAssign(Container<Element, Allocator> & vec, size_t n)
{
	vec.assign(n, 42);
}

#endif
