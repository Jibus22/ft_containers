#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

template <class Iter>
class reverseIterator
{
protected:
	typedef Iter								iterator;
	typedef reverseIterator						reverse_iterator;

	iterator									_iter;

public:
	//___________MEMBER TYPES_________________________________________________//
	typedef typename ft::iterator_traits<Iter>::value_type		value_type;
	typedef typename ft::iterator_traits<Iter>::difference_type	difference_type;
	typedef typename ft::iterator_traits<Iter>::pointer			pointer;
	typedef typename ft::iterator_traits<Iter>::reference		reference;
	typedef typename ft::iterator_traits<Iter>::iterator_category
		iterator_category;

	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	reverseIterator() {};
	reverseIterator(reverseIterator const & src) : _iter(src._iter) {};
	reverseIterator(iterator it) : _iter(it) {};
	//___________Destructor___________________________________________________//
	virtual ~reverseIterator() {};
	//___________Operator =___________________________________________________//
	reverseIterator &	operator=(reverseIterator const & src)
	{
		_iter = src._iter;
		return (*this);
	};
	//___________OPERATOR OVERLOADS___________________________________________//
	//___________Comparisons__________________________________________________//
	bool					operator==(const reverse_iterator & rhs) const
							{return (_iter == rhs._iter);};
	bool					operator!=(const reverse_iterator & rhs) const
							{return (_iter != rhs._iter);};
	bool					operator<(const reverse_iterator & rhs) const
							{return !(_iter < rhs._iter);};
	bool					operator>(const reverse_iterator & rhs) const
							{return !(_iter > rhs._iter);};
	bool					operator<=(const reverse_iterator & rhs) const
							{return (_iter >= rhs._iter);};
	bool					operator>=(const reverse_iterator & rhs) const
							{return (_iter <= rhs._iter);};

	//___________Dereferencement______________________________________________//
	reference				operator[](const difference_type i) const
							{return _iter[i];};
	reference				operator*() const {return *_iter;};
	pointer					operator->() const {return _iter.operator->();};

	//___________Incrementation_______________________________________________//
	reverse_iterator		&operator++()
	{
		_iter--;
		return *this;
	};
	reverse_iterator		operator++(int)
	{
		reverse_iterator	tmp(*this);
		_iter--;
		return tmp;
	};

	//___________Decrementation_______________________________________________//
	reverse_iterator		&operator--()
	{
		_iter++;
		return *this;
	};
	reverse_iterator		operator--(int)
	{
		reverse_iterator	tmp(*this);
		_iter++;
		return tmp;
	};

	//___________Arithmetic Operations________________________________________//
	reverse_iterator		operator+(const difference_type n) const
							{return (reverse_iterator(_iter - n));};
	reverse_iterator		operator-(const difference_type n) const
							{return (reverse_iterator(_iter + n));};
	difference_type			operator-(const reverse_iterator rhs) const
							{return (_iter + rhs._iter);};

	//___________Assignment Operations________________________________________//
	reverse_iterator		&operator+=(const difference_type n)
	{	
		_iter -= n;
		return (*this);
	};
	reverse_iterator		&operator-=(const difference_type n)
	{	
		_iter += n;
		return (*this);
	};
};//end reverseIterator

} //end ft

#endif
