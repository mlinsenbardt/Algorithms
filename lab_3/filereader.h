//Linsenbardt, Michael
//mlinsenbardt
//filereader.h

#ifndef Filereader_H
#define Filereader_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
using namespace std;

class FileReader
{
	public:
		FileReader(bool nothing);
		~FileReader();
		string convert_to_output(string inserted);
	private:
		bool m_bool;
};

#endif
