//Linsenbardt,Michael
//mlinsenbardt
//rbtree.cpp

#include "rbtree.h"
#include <string>
#include <utility>
using namespace std;

typedef pair<string,int> Pair;
RBTree::RBTree()
{
    //cout<<"in rbt constructor"<<endl;
	nil=new Node(pair<string,int> ("empty",0),false,m_root,m_root,nil);
	m_root=nil;
    //cout<<m_root->m_value.first<<endl;
}

RBTree::~RBTree()
{
	delete m_root;
}

RBTree::Node::~Node()
{

}

void RBTree::insert(Pair inserted)
{
    //cout<<"first insert"<<endl;
    //if(m_root==nil)
       // cout<<"hooray"<<endl;
	Node *temp;
	temp=new Node(inserted,true,nil,nil,nil);
    //cout<<temp->m_value.first<<endl;
	insert(temp);
}

void RBTree::insert(Node *z)
{
    //cout<<"am i in insert?"<<endl;
    //cout<<z->m_parent->m_value.first<<endl;
	Node *y=nil;
	Node *x=m_root;
	while(x!=nil)
	{
		y=x;
        if(z->m_value.first == x->m_value.first)
        {
            x->m_value.second = x->m_value.second+1;
            return;
        }
		if(z->m_value.first < x->m_value.first)
		{
			x=x->m_left;
		}
		else
		{
			x=x->m_right;
		}
	}
	z->m_parent=y;
	if(y==nil)
	{
        //cout<<"First"<<endl;
		m_root=z;
	}
	else if(z->m_value.first < y->m_value.first)
	{
        //cout<<"to the left"<<endl;
		y->m_left = z;
	}
	else 
	{	
        //cout<<"to the right"<<endl;
		y->m_right = z;
	}
	z->m_left = nil;
	z->m_right = nil;
	z->m_color = true;//red
	RB_Insert_Fixup(z);
}

void RBTree::RB_Insert_Fixup(Node *z)
{
	Node *y;
    //cout<<z->m_parent->m_value.first<<endl;
    //cout<<"in fixup"<<endl;
	while (z->m_parent->m_color ==true)//red
	{
        //cout<<"in loop"<<endl;
		if(z->m_parent == z->m_parent->m_parent->m_left)
		{
            //cout<<"left subtree"<<endl;
			y=z->m_parent->m_parent->m_right;
			if(y->m_color==true)//red
			{
                //cout<<"wow"<<endl;
				z->m_parent->m_color=false;//black
				y->m_color=false;//black
				z->m_parent->m_parent->m_color=true;//red
				z=z->m_parent->m_parent;
			}
			else
			{ 
				if(z==z->m_parent->m_right)
				{
					z=z->m_parent;
					left_rotate(z);
				}
				z->m_parent->m_color = false;//black
				z->m_parent->m_parent->m_color = true;//red
				right_rotate(z->m_parent->m_parent);
			}
		}
		else 
		{
            //cout<<"right subtree"<<endl;
			y=z->m_parent->m_parent->m_left;
			if(y->m_color==true)//red
			{
				z->m_parent->m_color=false;//black
				y->m_color=false;//black
				z->m_parent->m_parent->m_color=true;//red
				z=z->m_parent->m_parent;
			}
			else 
			{
				if(z==z->m_parent->m_left)
				{
					z=z->m_parent;
					right_rotate(z);
				}
				z->m_parent->m_color = false;//black
				z->m_parent->m_parent->m_color = true;//red
				left_rotate(z->m_parent->m_parent);
			}
		}
	}
    //cout<<"out of loop"<<endl;
	m_root->m_color = false;//black
}

void RBTree::left_rotate(Node *x)
{
	Node *y;
	y = x->m_right;
	x->m_right = y->m_left;
	if(y->m_left != nil)
	{
		y->m_left->m_parent = x;
	}	
	y->m_parent = x->m_parent;
	if(x->m_parent==nil)
	{
		m_root = y;
	}
	else if(x==x->m_parent->m_left)
	{
		x->m_parent->m_left = y;
	}
	else
	{
		x->m_parent->m_right = y;
	}
	y->m_left = x;
	x->m_parent =y;
}

void RBTree::right_rotate(Node *x)
{
	Node *y;
	y = x->m_left;
	x->m_left = y->m_right;
	if(y->m_right != nil)
	{
		y->m_right->m_parent = x;
	}	
	y->m_parent = x->m_parent;
	if(x->m_parent==nil)
	{
		m_root = y;
	}
	else if(x==x->m_parent->m_right)
	{
		x->m_parent->m_right = y;
	}
	
	else
	{
		x->m_parent->m_left = y;
	}
	y->m_right = x;
	x->m_parent =y;
}

void RBTree::print()
{
	print(m_root);
}

void RBTree::print(Node *root)
{
	if(root ==nil)
	{
		return;
	}
	if(root->m_left !=nil)
	{
		print(root->m_left);
	}
	cout<<root->m_value.first<<" "<<root->m_value.second<<endl;
	
	if(root->m_right !=nil)
	{
		print(root->m_right);
	}
		
}

void RBTree::check_balance()
{
	check_balance(m_root);
}

void RBTree::check_balance(Node *root)
{
	int j=black_height(root->m_left);
	int k=black_height(root->m_right);
	
	cout<<"left subtree has "<<j<<" black nodes"<<endl;
	cout<<"right subtree has "<<k<<" black nodes"<<endl;
	if(j==k)
		cout<<"Tree is balanced"<<endl;
	else
		cout<<"Tree is not balanced"<<endl;
}

int RBTree::black_height(Node *root)
{

	int black_count=0;
	if(root == nil)
		return 0;
	if(root->m_color==false)
	{
		black_count=black_count+1;
	}
	//I don't think it matters which way I recurse at this point, since any path works
	black_count= black_count + black_height(root->m_left);
	return black_count;

}

