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
           class Compare = ft::less<Key>,
           class Allocator = std::allocator<ft::pair<const Key,T> >
           >
class map
{
public:
	//___________MEMBER TYPES_________________________________________________//
    typedef Key											key_type;
    typedef T											mapped_type;
    typedef ft::pair<const key_type, mapped_type>		value_type;
    typedef Compare										key_compare;
    typedef Allocator									allocator_type;
    typedef typename allocator_type::reference			reference;
    typedef typename allocator_type::const_reference	const_reference;
    typedef typename allocator_type::pointer			pointer;
    typedef typename allocator_type::const_pointer		const_pointer;
    typedef typename allocator_type::size_type			size_type;
    typedef typename allocator_type::difference_type	difference_type;

protected:
	typedef ft::bstNode<value_type>						node;
	typedef std::allocator<node>						node_allocator;
	typedef ft::bstree<node, key_compare>				tree;
	typedef node*										ptr;

public:
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
	tree												_tree;
	ptr													_root;
	ptr													_head;
	size_type											_size;
	key_compare											_comp;
	allocator_type										_allocator;
	node_allocator										_nodealloc;

public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _root(nullptr),
	_head(new node), _size(0), _comp(comp), _allocator(alloc)
	{
		initMe();
	};

	map(const map& x): _root(nullptr), _head(new node), _size(0)
	{
		initMe();
		_root = x.copy();
		_size = x._size;
		_head->lft = _tree.getMin(_root);
		if (_head->lft)
			_head->lft->head = _head;
		_head->rgt = _tree.getMax(_root);
		if (_head->rgt)
			_head->rgt->head = _head;
	};
	//___________Destructor___________________________________________________//
	virtual	~map()
	{
		clear();
		delete _head;
	};

	//___________Operator =___________________________________________________//
	map&	operator=(const map& src)
	{
		if (this == &src)
			return *this;
		if (!empty())
			clear();
		this->_root = src.copy();
		this->_size = src._size;
		_head->lft = _tree.getMin(_root);
		if (_head->lft)
			_head->lft->head = _head;
		_head->rgt = _tree.getMax(_root);
		if (_head->rgt)
			_head->rgt->head = _head;
		return *this;
	};

	//___________Iterators____________________________________________________//
	iterator			begin() {return iterator(_head->lft);};
	const_iterator		begin() const
						{return const_iterator(_head->lft);};
	iterator			end() {return iterator(_head);};
	const_iterator		end() const {return const_iterator(_head);};
	reverse_iterator		rbegin()
							{return reverse_iterator(_head->rgt);};
	const_reverse_iterator	rbegin() const
							{return const_reverse_iterator(_head->rgt);};
	reverse_iterator		rend()
							{return reverse_iterator(_head);};
	const_reverse_iterator	rend() const
							{return const_reverse_iterator(_head);};

	//___________Capacity_____________________________________________________//
	bool				empty() const {return !_size;};
	size_type			size() const {return _size;};
	size_type			max_size() const {return _nodealloc.max_size();};

	//___________Element access_______________________________________________//
	mapped_type&		operator[](const key_type& k)
	{
		return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
	};
	//___________Modifiers____________________________________________________//
	pair<iterator,bool>	insert(const value_type& val)
	{
		ptr		p = _root;
		ptr		p2 = p;
		bool	min = true;
		bool	max = true;

		if (!_root)
		{
			_root = new node(val);
			_size++;
			_head->lft = _root;
			_head->rgt = _root;
			_root->head = _head;
			return ft::make_pair(iterator(_root), true);
		}
		while (p)
		{
			p2 = p;
			if (_comp(p->val.first, val.first))
			{
				min = false;
				p = p->rgt;
			}
			else if (_comp(val.first, p->val.first))
			{
				max = false;
				p = p->lft;
			}
			else
				return ft::make_pair(iterator(p), false);
		}
		p = _tree.giveChild(p2, val, min, max);
		_size++;
		return ft::make_pair(iterator(p), true);
	};
	iterator			insert(iterator position, const value_type& val)
	{
		iterator	i(position);
		ptr			p = position.getNode();
		ptr			p2;

		if (++i == end())
		{
			if (_comp((*position).first, val.first))
			{
				_size++;
				return iterator(_tree.giveChild(p, val, false, true));
			}
		}
		else if (_comp((*position).first, val.first)
				&& _comp(val.first, (*i).first))
		{
			while (p)
			{
				p2 = p;
				if (_comp(p->val.first, val.first))
					p = p->rgt;
				else
					p = p->lft;
			}
			_size++;
			return iterator(_tree.giveChild(p2, val, false, false));
		}
		return (insert(val)).first;
	};

	template <class InputIterator>
	void				insert(InputIterator first, InputIterator last)
	{
		for (InputIterator i = first; i != last; i++)
			insert(*i);
	};
	iterator		erase(const_iterator position)
	{
		iterator	it(position);

		it++;
		if (!_tree.delNode(position.getNode(), position->first, &_root))
			if (!--_size)
				initMe();
		return it;
	};
	size_type		erase(const key_type& k)
	{
		if (_tree.delNode(_root, k, &_root))
			return 0;
		if (!--_size)
			initMe();
		return 1;
	};
	iterator		erase(const_iterator first, const_iterator last)
	{
		iterator	l(last);
		iterator	j(first);
		iterator	i(first);

		while (j != last) {
			++j;
			erase(i);
			i = j;
		}
		return l;
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
		initMe();
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

	void			initMe()
	{
		_root = nullptr;
		_head->lft = _head;
		_head->rgt = _head;
		_head->head = _head;
	}
}; //end class map

} //end ft

#endif
