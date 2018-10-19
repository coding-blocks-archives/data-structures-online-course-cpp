#include<iostream>
#include<list>
#include<unordered_map>
#include<map>
#include<cstring>
#include<queue>
using namespace std;
#define um map<T,list<T> >

template<typename T>
class Graph{
    um m;

public:
    Graph(){
    }
    void addEdge(T u,T v,bool bidir=true){
        m[u].push_back(v);
        if(bidir){
            m[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto it=m.begin();it!=m.end();it++){
            cout<<it->first<<"=>";

            for(auto j:it->second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }




    void bfs_traversal(T src,T dest){
        queue<T> q;
        unordered_map<T,bool> visited;
        unordered_map<T,T> parent;
        unordered_map<T,int> dist;
        q.push(src);
        visited[src] = true;
        parent[src]=src;
        dist[src] = 0;

        while(!q.empty()){
            T f = q.front();
            cout<<f<<" - ";
            q.pop();

            for(auto j=m[f].begin();j!=m[f].end();j++){
                if(!visited[*j]){
                    dist[*j] = dist[f] + 1;
                    parent[*j] = f;
                    visited[*j] = true;
                    q.push(*j);
                }
            }
        }

        for(auto it=m.begin();it!=m.end();it++){
            cout<<it->first<<" "<<dist[it->first]<<endl;
        }

        T temp = dest;
        cout<<endl;
        while(temp!=src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;
    }

    void dfsHelper(T node,unordered_map<T,bool> &visited){
        visited[node] = true;
        cout<<node<<" - ";

        for(auto it =m[node].begin();it!=m[node].end();it++){
            if(!visited[*it]){

                dfsHelper(*it,visited);
            }
        }

    }

    void dfs(){
        unordered_map<T,bool> visited;


        for(auto i:m){
            if(!visited[i.first]){
                dfsHelper(i.first,visited);
                cout<<endl;
            }
        }
    }




};

int main(){
    Graph<string> g;
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Jaipur","Delhi");
    g.addEdge("Jaipur","Mumbai");
    g.addEdge("Agra","Delhi");
    g.addEdge("Bhopal","Delhi");
    g.addEdge("Mumbai","Bhopal");
    g.addEdge("Andaman","Nicobar");
    g.printAdjList();

    string city1,city2;
    //cin>>city1>>city2;
    //g.bfs_traversal(city1,city2);


    g.dfs();

    cout<<endl;




}
