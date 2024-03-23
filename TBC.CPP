#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long b[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("TBC.INP","r",stdin);
    freopen("TBC.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i], cout<<b[i]*i-b[i-1]*(i-1)<<" ";
    return 0;
}
