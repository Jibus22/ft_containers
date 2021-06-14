#ifndef RESOURCES_HPP
# define RESOURCES_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include "colorResources.hpp"

//MACROS
# define _PRINT_FT_V_(vec)	_FT_BOX_();_PRINT_VEC_(vec)
# define _PRINT_STD_V_(vec)	_STD_BOX_();_PRINT_VEC_(vec)

//TESTING FUNCTIONS
void	iteratorsTest(void);
void	capacityTest(void);
void	elementAccessTest(void);
void	modifiersTest(void);

//PRINT PRESENTATION
void	_TITLE_(std::string title);
void	_STITLE_(std::string title);
void	_SSTITLE_(std::string title);
void	_THISTESTIS_(std::string title);
void	_FT_BOX_(void);
void	_STD_BOX_(void);

//PRINT OBJECTS
template <typename T>
void	_PRINT_VEC_(T & vec)
{
	std::cout << YELLOW_B << BLACK_C << "P->" << RESET << std::setfill (' ')
	<< std::setw(10) << "size: " << vec.size() << std::setw(16)
	<< "capacity: " << vec.capacity();
	if (vec.size())
		std::cout << std::setw(16) << "front: " << vec.front() << std::setw(16)
		<< "back: " << vec.back();
	std::cout << std::endl;
}

#endif
