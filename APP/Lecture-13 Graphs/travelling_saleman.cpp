#include<iostream>
using namespace std;


int dist[10][10] = {
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};
int n = 4;
int ALL_VISITED = (1<<n)-1;

int tsp(int current_city,int mask){
	
	if(mask==ALL_VISITED){
		return dist[current_city][0];
	}

	int ans = INT_MAX;
	for(int city=0;city<n;city++){

		if(city!=current_city && ((mask&(1<<city))==0)){
			ans = min(ans,dist[current_city][city] + tsp(city,mask|(1<<city)));
		}
	}
	return ans;
}
int main(){

	cout<<tsp(0,1);

	return 0;
}