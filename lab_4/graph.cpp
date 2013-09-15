//Linsenbardt,Michael
//mlinsenbardt
//graph.cpp

#include<iostream>
#include<cctype>
#include<stdlib.h>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include "graph.h"
using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::build_vertex_list(string vertex_names)
{
	string temp;
	int str_length=0;
	for(int i=0; vertex_names[i];i++)
	{
		str_length++;
		if(!isspace(vertex_names[i]) && str_length!= vertex_names.size())
		{
			temp.insert(temp.end(),1,vertex_names[i]);
		}
		else if(!isspace(vertex_names[i]) && str_length== vertex_names.size())
		{
			temp.insert(temp.end(),1,vertex_names[i]);
			insert_vertex(temp);
		}
		else
		{
			insert_vertex(temp);
			temp.clear();
		}
	}
}

void Graph::insert_vertex(string name)
{
	Vertex *temp=new Vertex();
	temp->name_vertex(name);
	m_adjacency_list.insert(pair<string,Vertex> (name,(*temp)));
}

void Graph::build_edge_list(string end1,string end2, int weight)
{
	m_adjacency_list[end1].make_edges(end1,end2,weight);
	m_adjacency_list[end2].make_edges(end1,end2,weight);
}

void Graph::breadth_first()
{
	Vertex *source=NULL;
	queue<Vertex*> m_queue;
	map<string,Vertex>::iterator it;
	for(it=m_adjacency_list.begin();it!=m_adjacency_list.end();it++)
	{
		if(it==m_adjacency_list.begin())
		{
			source=&m_adjacency_list[it->first];
		}
		(it->second).m_color=0;//white
		(it->second).m_distance=60;
		(it->second).m_prev=NULL;
	}
	(*source).m_color=1;//gray
	(*source).m_distance=0;
	(*source).m_prev=NULL;
	m_queue.push(source);
	while(m_queue.empty()==false)
	{
		Vertex *u=m_queue.front();
		cout<<"Visiting vertex: "<<u->m_name;
		cout<<" Distance: "<<(*u).m_distance<<endl;
		m_queue.pop();
		u->breadth_find_adj(m_queue,m_adjacency_list);
		(*u).m_color=2;//black
	}
}

void Graph::Vertex::breadth_find_adj(queue<Vertex*> &m_queue,map <string,Vertex> &m_adjacency_list)
{
	Vertex* temp;
	list<Edge>::iterator lit;
	for(lit=edge_list.begin();lit!=edge_list.end();lit++)
	{
		if(lit->return_end1()==m_name)
		{
			temp=&m_adjacency_list[lit->return_end2()];
			if((*temp).m_color==0)//white
			{
				(*temp).m_color=1;//gray
				(*temp).m_distance=m_distance+1;
				(*temp).m_prev=&m_adjacency_list[m_name];
				m_queue.push(temp);	
			}
		}
		else if(lit->return_end2()==m_name)
		{
			temp=&m_adjacency_list[lit->return_end1()];
			if((*temp).m_color==0)//white
			{
				(*temp).m_color=1;//gray
				(*temp).m_distance=m_distance+1;
				(*temp).m_prev=&m_adjacency_list[m_name];
				m_queue.push(temp);	
			}
		}	
	}		
}

void Graph::depth_first()
{

	Vertex* u=NULL;
	map<string,Vertex>::iterator it;
	for(it=m_adjacency_list.begin();it!=m_adjacency_list.end();it++)
	{
		u=&(it->second);
		(*u).m_color=0;//white
		(*u).m_prev=NULL;	
	}
	int time=0;
	for(it=m_adjacency_list.begin();it!=m_adjacency_list.end();it++)
	{
		u=&(it->second);
		if((*u).m_color==0)//white
		{
			u->depth_visit(time,m_adjacency_list);
		}
	}	
}

void Graph::Vertex::depth_visit(int &time,map <string,Vertex> &m_adjacency_list)
{
	Vertex* temp;
	time++;
	m_distance=time;
	m_color=1;//gray
	cout<<"Visiting Vertex: "<<m_name<<" Time: "<<time<<endl;
	list<Edge>::iterator lit;
	for(lit=edge_list.begin();lit!=edge_list.end();lit++)
	{
		if(lit->return_end1()==m_name)
		{
			temp=&m_adjacency_list[lit->return_end2()];
			if((*temp).m_color==0)//white
			{
				(*temp).m_prev=&m_adjacency_list[m_name];
				(*temp).depth_visit(time,m_adjacency_list);
			}
		}
		else if(lit->return_end2()==m_name)
		{
			temp=&m_adjacency_list[lit->return_end1()];
			if((*temp).m_color==0)//white
			{
				(*temp).m_prev=&m_adjacency_list[m_name];
				(*temp).depth_visit(time,m_adjacency_list);
			}
		}	
	}
	m_color=2;//black
	time++;
	cout<<"Finished Vertex: "<<m_name<<" Time: "<<time<<endl;
}

void Graph::prim()
{
	Vertex* u;
	Vertex* r;
	PQueue m_queue;
	map<string,Vertex>::iterator it;
	for(it=m_adjacency_list.begin();it!=m_adjacency_list.end();it++)
	{
		if(it==m_adjacency_list.begin())
		{
			r=&m_adjacency_list[it->first];
		}
		u=&(it->second);
		(*u).m_key=60;
		(*u).m_prev=NULL;
		m_queue.push(u);
	}
	(*r).m_key=0;
	while(m_queue.empty()==false)
	{
		m_queue.insertionsort();
		m_queue.pop(u);
		(*u).prim_extract_min(m_queue.m_vector,m_adjacency_list);
	}
}

