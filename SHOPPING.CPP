#include <bits/stdc++.h>
#define task "SHOPPING"
using namespace std;
const long long INF=1e9+5;
const long long MOD=1e9+7;
const int N=2000+5;
void fre(){
    if (fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
}
struct shop{
    int x,y,z;  
};
bool check(shop a, shop b){
    return a.z>b.z;
}
void solve(){
    int n,a,b; cin>>n>>a>>b;
    shop s[N];
    for (int i=1;i<=n;i++) cin>>s[i].x>>s[i].y>>s[i].z;
    if (!b){
        int f[n+1][a+1];
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
            for (int j=0;j<=a;j++){
                f[i][j]=f[i-1][j];
                if (j>=s[i].y) f[i][j]=max(f[i][j],f[i-1][j-s[i].y]+s[i].x);
            }
        cout<<f[n][a];
    }
    else{
        sort(s+1,s+n+1,check);
        int f[n+1][a+1][b+1];
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
            for (int j=0;j<=a;j++)
                for (int k=0;k<=b;k++){
                    f[i][j][k]=f[i-1][j][k];
                    int t=min(k/s[i].z*s[i].z,s[i].y*s[i].z);
                    if (j>=s[i].y-t/s[i].z) f[i][j][k]=max(f[i][j][k],f[i-1][j-(s[i].y-t/s[i].z)][k-t]+s[i].x);
                }
        cout<<f[n][a][b];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    fre();
    int t=1; // cin>>t;
    while (t--) solve();
    return 0;
}
