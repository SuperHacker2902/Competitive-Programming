#include <bits/stdc++.h>
#define task "QSTRING"
using namespace std;
const long long INF=1e9+5;
const long long MOD=1e9+7;
const long long N=2e3+5;
string a,b;
int f[N][N],pos[N];
int n,m;
void fre(){
    if (fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
}
void solve(){
    cin>>a>>b;
    n=a.size(); m=b.size();
    a=" "+a; b=" "+b;
    for (int i=n;i;i--){
        int l=i,r=m;
        if (a[l]!=b[r]) continue;
        while (l&&r){
            if (a[l]==b[r]) l--, r--;
            else l--;
        }
        if (!r) pos[i]=l+1;
    }
    for (int j=0;j<=n;j++){
        for (int i=m+j;i<=n;i++){
            f[i][j]=max(f[i][j],f[i-1][j]);
            if (j>=1) f[i][j]=max(f[i][j],f[i-1][j-1]);
            if (pos[i]){
                int del=i-pos[i]+1-m;
                if (j>=del) f[i][j]=max(f[i][j],f[pos[i]-1][j-del]+1);
            }
        }
    }
    for (int i=0;i<=n;i++) cout<<f[n][i]<<" ";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    fre();
    int t=1; // cin>>t;
    while (t--) solve();
    return 0;
}
