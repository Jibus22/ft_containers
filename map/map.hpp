#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <cmath>
#include "mapBiDirIterator.hpp"
#include "reverseIterator.hpp"
#include "enable_if.hpp"
#include "ftequal.hpp"
#include "ftless.hpp"
#include "ftpair.hpp"
#include "bstree.hpp"
#include "ftlexicographical_compare.hpp"

#ifndef __APPLE__
# define __APPLE__ 0
#endif

namespace ft {

//template <template <typename, typename> class Container,
		//typename Element, typename Allocator>

template < class Key,
           class T,
           class Compare = std::less<Key>,
           class Allocator = std::allocator<std::pair<const Key,T> >
           >
class map
{
public:
	//___________MEMBER TYPES_________________________________________________//
    typedef Key											key_type;
    typedef T											mapped_type;
    typedef std::pair<const key_type, mapped_type>		value_type;
    typedef Compare										key_compare;
    typedef Allocator									allocator_type;
    typedef typename allocator_type::reference			reference;
    typedef typename allocator_type::const_reference	const_reference;
    typedef typename allocator_type::pointer			pointer;
    typedef typename allocator_type::const_pointer		const_pointer;
    typedef typename allocator_type::size_type			size_type;
    typedef typename allocator_type::difference_type	difference_type;

    typedef ft::mapBiDirIterator<value_type, key_compare>		iterator;
    typedef const ft::mapBiDirIterator<value_type, key_compare>	const_iterator;

    typedef ft::reverseIterator<iterator>				reverse_iterator;
    typedef ft::reverseIterator<const_iterator>			const_reverse_iterator;

	//___________NESTED CLASS_________________________________________________//
	class value_compare: ft::binary_function <value_type, value_type, bool>
	{
		protected:
		key_compare comp;
		value_compare(key_compare c): comp(c) {};
		public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator()(const value_type& x, const value_type& y) const
		{return comp(x.first, y.first);}
	};

protected:
	typedef ft::bstNode<value_type>						node;
	typedef ft::bstree<node, key_compare>				tree;
	typedef node*										ptr;

	tree												_tree;
	ptr													_root;
	size_type											_size;
	key_compare											_comp;
	allocator_type										_allocator;
public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _root(nullptr),
	_size(0), _comp(comp), _allocator(alloc) {};

	map(const map& x): _root(nullptr), _size(0)
	{
		_root = x.copy();
		_size = x._size;
	};
	//___________Destructor___________________________________________________//
	virtual	~map() {clear();};

	//___________Operator =___________________________________________________//
	map&	operator=(const map& src)
	{
		if (this == &src)
			return *this;
		if (!empty())
			clear();
		this->_root = src.copy();
		this->_size = src._size;
		return *this;
	};

	//___________Iterators____________________________________________________//
	iterator			begin() {return iterator(_tree.getMin(_root));};
	const_iterator		begin() const
						{return const_iterator(_tree.getMin(_root));};
	iterator			end() {return iterator(nullptr);};
	const_iterator		end() const {return const_iterator(nullptr);};
/*
	reverse_iterator		rbegin()
							{return reverse_iterator(_head->next);};
	const_reverse_iterator	rbegin() const
							{return const_reverse_iterator(_head->next);};
	reverse_iterator		rend()
							{return reverse_iterator(_head);};
	const_reverse_iterator	rend() const
							{return const_reverse_iterator(_head);};*/

	//___________Capacity_____________________________________________________//
	bool				empty() const {return !_size;};
	size_type			size() const {return _size;};
	/*size_type			max_size() const {return _allocator.max_size();};*/

	//___________Element access_______________________________________________//
	mapped_type&		operator[](const key_type& k)
	{
		return (*((this->insert(std::make_pair(k,mapped_type()))).first)).second;
	};
	//___________Modifiers____________________________________________________//
	pair<iterator,bool>	insert(const value_type& val)
	{
		ptr	p = _root;
		ptr	p2 = p;

		if (!_root)
		{
			_root = new node(val);
			_size++;
			return ft::make_pair(iterator(_root), true);
		}
		while (p)
		{
			p2 = p;
			if (_comp(p->val.first, val.first))
				p = p->rgt;
			else if (_comp(val.first, p->val.first))
				p = p->lft;
			else
				return ft::make_pair(iterator(p), false);
		}
		p = _tree.giveChild(p2, val);
		_size++;
		return ft::make_pair(iterator(p), true);
	};
	iterator			insert(iterator position, const value_type& val)
	{
		iterator	i(position);
		ptr			p;

		if (_comp((*i).first, val.first) && !_comp(val.first, (*i).first)
				&& _comp(val.first, (*++i).first))
		{
			p = i.getNode();
			_size++;
			return iterator(_tree.giveChild(p, val));
		}
		return (insert(val)).first;
	};

	template <class InputIterator>
	void				insert(InputIterator first, InputIterator last)
	{
		for (InputIterator i = first; i != last; i++)
			insert(*i);
	};
	void			erase(iterator position)
	{
		if (!_tree.delNode(position.getNode(), position->first, &_root))
			if (!--_size)
				_root = nullptr;
	};
	size_type		erase(const key_type& k)
	{
		if (_tree.delNode(_root, k, &_root))
			return 0;
		if (!--_size)
			_root = nullptr;
		return 1;
	};
	void			erase(iterator first, iterator last)
	{
		for ( ; first != last; first++)
			erase(first);
	};
	void				swap(map& x)
	{
		ptr			tmp = _root;
		size_type	tmpsize = _size;

		_root = x._root;
		_size = x._size;
		x._root = tmp;
		x._size = tmpsize;
	};
	void				clear()
	{
		_tree.postOrderDelete(_root);
		_root = nullptr;
		_size = 0;
	};

	//___________Operations___________________________________________________//


	private:
	ptr				copy() const
	{
		ptr		newNode = nullptr;

		_tree.preOrderCpy(_root, &newNode);
		return newNode;
	};
}; //end class map

} //end ft

#endif
