#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <cstddef>
#include "../iterators/mapIter.hpp"
#include "../iterators/reverseIterator.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/ftequal.hpp"
#include "../utils/ftless.hpp"
#include "../utils/ftpair.hpp"
#include "bstree.hpp"
#include "../utils/ftlexicographical_compare.hpp"

#ifndef __APPLE__
# define __APPLE__ 0
#endif

namespace ft {

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

	//___________NESTED CLASS_________________________________________________//
	class value_compare: ft::binary_function <value_type, value_type, bool>
	{
		friend class map;
		protected:
		key_compare							comp;

		value_compare(key_compare c): comp(c) {};

		public:
		typedef bool						result_type;
		typedef value_type					first_argument_type;
		typedef value_type					second_argument_type;

		bool operator()(const value_type& x, const value_type& y) const
		{return comp(x.first, y.first);}
	};

protected:
	typedef ft::bstNode<value_type>						node;
	typedef typename allocator_type::template rebind<node>::other
		node_allocator;

	typedef ft::bstree<node, key_compare, node_allocator>	tree;
	typedef node*										ptr;

	tree												_tree;
	ptr													_root;
	ptr													_head;
	size_type											_size;
	key_compare											_comp;
	allocator_type										_allocator;
	node_allocator										_nodealloc;

public:
    typedef ft::mapIter<value_type, key_compare, node_allocator>	iterator;
    typedef ft::cmapIter<value_type, key_compare, node_allocator>
		const_iterator;

    typedef ft::reverse_iterator<iterator>				reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _root(NULL),
	_head(newNd(node())), _size(0), _comp(comp), _allocator(alloc)
	{
		initMe();
	};

	template <class InputIterator>
	map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): _root(NULL),
	_head(newNd(node())), _size(0), _comp(comp), _allocator(alloc)
	{
		initMe();
		insert(first, last);
	};

	map(const map& x): _root(NULL), _head(newNd(node())), _size(0),
	_comp(x._comp), _allocator(x._allocator)
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
		delNd(_head);
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
	iterator				begin() {return iterator(_head->lft);};
	const_iterator			begin() const
							{return const_iterator(_head->lft);};
	iterator				end() {return iterator(_head);};
	const_iterator			end() const {return const_iterator(_head);};
	reverse_iterator		rbegin()
							{return reverse_iterator(end());};
	const_reverse_iterator	rbegin() const
							{return const_reverse_iterator(end());};
	reverse_iterator		rend()
							{return reverse_iterator(begin());};
	const_reverse_iterator	rend() const
							{return const_reverse_iterator(begin());};

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
			_root = newNd(node(val));
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

		if (i == end())
			return (insert(val)).first;
		else if (++i == end())
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
	iterator		erase(iterator position)
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
	iterator		erase(iterator first, iterator last)
	{
		iterator	i(first);

		while (first != last) {
			++first;
			erase(i);
			i = first;
		}
		return last;
	};
	void				swap(map& x)
	{
		ptr			tmp_root = _root;
		ptr			tmp_head = _head;
		size_type	tmp_size = _size;

		_root = x._root;
		_head = x._head;
		_size = x._size;
		x._root = tmp_root;
		x._head = tmp_head;
		x._size = tmp_size;
	};
	void				clear()
	{
		_tree.postOrderDelete(_root);
		initMe();
		_size = 0;
	};

	//___________Observers____________________________________________________//
	key_compare			key_comp() const {return _comp;};
	value_compare		value_comp() const {return value_compare(_comp);};

	//___________Operations___________________________________________________//
	iterator			find(const key_type& k)
	{
		ptr	find = _tree.findKey(_root, k);
		if (!find)
			return end();
		return iterator(find);
	};
	const_iterator		find(const key_type& k) const
	{
		ptr	find = _tree.findKey(_root, k);
		if (!find)
			return end();
		return const_iterator(find);
	};
	size_type			count(const key_type& k) const
	{
		if (_tree.findKey(_root, k))
			return 1;
		return 0;
	};
	iterator			lower_bound(const key_type& k)
	{
		ptr			p = _root;
		ptr			last = p;
		iterator	i;

		while (p)
		{
			last = p;
			if (_comp(p->val.first, k))
				p = p->rgt;
			else if (_comp(k, p->val.first))
				p = p->lft;
			else
				return iterator(p);
		}
		return bound(last, k);
	};
	const_iterator		lower_bound(const key_type& k) const
	{
		ptr			p = _root;
		ptr			last = p;
		iterator	i;

		while (p)
		{
			last = p;
			if (_comp(p->val.first, k))
				p = p->rgt;
			else if (_comp(k, p->val.first))
				p = p->lft;
			else
				return const_iterator(p);
		}
		return bound(last, k);
	};
	iterator			upper_bound(const key_type& k)
	{
		ptr			p = _root;
		ptr			last = p;
		iterator	i;

		while (p)
		{
			last = p;
			if (_comp(p->val.first, k))
				p = p->rgt;
			else if (_comp(k, p->val.first))
				p = p->lft;
			else
				return ++iterator(p);
		}
		return bound(last, k);
	};
	const_iterator		upper_bound(const key_type& k) const
	{
		ptr			p = _root;
		ptr			last = p;
		iterator	i;

		while (p)
		{
			last = p;
			if (_comp(p->val.first, k))
				p = p->rgt;
			else if (_comp(k, p->val.first))
				p = p->lft;
			else
				return ++const_iterator(p);
		}
		return bound(last, k);
	};

	ft::pair<iterator,iterator>				equal_range(const key_type& k)
	{return ft::make_pair(lower_bound(k), upper_bound(k));};
	ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
	{return ft::make_pair(lower_bound(k), upper_bound(k));};

	//___________Internal utilities___________________________________________//
	private:
	ptr				copy() const
	{
		ptr		newNode = NULL;

		_tree.preOrderCpy(_root, &newNode);
		return newNode;
	};

	void			initMe()
	{
		_root = NULL;
		_head->lft = _head;
		_head->rgt = _head;
		_head->head = _head;
	}

	iterator		bound(ptr last, const key_type& k)
	{
		if (!last)
			return end();
		if (_comp(last->val.first, k))
			return ++iterator(last);
		else if (_comp(k, last->val.first))
			return iterator(last);
		else
			return end();
	};
	const_iterator	bound(ptr last, const key_type& k) const
	{
		if (!last)
			return end();
		if (_comp(last->val.first, k))
			return ++const_iterator(last);
		else if (_comp(k, last->val.first))
			return const_iterator(last);
		else
			return end();
	};

	typename node_allocator::pointer
	newNd(typename node_allocator::const_reference val)
	{
		typename node_allocator::pointer	p = _nodealloc.allocate(1);
		_nodealloc.construct(p, val);
		return p;
	};
	void	delNd(typename node_allocator::pointer p)
	{
		_nodealloc.destroy(p);
		_nodealloc.deallocate(p, 1);
	};
}; //end class map


//___________Relational operators_________________________________________//
template <class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs)
{
	return (lhs.size() == rhs.size()
		&& ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
};

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs) {return (!(lhs == rhs));};

template <class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs)
{
	return ft::lexicographical_compare(lhs.begin(),
				lhs.end(), rhs.begin(), rhs.end());
};

template <class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs) {return rhs < lhs;};

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs) {return (!(lhs < rhs));};

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs) {return (!(rhs < lhs));};


//___________Swap Overload________________________________________________//
template <class Key, class T, class Compare, class Alloc>
void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
{x.swap(y);};

} //end ft

#endif
