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


};

int main(){
    Graph<int> g;
    int board[50] = {0};
    board[2]= 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    ///Add Edges
    for(int u=0;u<36;u++){

        if(board[u]==0){
            for(int dice=1;dice<=6;dice++){
                int v  = u + dice + board[u+dice];

                if(v<=36 ){
                    g.addEdge(u,v,false);
                }
            }
        }

    }

    ///find the shortest path
    g.bfs_traversal(0,36);



    return 0;
}
