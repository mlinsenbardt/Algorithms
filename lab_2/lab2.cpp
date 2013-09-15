//Linsenbardt,Michael
//mlinsenbardt
//lab2.cpp

#include "lab2.h"
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

WordSort :: WordSort(vector<Pair> my_vector)
{
	m_vector = my_vector;
}

WordSort :: ~WordSort()
{
	
}
void WordSort :: print()
{
	vector<Pair>::iterator it;
	for(it=m_vector.begin();it!=m_vector.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}

void WordSort :: insertionsort(string command)
{
	vector<Pair>::iterator it;
	if(command == "VALUES")
	{
		int i=0;
		for (it=m_vector.begin();it!=m_vector.end();it++)
		{
			int value= (*it).second;
			int j=i;
			while (i>0 && return_value(i-1) > value )
			{
				swap(i,i-1);
				i--;
			}

			i=j;
			i++;
		}
		print();
	}
	if(command == "KEYS")
	{
		int i=0;
		for (it=m_vector.begin();it!=m_vector.end();it++)
		{
			string key= (*it).first;
			int j=i;
			while (i>0 && return_key(i-1) > key )
			{
				swap(i,i-1);
				i--;
			}

			i=j;
			i++;
		}
		print();
	}
}

void WordSort :: heapsort(string command)
{
	build_max_heap(command);
	int length=m_vector.size();
		for( int i=m_vector.size()-1; i>0;i--)
		{
			swap(0,i);
			length=length-1;
			max_heapify(0,length,command);
		}
		print();

}

void WordSort :: build_max_heap(string command)
{
	int length=m_vector.size();
	for( int i=(m_vector.size()/2);i>=0;i--)
	{
		max_heapify(i,length,command);
	} 
}

void WordSort :: max_heapify(int i,int length,string command)
{
	if(command=="VALUES")
	{
		int l=(2*i)+1;
		int r=(2*i)+2;
		int largest;
		if( (l <length) && (return_value(l) > return_value(i)))
		{
			largest =l;
		}
		else if((l <length) && (return_value(l) == return_value(i)) && (return_key(l) > return_key(i)))
		{
			largest =l;
		}
		else
		{
			largest=i;
		}
		if( (r <length) && (return_value(r) > return_value(largest)))
		{
			largest =r;
		}
		else if((r <length) && (return_value(r) == return_value(largest)) && (return_key(r) > return_key(largest)))
		{
			largest =r;
		}
		if(largest != i)
		{
			swap(i,largest);
			max_heapify(largest,length,command);
		}
			
	}
	
	if(command=="KEYS")
	{
		int l=(2*i)+1;
		int r=(2*i)+2;
		int largest;
		if( (l <length) && (return_key(l) > return_key(i)))
		{
			largest =l;
		}
		else
		{
			largest=i;
		}
		if( (r <length) && (return_key(r) > return_key(largest)))
		{
			largest=r;
		}
		if(largest != i)
		{
			swap(i,largest);
			max_heapify(largest,length,command);
		}
	}
}

void WordSort :: quicksort(string command)
{
	int p=0;
	int r=m_vector.size()-1;

	if( p<r)
	{
		int q = partition(p,r,command);
		quicksort(p,q-1,command);
		quicksort(q+1,r,command);
	}
		print();
}

void WordSort :: quicksort(int start, int end,string command)
{   
    int p=start;
    int r=end;
	if(p<r)
	{
		int q=partition(p,r,command);
		quicksort(p,q-1,command);
		quicksort(q+1,r,command);
	}
}

int WordSort :: partition(int p, int r, string command)
{
	if(command=="KEYS")
	{
		string x=return_key(r);
		int i=p-1;
		for(int j=p; j<r;j++)
		{
			if(return_key(j)<x)
			{
				i=i+1;
				swap(i,j);
			}
			
		}
		swap(i+1,r);
		return i+1;
	}

	if(command=="VALUES")
	{
		int x=return_value(r);
		int i=p-1;
		for(int j=p; j<r;j++)
		{
			if(return_value(j) <x)
			{
				i=i+1;
				swap(i,j);
			}
            else if(return_value(j) ==x)
            {
				if(return_key(j) <return_key(r))
				 {
					i=i+1;
					swap(i,j);
				 }
			}
		}
		swap(i+1,r);
		return i+1;
	}
}

void WordSort :: mergesort(string command)
{
	vector<Pair> left;
	vector<Pair> right;
	int middle = m_vector.size()/2;
	for(int i=0;i<middle;i++)
	{
	        left.insert(left.end(),m_vector[i]);
	}
	for(int i=middle;i<m_vector.size();i++)
	{
	        right.insert(right.end(),m_vector[i]);
	}
	left=mergesort(left,command);
	right=mergesort(right,command);
	m_vector= merge(left,right,command);

	print();
}

vector <Pair> WordSort :: mergesort(vector<Pair> inserted,string command)
{
	if(inserted.size() <=1)
	{
		return inserted;
	}
	vector<Pair> left;
	vector<Pair> right;
	int middle = inserted.size()/2;
	for(int i=0;i<middle;i++)
	{
	        left.insert(left.end(),inserted[i]);
	}
	for(int i=middle;i<inserted.size();i++)
	{
	        right.insert(right.end(),inserted[i]);
	}
	left=mergesort(left,command);
	right=mergesort(right,command);

	return merge(left, right,command);
}

vector <Pair> WordSort :: merge(vector<Pair> left,vector<Pair> right,string command)
{
	vector<Pair> result;
	vector<Pair>::iterator lit=left.begin();
	vector<Pair>::iterator rit=right.begin();
	if(command=="KEYS")
	{
		while(left.size() >0 || right.size() >0)
		{
			if (left.size() >0 && right.size() >0)
			{
				if((*lit).first <= (*rit).first)
				{
					result.insert(result.end(),left[0]);
					left.erase(left.begin());
				}
				else
				{
					result.insert(result.end(),right[0]);
					right.erase(right.begin());
				}
			}
			else if(left.size() >0)
			{
				result.insert(result.end(),left[0]);
				left.erase(left.begin());
			}
			else if(right.size() >0)
			{
				result.insert(result.end(),right[0]);
				right.erase(right.begin());
			}
		}
	}

	if(command=="VALUES")
	{
		while(left.size() >0 || right.size() >0)
		{
			if (left.size() >0 && right.size() >0)
			{
				if((*lit).second <= (*rit).second)
				{
					result.insert(result.end(),left[0]);
					left.erase(left.begin());
				}
				else if((*rit).second <= (*lit).second)
				{
					result.insert(result.end(),right[0]);
					right.erase(right.begin());
				}
				else if((*rit).second == (*lit).second)
				{
					if((*lit).first <= (*rit).first)
					{
						result.insert(result.end(),left[0]);
						left.erase(left.begin());
					}
					else
					{
						result.insert(result.end(),right[0]);
						right.erase(right.begin());
					}
				}
			}
			else if(left.size() >0)
			{
				result.insert(result.end(),left[0]);
				left.erase(left.begin());
			}
			else if(right.size() >0)
			{
				result.insert(result.end(),right[0]);
				right.erase(right.begin());
			}
		}
	}	
	return result;
}
bool WordSort :: swap(int first, int second)
{
	Pair temp;
	temp = m_vector[first];
	m_vector[first]=m_vector[second];
	m_vector[second]=temp;
	return true;

}

//I had these doing much more before realizing I could just do this and save processing time. 
//I was to lazy to just swap out the function calls with this line. I think this reads nicer anyway.
int WordSort :: return_value(int index)
{
    return m_vector[index].second;
	
}

//I had these doing much more before realizing I could just do this and save processing time. 
//I was to lazy to just swap out the function calls with this line. I think this reads nicer anyway.
string WordSort :: return_key(int index)
{
    return m_vector[index].first;	
}
