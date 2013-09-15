//Linsenbardt,Michael
//mlinsenbardt
//lab2.h

#ifndef Lab2_H
#define Lab2_H

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

class WordSort
{
	public:
		typedef pair<string,int> Pair;
		WordSort(vector<Pair> my_vector);
		~WordSort();
		void print();
		int return_value(int index);
		string return_key(int index);
		bool swap(int first,int second);
		void insertionsort(string command);
		void heapsort(string command);
		void build_max_heap(string command);
		void max_heapify(int i, int length, string command);
		void quicksort(string command);
		void quicksort(int start, int end, string command);
		void mergesort(string command);
		vector<Pair> mergesort(vector<Pair> inserted,string command);
		vector<Pair> merge(vector<Pair> left, vector<Pair> right, string command);
		int partition(int p, int r, string command);
	private:
		vector<Pair> m_vector;

};
#endif
