#include "queue.hpp"
#include "resources.hpp"
#include <queue>

///////PUSH
template <typename Container>
void	pushTest(Container vec)
{
	_THISTESTIS_("10 push:      ", NOENDL);
	fillContainr(vec, 10);
	_PRINT_LST_(vec);

	_THISTESTIS_("50 more push: ", NOENDL);
	fillContainr(vec, 50);
	_PRINT_LST_(vec);

	_THISTESTIS_("500 more push:", NOENDL);
	fillContainr(vec, 500);
	_PRINT_LST_(vec);
}

///////POP
template <typename Container>
void	popTest(Container vec)
{
	_THISTESTIS_("State of current container", ENDL);
	_THISTESTIS_("with 500 elem:   ", NOENDL);
	fillContainr(vec, 500);
	_PRINT_LST_(vec);

	_THISTESTIS_("pop 10 elements: ", NOENDL);
	for (size_t i = 0; i < 10; i++)
		vec.pop();
	_PRINT_LST_(vec);

	_THISTESTIS_("pop 200 elements:", NOENDL);
	for (size_t i = 0; i < 200; i++)
		vec.pop();
	_PRINT_LST_(vec);

	_THISTESTIS_("pop 290 elements:", NOENDL);
	for (size_t i = 0; i < 290; i++)
		vec.pop();
	_PRINT_LST_(vec);
}

////////MAIN
void	modifiersTest()
{
	_STITLE_("MODIFIERS TEST");

	std::queue<int>			stdvec;
	ft::queue<int>			ftvec;
	std::queue<std::string>	stdvec2;
	ft::queue<std::string>	ftvec2;

	_SSTITLE_("'PUSH' TEST");
	_STD_TITLE_("(int)"); pushTest(stdvec);
	_FT_TITLE_("(int)"); pushTest(ftvec);
	_STD_TITLE_("(str)"); pushTest(stdvec2);
	_FT_TITLE_("(str)"); pushTest(ftvec2);

	_SSTITLE_("'POP' TEST");
	_STD_TITLE_("(int)"); popTest(stdvec);
	_FT_TITLE_("(int)"); popTest(ftvec);
	_STD_TITLE_("(str)"); popTest(stdvec2);
	_FT_TITLE_("(str)"); popTest(ftvec2);
}

/*
 * push()
 * pop()
*/
