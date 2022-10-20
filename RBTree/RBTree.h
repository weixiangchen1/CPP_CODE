#pragma once

enum color
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;

	color _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
		, _kv(kv)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				assert(false);
			}
		}

		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		// 控制颜色，控制平衡
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//      g
					//    p
					//  c
					if (parent->_left == cur)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//      g
					//    p
					//      c
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						grandfather->_col = RED;
						cur->_col = BLACK;
					}
				}
			}
			else  // grandfather->_right == parent
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//     g
					//       p
					//         c
					if (parent->_right == cur)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//      g
					//		   p
					//      c
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						grandfather->_col = RED;
						cur->_col = BLACK;
					}
					
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;
			subR->_parent = parentParent;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;

			subL->_parent = parentParent;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	bool IsBalance()
	{
		if (_root && _root->_col == RED)
		{
			cout << "根节点不为黑色" << endl;
			return false;
		}

		int banchmark = 0;
		Node* left = _root;
		while (left)
		{
			if (left->_col == BLACK)
				++banchmark;

			left = left->_left;
		}
		int blackNum = 0;

		return _IsBalance(_root, banchmark, blackNum);
	}

	bool _IsBalance(Node* root, int banchmark, int blackNum)
	{
		if (root == nullptr)
		{
			if (banchmark != blackNum)
			{
				cout << "存在路径的黑色结点不相等" << endl;
				return false;
			}

			return true;
		}

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "出现连续的红色结点" << endl;
			return false;
		}

		if (root->_col == BLACK)
		{
			++blackNum;
		}

		return _IsBalance(root->_left, banchmark, blackNum)
			&& _IsBalance(root->_right, banchmark, blackNum);
	}

private:
	Node* _root;
};

void TestRBTree()
{
	RBTree<int, int> root;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };

	for (auto e : a)
	{
		root.Insert(make_pair(e, e));
	}
	root.InOrder();
	cout << "Tree is RBTree? " << ":" << root.IsBalance();

}