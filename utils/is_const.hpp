#ifndef ISCONST_HPP
#define ISCONST_HPP

namespace ft {

template<typename T>
struct is_const
{
    typedef T const		reference_type;
    static const bool	value = false;
};

template<typename T>
struct is_const<T const>
{
    typedef T const		reference_type;
    static const bool	value = true;
};

}

#endif
