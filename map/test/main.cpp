#include "map.hpp"
#include "resources.hpp"
#include <map>

int	main(int ac, char *av[])
{
	std::string		arg;

	if (ac == 2)
		arg = std::string(av[1]);
	while (ac > 1) {
		if (ac > 2)
			std::cout << av[0] << " error: too many args" << std::endl;
		else if (arg != "1" && arg != "2" && arg != "3"
				&& arg != "4" && arg != "5" && arg != "6")
			std::cout << av[0] << " usage: none, 1, 2, 3, 4, 5 or 6" << std::endl;
		else
			break ;
		return (1);
	}
	_TITLE_("MAP TEST");
	if (ac == 1 || arg == "1")
		iteratorsTest();
	if (ac == 1 || arg == "2")
		capacityTest();
	if (ac == 1 || arg == "3")
		elementAccessTest();
	if (ac == 1 || arg == "4")
		modifiersTest();
	/*if (ac == 1 || arg == "5")
		operationTest();
	if (ac == 1 || arg == "6")
		otherTest();*/

	return (0);
}
