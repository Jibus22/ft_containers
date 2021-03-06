#include "resources.hpp"

//_______________________________PRINT TITLES_________________________________//

void	_TITLE_(const std::string & title)
{
	std::cout << BLACK_C << GREEN_B << BOLD << UNDERLINE << std::setfill ('=')
	<< std::setw(40) << title << std::setw(40) << RESET << std::endl;
}

void	_STITLE_(const std::string & title)
{
	std::cout << std::endl << std::endl << YELLOW_C << BLUE_B << BOLD
	<< std::setfill ('-') << std::setw(30) << RESET << YELLOW_C << title
	<< BLUE_B << std::setw(30) << RESET << std::endl;
}

void	_SSTITLE_(const std::string & title)
{
	std::cout << std::endl << "\t\t" << RED_C << std::setfill ('*')
	<< std::setw(30) << title << std::setw(30) << RESET << std::endl;
}

void	_THISTESTIS_(const std::string & title, int isendl)
{
	std::cout << MAGENTA_B << "  " << RESET << MAGENTA_B << " "
	<< RESET << ITALIC << WHITE_C << title << "  " << RESET;
	if (isendl)
		std::cout << std::endl;
}

void	_FT_TITLE_(const std::string & type)
{
	std::cout << BLACK_C << GREEN_B << BOLD << " FT " << ITALIC << type
	<< RESET << std::endl;
}

void	_STD_TITLE_(const std::string & type)
{
	std::cout << BLACK_C << GREEN_B << BOLD << "STD " << ITALIC << type
	<< RESET << std::endl;
}

void	_SPLIT_LINE_(void)
{
	std::cout << std::endl << WHITE_C
	<< "\t\t\t------------------------------- " << RESET << std::endl;
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
