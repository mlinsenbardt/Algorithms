//Linsenbardt,Michael
//s_hash.h
#ifndef S_Hash_H
#define S_Hash_H

#include <iostream>
#include <string>
#include <queue>
using namespace std;

class SHash
{
	public:
		SHash();
		~SHash();
		void initialize_table();
		void print_table();
		void linear_insert(string inserted);
		void quadratic_insert(string inserted);
		void print_collisions();
	private:
		string m_table [11];
		queue <int> m_collisions;
};

#endif
