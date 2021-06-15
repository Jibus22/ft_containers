#ifndef RESOURCES_HPP
# define RESOURCES_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include "colorResources.hpp"

//TESTING FUNCTIONS
void	iteratorsTest(void);
void	capacityTest(void);
void	elementAccessTest(void);
void	modifiersTest(void);

//PRINT PRESENTATION
void	_TITLE_(const std::string & title);
void	_STITLE_(const std::string & title);
void	_SSTITLE_(const std::string & title);
void	_THISTESTIS_(const std::string & title);
void	_FT_TITLE_(const std::string & type);
void	_STD_TITLE_(const std::string & type);

void	_FT_BOX_(void);
void	_STD_BOX_(void);

//PRINT OBJECTS
template <typename T>
void	printVec(const T & vec)
{
	std::cout << YELLOW_B << BLACK_C << "P->" << RESET << std::setfill (' ')
	<< std::setw(10) << "size: " << vec.size() << std::setw(16)
	<< "capacity: " << vec.capacity();
	if (vec.size())
		std::cout << std::setw(16) << "front: " << vec.front() << std::setw(16)
		<< "back: " << vec.back();
	std::cout << std::endl;
}

template <typename T>
void	_PRINT_VEC_(const T & vec)
{
	_FT_BOX_();
	printVec(vec);
}

template <typename T>
void	_PRINT_VEC_(const std::vector<T> & vec)
{
	_STD_BOX_();
	printVec(vec);
}

//MOD OBJECTS
#endif
