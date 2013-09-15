//Linsenbardt, Michael
//January 7,2013
//Hash table practice with decimals

#include "dec_hash.h"
#include<iostream>
#include <cmath>
using namespace std;

DecHash::DecHash()
{

}

DecHash::~DecHash()
{

}

void DecHash::initialize_table()
{
	for(int i=0; i<11;i++)
	{
		m_table[i]=0;
	}	
}

void DecHash::print_table()
{
	for(int i=0; i<11;i++)
	{
		cout<<"| "<<m_table[i];
	}
	cout<<endl;
}

void DecHash::linear_insert(int inserted)
{
	bool entered=false;
	int index;
	index = inserted%11;
	while(entered==false)
	{
		if(m_table[index]==0)
		{
			m_table[index]=inserted;
			entered=true;
			cout<<"Linear insert"<<endl;	
			print_table();
		}
		else
		{
			m_collisions.push(index);
			index++;
		}
	}
	
}

void DecHash::quadratic_insert(int inserted)
{
		bool entered=false;
	int index;
	int count=1;
	index = inserted%11;
	while(entered==false)
	{
		if(m_table[index]==0)
		{
			m_table[index]=inserted;
			entered=true;
			cout<<"Quadratic insert"<<endl;
			print_table();	
		}
	
		else
			m_collisions.push(index);
			index=index+pow(count,2);
			count++;
	}
	
}

void DecHash::print_collisions()
{
	while(m_collisions.empty()==false)
	{
		cout<<"Collision at "<<m_collisions.front()<<" ";
		m_collisions.pop();
	}
	cout<<endl;
}
