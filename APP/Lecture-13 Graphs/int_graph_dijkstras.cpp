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
    void addEdge(int u,int v,int wt){

        l[u].push_back(make_pair(wt,v));
        l[v].push_back(make_pair(wt,u));
    }


    void shortestPath(int src,int dest){
        int *dist = new int[V];
        for(int i=0;i<V;i++){
            dist[i] = INT_MAX;
        }

        dist[src] = 0;
        set<pair<int,int> > s;
        s.insert( make_pair(0,src));


        ///Do some work (Visit a node) V times
        for(int i=0;i<V;i++){

            auto it = s.begin();
            int f = it->second;

            s.erase(it);

            for(auto j = l[f].begin();j!=l[f].end();j++){


                    if(dist[f] + j->first < dist[j->second]){

                        int oldDist = dist[j->second];
                        int oldNode = j->second;

                        dist[j->second] = dist[f] + j->first;

                        if(s.find(make_pair(oldDist,oldNode))!=s.end()){
                            s.erase(make_pair(oldDist,oldNode));
                        }

                        s.insert(make_pair(dist[j->second],j->second));

                    }

            }

        }

        for(int i=0;i<V;i++){
                cout<<i<<" -- "<<dist[i]<<endl;
        }



    }

};


int main(){

    Graph g(6);
    g.addEdge(0,1,1);

    g.addEdge(0,2,2);
    g.addEdge(1,2,3);
    g.addEdge(1,3,5);
    g.addEdge(2,4,1);
    g.addEdge(2,3,2);
    g.addEdge(4,5,1);

    g.addEdge(3,5,6);

    g.shortestPath(0,5);


}
