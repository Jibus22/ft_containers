#ifndef VECITER_HPP
# define VECITER_HPP

#include "iterator_traits.hpp"

namespace ft {

template <typename T>
class cvecIter
{
public:
	//___________MEMBER TYPES_________________________________________________//
	typedef T								value_type;
    typedef T*						pointer;
	typedef T&						reference;
	typedef ptrdiff_t						difference_type;
	typedef ft::random_access_iterator_tag	iterator_category;

protected:
    typedef cvecIter				iterator;
	pointer							_ptr;

public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	cvecIter() : _ptr(nullptr) {};
	cvecIter(cvecIter const & src) : _ptr(src._ptr) {};
	cvecIter(pointer ptr) : _ptr(ptr) {};

	//___________Destructor___________________________________________________//
	virtual	~cvecIter() {};

	//___________Operator =___________________________________________________//
	cvecIter &	operator=(cvecIter const & src)
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
	bool					operator<(const iterator & rhs) const
							{return (_ptr < rhs._ptr);};
	bool					operator>(const iterator & rhs) const
							{return (_ptr > rhs._ptr);};
	bool					operator<=(const iterator & rhs) const
							{return (_ptr <= rhs._ptr);};
	bool					operator>=(const iterator & rhs) const
							{return (_ptr >= rhs._ptr);};

	//___________Dereferencement______________________________________________//
	reference				operator[](const difference_type i) const
							{return _ptr[i];};
	const value_type&		operator*() const {return *_ptr;};
	const value_type*		operator->() const {return _ptr;};

	//___________Incrementation_______________________________________________//
	iterator				&operator++()
	{
		_ptr++;
		return *this;
	};
	iterator				operator++(int)
	{
		iterator			tmp(*this);
		_ptr++;
		return tmp;
	};

	//___________Decrementation_______________________________________________//
	iterator				&operator--()
	{
		_ptr--;
		return *this;
	};
	iterator				operator--(int)
	{
		iterator			tmp(*this);
		_ptr--;
		return tmp;
	};

	//___________Arithmetic Operations________________________________________//
	iterator				operator+(const difference_type n) const
							{return (iterator(_ptr + n));};
	iterator				operator-(const difference_type n) const
							{return (iterator(_ptr - n));};
	difference_type			operator-(const iterator rhs) const
							{return (_ptr - rhs._ptr);};

	//___________Assignment Operations________________________________________//
	iterator				&operator+=(const difference_type n)
	{	
		_ptr += n;
		return (*this);
	};
	iterator				&operator-=(const difference_type n)
	{	
		_ptr -= n;
		return (*this);
	};
};//end cvecIter

template <typename T>
class vecIter
{
public:
	//___________MEMBER TYPES_________________________________________________//
	typedef T								value_type;
    typedef T*								pointer;
	typedef T&								reference;
	typedef ptrdiff_t						difference_type;
	typedef ft::random_access_iterator_tag	iterator_category;

private:
    typedef vecIter	iterator;
	pointer							_ptr;

public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	vecIter() : _ptr(nullptr) {};
	vecIter(vecIter const & src) : _ptr(src._ptr) {};
	vecIter(pointer ptr) : _ptr(ptr) {};

	//___________Destructor___________________________________________________//
	virtual	~vecIter() {};

	//___________Operator =___________________________________________________//
	vecIter &	operator=(vecIter const & src)
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
	bool					operator<(const iterator & rhs) const
							{return (_ptr < rhs._ptr);};
	bool					operator>(const iterator & rhs) const
							{return (_ptr > rhs._ptr);};
	bool					operator<=(const iterator & rhs) const
							{return (_ptr <= rhs._ptr);};
	bool					operator>=(const iterator & rhs) const
							{return (_ptr >= rhs._ptr);};

	//___________Dereferencement______________________________________________//
	reference				operator[](const difference_type i) const
							{return _ptr[i];};
	reference				operator*() const {return *_ptr;};
	pointer					operator->() const {return _ptr;};

	//___________Incrementation_______________________________________________//
	iterator				&operator++()
	{
		_ptr++;
		return *this;
	};
	iterator				operator++(int)
	{
		iterator			tmp(*this);
		_ptr++;
		return tmp;
	};

	//___________Decrementation_______________________________________________//
	iterator				&operator--()
	{
		_ptr--;
		return *this;
	};
	iterator				operator--(int)
	{
		iterator			tmp(*this);
		_ptr--;
		return tmp;
	};

	//___________Arithmetic Operations________________________________________//
	iterator				operator+(const difference_type n) const
							{return (iterator(_ptr + n));};
	iterator				operator-(const difference_type n) const
							{return (iterator(_ptr - n));};
	difference_type			operator-(const iterator rhs) const
							{return (_ptr - rhs._ptr);};

	//___________Assignment Operations________________________________________//
	iterator				&operator+=(const difference_type n)
	{	
		_ptr += n;
		return (*this);
	};
	iterator				&operator-=(const difference_type n)
	{	
		_ptr -= n;
		return (*this);
	};
};//end vecIter

} //end ft

#endif
