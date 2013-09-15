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
#include "lab2.h"
using namespace std;

//timespec diff(timespec start, timespec end);

int main(int argc, char *argv[])
{
	ifstream my_ifile(argv[1], ios::in);
	map<string,int> my_map;
	typedef pair<string,int> Pair;
	vector<Pair> my_vector;
	string inserted;
	bool nothing =true;
	FileReader my_reader(nothing);
	while(my_ifile>>inserted)
	{
		inserted=my_reader.convert_to_output(inserted);
        pair< map<string, int>::iterator, bool> ret;
        if(inserted.size()>0)
        {
            ret = my_map.insert(pair<string,int> (inserted, 1)); 
            if(ret.second == false )
            {
                my_map[inserted]++;   
            }
        }

	}
    map<string,int>::iterator it;
	for(it=my_map.begin();it!=my_map.end();it++)
	{
		my_vector.insert(my_vector.end(),*(it));
	}
	timespec time1, time2;
	WordSort my_sort(my_vector);

	cout<<"QuickSort by Values"<<endl;
	//clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	my_sort.quicksort("VALUES");
	//clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	//cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;

	cout<<"QuickSort by Keys" <<endl;
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	my_sort.quicksort("KEYS");
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    //cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;

	cout<<"MergeSort by Values"<<endl;
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	my_sort.mergesort("VALUES");
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    //cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;

	cout<<"MergeSort by Keys"<<endl;
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	my_sort.mergesort("KEYS");
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    //cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;

	cout<<"HeapSort by Values"<<endl;
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	my_sort.heapsort("VALUES");
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    //cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;

	cout<<"HeapSort by Keys"<<endl;
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	my_sort.heapsort("KEYS");
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    //cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;

	cout<<"InsertionSort by Values"<<endl;
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	my_sort.insertionsort("VALUES");
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    //cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;

	cout<<"InsertionSort by Keys"<<endl;
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	my_sort.insertionsort("KEYS"); 
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    //cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;
            
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
