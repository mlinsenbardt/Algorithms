//Linsenbardt, Michael
//mlinsenbardt
//filereader.cpp

#include "filereader.h"
#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <utility>
using namespace std;

//I had this function initialize bool nothing since it was the only way I could think to call the constructor
//without putting it in a loop
typedef pair<string,int> Pair;
FileReader::FileReader(bool nothing)
{
	m_bool=nothing;
}

FileReader ::~FileReader()
{

}

string FileReader :: convert_to_output(string inserted)
{
	string temp;
	for (int i=0; inserted[i];i++)
	{
		if(isalnum(inserted[i]))
		{
			inserted[i]=tolower(inserted[i]);
			temp.insert(temp.end(),1,inserted[i]);
		}
	}
	return temp;
}

