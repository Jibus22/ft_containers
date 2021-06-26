#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

#ifndef __APPLE__
# define __APPLE__ 0
#endif

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack
{
public:
	//___________MEMBER TYPES_________________________________________________//
    typedef T											value_type;
    typedef Container									container_type;
    typedef typename container_type::size_type			size_type;
private:
protected:
	container_type										_ctnr;
public:
	//___________MEMBER FUNCTIONS_____________________________________________//
	//___________Constructors_________________________________________________//
	explicit stack (const container_type& ctnr = container_type()) : _ctnr(ctnr)
	{};

	//___________Destructor___________________________________________________//
	virtual	~stack() {};

	//___________Operator =___________________________________________________//
	//___________Capacity_____________________________________________________//
	size_type			size() const {return _ctnr.size();};
	bool				empty() const {return _ctnr.empty();};

	//___________Element access_______________________________________________//
	value_type&			top() {return _ctnr.back();};
	const value_type&	top() const {return _ctnr.back();};

	//___________Modifiers____________________________________________________//
	void				push(const value_type& val) {_ctnr.push_back(val);};
	void				pop() {_ctnr.pop_back();};

	//___________Relational operators declaration (friends)___________________//
	template <class U, class Ctnr>
	friend bool	operator==(const ft::stack<U,Ctnr>& lhs,
				const ft::stack<U,Ctnr>& rhs);;

	template <class U, class Ctnr>
	friend bool	operator!=(const ft::stack<U,Ctnr>& lhs,
				const ft::stack<U,Ctnr>& rhs);

	template <class U, class Ctnr>
	friend bool	operator<(const ft::stack<U,Ctnr>& lhs,
				const ft::stack<U,Ctnr>& rhs);

	template <class U, class Ctnr>
	friend bool	operator<=(const ft::stack<U,Ctnr>& lhs,
				const ft::stack<U,Ctnr>& rhs);

	template <class U, class Ctnr>
	friend bool	operator>(const ft::stack<U,Ctnr>& lhs,
				const ft::stack<U,Ctnr>& rhs);

	template <class U, class Ctnr>
	friend bool	operator>=(const ft::stack<U,Ctnr>& lhs,
				const ft::stack<U,Ctnr>& rhs);
}; //end class stack


//___________Relational operators definition______________________________//
template <class T, class Container>
bool	operator==(const ft::stack<T,Container>& lhs,
					const ft::stack<T,Container>& rhs)
{return lhs._ctnr == rhs._ctnr;};


template <class T, class Container>
bool	operator!=(const ft::stack<T,Container>& lhs,
					const ft::stack<T,Container>& rhs)
{return lhs._ctnr != rhs._ctnr;};

template <class T, class Container>
bool	operator<(const ft::stack<T,Container>& lhs,
					const ft::stack<T,Container>& rhs)
{return lhs._ctnr < rhs._ctnr;};

template <class T, class Container>
bool	operator<=(const ft::stack<T,Container>& lhs,
					const ft::stack<T,Container>& rhs)
{return lhs._ctnr <= rhs._ctnr;};

template <class T, class Container>
bool	operator>(const ft::stack<T,Container>& lhs,
					const ft::stack<T,Container>& rhs)
{return lhs._ctnr > rhs._ctnr;};

template <class T, class Container>
bool	operator>=(const ft::stack<T,Container>& lhs,
					const ft::stack<T,Container>& rhs)
{return lhs._ctnr >= rhs._ctnr;};


} //end ft

#endif
