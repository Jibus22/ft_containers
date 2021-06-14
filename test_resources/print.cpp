#include "resources.hpp"

//_______________________________PRINT TITLES_________________________________//

void	_TITLE_(std::string title)
{
	std::cout << BLACK_C << GREEN_B << BOLD << UNDERLINE << std::setfill ('=')
	<< std::setw(40) << title << std::setw(40) << RESET << std::endl;
}

void	_STITLE_(std::string title)
{
	std::cout << YELLOW_C << BLUE_B << BOLD << std::setfill ('-')
	<< std::setw(30) << RESET << YELLOW_C << title << BLUE_B << std::setw(30)
	<< RESET << std::endl;
}

void	_SSTITLE_(std::string title)
{
	std::cout << RED_C << std::setfill ('*') << std::setw(20) << title <<
	std::setw(20) << RESET << std::endl;
}

void	_THISTESTIS_(std::string title)
{
	std::cout << MAGENTA_B << " " << RESET << MAGENTA_B << " "
	<< RESET << ITALIC << WHITE_C << title << RESET << std::endl;
}

//_______________________________STD & FT BOXS________________________________//

void	_FT_BOX_(void)
{
	std::cout << WHITE_B << GREEN_C << "V" << RESET << WHITE_C
	<< " ft:\t" << RESET;
}

void	_STD_BOX_(void)
{
	std::cout << WHITE_B << GREEN_C << "V" << RESET << WHITE_C
	<< "std:\t" << RESET;
}
