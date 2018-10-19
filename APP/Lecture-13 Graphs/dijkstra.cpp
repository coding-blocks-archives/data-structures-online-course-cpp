#include<bits/stdc++.h>
using namespace std;

class Graph{

	int V;
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int> >[V];
	}
	void addEdge(int u,int v,int cost,bool bidir=true){
		l[u].push_back(make_pair(v,cost));
		if(bidir){
			l[v].push_back(make_pair(u,cost));
		}
	}

	void dijkstra(int src){
		int *dist = new int[V];
		
		for(int i=0;i<V;i++){
			dist[i] = INT_MAX;
		}
		dist[src] = 0;
		set<pair<int,int> > s;
		s.insert(make_pair(0,src));

		while(!s.empty()){
			auto p  = *(s.begin());
			int parent = p.second;
			s.erase(s.begin());

			for(auto childPair:l[parent]){
				
				int childNode = childPair.first;
				int edgeLen = childPair.second;

				if(dist[parent]+edgeLen < dist[childNode]){

					auto f = s.find(childPair);
					if(f!=s.end()){
						s.erase(f);
					}


					dist[childNode] = dist[parent] + edgeLen;
					s.insert(make_pair(dist[childNode],childNode));
				}
			}
		}
		for(int i=0;i<V;i++){
			cout<<"Node is "<<i<<" and at a dist "<<dist[i]<<endl;
		}
	}
};

int main(){

	Graph g(5);
	g.addEdge(1,2,1);
	g.addEdge(2,3,2);
	g.addEdge(3,4,1);
	g.addEdge(4,1,5);
	g.addEdge(1,3,4);
	g.dijkstra(1);



}