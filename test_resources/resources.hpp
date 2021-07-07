#ifndef RESOURCES_HPP
# define RESOURCES_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "colorResources.hpp"
#include "ftless.hpp"
#include "ftpair.hpp"

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
void	_PRINT_STK_(const T & vec)
{
	std::cout << std::setfill (' ') << "size:" << std::setw(5) << vec.size()
	<< "   ";
	if (vec.size())
		std::cout << "top:" << std::setw(5) << vec.top();
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

template <typename T>
void	_PRINT_MAP_(const T & vec)
{
	std::cout << std::setfill (' ') << "size:" << std::setw(5) << vec.size()
	<< "   ";
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

template <typename Container>
void	_PRINT_MAP_CONTENT_(Container & mapp)
{
	typedef typename Container::iterator	iterator;
	std::cout << std::setfill (' ') << YELLOW_B;
	for (iterator i = mapp.begin(); i != mapp.end(); i++)
		std::cout << MAGENTA_C << "|" << CYAN_B << BLACK_C
		<< std::setw(5) << i->first << YELLOW_B << BLACK_C
		<< std::setw(3) << i->second << " ";
	std::cout << RED_C << "|" << RESET << std::endl;
}

template <typename Iter>
void	_DISPLAY_MAP_NODE_(Iter it)
{
	std::cout << "key: " << it->first << "\tmapped val: "
		<< it->second << std::endl;
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
		vec.push(j++);
}

template <template <typename, typename> class Container,
		typename Containr>
void	fillContainr(Container<std::string, Containr> & vec, size_t n)
{
	char	buf[1];

	buf[0] = '`';
	for (size_t i = 0; i < n; i++)
	{
		if (buf[0] == 'z')
			buf[0] = 'a';
		else
			buf[0] += 1;
		vec.push(std::string(buf, 1));
	}
}

template <template <typename, typename> class Container,
		typename Element, typename Containr>
void	fillContainr(Container<Element, Containr> & vec, size_t n)
{
	int		j = 0;

	for (size_t i = 0; i < n; i++)
		vec.push(j++);
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

//FILLMAP

template <template <typename, typename, typename, typename> class Container,
		typename Key, typename T, typename Allocator>
void	fillmap(Container<Key, T, ft::less<Key>, Allocator> & mapp, size_t n)
{
	for (; n > 0; n--)
	{
		mapp.insert(ft::make_pair(50 * n, "a"));
		mapp.insert(ft::make_pair(25 * n, "b"));
		mapp.insert(ft::make_pair(75 * n, "c"));
		mapp.insert(ft::make_pair(10 * n, "d"));
		mapp.insert(ft::make_pair(40 * n, "e"));
		mapp.insert(ft::make_pair(65 * n, "f"));
		mapp.insert(ft::make_pair(90 * n, "g"));
		mapp.insert(ft::make_pair(5 * n, "h"));
		mapp.insert(ft::make_pair(18 * n, "i"));
		mapp.insert(ft::make_pair(32 * n, "j"));
		mapp.insert(ft::make_pair(45 * n, "k"));
		mapp.insert(ft::make_pair(58 * n, "l"));
		mapp.insert(ft::make_pair(70 * n, "m"));
		mapp.insert(ft::make_pair(82 * n, "n"));
		mapp.insert(ft::make_pair(100 * n, "o"));
		mapp.insert(ft::make_pair(22 * n, "p"));
		mapp.insert(ft::make_pair(42 * n, "q"));
		mapp.insert(ft::make_pair(62 * n, "r"));
		mapp.insert(ft::make_pair(78 * n, "s"));
		mapp.insert(ft::make_pair(120 * n, "t"));
	}
}

template <template <typename, typename, typename, typename> class Container,
		typename Key, typename T, typename Compare, typename Allocator>
void	fillmap(Container<Key, T, Compare, Allocator> & mapp, size_t n)
{
	for (; n > 0; n--)
	{
		mapp.insert(std::make_pair(50 * n, "a"));
		mapp.insert(std::make_pair(25 * n, "b"));
		mapp.insert(std::make_pair(75 * n, "c"));
		mapp.insert(std::make_pair(10 * n, "d"));
		mapp.insert(std::make_pair(40 * n, "e"));
		mapp.insert(std::make_pair(65 * n, "f"));
		mapp.insert(std::make_pair(90 * n, "g"));
		mapp.insert(std::make_pair(5 * n, "h"));
		mapp.insert(std::make_pair(18 * n, "i"));
		mapp.insert(std::make_pair(32 * n, "j"));
		mapp.insert(std::make_pair(45 * n, "k"));
		mapp.insert(std::make_pair(58 * n, "l"));
		mapp.insert(std::make_pair(70 * n, "m"));
		mapp.insert(std::make_pair(82 * n, "n"));
		mapp.insert(std::make_pair(100 * n, "o"));
		mapp.insert(std::make_pair(22 * n, "p"));
		mapp.insert(std::make_pair(42 * n, "q"));
		mapp.insert(std::make_pair(62 * n, "r"));
		mapp.insert(std::make_pair(78 * n, "s"));
		mapp.insert(std::make_pair(120 * n, "t"));
	}
}

#endif
