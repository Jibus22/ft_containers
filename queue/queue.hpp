#ifndef QUEUE_HPP
# define QUEUE_HPP

#include <cstddef>
#include "../list/list.hpp"

#ifndef __APPLE__
# define __APPLE__ 0
#endif

namespace ft {

template <class T, class Container = ft::list<T> >
class queue
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
	explicit queue (const container_type& ctnr = container_type()) : _ctnr(ctnr)
	{};

	//___________Destructor___________________________________________________//
	virtual	~queue() {};

	//___________Operator =___________________________________________________//
	//___________Capacity_____________________________________________________//
	bool				empty() const {return _ctnr.empty();};
	size_type			size() const {return _ctnr.size();};

	//___________Element access_______________________________________________//
	value_type&			front() {return _ctnr.front();};
	const value_type&	front() const {return _ctnr.front();};
	value_type&			back() {return _ctnr.back();};
	const value_type&	back() const {return _ctnr.back();};

	//___________Modifiers____________________________________________________//
	void				push(const value_type& val) {_ctnr.push_back(val);};
	void				pop() {_ctnr.pop_front();};

	//___________Relational operators declaration (friends)___________________//
	template <class U, class Ctnr>
	friend bool	operator==(const ft::queue<U,Ctnr>& lhs,
				const ft::queue<U,Ctnr>& rhs);;

	template <class U, class Ctnr>
	friend bool	operator!=(const ft::queue<U,Ctnr>& lhs,
				const ft::queue<U,Ctnr>& rhs);

	template <class U, class Ctnr>
	friend bool	operator<(const ft::queue<U,Ctnr>& lhs,
				const ft::queue<U,Ctnr>& rhs);

	template <class U, class Ctnr>
	friend bool	operator<=(const ft::queue<U,Ctnr>& lhs,
				const ft::queue<U,Ctnr>& rhs);

	template <class U, class Ctnr>
	friend bool	operator>(const ft::queue<U,Ctnr>& lhs,
				const ft::queue<U,Ctnr>& rhs);

	template <class U, class Ctnr>
	friend bool	operator>=(const ft::queue<U,Ctnr>& lhs,
				const ft::queue<U,Ctnr>& rhs);
}; //end class queue


//___________Relational operators definition______________________________//
template <class T, class Container>
bool	operator==(const ft::queue<T,Container>& lhs,
					const ft::queue<T,Container>& rhs)
{return lhs._ctnr == rhs._ctnr;};


template <class T, class Container>
bool	operator!=(const ft::queue<T,Container>& lhs,
					const ft::queue<T,Container>& rhs)
{return lhs._ctnr != rhs._ctnr;};

template <class T, class Container>
bool	operator<(const ft::queue<T,Container>& lhs,
					const ft::queue<T,Container>& rhs)
{return lhs._ctnr < rhs._ctnr;};

template <class T, class Container>
bool	operator<=(const ft::queue<T,Container>& lhs,
					const ft::queue<T,Container>& rhs)
{return lhs._ctnr <= rhs._ctnr;};

template <class T, class Container>
bool	operator>(const ft::queue<T,Container>& lhs,
					const ft::queue<T,Container>& rhs)
{return lhs._ctnr > rhs._ctnr;};

template <class T, class Container>
bool	operator>=(const ft::queue<T,Container>& lhs,
					const ft::queue<T,Container>& rhs)
{return lhs._ctnr >= rhs._ctnr;};


} //end ft

#endif
