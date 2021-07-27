#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>

namespace ft {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag: public input_iterator_tag {};
struct bidirectional_iterator_tag: public forward_iterator_tag {};
struct random_access_iterator_tag: public bidirectional_iterator_tag {};
struct contiguous_iterator_tag: public random_access_iterator_tag {};

/*
HOW TO BUILD ITERATORS AND WHY TAGS & TRAITS ?

There is kind of a convention to build iterators, which evolved through time.
At a moment a custom iterator had to inherit from std::iterator so it get
all its declared typedef.
But this is now deprecated bc the method didn't allow to use directly these
typedef.

Now the convention asks to directly 'typedef', or 'using' (if C++11 allowed)
into the custom iterator all the conventionnal alias.

iterator_traits is interface-like, so we can retrieve conventionnal
information from any iterator. We could instead do it directly from our
iterator except it wouldn't work with a standard pointer (which isn't a class)
iterator_traits specialization permits to add these abstract nested types to a
pointer

At last, tags are these above empty struct which are declared into any
conventionnal iterator to inform any method or algorithm which type of
iterator it is & how it can use it.
More precisely, these algorithms would have different specializations relative
to these tags.
*/

template <class Iterator>
struct iterator_traits
{
	typedef typename Iterator::iterator_category	iterator_category;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
};

template <class T>
struct iterator_traits<T*>
{
	typedef random_access_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef ptrdiff_t					difference_type;
	typedef T*							pointer;
	typedef T&							reference;
};

template <class T>
struct iterator_traits<const T*>
{
	typedef random_access_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef ptrdiff_t					difference_type;
	typedef const T*					pointer;
	typedef const T&					reference;
};

}

#endif
