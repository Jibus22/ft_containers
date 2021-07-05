#include "bst.hpp"

void	testOne(bstree<int> tree)
{
	std::cout << "in order print:\n";
	tree.iop();
	std::cout << "preorder print:\n";
	tree.preop();
	std::cout << "postorder print:\n";
	tree.postop();
	std::cout << "max: " << tree.findMax()->val << "\n";
	std::cout << "min: " << tree.findMin()->val << "\n";

	std::cout << "find key 30: " << tree.findKey(30)->val << std::endl;
	std::cout << "find key 89: " << tree.findKey(89)->val << std::endl;
	std::cout << "find key 20: " << tree.findKey(20)->val << std::endl;

	std::cout << "inorder pred 12: " << tree.ioPred(tree.findKey(12))->val
	<< std::endl;
	std::cout << "inorder suc 12: " << tree.ioSuc(tree.findKey(12))->val
	<< std::endl;
	std::cout << "inorder pred 13: " << tree.ioPred(tree.findKey(13))->val
	<< std::endl;
	std::cout << "inorder suc 13: " << tree.ioSuc(tree.findKey(13))->val
	<< std::endl;
	//std::cout << "find nokey: " << tree.findKey(22)->val << std::endl;

	std::cout << "next node 89: " << tree.next(tree.findKey(89))->val
		<< "\tprev node 89: " << tree.prev(tree.findKey(89))->val << std::endl;
	std::cout << "del 89. ";
	tree.del(89);
	std::cout << "in order print:\n";
	tree.iop();

	std::cout << "next node 13: " << tree.next(tree.findKey(13))->val
		<< "\tprev node 13: " << tree.prev(tree.findKey(13))->val << std::endl;
	std::cout << "del 13. ";
	tree.del(13);
	std::cout << "in order print:\n";
	tree.iop();

	std::cout << "next node 30: " << tree.next(tree.findKey(30))->val
		<< "\tprev node 30: " << tree.prev(tree.findKey(30))->val << std::endl;
	std::cout << "del 30. ";
	tree.del(30);
	std::cout << "in order print:\n";
	tree.iop();

	std::cout << "next node 20: " << tree.next(tree.findKey(20))->val
		<< "\tprev node 20: " << tree.prev(tree.findKey(20))->val << std::endl;
	std::cout << "del 20. ";
	tree.del(20);
	std::cout << "in order print:\n";
	tree.iop();

	std::cout << "del 42893. ";
	tree.del(42893);
	std::cout << "in order print:\n";
	tree.iop();

	std::cout << "next node 42: " << tree.next(tree.findKey(42))->val
		<< "\tprev node 42: " << tree.prev(tree.findKey(42))->val << std::endl;
	std::cout << "del 42. ";
	tree.del(42);
	std::cout << "in order print:\n";
	tree.iop();

	std::cout << "next node 12: " << tree.next(tree.findKey(12))->val
		<< "\tprev node 12: " << tree.prev(tree.findKey(12))->val << std::endl;
	std::cout << "del 12. ";
	tree.del(12);
	std::cout << "in order print:\n";
	tree.iop();
}

int	main()
{
	typedef bstree<int>::iterator	iterator;

	bstree<int>						tree;
	iterator						bla;

	tree.insert(30);
	tree.insert(13);
	tree.insert(42);
	tree.insert(89);
	tree.insert(20);
	tree.insert(12);

	testOne(tree);

	for (iterator i = tree.begin(); i != tree.end(); i++)
		std::cout << *i << std::endl;

	std::cout << "size bf clear: " << tree.size() << "\tempty: "
		<< tree.empty() << std::endl;
	tree.clear();
	std::cout << "size bf clear: " << tree.size() << "\tempty: "
		<< tree.empty() << std::endl;
	(void)bla;
	return (0);
}
