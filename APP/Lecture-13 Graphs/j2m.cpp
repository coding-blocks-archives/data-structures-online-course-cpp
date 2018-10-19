#include<iostream>
#include<list>
using namespace std;


class Graph{

	list<int> *l;
	int V;
public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}
	void addEdge(int u,int v,bool bidir=true){
		l[u].push_back(v);
		if(bidir){
			l[v].push_back(u);
		}
	}

	int dfsHelper(int node,bool *visited){
		visited[node] = true;
		cout<<node<<" , ";

		int cnt = 1;

		for(auto neighbour:l[node]){
			if(!visited[neighbour]){
				cnt += dfsHelper(neighbour,visited);
			}
		}
		return cnt;
	}

	int dfsMain(){
		bool *visited = new bool[V]{0};

		int ans = (V*(V-1))/2;

		for(int i=0;i<V;i++){
			if(!visited[i]){
				int cs = dfsHelper(i,visited);
				ans -= (cs)*(cs-1)/2;
				cout<<endl;
			}
			
		}
		return ans;
	}
};


int main(){
	
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(2,3);
	g.addEdge(0,4);

	cout<<"Final ans is"<<endl;
	cout<< g.dfsMain();
	return 0;
}