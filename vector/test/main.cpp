#include "vector.hpp"
#include <vector>

void	iteratorsTest()
{
}
void	capacityTest()
{}

void	elementAccessTest()
{}

void	modifiersTest()
{}

int	main(int ac, char *av[])
{
	if (ac > 1) {
		std::cout << av[0] << " doesn't requiere any args" << std::endl;
		return (1);
	}
	iteratorsTest();
	capacityTest();
	elementAccessTest();
	modifiersTest();
	return (0);
}
