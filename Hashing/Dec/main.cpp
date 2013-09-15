//Linsenbardt, Michael
//main.cpp

#include <iostream>
#include <cmath>
#include "dec_hash.h"
using namespace std;
int main()
{
	int input;
	DecHash lin_DecHash;
	DecHash quad_DecHash;
	lin_DecHash.initialize_table();
	quad_DecHash.initialize_table();
	cin>>input;
	while(input!=0)
	{
		cout<<"Please enter a decimal number greater than 0"<<endl;
		//cin>>input;
		lin_DecHash.linear_insert(input);
		quad_DecHash.quadratic_insert(input);
		//my_DecHash.print_table();
		cin>>input;
	}
	cout<<"Collisions during Linear Probing"<<endl;
	lin_DecHash.print_collisions();
	cout<<"Collisions during Quadratic Probing"<<endl;
	quad_DecHash.print_collisions();
	return 0;
}
