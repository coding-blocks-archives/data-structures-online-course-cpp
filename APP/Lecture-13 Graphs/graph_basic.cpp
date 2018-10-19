#include<iostream>
#include<list>
using namespace std;


class Graph{
    int V;
    ///Pointer to a dynamic Array of Linked Lists
    list <int> *l;

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

    void printAdjList(){

        for(int i=0;i<V;i++){
            cout<<i<<"=>";
            /// for(list<int>::iterator it = l[i].begin();it!=l[i].end();it++) cout<< *it <<endl;
            /// for(vector<int>::iterator iv =

            for(auto j:l[i]){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};


int main(){

    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.printAdjList();


}
