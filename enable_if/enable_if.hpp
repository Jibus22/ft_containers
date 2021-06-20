#ifndef ENABLEIF_HPP
#define ENABLEIF_HPP

namespace ft {

//Thanks to these template struct definitions, type is only defined when bool
//is true because of this is only defined into the specialized
//struct with Cond = true
template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> {typedef T type;};

}

#endif
