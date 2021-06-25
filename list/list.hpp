#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <cmath>
#include "biDirectionalIterator.hpp"
#include "reverseIterator.hpp"
#include "enable_if.hpp"
#include "ftnode.hpp"

//If the macro below isn't defined it means we aren't on a mac but
//we have to define it to 0 to be able to use it on any platform
#ifndef __APPLE__
# define __APPLE__ 0
#endif

namespace ft {

class test
{
	std::string		_str;
	public:
	test() {std::cout << "constructor called" << std::endl;};
	test(std::string str) : _str(str)
	{
		std::cout << "constructor " << _str <<  " called" << std::endl;
	};
	test(const test& src) : _str(src._str)
	{
		std::cout << "CC " << _str <<  " called" << std::endl;
	};
	~test() {std::cout << "destructor " << _str << " called" << std::endl;};
	test&	operator=(const test& src)
	{
		std::cout << "= operator " << _str <<  " called" << std::endl;
		if (this == &src)
			return *this;
		return *this;
	};

};

template <typename T, typename Allocator = std::allocator<T> >
class list
{
public:
	//___________MEMBER TYPES_________________________________________________//
    typedef T											value_type;
    typedef Allocator									allocator_type;
	typedef value_type*									pointer;
    typedef typename allocator_type::reference			reference;
    typedef typename allocator_type::const_reference	const_reference;
    typedef typename allocator_type::difference_type	difference_type;
    typedef typename allocator_type::size_type			size_type;
    typedef ft::biDirectionalIterator<T>				iterator;
    typedef const ft::biDirectionalIterator<T>			const_iterator;
    typedef ft::reverseIterator<iterator>				reverse_iterator;
    typedef ft::reverseIterator<const_iterator>			const_reverse_iterator;
private:
protected:
	typedef ft::node<value_type>						node;
	node												*_head;
	allocator_type										_allocator;
	size_type											_size;
public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	list() :  _head(new node), _size(0) {};
	list(const list& src) : _head(new node), _size(0)
	{*this = src;};

	//___________Destructor___________________________________________________//
	virtual	~list()
	{
		clear();
		delete _head;
	};

	//___________Operator =___________________________________________________//
	list&	operator=(const list& src)
	{
		if (this == &src)
			return *this;
		assign(src.begin(), src.end());
		return *this;
	};

	//___________Iterators____________________________________________________//
	iterator			begin() {return iterator(_head->prev);};
	const_iterator		begin() const {return const_iterator(_head->prev);};
	iterator			end() {return iterator(_head);};
	const_iterator		end() const {return const_iterator(_head);};

	reverse_iterator		rbegin()
							{return reverse_iterator(_head->next);};
	const_reverse_iterator	rbegin() const
							{return const_reverse_iterator(_head->next);};
	reverse_iterator		rend()
							{return reverse_iterator(_head);};
	const_reverse_iterator	rend() const
							{return const_reverse_iterator(_head);};

	//___________Capacity_____________________________________________________//
	bool				empty() const {return (!(_size));};
	size_type			size() const {return _size;};
	size_type			max_size() const {return _allocator.max_size();};

	//___________Element access_______________________________________________//
	reference			front() {return _head->prev->value;};
	const_reference		front() const {return _head->prev->value;};
	reference			back() {return _head->next->value;};
	const_reference		back() const {return _head->next->value;};

	//___________Modifiers____________________________________________________//
	template <typename InputIterator>
	void				assign(typename
			ft::enable_if<!std::numeric_limits<InputIterator>::is_integer,
			InputIterator>::type first, InputIterator last)
	{
		ptrdiff_t	size = 0;

		for (InputIterator it = first; it != last; it++)
			size++;
		clear();
		for (InputIterator i = first; i != last; i++)
			push_back(*i);
	};
	void				assign(size_type n, const value_type& val)
	{
		clear();
		for (size_type i = 0; i < n; i++)
			push_back(val);
	};
	void				push_front(const value_type& val)
	{
		node*			newnode = new node(_head->prev, _head, val);

		_head->prev->next = newnode;
		_head->prev = newnode;
		_size++;
	};
	void				pop_front()
	{
		node*			tmp_p = _head->prev->prev;

		delete _head->prev;
		_head->prev = tmp_p;
		tmp_p->next = _head;
		_size--;
	};
	void				push_back(const value_type& val)
	{
		node*			newnode = new node(_head, _head->next, val);

		_head->next->prev = newnode;
		_head->next = newnode;
		_size++;
	};
	void				pop_back()
	{
		node*			tmp_n = _head->next->next;

		delete _head->next;
		_head->next = tmp_n;
		tmp_n->prev = _head;
		_size--;
	};
	iterator			insert(iterator position, const value_type& val)
	{
		node*			insertpos = position.getNode();
		node*			newnode = new node(insertpos, insertpos->next, val);

		insertpos->next->prev = newnode;
		insertpos->next = newnode;
		_size++;
		return iterator(newnode);
	};
	void				insert(iterator position, size_type n,
						const value_type& val)
	{
		while (n-- > 0)
			insert(position, val);
	};
	template <typename InputIterator>
	void				insert(iterator position, InputIterator first,
						InputIterator last)
	{
		while (first != last)
			insert(position, *first++);
	};
	iterator			erase(iterator position)
	{
		iterator		it;
		node*			pos = position.getNode();

		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		it = pos->prev;
		delete pos;
		_size--;
		return (it);
	};
	iterator			erase(iterator first, iterator last)
	{
		while (first != last)
			erase(first++);
		return (iterator(first));
	};
	void				swap(list& x)
	{
		node*		tmp = _head;
		size_type	tmpsize = _size;

		_head = x._head;
		_size = x._size;
		x._head = tmp;
		x._size = tmpsize;
	};
	void				resize(size_type n, value_type val = value_type())
	{
		for (size_type s = _size; s > n; s--)
			pop_back();
		for (size_type s = _size; s < n; s++)
			push_back(val);
	};
	void				clear()
	{
		while (_size > 0)
			pop_back();
	};

