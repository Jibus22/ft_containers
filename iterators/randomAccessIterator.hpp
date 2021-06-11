#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

namespace ft {

template <typename T, typename Distance = ptrdiff_t,
		 typename Pointer = T*, typename Reference = T&>
class randomAccessIterator
{
protected:
public:
	//___________MEMBER TYPES_________________________________________________//
	typedef T				value_type;
	typedef Distance		difference_type;
    typedef Pointer			pointer;
    typedef Reference		reference;

	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	randomAccessIterator() : _ptr(nullptr) {};
	randomAccessIterator(randomAccessIterator const & src) { _ptr = src._ptr;};
	randomAccessIterator(pointer ptr) : _ptr(ptr) {};
	//___________Destructor___________________________________________________//
	virtual	~randomAccessIterator() {};
	//___________Operator =___________________________________________________//
	randomAccessIterator &	operator=(randomAccessIterator const & src) {
		_ptr = src._ptr;
		return (*this);
	};
private:
	pointer					_ptr;
};//end randomAccessIterator

} //end ft

#endif
