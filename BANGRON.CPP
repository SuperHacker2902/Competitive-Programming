#include <bits/stdc++.h>
#define task "BANGRON"
using namespace std;
const long long INF=1e9+5;
const long long MOD=1e9+7;
const long long N=1e6+5;
void fre(){
    if (fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
}
void solve(){
    string s; cin>>s;
    long long ans=0;
    for(int i=0;i<s.size()-2;i++){
        int demO=0,demL=0,demP=0;
        for(int j=i;j<s.size();j++){
            if(s[j]=='O') demO++;
            else if(s[j]=='L') demL++;
            else if(s[j]=='P') demP++;
            if(demO>=3||demL>=3||demP>=3){
                ans+=s.size()-j;
                break;
            }
        }
    }
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
