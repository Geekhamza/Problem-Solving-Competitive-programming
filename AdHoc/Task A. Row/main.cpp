#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
ll n;
vi  ai,bi;
int main()
{
    freopen("row07.in","r",stdin);
    //freopen("row07.ans","w",stdout);
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    ai.clear();
    bi.clear();
    vector<vector<ll> > res;

    for(ll i=0;i<n;i++){
    ll x;
    cin>>x;
    ai.push_back(x);
    }
    for(ll i=0;i<n;i++){
    ll x;
    cin>>x;
    bi.push_back(x);
    }

    ll cmp_used=0;
    while(cmp_used<(n)){
    //cout<<" used "<<cmp_used<<endl;
    vi tmp;
    ll i=-1;
    ll j=0;

    while(i<n){
    i++;
    cout<<i<<endl;
    //cout<<" i "<<i<<endl;
    while(ai[i]==-1)
    i++;
    if(i>=n)
    break;
   // cout<<" next i "<<i<<endl;
    ///i fixed no -1
    ll tmp_j=j;
    while(ai[i]!=bi[j]&&j<n){
    j++;
    }
    if(j>=n){
    j=tmp_j;
    continue;
    }

    //cout<<"  to add "<<ai[i]<<" found in i "<<i<<" and j "<<j<<endl;
    tmp.push_back(ai[i]);
    ai[i]=-1;
    bi[j]=-1;
    //j++;
    //i++;
    cmp_used++;

    }

    res.push_back(tmp);
    }


    cout<<res.size()<<endl;
    for(ll i=0;i<res.size();i++){
    cout<<res[i].size()<<" ";
        for(ll j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
}

    return 0;
}

/*
1
6
1 2 3 4 5 6
2 3 6 1 4 5
*/
