#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <cmath>
#include "biDirectionalIterator.hpp"
#include "reverseIterator.hpp"
#include "enable_if.hpp"
#include "ftnode.hpp"
#include "ftequal.hpp"
#include "ftless.hpp"
#include "ftpair.hpp"
#include "ftlexicographical_compare.hpp"

#ifndef __APPLE__
# define __APPLE__ 0
#endif

namespace ft {

//template <template <typename, typename> class Container,
		//typename Element, typename Allocator>

template <typename T>
struct avlNode
{
    typedef T				value_type;
	typedef ft::avlNode		node;
	typedef node*			pointer;

	pointer					lft, rgt, parent;
	value_type				val;

	avlNode(const value_type& v = value_type()):
		lft(nullptr), rgt(nullptr), parent(nullptr), val(v) {};

	avlNode(const pointer p, const value_type & v):
		lft(nullptr), rgt(nullptr), parent(p), val(v) {};

	avlNode(const node & src):
		lft(src.lft), rgt(src.rgt), parent(src.parent), val(src.val) {};

	virtual ~avlNode() {};

	avlNode& operator=(const node& src)
	{
		if (this == &src)
			return *this;
		lft = src.lft;
		rgt = src.rgt;
		parent = src.parent;
		val = src.val;
		return *this;
	};

	/*void	link(pointer p)
	{
		if (!parent)
			return ;
		if (val.first < parent->val.first && parent->lft == nullptr)
			parent->lft = this;
		else if (val.first > parent->val.first && parent->rgt == nullptr)
			parent->rgt = this;
		else
			std::cout << "\navlNode error: same value trying to be added\n";
	};*/
};

template < class Key,
           class T,
           class Compare = less<Key>,
           class Allocator = std::allocator<pair<const Key,T> >
           >
class map
{
public:
	//___________MEMBER TYPES_________________________________________________//
    typedef Key											key_type;
    typedef T											mapped_type;
    typedef pair<const key_type, mapped_type>			value_type;
    typedef Compare										key_compare;
    typedef Allocator									allocator_type;
    typedef typename allocator_type::reference			reference;
    typedef typename allocator_type::const_reference	const_reference;
    typedef typename allocator_type::pointer			pointer;
    typedef typename allocator_type::const_pointer		const_pointer;
    typedef typename allocator_type::size_type			size_type;
    typedef typename allocator_type::difference_type	difference_type;

    typedef ft::biDirectionalIterator<value_type>		iterator;
    typedef const ft::biDirectionalIterator<value_type>	const_iterator;
    typedef ft::reverseIterator<iterator>				reverse_iterator;
    typedef ft::reverseIterator<const_iterator>			const_reverse_iterator;
private:
protected:
	typedef ft::avlNode<value_type>						node;

	node												*_root;
	allocator_type										_allocator;
	size_type											_size;
public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
	{
		(void)comp;
		(void)alloc;
	};
	map(const map& x) {(void)x;};
	//___________Destructor___________________________________________________//
	virtual	~map()
	{};

	//___________Operator =___________________________________________________//
	map&	operator=(const map& src)
	{
		if (this == &src)
			return *this;
		return *this;
	};

	//___________Iterators____________________________________________________//
	/*iterator			begin() {return iterator(_head->prev);};
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
							{return const_reverse_iterator(_head);};*/

	//___________Capacity_____________________________________________________//
	/*bool				empty() const {return (!(_size));};
	size_type			size() const {return _size;};
	size_type			max_size() const {return _allocator.max_size();};*/

	//___________Element access_______________________________________________//
	/*reference			operator[](size_type n) {return _array[n];};
	const_reference		operator[](size_type n) const {return _array[n];};*/

	//___________Modifiers____________________________________________________//
	/*template <typename InputIterator>
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
	void				swap(map& x)
	{
		node*		tmp = _head;
		size_type	tmpsize = _size;

		_head = x._head;
		_size = x._size;
		x._head = tmp;
		x._size = tmpsize;
	};
	void				clear()
	{
		while (_size > 0)
			pop_back();
	};*/

	//___________Operations___________________________________________________//
}; //end class map

} //end ft

#endif