	//___________Operations___________________________________________________//
	void				splice(iterator position, list& x)
	{splice(position, x, x.begin(), x.end());};
	void				splice(iterator position, list& x, iterator i)
	{splice(position, x, i, ++i);};
	void				splice(iterator position, list& x,
								iterator first, iterator last)
	{
		node*			pos = position.getNode();
		node*			f = first.getNode();
		node*			l = last.getNode();
		node*			e = l->next;

		for (iterator i = first; i != last; i++)
		{
			_size++;
			x._size--;
		}
		f->next->prev = l;
		l->next = f->next;
		f->next = pos->next;
		f->next->prev = f;
		pos->next = e;
		pos->next->prev = pos;
	};
	void				remove(const value_type& val)
	{
		iterator		i = begin();

		while (i != end())
		{
			if (*i == val)
				i = erase(i);
			else
				i++;
		}
	};
	template <class Predicate>
	void				remove_if(Predicate pred)
	{
		iterator		i = begin();

		while (i != end())
		{
			if (pred(*i))
				i = erase(i);
			else
				i++;
		}
	};
	void				unique()
	{
		iterator		i = begin();
		iterator		ipo = i;

		ipo++;
		while (ipo != end())
		{
			if (*ipo == *i)
				ipo = erase(ipo);
			else
			{
				i++;
				ipo++;
			}
		}
	};
	template <class BinaryPredicate>
	void				unique(BinaryPredicate binary_pred)
	{
		iterator		i = begin();
		iterator		ipo = i;

		ipo++;
		while (ipo != end())
		{
			if (binary_pred(*i, *ipo) == true)
				ipo = erase(ipo);
			else
			{
				i++;
				ipo++;
			}
		}
	};
	void				merge(list& x)
	{
		iterator		i = begin();
		iterator		ix = x.begin();

		if (&x == this)
			return ;
		while (i != end() && ix != x.end())
		{
			if (*ix < *i)
				splice(i, x, ix, ++ix);
			else
				i++;
		}
		if (!x.empty())
			splice(i, x);
	};
	template <class Compare>
	void				merge(list& x, Compare comp)
	{
		iterator		i = begin();
		iterator		ix = x.begin();

		if (&x == this)
			return ;
		while (i != end() && ix != x.end())
		{
			if (comp(*ix, *i))
				splice(i, x, ix, ++ix);
			else
				i++;
		}
		if (!x.empty())
			splice(i, x);
	};
	void				sort()
	{
		iterator		i = begin();
		iterator		ipo = i;

		while (++ipo != end())
		{
			if (*ipo < *i)
			{
				splice(i, *this, ipo, ++ipo);
				i = begin();
				ipo = i;
			}
			else
				i++;
		}
	};
	template <class Compare>
	void				sort(Compare comp)
	{
		iterator		i = begin();
		iterator		ipo = i;

		while (++ipo != end())
		{
			if (comp(*ipo, *i))
			{
				splice(i, *this, ipo, ++ipo);
				i = begin();
				ipo = i;
			}
			else
				i++;
		}
	};
	void				reverse()
	{
		node*			it = _head;
		node*			n_tmp = it->next;

		for (size_type i = 0; i <= _size; i++)
		{
			it->next = it->prev;
			it->prev = n_tmp;
			it = n_tmp;
			n_tmp = it->next;
		}
	};
}; //end class list

} //end ft

#endif
