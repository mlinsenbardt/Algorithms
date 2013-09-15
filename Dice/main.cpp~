#include "dice.h"
#include <iostream>
using namespace std;

int main()
{
	dice CompD, UserD;
	int iterations;
	cin >> iterations;
	while(iterations)
	{
		cout<<"Comp"<<endl;
		CompD.roll();
		cout<<"User"<<endl;
		UserD.roll();
		if(CompD.return_value() > UserD.return_value())
		{
			cout<<"Computer wins!"<<endl;
		}
		else if(CompD.return_value() < UserD.return_value())
		{
			cout<<"User wins!"<<endl;
		}
		else
		{
			cout<<"It's a tie!"<<endl;
		}
		iterations--;
	}
	return 0;
}