void Graph::Vertex::prim_extract_min(vector<Vertex*> &m_vector,map <string,Vertex> &m_adjacency_list)
{
	Vertex* v;
	cout<<"Vertex: "<<m_name<<" Key: "<<m_key<<endl;
	list<Edge>::iterator lit;
	for(lit=edge_list.begin();lit!=edge_list.end();lit++)
	{
		if(lit->return_end1()==m_name)
		{
			v=&m_adjacency_list[lit->return_end2()];
			if(lit->return_weight()<(*v).m_key)
			{
				(*v).m_prev=&m_adjacency_list[m_name];
				(*v).m_key=lit->return_weight();
			}
		}
		if(lit->return_end2()==m_name)
		{
			v=&m_adjacency_list[lit->return_end1()];
			if(lit->return_weight()<(*v).m_key)
			{
				(*v).m_prev=&m_adjacency_list[m_name];
				(*v).m_key=lit->return_weight();
			}
		}
	}
}

Graph::PQueue::PQueue()
{

}

Graph::PQueue::~PQueue()
{

}

void Graph::PQueue::push(Vertex* inserted)
{
	m_vector.insert(m_vector.end(),inserted);
}

void Graph::PQueue::pop(Vertex* &inserted)
{
	inserted=m_vector.front();
	m_vector.erase(m_vector.begin());
}

bool Graph::PQueue::empty()
{
	if(m_vector.size()==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Graph::PQueue::swap(int first,int second,Vertex* temp)
{
	temp=m_vector[first];
	m_vector[first]=m_vector[second];
	m_vector[second]=temp;
	return true;
}

void Graph::PQueue::insertionsort()
{
	Vertex* temp;
	vector<Vertex*>::iterator it;
	int i=0;
	for (it=m_vector.begin();it!=m_vector.end();it++)
	{
		int value= (*it)->m_key;
		string name=(*it)->m_name;
		int j=i;
		while ((i>0 && m_vector[i-1]->m_key > value) ||(i>0 && m_vector[i-1]->m_key == value && m_vector[i-1]->m_name > name))
		{
			swap(i,i-1,temp);
			i--;
		}
		i=j;
		i++;
	}
}

/*void Graph::PQueue::mergesort()
{
	vector<Vertex*> left;
	vector<Vertex*> right;
	cout<<"here"<<endl;
	int middle = m_vector.size()/2;
	for(int i=0;i<middle;i++)
	{
	        left.insert(left.end(),m_vector[i]);
	}
	for(int i=middle;i<m_vector.size();i++)
	{
	        right.insert(right.end(),m_vector[i]);
	}
	left=mergesort(left);
	right=mergesort(right);
	merge(left,right,m_vector);
}

vector<Vertex*> Graph::PQueue::mergesort(vector<Vertex*> inserted)
{
	if(inserted.size() <=1)
	{
		return inserted;
	}
	cout<<"here"<<endl;
	vector<Vertex*> left;
	vector<Vertex*> right;
	int middle = m_vector.size()/2;
	for(int i=0;i<middle;i++)
	{
	        left.insert(left.end(),m_vector[i]);
	}
	for(int i=middle;i<m_vector.size();i++)
	{
	        right.insert(right.end(),m_vector[i]);
	}
	int lefti=mergesort(left);
	int righti=mergesort(right);
	merge(left,right,inserted);
}
void Graph::PQueue::merge(vector<Vertex*> left,vector<Vertex*> right,vector<Vertex*> &final)
{
	vector<Vertex*> result;
	vector<Vertex*>::iterator lit=left.begin();
	vector<Vertex*>::iterator rit=right.begin();
	while(left.size() >0 || right.size() >0)
	{
		if (left.size() >0 && right.size() >0)
		{
			if((*lit)->m_key <= (*rit)->m_key)
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
}*/

void Graph::print_adjacency()
{
	string name;
	map<string,Vertex>::iterator it;
	//int count=0;
	for(it=m_adjacency_list.begin();it!=m_adjacency_list.end();it++)
	{
		name=it->first;
		cout<<"Vertex: "<<name<<endl;
		(it->second).print_edges();
		/*count++;
		if(count>15)
		{
			break;
		}*/
	}
}

void Graph::Vertex::name_vertex(string name)
{
	m_name=name;
}

void Graph::Vertex::make_edges(string end1,string end2, int weight)
{
	Edge *temp=new Edge(end1,end2,weight);
	edge_list.insert(edge_list.end(),*temp);
}

void Graph::Vertex::print_edges()
{
	string end1;
	string end2;
	int weight;
	list<Edge>::iterator it;
	for(it=edge_list.begin();it!=edge_list.end();it++)
	{
		end1=it->return_end1();
		end2=it->return_end2();
		weight=it->return_weight();
		cout<<" Edge: "<<end1<<" , "<<end2<<" , "<<weight<<endl;
	}
}

Graph::Vertex::Vertex()
{

}

Graph::Vertex::~Vertex()
{

}

Graph::Vertex::Edge::Edge(string end1,string end2, int weight)
{
	m_end1=end1;
	m_end2=end2;
	m_weight=weight;
}

Graph::Vertex::Edge::~Edge()
{

}

string Graph::Vertex::Edge::return_end1()
{
	return m_end1;
}

string Graph::Vertex::Edge::return_end2()
{
	return m_end2;
}

int Graph::Vertex::Edge::return_weight()
{
	return m_weight;
}
