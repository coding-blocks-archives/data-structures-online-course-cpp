ṭ#include<iostream>
#include<ctime>
#define DONE (1<<n)-1
using namespace std;

int ans =0;

void solve(int row,int ld,int rd,int n){
    if(row==DONE){ ans++;return;}

    int pos = DONE &(~(row|ld|rd));
    while(pos>0){
        int p = pos&(-pos);
        pos -= p;
        solve(row|p, (ld|p)<<1,(rd|p)>>1,n);
    }
}

int main(){
    int n;
    cin>>n;

    clock_t st = clock();

    solve(0,0,0,n);
    cout<< clock()  - st<<endl;

   // cout<<ans<<endl;

return 0;
}
