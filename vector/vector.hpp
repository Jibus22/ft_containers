#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "randomAccessIterator.hpp"

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector
{
public:
	//___________MEMBER TYPES_________________________________________________//
    typedef T											value_type;
    typedef Allocator									allocator_type;
	typedef value_type*									pointer;
    typedef typename allocator_type::reference			reference;
    typedef typename allocator_type::const_reference	const_reference;
    typedef typename allocator_type::difference_type	difference_type;
    typedef typename allocator_type::size_type			size_type;
    typedef ft::randomAccessIterator<T>					iterator;
private:
protected:
	pointer												_array;
	allocator_type										_allocator;
	size_type											_capacity;
	size_type											_size;
public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	vector() : _array(nullptr), _capacity(0), _size(0) {};
	vector(vector const & src)
	{
		//recopier avec les iterators, peu etre avec l'aide d'une fonction mebre
		(void)src;
	};
	//___________Destructor___________________________________________________//
	virtual	~vector() {};

	//___________Operator =___________________________________________________//
	vector&	operator=(vector const & src)
	{
		//deep copy egalement, utiliser une fonction membre qui fait le taf
		(void)src;
		return (*this);
	};

	//___________Iterators____________________________________________________//
	iterator	begin() {return iterator(_array);};
	iterator	end() {return iterator(_array + _size);};
	//___________Capacity_____________________________________________________//
	size_type	capacity() const {return _capacity;};
	size_type	size() const {return _size;};
	//___________Element access_______________________________________________//
	//___________Modifiers____________________________________________________//
	void		push_back(const value_type& val)
	{
		(void)val;
	};
}; //end class vector

} //end ft

#endif

/*
    typedef typename allocator_type::pointer			pointer;
    typedef typename allocator_type::const_pointer		const_pointer;
    typedef implementation-defined                   const_iterator;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
*/
