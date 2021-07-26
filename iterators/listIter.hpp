#ifndef LISTITER_HPP
# define LISTITER_HPP

#include "../list/ftnode.hpp"
#include "../utils/iterator_traits.hpp"

namespace ft {

template <typename T> class clistIter;

template <typename T>
class listIter
{
	friend class clistIter<T>;
public:
	//___________MEMBER TYPES_________________________________________________//
	typedef T								value_type;
    typedef T*								pointer;
	typedef T&								reference;
	typedef ptrdiff_t						difference_type;
	typedef ft::bidirectional_iterator_tag	iterator_category;

private:
    typedef listIter				iterator;
	typedef ft::node<value_type>	node;

	node							*_ptr;

public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	listIter() : _ptr(nullptr) {};
	listIter(listIter const & src) : _ptr(src._ptr) {};
	listIter(node *ptr) : _ptr(ptr) {};

	//___________Destructor___________________________________________________//
	virtual	~listIter() {};

	//___________Operator =___________________________________________________//
	listIter &	operator=(listIter const & src)
	{
		_ptr = src._ptr;
		return (*this);
	};

	//___________OPERATOR OVERLOADS___________________________________________//
	//___________Comparisons__________________________________________________//
	bool					operator==(const clistIter<T> & rhs) const
							{return (_ptr == rhs._ptr);};
	bool					operator!=(const clistIter<T> & rhs) const
							{return (_ptr != rhs._ptr);};

	bool					operator==(const listIter<T> & rhs) const
							{return (_ptr == rhs._ptr);};
	bool					operator!=(const listIter<T> & rhs) const
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
};//end listIter

template <typename T>
class clistIter
{
	friend class listIter<T>;
public:
	//___________MEMBER TYPES_________________________________________________//
	typedef T								value_type;
    typedef const T*						pointer;
	typedef const T&						reference;
	typedef ptrdiff_t						difference_type;
	typedef ft::bidirectional_iterator_tag	iterator_category;

private:
    typedef clistIter				iterator;
	typedef ft::node<value_type>	node;
	node							*_ptr;

public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	clistIter() : _ptr(nullptr) {};
	clistIter(clistIter const & src) : _ptr(src._ptr) {};
	clistIter(listIter<value_type> const & src) : _ptr(src._ptr) {};
	clistIter(node *ptr) : _ptr(ptr) {};

	//___________Destructor___________________________________________________//
	virtual	~clistIter() {};

	//___________Operator =___________________________________________________//
	clistIter &	operator=(clistIter const & src)
	{
		_ptr = src._ptr;
		return (*this);
	};
	clistIter &	operator=(listIter<value_type> const & src)
	{
		_ptr = src._ptr;
		return (*this);
	};

	//___________OPERATOR OVERLOADS___________________________________________//
	//___________Comparisons__________________________________________________//
	bool					operator==(const clistIter<T> & rhs) const
							{return (_ptr == rhs._ptr);};
	bool					operator!=(const clistIter<T> & rhs) const
							{return (_ptr != rhs._ptr);};

	bool					operator==(const listIter<T> & rhs) const
							{return (_ptr == rhs._ptr);};
	bool					operator!=(const listIter<T> & rhs) const
							{return (_ptr != rhs._ptr);};

	//___________Dereferencement______________________________________________//
	const value_type&		operator*() const {return _ptr->value;};
	const value_type*		operator->() const {return &(_ptr->value);};

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
};//end clistIter

} //end ft

#endif
