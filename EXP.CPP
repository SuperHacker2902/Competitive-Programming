#include <bits/stdc++.h>
#define task "EXP"
using namespace std;
const long long INF=1e9+5;
const long long MOD=1e9+7;
const long long N=500+5;
const long long PLUS=25005;
long long n,s,sum=0;
long long a[N];
bool f[N][PLUS*2];
void fre(){
    if (fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    cin>>s;
    f[1][a[1]+PLUS]=1;
    for (int i=2;i<=n;i++){
        for (int j=-PLUS;j<=PLUS;j++){
            f[i][j+PLUS]|=(f[i-1][j+a[i]+PLUS]|f[i-1][j-a[i]+PLUS]);
        }
    }
    if (f[n][s+PLUS]) cout<<"YES";
    else cout<<"NO";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    fre();
    long long t=1; // cin>>t;
    while (t--) solve();
    return 0;
}
