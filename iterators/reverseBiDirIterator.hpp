#ifndef REVERSEBIDIRITERATOR_HPP
# define REVERSEBIDIRITERATOR_HPP

namespace ft {

template <class Iter>
class reverseBiDirIterator
{
private:
	typedef Iter								iterator;
	typedef reverseBiDirIterator				reverse_iterator;
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
	reverseBiDirIterator() {};
	reverseBiDirIterator(reverseBiDirIterator const & src) : _iter(src._iter) {};
	reverseBiDirIterator(iterator it) : _iter(it) {};
	//___________Destructor___________________________________________________//
	virtual ~reverseBiDirIterator() {};
	//___________Operator =___________________________________________________//
	reverseBiDirIterator &	operator=(reverseBiDirIterator const & src)
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

	//___________Dereferencement______________________________________________//
	reference				operator*() const {return *_iter;};
	pointer					operator->() const {return _iter;};

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

};//end randomAccessIterator

} //end ft

#endif
