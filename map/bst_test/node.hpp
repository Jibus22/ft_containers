#ifndef NODE_HPP
#define NODE_HPP

namespace ft {

template <typename T>
struct bstnode
{
	typedef T					value_type;
	typedef bstnode				node;
	typedef node*				pointer;

	pointer		lft, rgt, prt;
	value_type	val;

	bstnode(const value_type& v = value_type()):
		lft(nullptr), rgt(nullptr), prt(nullptr), val(v) {};
	bstnode(const bstnode& src) : val(src.val) {};
	bstnode&	operator=(const bstnode& rhs) {
		if (this == &rhs)
			return *this;
		val = rhs.val;
		return *this;
	}
	virtual ~bstnode() {};

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

	void	inorderPrint(pointer p)
	{
		if (!p)
			return ;
		inorderPrint(p->lft);
		std::cout << p->val << std::endl;
		inorderPrint(p->rgt);
	};

	void	preorderPrint(pointer p)
	{
		if (!p)
			return ;
		std::cout << p->val << std::endl;
		preorderPrint(p->lft);
		preorderPrint(p->rgt);
	};

	void	postorderPrint(pointer p)
	{
		if (!p)
			return ;
		postorderPrint(p->lft);
		postorderPrint(p->rgt);
		std::cout << p->val << std::endl;
	};

	pointer	findMax(pointer p) const
	{
		if (!p)
			return p;
		while (p->rgt)
			p = p->rgt;
		return p;
	};

	pointer	findMin(pointer p) const
	{
		if (!p)
			return p;
		while (p->lft)
			p = p->lft;
		return p;
	};

	pointer	findKey(pointer p, const value_type key) const
	{
		while (p)
		{
			if (p->val < key)
				p = p->rgt;
			else if (p->val > key)
				p = p->lft;
			else
				return p;
		}
		return p;
	}

	pointer	inorderSuc(const pointer p) const
	{
		if (!p->rgt)
			return p;
		return findMin(p->rgt);
	};

	pointer	inorderPred(const pointer p) const
	{
		if (!p->lft)
			return p;
		return findMax(p->lft);
	};

	pointer	nextNode(const pointer p) const
	{
		pointer			nxt = inorderSuc(p);

		if (nxt == p)
			while (nxt->prt && !(nxt->val > p->val))
				nxt = nxt->prt;
		if (nxt->val > p->val)
			return nxt;
		else
			return p;
	}

	pointer	prevNode(const pointer p) const
	{
		pointer			nxt = inorderPred(p);

		if (nxt == p)
			while (nxt->prt && !(nxt->val < p->val))
				nxt = nxt->prt;
		if (nxt->val < p->val)
			return nxt;
		else
			return p;
	}

	int	delNode(const pointer p, const value_type key) const
	{
		const pointer	todel = findKey(p, key);
		pointer			substitute;

		if (!todel)
			return (1);
		if (todel->rgt)
			substitute = findMin(todel->rgt);
		else if (todel->lft)
			substitute = findMax(todel->lft);
		else
			substitute = todel;
		sendToParent(substitute);
		todel->val = substitute->val;
		delete substitute;
		return (0);
	};

	void	postOrderDelete(const pointer p) const
	{
		if (!p)
			return ;
		postOrderDelete(p->lft);
		postOrderDelete(p->rgt);
		delete p;
	};

	void	preOrderCpy(const pointer rt, pointer *newNode) const
	{
		if (!rt)
			return ;
		*newNode = insert(*newNode, rt->val);
		preOrderCpy(rt->lft, newNode);
		preOrderCpy(rt->rgt, newNode);
	};

	private:
	void	sendToParent(const pointer tosend) const//works only with node which
	{//has at most 1 child bc the purpose is to be used with inorder suc or pred
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
		if (*relay)
			(*relay)->prt = tosend->prt;
		//parent of tosend points now to lft or rgt tosend child, & this child
		//has now parent of tosend as parent.
	};
};

}

#endif
