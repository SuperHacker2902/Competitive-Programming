#include <bits/stdc++.h>
#define task "SELECT"
using namespace std;
const long long INF=1e9+5;
const long long N=1e6+5;
int n;
long long a[5][N];
long long f[20][N];
vector <int> v[N],v1;
void fre(){
    if (fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
}
bool check(int x){
    for (int i=0;i<3;i++){
        if ((x&(1<<i))&&(x&(1<<i+1))) return 0;
    }
    return 1;
}
long long get(int j, int x){
    long long ans=0;
    for (int i=0;i<4;i++)
        if (x&(1<<i)) ans+=a[i+1][j];
        return ans;
}
void solve(){
    long long ans=-INF;
    cin>>n;
    for (int i=1;i<=4;i++){
        for (int j=1;j<=n;j++) cin>>a[i][j], ans=max(ans,a[i][j]);
    }
    if (ans<0){
        cout<<ans; return;
    }
    for (int i=0;i<16;i++){
        if (!check(i)) continue;
        v1.push_back(i);
        for (int j=0;j<16;j++){
            if ((i&j)==0&&check(j)) v[i].push_back(j);
        }
    }
    for (int j=1;j<=n;j++){
        for (int i:v1){
            long long s=get(j,i);
            for (int x:v[i]) f[i][j]=max(f[i][j],f[x][j-1]+s);
            ans=max(ans,f[i][j]);
        }
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    fre();
    long long t=1; //cin>>t;
    while (t--) solve();
    return 0;
}
