#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

#include "../utils/iterator_traits.hpp"

namespace ft {

template <class Iter>
class reverse_iterator
{
public:
	//___________MEMBER TYPES_________________________________________________//
	typedef typename ft::iterator_traits<Iter>::value_type		value_type;
	typedef typename ft::iterator_traits<Iter>::difference_type	difference_type;
	typedef typename ft::iterator_traits<Iter>::pointer			pointer;
	typedef typename ft::iterator_traits<Iter>::reference		reference;
	typedef typename
		ft::iterator_traits<Iter>::iterator_category		iterator_category;

	typedef Iter			iterator_type;
protected:
	iterator_type			current;
public:

	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	reverse_iterator(): current(iterator_type()) {};
	reverse_iterator(iterator_type it) : current(it) {};
	template <class U>
	reverse_iterator(const reverse_iterator<U>& rev_it): current(rev_it.base()) {};
	//___________Destructor___________________________________________________//
	virtual ~reverse_iterator() {};
	//___________Operator =___________________________________________________//
	template <class U>
	reverse_iterator&		operator=(const reverse_iterator<U>& other)
	{current = other.base(); return *this;};

	iterator_type			base() const {return current;};
	//___________OPERATOR OVERLOADS___________________________________________//
	//___________Dereferencement______________________________________________//
	reference				operator[](const difference_type i) const
							{return *(*this + i);};
	reference				operator*() const {return *--base();};
	pointer					operator->() const {return &(operator*());};

	//___________Incrementation_______________________________________________//
	reverse_iterator		&operator++()
	{
		current--;
		return *this;
	};
	reverse_iterator		operator++(int)
	{
		reverse_iterator	tmp(*this);
		current--;
		return tmp;
	};

	//___________Decrementation_______________________________________________//
	reverse_iterator		&operator--()
	{
		current++;
		return *this;
	};
	reverse_iterator		operator--(int)
	{
		reverse_iterator	tmp(*this);
		current++;
		return tmp;
	};

	//___________Arithmetic Operations________________________________________//
	reverse_iterator		operator+(const difference_type n) const
							{return (reverse_iterator(current - n));};

	reverse_iterator		operator-(const difference_type n) const
							{return (reverse_iterator(current + n));};

	//___________Assignment Operations________________________________________//
	reverse_iterator		&operator+=(const difference_type n)
	{	
		current -= n;
		return (*this);
	};
	reverse_iterator		&operator-=(const difference_type n)
	{	
		current += n;
		return (*this);
	};
};//end reverse_iterator

//___________Relationnal operators________________________________________//
template <class Iterator1, class Iterator2>
bool	operator==(const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs)
					{return lhs.base()==rhs.base();};
template <class Iterator1, class Iterator2>
bool	operator!=(const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs)
					{return lhs.base()!=rhs.base();};
template <class Iterator1, class Iterator2>
bool	operator< (const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs)
					{return lhs.base()> rhs.base();};
template <class Iterator1, class Iterator2>
bool	operator<=(const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs)
					{return lhs.base()>=rhs.base();};
template <class Iterator1, class Iterator2>
bool	operator> (const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs)
					{return lhs.base()< rhs.base();};
template <class Iterator1, class Iterator2>
bool	operator>=(const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs)
					{return lhs.base()<=rhs.base();};


template <class Iter>
ft::reverse_iterator<Iter>
operator+(typename ft::reverse_iterator<Iter>::difference_type n,
		const ft::reverse_iterator<Iter>& it)
					{return it.operator+(n);};

template<class Iter1, class Iter2>
typename ft::reverse_iterator<Iter1>::difference_type
operator-(const ft::reverse_iterator<Iter1>& lhs,
		const ft::reverse_iterator<Iter2>& rhs)
					{return rhs.base() - lhs.base();};

} //end ft

#endif
