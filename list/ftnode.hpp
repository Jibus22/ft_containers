#ifndef FTNODE_HPP
#define FTNODE_HPP

namespace ft {

template <typename T>
struct node
{
	T			value;
	node*		prev;
	node*		next;

	node(const T & val = T()): value(val), prev(this), next(this) {};
	node(node* p, node* n, const T & val = T()): value(val), prev(p), next(n) {};

	node(const node& src) : value(src.value)
	{
		if (src.prev == &src && src.next == &src)
		{
			prev = this;
			next = this;
		}
		else
		{
			prev = src.prev;
			next = src.next;
		}
	};
	node &	operator=(node const & src)
	{
		value = src.value;
		return (*this);
	};
	~node(){};
};

}

#endif
