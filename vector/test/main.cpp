#include "vector.hpp"
#include <vector>

void	printSizenCapacity(int nb, std::vector<int>& vec1, std::vector<int>& vec2,
		std::vector<std::string>& vec3, ft::vector<int>& vecx)
{
	int							i;
	int							div;
	std::cout << "__________// PRINT SIZE & CAPACITY //__________" << std::endl;

	for (i = 0; i < nb; i++)
	{
		vec3.push_back("BLA");
		vec2.push_back(42);
		vec1.push_back(42);
	}
	std::cout << "nb de push_back: " << nb << std::endl;

	std::cout << "SIZE" << std::endl;
	std::cout << "vec1: " << vec1.size() << std::endl;
	std::cout << "vec2: " << vec2.size() << std::endl;
	std::cout << "vec3: " << vec3.size() << std::endl;
	std::cout << "vecx: " << vecx.size() << std::endl;

	std::cout << "CAPACITY" << std::endl;
	std::cout << "vec1: " << vec1.capacity() << std::endl;
	std::cout << "vec2: " << vec2.capacity() << std::endl;
	std::cout << "vec3: " << vec3.capacity() << std::endl;
	std::cout << "vecx: " << vecx.capacity() << std::endl;

	div = nb / 2;
	for (i = 0; i < div; i++)
	{
		vec3.pop_back();
		vec2.pop_back();
		vec1.pop_back();
	}
	std::cout << "nb de pop_back: " << div << std::endl;

	std::cout << "SIZE" << std::endl;
	std::cout << "vec1: " << vec1.size() << std::endl;
	std::cout << "vec2: " << vec2.size() << std::endl;
	std::cout << "vec3: " << vec3.size() << std::endl;
	std::cout << "vecx: " << vecx.size() << std::endl;

	std::cout << "CAPACITY" << std::endl;
	std::cout << "vec1: " << vec1.capacity() << std::endl;
	std::cout << "vec2: " << vec2.capacity() << std::endl;
	std::cout << "vec3: " << vec3.capacity() << std::endl;
	std::cout << "vecx: " << vecx.capacity() << std::endl;

}

void	iteratorsTest(std::vector<int>& vec1, ft::vector<int>& vecx)
{
	std::cout << "______________// ITERATOR TEST //______________" << std::endl;
	std::vector<int>::iterator	b, e;

	vec1.push_back(21);
	b = vec1.begin();
	e = vec1.end();
	std::cout << "begin it after push(21): "<< *b << std::endl;
	std::cout << "end it after push(21): "<< *e << std::endl;
	vec1.pop_back();
	b = vec1.begin();
	e = vec1.end();
	std::cout << "begin it after pop: "<< *b << std::endl;
	std::cout << "end it after pop: "<< *e << std::endl;

	std::cout << "---" << std::endl;
	vec1.push_back(42);
	b = vec1.begin();
	e = vec1.end();
	std::cout << "begin it after push(42): "<< *b << std::endl;
	std::cout << "end it after push(42): "<< *e << std::endl;
	vec1.pop_back();
	b = vec1.begin();
	e = vec1.end();
	std::cout << "begin it after pop: "<< *b << std::endl;
	std::cout << "end it after pop: "<< *e << std::endl;
	(void)vecx;
}

void	iteratorsTry()
{
	std::cout << "______________// ITERATOR TRY //_______________" << std::endl;
	std::vector<int>			vec1;
	vec1.push_back(21);
	std::vector<int>::iterator	b(vec1.begin());
	std::vector<int>::iterator	c(b);
	std::vector<int>::iterator	d = c;
	(void)b;
	(void)c;
	(void)d;
	std::vector<int>			vec2(vec1);
	vec1.push_back(42);
	std::cout << "back vec1: " << vec1.back() << "back vec2: "
	<< vec2.back() << std::endl;
	std::vector<int>			vec3 = vec2;
	vec2.push_back(142);
	std::cout << "back vec2: " << vec2.back() << "back vec3: "
	<< vec3.back() << std::endl;

}

int	main(int ac, char *av[])
{
	int							nb;
	std::vector<int>			vec1;
	std::vector<int>			vec2(10, 0);
	std::vector<std::string>	vec3(10, "B");
	ft::vector<int>				vecx;

	if (ac != 2)
		return (1);
	nb = std::stoi(av[1]);
	printSizenCapacity(nb, vec1, vec2, vec3, vecx);
	iteratorsTest(vec1, vecx);
	iteratorsTry();

	(void)vec1;
	(void)vec2;
	(void)vecx;
	return (0);
}
