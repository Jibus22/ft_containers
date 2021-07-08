#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

namespace ft {

template <class Iter>
class reverseIterator
{
private:
	typedef Iter								iterator;
	typedef reverseIterator						reverse_iterator;
public:
	typedef typename iterator::value_type		value_type;
	typedef typename iterator::difference_type	difference_type;
	typedef typename iterator::pointer			pointer;
	typedef typename iterator::reference		reference;
protected:
	iterator									_iter;
public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	reverseIterator() {};
	reverseIterator(reverseIterator const & src) : _iter(src._iter) {};
	reverseIterator(iterator it) : _iter(it) {};
	//___________Destructor___________________________________________________//
	virtual ~reverseIterator() {};
	//___________Operator =___________________________________________________//
	reverseIterator &	operator=(reverseIterator const & src)
	{
		_iter = src._iter;
		return (*this);
	};
	//___________OPERATOR OVERLOADS___________________________________________//
	//___________Comparisons__________________________________________________//
	bool					operator==(const reverse_iterator & rhs) const
							{return (_iter == rhs._iter);};
	bool					operator!=(const reverse_iterator & rhs) const
							{return (_iter != rhs._iter);};
	bool					operator<(const reverse_iterator & rhs) const
							{return !(_iter < rhs._iter);};
	bool					operator>(const reverse_iterator & rhs) const
							{return !(_iter > rhs._iter);};
	bool					operator<=(const reverse_iterator & rhs) const
							{return (_iter >= rhs._iter);};
	bool					operator>=(const reverse_iterator & rhs) const
							{return (_iter <= rhs._iter);};

	//___________Dereferencement______________________________________________//
	reference				operator[](const difference_type i) const
							{return _iter[i];};
	reference				operator*() const {return *_iter;};
	pointer					operator->() const {return _iter.operator->();};

	//___________Incrementation_______________________________________________//
	reverse_iterator		&operator++()
	{
		_iter--;
		return *this;
	};
	reverse_iterator		operator++(int)
	{
		reverse_iterator	tmp(*this);
		_iter--;
		return tmp;
	};

	//___________Decrementation_______________________________________________//
	reverse_iterator		&operator--()
	{
		_iter++;
		return *this;
	};
	reverse_iterator		operator--(int)
	{
		reverse_iterator	tmp(*this);
		_iter++;
		return tmp;
	};

	//___________Arithmetic Operations________________________________________//
	reverse_iterator		operator+(const difference_type n) const
							{return (reverse_iterator(_iter - n));};
	reverse_iterator		operator-(const difference_type n) const
							{return (reverse_iterator(_iter + n));};
	difference_type			operator-(const reverse_iterator rhs) const
							{return (_iter + rhs._iter);};

	//___________Assignment Operations________________________________________//
	reverse_iterator		&operator+=(const difference_type n)
	{	
		_iter -= n;
		return (*this);
	};
	reverse_iterator		&operator-=(const difference_type n)
	{	
		_iter += n;
		return (*this);
	};
};//end randomAccessIterator

} //end ft

#endif
