#ifndef Dice_H
#define Dice_H

#include <iostream>
using namespace std;

class dice
{
	public:
		dice();
		~dice();
		void roll();
		int return_value();
	private:
		int m_value;
};

#endif
