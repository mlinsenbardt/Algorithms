//Linsenbardt,Michael
//mlinsenbardt
//main.cpp

#include<iostream>
#include<fstream>
#include "graph.h"
using namespace std;

int main(int argc, char *argv[])
{
	ifstream my_ifile(argv[1], ios::in);
	string vertex_names;
	string end1;
	string end2;
	int weight;
	Graph my_graph;
	getline(my_ifile,vertex_names);
	my_graph.build_vertex_list(vertex_names);
	while(my_ifile>>end1)
	{
		//cout<<end1<<endl;
		my_ifile>>end2;
		//cout<<end2<<endl;
		my_ifile>>weight;
		//cout<<weight<<endl;
		my_graph.build_edge_list(end1,end2,weight);
	}
	//my_graph.print_adjacency();
	my_graph.breadth_first();
	my_graph.depth_first();
	my_graph.prim();
	return 0;
}
