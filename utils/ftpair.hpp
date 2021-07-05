#ifndef FTPAIR_HPP
#define FTPAIR_HPP

namespace ft {

template <class T1, class T2>
struct pair
{
	typedef T1		first_type;
	typedef T2		second_type;

	first_type		first;
	second_type		second;

	pair() : first(first_type()), second(second_type()) {};
	template<class U, class V>
	pair(const pair<U,V>& pr): first(pr.first), second(pr.second) {};
	pair (const first_type& a, const second_type& b): first(a), second(b) {};
	virtual ~pair() {};
	pair& operator=(const pair& pr)
	{
		first = pr.first;
		second = pr.second;
		return *this;
	};
};

//___________Relational operators_________________________________________//
template <class T1, class T2>
bool	operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{return lhs.first==rhs.first && lhs.second==rhs.second;}

template <class T1, class T2>
bool	operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{return !(lhs==rhs);}

template <class T1, class T2>
bool	operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);}
//Compares lhs and rhs lexicographically by operator<, that is, compares the
//first elements and only if they are equivalent, compares the second elements.

template <class T1, class T2>
bool	operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{return !(rhs<lhs);}

template <class T1, class T2>
bool	operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{return rhs<lhs;}

template <class T1, class T2>
bool	operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{return !(lhs<rhs);}

#endif
