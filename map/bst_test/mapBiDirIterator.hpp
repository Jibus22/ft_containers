#ifndef MAPBIDIRITERATOR_HPP
# define MAPBIDIRITERATOR_HPP

#include "node.hpp"

namespace ft {

template <typename T, typename Distance = ptrdiff_t,
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
    typedef mapBiDirIterator		iterator;
	typedef ft::bstnode<value_type>	node;

	node							_nd;
	node							*_ptr;

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
		node*			nxt = _nd.nextNode(_ptr);

		if (_ptr == nxt)
			_ptr = nullptr;
		else
			_ptr = nxt;
		return *this;
	};
	iterator				operator++(int)
	{
		iterator		tmp(*this);
		node*			nxt = _nd.nextNode(_ptr);

		if (_ptr == nxt)
			_ptr = nullptr;
		else
			_ptr = nxt;
		return tmp;
	};

	//___________Decrementation_______________________________________________//
	iterator				&operator--()
	{
		node*			nxt = _nd.prevNode(_ptr);

		if (_ptr == nxt)
			_ptr = nullptr;
		else
			_ptr = nxt;
		return *this;
	};
	iterator				operator--(int)
	{
		iterator		tmp(*this);
		node*			nxt = _nd.prevNode(_ptr);

		if (_ptr == nxt)
			_ptr = nullptr;
		else
			_ptr = nxt;
		return tmp;
	};

	node*		getNode() const {return _ptr;};
};//end mapBiDirIterator

} //end ft

#endif
