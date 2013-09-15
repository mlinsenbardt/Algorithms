//Linsenbardt, Michael
//main.cpp

#include <iostream>
#include <string>
#include <cmath>
#include "s_hash.h"
using namespace std;
int main()
{
	int input;
	SHash lin_SHash;
	SHash quad_SHash;
	lin_SHash.initialize_table();
	quad_SHash.initialize_table();
	cin>>input;
	while(input!=0)
	{
		cout<<"Please enter a string"<<endl;
		//cin>>input;
		lin_SHash.linear_insert(input);
		quad_SHash.quadratic_insert(input);
		//my_DecHash.print_table();
		cin>>input;
	}
	cout<<"Collisions during Linear Probing"<<endl;
	lin_SHash.print_collisions();
	cout<<"Collisions during Quadratic Probing"<<endl;
	quad_SHash.print_collisions();
	return 0;
}
