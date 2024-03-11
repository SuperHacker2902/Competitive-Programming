#include <bits/stdc++.h>
#define task "SPSEQ"
using namespace std;
const long long INF=1e9+5;
const long long MOD=1e9+7;
const long long N=1e6+5;
long long n;
unordered_map <long long, long long> bit1, bit2;
long long a[N];
long long dp1[N],dp2[N];
long long f1[N],f2[N];
void fre(){
    if (fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
}
void solve(){
    cin>>n;
    f1[1]=dp1[1]=f2[1]=dp2[1]=1;
    for (int i=1;i<=n;i++) cin>>a[i];
    long long res=1;
    for (int i=2;i<=n;i++){
        long long l=1,r=res,j=0;
        while (l<=r){
            long long m=(l+r)>>1;
            if (a[i]>a[f1[m]]) j=m, l=m+1;
            else r=m-1;
        }
        if (j==res) f1[++res]=i;
        if (a[i]<a[f1[j+1]]) f1[j+1]=i;
        dp1[i]=j+1;
    }
    reverse(a+1,a+n+1);
    res=1;
    for (int i=2;i<=n;i++){
        long long l=1,r=res,j=0;
        while (l<=r){
            long long m=(l+r)>>1;
            if (a[i]>a[f2[m]]) j=m, l=m+1;
            else r=m-1;
        }
        if (j==res) f2[++res]=i;
        if (a[i]<a[f2[j+1]]) f2[j+1]=i;
        dp2[i]=j+1;
    }
    reverse(dp2+1,dp2+n+1);
    long long ans=0;
    for (int i=1;i<=n;i++) ans=max(ans,min(dp1[i],dp2[i])*2-1);
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    fre();
    int t=1; // cin>>t;
    while (t--) solve();
    return 0;
}
