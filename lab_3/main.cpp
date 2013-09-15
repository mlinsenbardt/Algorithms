//Linsenbardt, Michael
//mlinsenbardt
//main.cpp

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <locale>
#include <fstream>
#include <utility>
#include <cctype>
#include <vector>
#include <time.h>
#include "filereader.h"
#include "rbtree.h"
#include "wordcounts.h"
using namespace std;

//timespec diff(timespec start, timespec end);

int main(int argc, char *argv[])
{
	ifstream my_ifile(argv[1], ios::in);
	RBTree my_rbt;
	map<string,int> my_map;
	typedef pair<string,int> Pair;
	vector<Pair> my_vector;
	string inserted;
	bool nothing =true;
	FileReader my_reader(nothing);
    WordCounts my_wordcount(nothing);
    //timespec time1, time2;
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	while(my_ifile>>inserted)
	{
		inserted=my_reader.convert_to_output(inserted);
        my_wordcount.change_counts(inserted);
	}
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    //cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    //flush(cout);
    my_wordcount.print();
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    //cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;
	//my_wordcount.check();

	return 0;
}

/*timespec diff(timespec start, timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}*/
