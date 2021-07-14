#ifndef BSTREE_HPP
#define BSTREE_HPP

#include "ftless.hpp"
#include "ftpair.hpp"

namespace ft {

template <typename T>
struct bstNode
{
	typedef T					value_type;
	typedef bstNode				node;
	typedef node*				pointer;

	pointer		lft, rgt, prt, head;
	value_type	val;

	bstNode(const value_type& v = value_type()):
		lft(nullptr), rgt(nullptr), prt(nullptr), head(nullptr), val(v)
	{};
	bstNode(const bstNode& src) :
		lft(nullptr), rgt(nullptr), prt(nullptr), head(nullptr), val(src.val)
	{};
	bstNode&	operator=(const bstNode& rhs) {
		if (this == &rhs)
			return *this;
		lft = rhs.lft;
		rgt = rhs.rgt;
		prt = rhs.prt;
		if (rhs.head)
			head = rhs.head;
		if (prt)
		{
			if (prt->lft == &rhs)
				prt->lft = this;
			else
				prt->rgt = this;
		}
		if (lft)
			lft->prt = this;
		if (rgt)
			rgt->prt = this;
		if (head)
		{
			if (head->lft == &rhs)
				head->lft = this;
			if (head->rgt == &rhs)
				head->rgt = this;
		}
		return *this;
	}
	virtual ~bstNode() {};
};

template <typename T, typename Compare, typename Allocator>
struct bstree
{
	typedef T								node;
	typedef typename node::value_type		value_type;
	typedef typename node::pointer			pointer;
    typedef Compare							key_compare;
	typedef typename value_type::first_type	key_type;
	typedef Allocator						node_allocator;

	key_compare								_comp;
	node_allocator							_nodealloc;

	void	postOrderDelete(const pointer p) const
	{
		if (!p)
			return ;
		postOrderDelete(p->lft);
		postOrderDelete(p->rgt);
		delete p;
	};

	pointer	giveChild(const pointer p, const value_type& val,
				const bool min, const bool max) const
	{
		if (_comp(p->val.first, val.first))
		{
			p->rgt = new node(val);
			p->rgt->prt = p;
			if (max)
			{
				p->rgt->head = p->head;
				p->rgt->head->rgt = p->rgt;
				if (p->head->lft != p )
					p->head = nullptr;
			}
			return p->rgt;
		}
		else
		{
			p->lft = new node(val);
			p->lft->prt = p;
			if (min)
			{
				p->lft->head = p->head;
				p->lft->head->lft = p->lft;
				if (p->head->rgt != p )
					p->head = nullptr;
			}
			return p->lft;
		}
	};

	pointer	successor(const pointer p) const
	{
		pointer	succ = p;

		if (p->rgt)
			return getMin(p->rgt);
		while (succ->prt && !_comp(p->val.first, succ->val.first))
			succ = succ->prt;
		if (_comp(p->val.first, succ->val.first))
			return succ;
		else
			return nullptr;
	};

	pointer	predecessor(const pointer p) const
	{
		pointer	succ = p;

		if (p->lft)
			return getMax(p->lft);
		while (succ->prt && !_comp(succ->val.first, p->val.first))
			succ = succ->prt;
		if (_comp(succ->val.first, p->val.first))
			return succ;
		else
			return nullptr;
	};

	pointer	getMin(pointer p) const
	{
		if (!p)
			return p;
		while (p->lft)
			p = p->lft;
		return p;
	};

	pointer	getMax(pointer p) const
	{
		if (!p)
			return p;
		while (p->rgt)
			p = p->rgt;
		return p;
	};

	void	preOrderCpy(const pointer rt, pointer *newNode) const
	{
		if (!rt)
			return ;
		*newNode = insert(*newNode, rt->val);
		preOrderCpy(rt->lft, newNode);
		preOrderCpy(rt->rgt, newNode);
	};

	pointer	findKey(pointer p, const key_type& key) const
	{
		while (p)
		{
			if (_comp(p->val.first, key))
				p = p->rgt;
			else if (_comp(key, p->val.first))
				p = p->lft;
			else
				return p;
		}
		return p;//Here it must be nullptr in any case
	};

	int	delNode(const pointer p, const key_type& key, pointer *p2) const
	{
		const pointer	todel = findKey(p, key);
		pointer			substitute;

		if (!todel)
			return (1);
		if (todel->rgt)
			substitute = getMin(todel->rgt);
		else if (todel->lft)
			substitute = getMax(todel->lft);
		else
			substitute = todel;
		sendToParent(substitute, todel);
		*substitute = *todel;
		if (!substitute->prt)//means root changed
			*p2 = substitute;
		delete todel;
		return (0);
	};

	private:
	void	sendToParent(const pointer tosend, const pointer todel) const
	{//works only with node which has at most 1 child bc the purpose is to
	//be used with inorder suc or pred
		pointer	*relay;

		if (!tosend->prt)
			return ;
		if (tosend->prt->lft == tosend)
			relay = &(tosend->prt->lft);
		else if (tosend->prt->rgt == tosend)
			relay = &(tosend->prt->rgt);
		else
			return ;
		if (tosend->lft)
			*relay = tosend->lft;
		else if (tosend->rgt)
			*relay = tosend->rgt;
		else
			*relay = nullptr;
		if (*relay && tosend->prt != todel)//if succ don't take place of parent
			(*relay)->prt = tosend->prt;//child of succ take parent succ as prt
		if (tosend == todel && tosend->head)//if this is leaf node & min/max node
		{
			tosend->prt->head = tosend->head;
			if (tosend->head->lft == tosend)
				tosend->head->lft = tosend->prt;
			else
				tosend->head->rgt = tosend->prt;
		}
		//parent of tosend points now to lft or rgt tosend child, & this child
		//has now parent of tosend as parent.
	};

	pointer	insert(pointer p, value_type v) const
	{
		if (!p)
			return new node(v);
		if (v < p->val)
		{
			p->lft = insert(p->lft, v);
			p->lft->prt = p;
		}
		else
		{
			p->rgt = insert(p->rgt, v);
			p->rgt->prt = p;
		}
		return p;
	};

	typename node_allocator::pointer
	newNd(typename node_allocator::const_reference val)
	{
		typename node_allocator::pointer	p = _nodealloc.allocate(1);
		_nodealloc.construct(p, val);
		return p;
	};
	void	delNd(typename node_allocator::pointer p)
	{
		_nodealloc.destroy(p);
		_nodealloc.deallocate(p, 1);
	};
};

}

#endif
