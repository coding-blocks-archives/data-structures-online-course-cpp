#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    ///Pointer to array of lists ( array of lists )
    list<int> *l;

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
    void dfsHelper(int i,bool visited[],int &cp_size){
            visited[i] = true;
            cp_size++;

            for(auto it=l[i].begin();it!=l[i].end();it++){
                if(!visited[*it]){
                    dfsHelper(*it,visited,cp_size);
                }
            }
    }

    int dfsMoon(){
        bool* visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        int n = V;
        int total_ways = (n)*(n-1)/2;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                int cp_size = 0;
                dfsHelper(i,visited,cp_size);
                 total_ways -= (cp_size*(cp_size-1)/2);
            }

        }
        return total_ways;

    }
    void dfsHelperHoli(int i,bool *visited,int *cnt){

            visited[i] = true;

             for(auto it=l[i].begin();it!=l[i].end();it++){
                if(!visited[*it]){
                    dfsHelperHoli(*it,visited,cnt);
                }
                cnt[i] += cnt[*it];

            }
    }
    void dfsHelperHoliCost(int i,bool *visited,int *cnt,int total_cost){




    }

    void dfsHoli(){

        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }

        int *cnt = new int[V];

        for(int i=0;i<V;i++){
            cnt[i] = 1;
        }

        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        ///Cost Compute
        int total_cost = 0;





    }


};

int main(){

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(0,4);
    cout<< g.dfsMoon()<<endl;

return 0;
}
