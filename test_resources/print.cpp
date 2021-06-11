#include "resources.hpp"

void	title(std::string title)
{
	std::cout << BLACK_C << GREEN_B << BOLD << UNDERLINE << std::setfill ('=')
	<< std::setw(40) << title << std::setw(40) << RESET << std::endl;
}

void	subTitle(std::string title)
{
	std::cout << YELLOW_C << BLUE_B << BOLD << std::setfill ('-')
	<< std::setw(30) << RESET << YELLOW_C << title << BLUE_B << std::setw(30)
	<< RESET << std::endl;
}

void	subsubTitle(std::string title)
{
	std::cout << RED_C << std::setfill ('*') << std::setw(20) << title <<
	std::setw(20) << RESET << std::endl;
}