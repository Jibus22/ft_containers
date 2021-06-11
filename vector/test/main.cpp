#include "vector.hpp"
#include "resources.hpp"
#include <vector>

int	main(int ac, char *av[])
{
	title("VECTOR TEST");
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
