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

	private:
	node						_nd;
	pointer						_root;
	size_t						_size;

	public:
	bstree(): _root(nullptr), _size(0) {};
	bstree(const bstree& src): _root(nullptr), _size(0) {*this = src;};
	virtual ~bstree() {clear();};

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

	iterator		begin() {return(iterator(findMin()));};
	iterator		end() {return(iterator(nullptr));};

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

	size_t			size() const {return _size;};
	bool			empty() const {return !_size;};

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
