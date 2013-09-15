#include "dice.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

dice::dice()
{

}

dice::~dice()
{

}

void dice::roll()
{
	int value;
	value = rand() % 6;
	switch (value)
	{
		case 0:
			cout<<"It's a six"<<endl;
			m_value = 6;
			break;
		case 1:
			cout <<"It's a one"<<endl;
			m_value = 1;
			break;
		case 2:
			cout <<"It's a two"<<endl;
			m_value = 2;
			break;
		case 3:
			cout <<"It's a three"<<endl;
			m_value = 3;
			break;
		case 4:
			cout <<"It's a four"<<endl;
			m_value = 4;
			break;
		case 5:
			cout <<"It's a five"<<endl;
			m_value = 5;
			break;
	}
}

int dice:: return_value()
{
	return m_value;	
}
