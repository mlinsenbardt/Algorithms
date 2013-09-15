//Linsenbardt,Michael
//mlinsenbardt
//rbtree.h

#ifndef Rbtree_H
#define Rbtree_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
using namespace std;

typedef pair<string,int> Pair;
class RBTree
{
	public:
		RBTree();
		~RBTree();
		void insert(Pair inserted);
		void left_rotate();
		void right_rotate();
		void check_balance();
		void print();
        bool lookup(string inserted);

	private:
		class Node
		{

			public:
				Node(Pair value, bool color, Node *left, Node *right, Node *parent)
				{m_value = value; m_color = color; m_left = left; m_right = right; m_parent = parent;}
			~Node();
			Pair m_value;
			bool m_color;//false=black true=red
			Node *m_left;
			Node *m_right;
			Node *m_parent;
		};
		Node *m_root;
		void print(Node *root);
		void insert(Node *z);
		void RB_Insert_Fixup(Node *z);
		void left_rotate(Node *x);
		void right_rotate(Node *x);
		void check_balance(Node *root);
		int black_height(Node *root);
		Node *nil;
};
#endif
