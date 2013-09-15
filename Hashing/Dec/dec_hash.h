//Linsenbardt,Michael
//dec_hash.h
#ifndef Dec_Hash_H
#define Dec_Hash_H

#include <iostream>
#include <queue>
using namespace std;

class DecHash
{
	public:
		DecHash();
		~DecHash();
		void initialize_table();
		void print_table();
		void linear_insert(int inserted);
		void quadratic_insert(int inserted);
		void print_collisions();
	private:
		int m_table [11];
		queue <int> m_collisions;
};

#endif
