#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
string a[N+1];
string convert(int n, int c, int m){
    string tem;
    while (m--){
        tem=char(n%c+'0')+tem;
        n/=c;
    }
    return tem;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("MATTHU.INP","r",stdin);
    freopen("MATTHU.OUT","w",stdout);
    int n,m,k,x;
    string s;
    cin>>n>>m>>k>>x>>s;
    for (int i=0;i<m;i++){
        string tem; cin>>tem;
        sort(tem.begin(),tem.end());
        a[i]=tem;
    }
    string ans=convert(x-1,k,m);
    int pos=0;
    for (int i=0;i<n;i++)
        if (s[i]=='#') s[i]=a[pos][ans[pos]-'0'], pos++;
    cout<<s;
    return 0;
}
