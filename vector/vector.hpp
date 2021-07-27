#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <cstddef>
#include "../iterators/vecIter.hpp"
#include "../iterators/reverseIterator.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/ftequal.hpp"
#include "../utils/ftlexicographical_compare.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/is_integral.hpp"

//If the macro below isn't defined it means we aren't on a mac, so
//we have to define it to 0 to be able to use it on any platform.
//This macro is defined (on 1) by the compiler only if we are on macosx.
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

    typedef ft::vecIter<value_type>						iterator;
    typedef ft::cvecIter<value_type>					const_iterator;
    typedef ft::reverse_iterator<iterator>				reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

protected:
	pointer												_array;
	size_type											_capacity;
	size_type											_size;
	allocator_type										_allocator;

public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	explicit vector(const allocator_type& alloc = allocator_type()):
		_array(NULL), _capacity(0), _size(0), _allocator(alloc)
	{};

	explicit vector(size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) :
		_array(NULL), _capacity(0), _size(0), _allocator(alloc)
	{assign(n, val);};

	template <class InputIterator>
    vector(InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type()) :
		_array(NULL), _capacity(0), _size(0), _allocator(alloc)
	{assign(first, last);};

	vector(const vector& src) : _array(NULL), _capacity(0), _size(0),
	_allocator(src._allocator)
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
	iterator				begin() {return iterator(_array);};
	const_iterator			begin() const {return const_iterator(_array);};
	iterator				end() {return iterator(_array + _size);};
	const_iterator			end() const {return const_iterator(_array + _size);};

	reverse_iterator		rbegin()
							{return reverse_iterator(end());};
	const_reverse_iterator	rbegin() const
							{return const_reverse_iterator(end());};
	reverse_iterator		rend()
							{return reverse_iterator(begin());};
	const_reverse_iterator	rend() const
							{return const_reverse_iterator(begin());};

	//___________Capacity_____________________________________________________//
	size_type			size() const {return _size;};
	size_type			max_size() const {return _allocator.max_size();};
	void				resize(size_type n, value_type val = value_type())
	{
		size_type const	&headroom = (__APPLE__ ? _capacity : _size);

		for (size_type s = _size; s > n; s--)
			pop_back();
		if (n > _capacity)
		{
			if (n <= headroom * 2)
				this->reserve(headroom * 2);
			else
				this->reserve(n);
		}
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
		{
			if (__APPLE__)
				throw std::length_error("allocator<T>::allocate(size_t n) 'n' "
						"exceeds maximum supported size");
			else
				throw std::length_error("vector::reserve");
		}
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
			throw std::out_of_range("vector");
		else
		{
			std::stringstream ss;
			ss << "vector::_M_range_check: __n (which is " << n
				<< ") >= this->size() (which is " << this->_size << ")";
			throw std::out_of_range(ss.str());
		}
	};
	const_reference		at(size_type n) const
	{
		if (n < _size)
			return _array[n];
		if (__APPLE__)
			throw std::out_of_range("vector");
		else
		{
			std::stringstream ss;
			ss << "vector::_M_range_check: __n (which is " << n
				<< ") >= this->size() (which is " << this->_size << ")";
			throw std::out_of_range(ss.str());
		}
	};
	reference			front() {return _array[0];};
	const_reference		front() const {return _array[0];};
	reference			back() {return _array[_size - 1];};
	const_reference		back() const {return _array[_size - 1];};

	//___________Modifiers____________________________________________________//
	template <typename InputIterator>
	void				assign(typename
			ft::enable_if<!ft::is_integral<InputIterator>::value,
			InputIterator>::type first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	size = 
			distance(first, last, typename
					ft::iterator_traits<InputIterator>::iterator_category());

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
		if (__APPLE__ && i > _capacity)
			reserve(i > 2 * _capacity ? i : _capacity * 2);
		else if (!__APPLE__ && i > _capacity)
			reserve(i > 2 * _size ? i : _size * 2);
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
	void				insert(iterator position, typename
			ft::enable_if<!ft::is_integral<InputIterator>::value,
			InputIterator>::type first, InputIterator last)
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
		if (__APPLE__ && i > _capacity)
			reserve(i > 2 * _capacity ? i : _capacity * 2);
		else if (!__APPLE__ && i > _capacity)
			reserve(i > 2 * _size ? i : _size * 2);
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
		iterator	ret(first);
		iterator	endCpy(end());

		while (last < endCpy)
			*first++ = *last++;
		while (first < endCpy)
		{
			this->_allocator.destroy(&*(first++));
			this->_size--;
		}
		return (ret);
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

private:
	//UTILS
	template <typename randomIterator>
	typename ft::iterator_traits<randomIterator>::difference_type
	distance(randomIterator first, randomIterator last,
			ft::random_access_iterator_tag)
	{return last - first;};
	template <typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last,
			ft::input_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type	diff;
		for (diff=0; first != last; first++, diff++);
		return diff;
	};
}; //end class vector


//___________Relational operators_________________________________________//
template <class T, class Alloc>
bool	operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return (lhs.size() == rhs.size()
		&& ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
};

template <class T, class Alloc>
bool	operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{return !(lhs == rhs);};

template <class T, class Alloc>
bool	operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(),
				lhs.end(), rhs.begin(), rhs.end());
};

template <class T, class Alloc>
bool	operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{return !(rhs < lhs);};

template <class T, class Alloc>
bool	operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{return rhs < lhs;};

template <class T, class Alloc>
bool	operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{return !(lhs < rhs);};


//___________Swap Overload________________________________________________//
template <class T, class Alloc>
void	swap(ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {x.swap(y);};

} //end ft

#endif
