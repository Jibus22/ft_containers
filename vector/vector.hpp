#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <exception>
#include "randomAccessIterator.hpp"

//If the macro below isn't defined it means we aren't on a mac but
//we have to define it to 0 to be able to use it on any platform
#ifndef __APPLE__
# define __APPLE__ 0
#endif

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector
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
    typedef ft::randomAccessIterator<T>					iterator;
    typedef ft::randomAccessIterator<const T>			const_iterator;
private:
protected:
	pointer												_array;
	allocator_type										_allocator;
	size_type											_capacity;
	size_type											_size;
public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	vector() : _array(nullptr), _capacity(0), _size(0) {};
	vector(const vector& src) : _array(nullptr), _capacity(0), _size(0)
	{*this = src;};

	//___________Destructor___________________________________________________//
	virtual	~vector()
	{
		clear();
		_allocator.deallocate(_array, _capacity);
	};

	//___________Operator =___________________________________________________//
	vector&	operator=(const vector& src)
	{
		if (this == &src)
			return *this;
		assign(src.begin(), src.end());
		return *this;
	};

	//___________Iterators____________________________________________________//
	iterator			begin() {return iterator(_array);};
	const_iterator		begin() const {return const_iterator(_array);};
	iterator			end() {return iterator(_array + _size);};
	const_iterator		end() const {return const_iterator(_array + _size);};

	//___________Capacity_____________________________________________________//
	size_type			size() const {return _size;};
	size_type			max_size() const {return _allocator.max_size();};
	void				resize(size_type n, value_type val = value_type())
	{
		(void)n;
		(void)val;
	};
	size_type			capacity() const {return _capacity;};
	bool				empty() const {return (!(_size));};
	void				reserve(size_type n)
	{
		pointer	tmp;

		if (n <= _capacity)
			return ;
		if (n > max_size())
			throw std::length_error("apple lenght error");
		tmp = _allocator.allocate(n);
		for (size_type i = 0; i < _size; i++)
			_allocator.construct(tmp + i, _array[i]);
		_allocator.deallocate(_array, _capacity);
		_array = tmp;
		_capacity = n;
	};

	//___________Element access_______________________________________________//
	reference			operator[](size_type n) {return _array[n];};
	const_reference		operator[](size_type n) const {return _array[n];};
	reference			at(size_type n)
	{
		if (n >= _size)
		{
			if (__APPLE__)
				throw std::out_of_range("vector apple");
			else
				throw std::out_of_range("vector linux");
		}
		return _array[n];
	};
	const_reference		at(size_type n) const
	{
		if (n >= _size)
		{
			if (__APPLE__)
				throw std::out_of_range("vector const apple");
			else
				throw std::out_of_range("vector const linux");
		}
		return _array[n];
	};
	reference			front() {return _array[0];};
	const_reference		front() const {return _array[0];};
	reference			back() {return _array[_size - 1];};
	const_reference		back() const {return _array[_size - 1];};

	//___________Modifiers____________________________________________________//
	template <typename InputIterator>
	void				assign(InputIterator first, InputIterator last)
	{
		clear();
		for (InputIterator i = first; i != last; i++)
			push_back(*i);
	};
	/*void				assign(size_type n, const value_type& val)
	{
		clear();
		for (size_type i = 0; i < n; i++)
			push_back(val);
	};*/
	void				push_back(const value_type& val)
	{
		if (_size == _capacity)
			reserve(_capacity > 0 ? _capacity * 2 : 1);
		_allocator.construct(_array + _size++, val);
	};
	void				pop_back() {_allocator.destroy(_array + --_size);};
	iterator			insert(iterator position, const value_type& val)
	{
		iterator		it = end();

		if (_size == _capacity)
			reserve(_capacity > 0 ? _capacity * 2 : 1);
		while (it != position)
		{
			_allocator.construct(&(*it), *(it - 1));
			_allocator.destroy(&(*(it - 1)));
			it--;
		}
		_allocator.construct(&(*it), val);
		return it;
	};
	/*void				insert(iterator position, size_type n,
						const value_type& val)
	{
		(void)position;
		(void)n;
		(void)val;
	};
	template <typename InputIterator>
	void				insert(iterator position, InputIterator first,
						InputIterator last)
	{
		(void)position;
		(void)first;
		(void)last;
	};
	iterator			erase(iterator position) {(void)position;};
	iterator			erase(iterator first, iterator last)
	{
		(void)first;
		(void)last;
	};
	void				swap(vector& x) {(void)x;};*/
	void				clear()
	{
		while (_size > 0)
			pop_back();
	};
}; //end class vector

} //end ft

#endif

/*
    typedef typename allocator_type::pointer			pointer;
    typedef typename allocator_type::const_pointer		const_pointer;
    typedef implementation-defined                   const_iterator;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
*/
