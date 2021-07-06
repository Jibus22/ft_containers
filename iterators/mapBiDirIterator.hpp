#ifndef MAPBIDIRITERATOR_HPP
# define MAPBIDIRITERATOR_HPP

#include "bstree.hpp"

namespace ft {

template <typename T, typename Compare, typename Distance = ptrdiff_t,
		 typename Pointer = T*, typename Reference = T&>
class mapBiDirIterator
{
public:
	//___________MEMBER TYPES_________________________________________________//
	typedef T						value_type;
	typedef Distance				difference_type;
    typedef Pointer					pointer;
    typedef Reference				reference;

private:
    typedef Compare								key_compare;
    typedef mapBiDirIterator					iterator;
	typedef ft::bstNode<value_type>				node;
	typedef ft::bstree<node, key_compare>		tree;

	tree							_tree;
	node*							_ptr;

public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	mapBiDirIterator() : _ptr(nullptr) {};
	mapBiDirIterator(mapBiDirIterator const & src) : _ptr(src._ptr) {};
	mapBiDirIterator(node *ptr) : _ptr(ptr) {};

	//___________Destructor___________________________________________________//
	virtual	~mapBiDirIterator() {};

	//___________Operator =___________________________________________________//
	mapBiDirIterator &	operator=(mapBiDirIterator const & src)
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
	reference				operator*() const {return _ptr->val;};
	pointer					operator->() const {return &(_ptr->val);};

	//___________Incrementation_______________________________________________//
	iterator				&operator++()
	{
		_ptr = _tree.successor(_ptr);
		return *this;
	};
	iterator				operator++(int)
	{
		iterator		tmp(*this);
		_ptr = _tree.successor(_ptr);
		return tmp;
	};

	//___________Decrementation_______________________________________________//
	iterator				&operator--()
	{
		_ptr = _tree.predecessor(_ptr);
		return *this;
	};
	iterator				operator--(int)
	{
		iterator		tmp(*this);
		_ptr = _tree.predecessor(_ptr);
		return tmp;
	};

	node*		getNode() const {return _ptr;};
};//end mapBiDirIterator

} //end ft

#endif
