#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP

#include "ftnode.hpp"

namespace ft {

template <typename T, typename Distance = ptrdiff_t,
		 typename Pointer = T*, typename Reference = T&>
class biDirectionalIterator
{
public:
	//___________MEMBER TYPES_________________________________________________//
	typedef T						value_type;
	typedef Distance				difference_type;
    typedef Pointer					pointer;
    typedef Reference				reference;

private:
    typedef biDirectionalIterator	iterator;
	typedef ft::node<value_type>	node;
	node							*_ptr;

public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	biDirectionalIterator() : _ptr(nullptr) {};
	biDirectionalIterator(biDirectionalIterator const & src) : _ptr(src._ptr) {};
	biDirectionalIterator(node *ptr) : _ptr(ptr) {};

	//___________Destructor___________________________________________________//
	virtual	~biDirectionalIterator() {};

	//___________Operator =___________________________________________________//
	biDirectionalIterator &	operator=(biDirectionalIterator const & src)
	{
		_ptr = src._ptr;
		return (*this);
	};

	//___________OPERATOR OVERLOADS___________________________________________//
	//___________Comparisons__________________________________________________//
	bool					operator==(const iterator & rhs) const
							{return (_ptr == rhs._ptr);};
	bool					operator!=(const iterator & rhs) const
							{return (_ptr != rhs._ptr);};

	//___________Dereferencement______________________________________________//
	reference				operator*() const {return _ptr->value;};
	pointer					operator->() const {return &(_ptr->value);};

	//___________Incrementation_______________________________________________//
	iterator				&operator++()
	{
		_ptr = _ptr->prev;
		return *this;
	};
	iterator				operator++(int)
	{
		iterator			tmp(*this);
		_ptr = _ptr->prev;
		return tmp;
	};

	//___________Decrementation_______________________________________________//
	iterator				&operator--()
	{
		_ptr = _ptr->next;
		return *this;
	};
	iterator				operator--(int)
	{
		iterator			tmp(*this);
		_ptr = _ptr->next;
		return tmp;
	};

	node*		getNode() const {return _ptr;};
};//end biDirectionalIterator

} //end ft

#endif
