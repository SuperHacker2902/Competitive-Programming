#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const long long MOD=1e9+7;
long long a[N];
long long f[N];
long long ans=0;
long long binpow(long long x, long long y){
    if (!y) return 1;
    long long tem=binpow(x,y/2);
    long long tem1=((tem%MOD)*(tem%MOD))%MOD;
    if (y%2) return (tem1*x)%MOD;
    else return tem1;
}
long long kCn(int n, int k){
    return f[n]*binpow((f[k]*f[n-k])%MOD,MOD-2)%MOD;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("XOSO.INP","r",stdin);
    freopen("XOSO.OUT","w",stdout);
    f[0]=1;
    int n,k; cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) f[i]=(f[i-1]*i)%MOD;
    for (int i=k;i<=n;i++) ans=(ans+a[i]*kCn(i-1,k-1))%MOD;
    cout<<ans;
    return 0;
}
