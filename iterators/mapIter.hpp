#ifndef MAPBIDIRITERATOR_HPP
# define MAPBIDIRITERATOR_HPP

#include "bstree.hpp"
#include "iterator_traits.hpp"

namespace ft {

template <typename T, typename Compare> class cmapIter;

template <typename T, typename Compare>
class mapIter
{
	friend class cmapIter<T, Compare>;
public:
	//___________MEMBER TYPES_________________________________________________//
	typedef T								value_type;
    typedef T*								pointer;
	typedef T&								reference;
	typedef ptrdiff_t						difference_type;
	typedef ft::bidirectional_iterator_tag	iterator_category;

private:
    typedef Compare								key_compare;
    typedef mapIter								iterator;
	typedef ft::bstNode<value_type>				node;
	typedef ft::bstree<node, key_compare>		tree;

	tree							_tree;
	node*							_ptr;

public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	mapIter() : _ptr(nullptr) {};
	mapIter(const mapIter & src) : _ptr(src._ptr) {};
	mapIter(node *ptr) : _ptr(ptr) {};

	//___________Destructor___________________________________________________//
	virtual	~mapIter() {};

	//___________Operator =___________________________________________________//
	mapIter &	operator=(const mapIter & src)
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
		node*		tmp = _ptr;

		if (_ptr->head == _ptr)//means we are currently the head node
				_ptr = _ptr->lft;
		else {
			_ptr = _tree.successor(_ptr);
			if (!_ptr)
				_ptr = tmp->head;
		}
		return *this;
	};
	iterator				operator++(int)
	{
		iterator		tmp(*this);
		operator++();
		return tmp;
	};

	//___________Decrementation_______________________________________________//
	iterator				&operator--()
	{
		node*		tmp = _ptr;

		if (_ptr->head == _ptr)//means we are currently the head node
			_ptr = _ptr->rgt;
		else {
			_ptr = _tree.predecessor(_ptr);
			if (!_ptr)
				_ptr = tmp->head;
		}
		return *this;
	};
	iterator				operator--(int)
	{
		iterator		tmp(*this);
		operator--();
		return tmp;
	};

	node*		getNode() const {return _ptr;};
};//end mapIter

template <typename T, typename Compare>
class cmapIter
{
public:
	//___________MEMBER TYPES_________________________________________________//
	typedef T								value_type;
    typedef T*								pointer;
	typedef T&								reference;
	typedef ptrdiff_t						difference_type;
	typedef ft::bidirectional_iterator_tag	iterator_category;

private:
    typedef Compare								key_compare;
    typedef cmapIter							iterator;
	typedef ft::bstNode<value_type>				node;
	typedef ft::bstree<node, key_compare>		tree;

	tree							_tree;
	node*							_ptr;

public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	cmapIter() : _ptr(nullptr) {};
	cmapIter(const cmapIter & src) : _ptr(src._ptr) {};
	cmapIter(const mapIter<value_type, key_compare> & src) : _ptr(src._ptr) {};
	cmapIter(node *ptr) : _ptr(ptr) {};

	//___________Destructor___________________________________________________//
	virtual	~cmapIter() {};

	//___________Operator =___________________________________________________//
	cmapIter &	operator=(const cmapIter & src)
	{
		_ptr = src._ptr;
		return (*this);
	};
	cmapIter &	operator=(const mapIter<value_type, key_compare> & src)
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
	const value_type&		operator*() const {return _ptr->val;};
	const value_type*		operator->() const {return &(_ptr->val);};

	//___________Incrementation_______________________________________________//
	iterator				&operator++()
	{
		node*		tmp = _ptr;

		if (_ptr->head == _ptr)//means we are currently the head node
				_ptr = _ptr->lft;
		else {
			_ptr = _tree.successor(_ptr);
			if (!_ptr)
				_ptr = tmp->head;
		}
		return *this;
	};
	iterator				operator++(int)
	{
		iterator		tmp(*this);
		operator++();
		return tmp;
	};

	//___________Decrementation_______________________________________________//
	iterator				&operator--()
	{
		node*		tmp = _ptr;

		if (_ptr->head == _ptr)//means we are currently the head node
			_ptr = _ptr->rgt;
		else {
			_ptr = _tree.predecessor(_ptr);
			if (!_ptr)
				_ptr = tmp->head;
		}
		return *this;
	};
	iterator				operator--(int)
	{
		iterator		tmp(*this);
		operator--();
		return tmp;
	};

	node*		getNode() const {return _ptr;};
};//end cmapIter

} //end ft

#endif
