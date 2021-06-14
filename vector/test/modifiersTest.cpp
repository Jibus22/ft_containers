#include "vector.hpp"
#include "resources.hpp"
#include <vector>

void	assignTest()
{
	_SSTITLE_("'ASSIGN' TEST");
	std::vector<int>	stdvec;
	ft::vector<int>		ftvec;

	for (int i = 0; i < 20; i++)
		stdvec.push_back(42);
	stdvec.assign(10, 21);
	_PRINT_STD_V_(stdvec);
	_PRINT_FT_V_(ftvec);
}

void	modifiersTest()
{
	_SSTITLE_("MODIFIERS TEST");
	assignTest();
}

/*
 * assign()
 * push_back()
 * pop_back()
 * insert()
 * erase()
 * swap()
 * clear()
*/
