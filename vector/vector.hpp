#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <cmath>
#include "randomAccessIterator.hpp"
#include "reverseIterator.hpp"
#include "enable_if.hpp"

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
    typedef ft::reverseIterator<iterator>				reverse_iterator;
    typedef ft::reverseIterator<const_iterator>			const_reverse_iterator;
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

	reverse_iterator		rbegin()
							{return reverse_iterator(_array + _size - 1);};
	const_reverse_iterator	rbegin() const
							{return const_reverse_iterator(_array + _size - 1);};
	reverse_iterator		rend()
							{return reverse_iterator(_array - 1);};
	const_reverse_iterator	rend() const
							{return const_reverse_iterator(_array - 1);};

	//___________Capacity_____________________________________________________//
	size_type			size() const {return _size;};
	size_type			max_size() const {return _allocator.max_size();};
	void				resize(size_type n, value_type val = value_type())
	{
		for (size_type s = _size; s > n; s--)
			pop_back();
		if (n > 2 * _capacity)
			reserve(n);
		for (size_type s = _size; s < n; s++)
			push_back(val);
	};
	size_type			capacity() const {return _capacity;};
	bool				empty() const {return (!(_size));};
	void				reserve(size_type n)
	{
		pointer		tmp;
		size_type	sizecpy = _size;

		if (n <= _capacity)
			return ;
		if (n > max_size())
			throw std::length_error("apple lenght error");
		tmp = _allocator.allocate(n);
		for (size_type i = 0; i < _size; i++)
			_allocator.construct(tmp + i, _array[i]);
		clear();
		_allocator.deallocate(_array, _capacity);
		_array = tmp;
		_capacity = n;
		_size = sizecpy;
	};

	//___________Element access_______________________________________________//
	reference			operator[](size_type n) {return _array[n];};
	const_reference		operator[](size_type n) const {return _array[n];};
	reference			at(size_type n)
	{
		if (n < _size)
			return _array[n];
		if (__APPLE__)
			throw std::out_of_range("vector apple");
		else
			throw std::out_of_range("vector linux");
	};
	const_reference		at(size_type n) const
	{
		if (n < _size)
			return _array[n];
		if (__APPLE__)
			throw std::out_of_range("vector const apple");
		else
			throw std::out_of_range("vector const linux");
	};
	reference			front() {return _array[0];};
	const_reference		front() const {return _array[0];};
	reference			back() {return _array[_size - 1];};
	const_reference		back() const {return _array[_size - 1];};

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
		reserve(size);
		for (InputIterator i = first; i != last; i++)
			push_back(*i);
	};
	void				assign(size_type n, const value_type& val)
	{
		clear();
		reserve(n);
		for (size_type i = 0; i < n; i++)
			push_back(val);
	};
	void				push_back(const value_type& val)
	{
		if (_size == _capacity)
			reserve(_capacity > 0 ? _capacity * 2 : 1);
		_allocator.construct(_array + _size++, val);
	};
	void				pop_back() {_allocator.destroy(_array + --_size);};
	iterator			insert(iterator position, const value_type& val)
	{
		typename iterator::difference_type	diff = end() - position;
		iterator							it;

		if (diff < 0)
			return end();
		if (_size == _capacity)
			reserve(_capacity > 0 ? _capacity * 2 : 1);
		it = end();
		while (diff-- > 0)
		{
			_allocator.construct(&(*it), *(it - 1));
			_allocator.destroy(&(*(it - 1)));
			it--;
		}
		_allocator.construct(&(*it), val);
		_size++;
		return it;
	};
	void				insert(iterator position, size_type n,
						const value_type& val)
	{
		typename iterator::difference_type	diff = end() - position;
		size_type							i = _size + n;
		size_type							j = _size;

		if (diff < 0 || n == 0)
			return ;
		if (i > 2 * _capacity)
			reserve(i);
		else if (i > _capacity)
			reserve(_capacity > 0 ? _capacity * 2 : 1);
		while (diff-- > 0)
		{
			_allocator.construct(_array + --i, _array[--j]);
			if (diff)
				_allocator.destroy(_array + j);
		}
		diff = n;
		while (diff-- > 0)
			_allocator.construct(_array + --i, val);
		_size += n;
	};
	template <typename InputIterator>
	void				insert(iterator position, InputIterator first,
						InputIterator last)
	{
		typename iterator::difference_type	diff = end() - position;
		size_type							j = _size;
		size_type							len = 0;
		size_type							i;

		for (InputIterator it = first; it != last; it++)
			len++;
		if (diff < 0 || len == 0)
			return ;
		i = _size + len;
		if (i > 2 * _capacity)
			reserve(i);
		else if (i > _capacity)
			reserve(_capacity > 0 ? _capacity * 2 : 1);
		while (diff-- > 0)
		{
			_allocator.construct(_array + --i, _array[--j]);
			if (diff)
				_allocator.destroy(_array + j);
		}
		diff = len;
		while (diff-- > 0)
			_allocator.construct(_array + j++, *first++);
		_size += len;
	};
	iterator			erase(iterator position)
	{
		for (size_type i = position - begin(); i < _size; i++)
		{
			_allocator.destroy(_array + i);
			if (i + 1 < _size)
				_allocator.construct(_array + i, _array[i + 1]);
		}
		_size--;
		return position;
	};
	iterator			erase(iterator first, iterator last)
	{
		size_type		start = first - begin();
		size_type		stop = last - begin();

		while (start < stop)
		{
			_allocator.destroy(_array + start);
			if (start + stop < _size)
				_allocator.construct(_array + start, _array[start + stop]);
			start++;
		}
		_size -= (last - first);
		while (start < _size)
		{
			_allocator.construct(_array + start, _array[start + stop]);
			start++;
		}
		return first;
	};
	void				swap(vector& x)
	{
		pointer		tmp_array;
		size_type	tmp_capacity;
		size_type	tmp_size;

		tmp_array = x._array;
		tmp_size = x._size;
		tmp_capacity = x._capacity;
		x._array = _array;
		x._size = _size;
		x._capacity = _capacity;
		_array = tmp_array;
		_size = tmp_size;
		_capacity = tmp_capacity;
	};
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
*/
