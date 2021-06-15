#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

namespace ft {

template <typename T, typename Distance = ptrdiff_t,
		 typename Pointer = T*, typename Reference = T&>
class randomAccessIterator
{
public:
	//___________MEMBER TYPES_________________________________________________//
	typedef T						value_type;
	typedef Distance				difference_type;
    typedef Pointer					pointer;
    typedef Reference				reference;

private:
    typedef randomAccessIterator	iterator;
	pointer							_ptr;

public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	randomAccessIterator() : _ptr(nullptr) {};
	randomAccessIterator(randomAccessIterator const & src) : _ptr(src._ptr) {};
	randomAccessIterator(pointer ptr) : _ptr(ptr) {};

	//___________Destructor___________________________________________________//
	virtual	~randomAccessIterator() {};

	//___________Operator =___________________________________________________//
	randomAccessIterator &	operator=(randomAccessIterator const & src)
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
	bool					operator<(const iterator & rhs) const
							{return (_ptr < rhs._ptr);};
	bool					operator>(const iterator & rhs) const
							{return (_ptr > rhs._ptr);};
	bool					operator<=(const iterator & rhs) const
							{return (_ptr <= rhs._ptr);};
	bool					operator>=(const iterator & rhs) const
							{return (_ptr >= rhs._ptr);};

	//___________Dereferencement______________________________________________//
	reference				operator[](const difference_type i) const
							{return _ptr[i];};
	reference				operator*() const {return *_ptr;};
	pointer					operator->() const {return _ptr;};

	//___________Incrementation_______________________________________________//
	iterator				&operator++()
	{
		_ptr++;
		return *this;
	};
	iterator				operator++(int)
	{
		iterator			tmp(*this);
		_ptr++;
		return tmp;
	};

	//___________Decrementation_______________________________________________//
	iterator				&operator--()
	{
		_ptr--;
		return *this;
	};
	iterator				operator--(int)
	{
		iterator			tmp(*this);
		_ptr--;
		return tmp;
	};

	//___________Arithmetic Operations________________________________________//
	iterator				operator+(const difference_type n) const
							{return (iterator(_ptr + n));};
	iterator				operator-(const difference_type n) const
							{return (iterator(_ptr - n));};
	difference_type			operator-(const iterator rhs) const
							{return (_ptr - rhs._ptr);};

	//___________Assignment Operations________________________________________//
	iterator				&operator+=(const difference_type n)
	{	
		_ptr += n;
		return (*this);
	};
	iterator				&operator-=(const difference_type n)
	{	
		_ptr -= n;
		return (*this);
	};
};//end randomAccessIterator

} //end ft

#endif
