#include<iostream>
#include<list>
#include<set>

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
    void dfs(int i,int *cnt,bool*vis){

        vis[i] = true;

        for(auto it=l[i].begin();it!=l[i].end();it++){
            if(!vis[it->first]){
                dfs(it->first,cnt,vis);
                cnt[i] += cnt[it->first];
            }

        }
       // cout<<cnt[i]<<endl;

    }
    int dfsCost(int i,int *cnt,bool *vis){
        vis[i] = true;
        int cost = 0;
        for(auto it=l[i].begin();it!=l[i].end();it++){
            if(!vis[it->first]){
                 cost += 2*it->second*min(V-cnt[it->first],cnt[it->first]) + dfsCost(it->first,cnt,vis);
            }
        }
        return cost;

    }




    void dfsHoliday(){
        int *cnt = new int[V];
        for(int i=0;i<V;i++){
            cnt[i] = 1;
        }

        bool *visited = new bool[V]{0};

        dfs(0,cnt,visited);

        for(int i=0;i<V;i++){
            cout<<i<<" "<<cnt[i]<<endl;
        }

        bool* visited2 = new bool[V]{0};

        cout<<dfsCost(0,cnt,visited2);

    }
    void dijkstra(int src){

        int *dist = new int[V];
        for(int i=0;i<V;i++){
            dist[i] = INT_MAX;
        }

        set<pair<int,int > >s;
        dist[src] = 0;
        s.insert(make_pair(dist[src],src));


        while(!s.empty()){

                auto f = s.begin();
                int currentNode = f->second;
                int currentNodeDist = f->first;
                s.erase(f);

                for(auto it=l[currentNode].begin();it!=l[currentNode].end();it++){
                        int child = it->first;
                        if(currentNodeDist + it->second < dist[child]){

                            auto exists = s.find(make_pair(dist[child],child));
                            if(exists!=s.end()){
                                s.erase(exists);
                            }
                            dist[child] = currentNodeDist + it->second;
                            s.insert(make_pair(dist[child],child));
                        }

                }
        }

        for(int i=0;i<V;i++){
            cout<<i<<" - "<<dist[i]<<" "<<endl;
        }


};


int main(){
    /*
    Graph g(4);
    g.addEdge(0,1,3);
    g.addEdge(1,2,2);
    g.addEdge(3,2,2);

    g.dfsHoliday();
    */
    Graph g(6);
    g.addEdge(0,2,1);
    g.addEdge(0,1,3);
    g.addEdge(1,2,2);
    g.addEdge(3,1,5);
    g.addEdge(2,3,1);
    g.addEdge(3,5,2);

    g.addEdge(1,4,7);
    g.addEdge(5,4,3);
    g.dijkstra(0);

    return 0;
}
