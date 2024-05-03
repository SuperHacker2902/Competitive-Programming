#include <bits/stdc++.h>
#define task "TIMGIUA"
using namespace std;
const long long INF=1e9;
const int N=1e7;
void fre(){
    if (fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
}
void solve(){
    long double l,r; cin>>l>>r;
    long long ans=round(sqrt(((l-0.5)*(l-0.5)+(r+0.5)*(r+0.5))/2)-0.5);
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    fre();
    int t=1; //cin>>t;
    while (t--) solve();
    return 0;
}
