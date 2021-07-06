#ifndef BST_HPP
# define BST_HPP

#include <iostream>
#include "node.hpp"
#include "mapBiDirIterator.hpp"

template <typename T>
class bstree
{
	public:
	typedef T									value_type;
	typedef ft::bstnode<value_type>				node;
	typedef node*								pointer;
	typedef ft::mapBiDirIterator<value_type>	iterator;
	typedef const iterator						const_iterator;

	private:
	node						_nd;
	pointer						_root;
	size_t						_size;

	public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	bstree(): _root(nullptr), _size(0) {};
	bstree(const bstree& src): _root(nullptr), _size(0) {*this = src;};

	//___________Destructor___________________________________________________//
	virtual ~bstree() {clear();};

	//___________Operator =___________________________________________________//
	bstree&	operator=(const bstree& src)
	{
		if (this == &src)
			return *this;
		if (_size)
			clear();
		_root = src.copy();
		_size = src._size;
		return *this;
	};

	//___________Iterators____________________________________________________//
	iterator		begin() {return(iterator(findMin()));};
	const_iterator	begin() const {return(const_iterator(findMin()));};
	iterator		end() {return(iterator(nullptr));};
	const_iterator	end() const {return(const_iterator(nullptr));};

	//___________Capacity_____________________________________________________//
	bool			empty() const {return !_size;};
	size_t			size() const {return _size;};

	//___________Element access_______________________________________________//
	value_type		operator[](const value_type& k)
	{
		pointer		find = findKey(k);

		if (!find)
			insert(k);
		else
			return find->val;
		return k;
	};
	//___________Modifiers____________________________________________________//
	void			insert(value_type v)
	{
		_root = _nd.insert(_root, v);
		_size++;
	}
	void			del(value_type key)
	{
		if (!_nd.delNode(_root, key))
			if (!--_size)
				_root = nullptr;
	};


	void			clear()
	{
		_nd.postOrderDelete(_root);
		_root = nullptr;
		_size = 0;
	};

	private:
	pointer			copy() const
	{
		pointer		newNode = nullptr;

		_nd.preOrderCpy(_root, &newNode);
		return newNode;
	};

	public:

	pointer	findKey(value_type key) {return(_nd.findKey(_root, key));};

	pointer next(pointer p) {return(_nd.nextNode(p));};
	pointer prev(pointer p) {return(_nd.prevNode(p));};

	void	iop(void) {_nd.inorderPrint(_root);};
	void	preop(void) {_nd.preorderPrint(_root);};
	void	postop(void) {_nd.postorderPrint(_root);};
	pointer	findMax() {return(_nd.findMax(_root));};
	pointer	findMin() {return(_nd.findMin(_root));};

	pointer	ioSuc(pointer p) {return(_nd.inorderSuc(p));};
	pointer	ioPred(pointer p) {return(_nd.inorderPred(p));};
};

#endif
