#include<iostream>
#include<unordered_map>
#include<vector>
#include<map>
using namespace std;

#define um map<T, vector<pair<T,int > > >

template<typename T>
class Graph{
    um m;
public:
    void addEdge(T u,T v,int cost,bool bidir=true){
            m[u].push_back(make_pair(v,cost));
            if(bidir){
                m[v].push_back(make_pair(u,cost));
            }
    }
    void printList(){
        for(auto it=m.begin();it!=m.end();it++){
                cout<<it->first<<"=>";

                for(auto j=0;j<it->second.size();j++){
                    cout<<it->second[j].first<<","<<it->second[j].second<<";";
                }
                cout<<endl;

        }

    }
    void dfsHelper(T node,unordered_map<T,bool> &visited){
            cout<<node<<" ";
            visited[node] = true;

            for(auto j:m[node]){
                if(!visited[j.first]){
                    dfsHelper(j.first,visited);
                }
            }

    }

    void dfs(T src){
        unordered_map<T,bool> visited;

        dfsHelper(src,visited);


    }


};




int main(){
    Graph<string> g;
    g.addEdge("Kohat","Dwarka",1);
    g.addEdge("Kohat","Pitampura",2);
    g.addEdge("Pitampura","Dwarka",3);
    g.addEdge("Pitampura","Rohini",4);
    g.addEdge("Rohini","DTU",5);

    g.dfs("Pitampura");

    //g.printList();

return 0;
}
