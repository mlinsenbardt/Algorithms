//Michael,Linsenbardt
//mlinsenbardt
//wordcounts.h

#ifndef Wordcounts_H
#define Wordcounts_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include "rbtree.h"
using namespace std;

typedef pair<string,int> Pair;
class WordCounts
{
	public:
        WordCounts(bool nothing);
        ~WordCounts();
        void change_counts(string inserted);
        void print();
        void check();
        RBTree return_tree();

	private:
		RBTree m_rbtree;
        bool m_bool;
};

#endif
