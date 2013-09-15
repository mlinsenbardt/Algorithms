//Linsenbardt,Michael
//mlinsenbardt
//graph.h

#ifndef Graph_h
#define Graph_h

#include<iostream>
#include<string>
#include<map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph
{
	public:
		Graph();
		~Graph();
		void build_vertex_list(string vertex_names);
		void insert_vertex(string name);
		void build_edge_list(string end1,string end2, int weight);
		void print_adjacency();
		void breadth_first();
		void depth_first();
		void prim();
	public:
		class Vertex
		{
			public:
				Vertex();
				~Vertex();
				void name_vertex(string name);
				void make_edges(string end1,string end2, int weight);
				void breadth_find_adj(queue<Vertex*> &m_queue,map <string,Vertex> &m_adjacency_list);
				void depth_visit(int &time,map <string,Vertex> &m_adjacency_list);
				void prim_extract_min(vector<Vertex*> &m_vector,map <string,Vertex> &m_adjacency_list);
				void print_edges();
				string m_name;
				int m_color;// 0=white 1=gray 2=black
				int m_distance;
				int m_key;
				Vertex *m_prev;
			private:
				class Edge
				{
					public:
						Edge(string end1,string end2, int weight);
						~Edge();
						string return_end1();
						string return_end2();
						int return_weight();
					private:
						int m_weight;
						string m_end1;
						string m_end2;
				};
				public:
					list<Edge> edge_list;
		};
	public:
		class PQueue
		{
			public:
				PQueue();
				~PQueue();
				void push(Vertex* inserted);
				//void mergesort();
				//vector<Vertex*> mergesort(vector<Vertex*> &inserted);
				//void merge(vector<Vertex*> left,vector<Vertex*> right,vector<Vertex*> &final);
				void insertionsort();
				bool empty();
				bool swap(int first,int second,Vertex* temp);
				void pop(Vertex* &inserted);
				vector<Vertex*> m_vector;
		};
	public:
		map <string,Vertex> m_adjacency_list;
};


#endif
