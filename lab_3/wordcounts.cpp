//Linsenbardt,Michael
//mlinsenbardt
//wordcounts.cpp

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include "rbtree.h"
#include "wordcounts.h"
using namespace std;

typedef pair<string,int> Pair;

WordCounts::WordCounts(bool nothing)
{
    m_bool=nothing;
}

WordCounts::~WordCounts()
{

}

void WordCounts::change_counts(string inserted)
{
        	if(inserted.size()>0)
        	{
        	        m_rbtree.insert(pair<string,int> (inserted, 1)); 
        	}
		
}

void WordCounts::print()
{
    m_rbtree.print();
}

void WordCounts::check()
{
    m_rbtree.check_balance();
}

RBTree WordCounts::return_tree()
{
    return m_rbtree;
}
