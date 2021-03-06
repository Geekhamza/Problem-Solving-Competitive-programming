#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vi raank,p,setSize;
int n;
map<string,ll>names;
ll cmp=0;

ll findSet(ll i)
{
    if(p[i]==i)return i;
    return p[i]=findSet(p[i]);
}
bool isSameSet(ll i,ll j){
        return(findSet(i)==findSet(j));
}

void unionSet(ll i,ll j){
if(!isSameSet(i,j)){
    ll x=findSet(i);
    ll y=findSet(j);
    if(raank[x]>raank[y]){ p[y]=x;setSize[x] += setSize[y];}
    else{ p[x]=y;setSize[y] += setSize[x];
        if(raank[x]==raank[y])
        raank[y]++;
    }
}

}



int main()
{
    int T;
    cin>>T;
    while(T--){
    cmp=0;
    cin>>n;
    p.assign(2*n,0);
    raank.assign(2*n,0);
    setSize.assign(2*n,1);

    for(ll i=0;i<(2*n);i++)
    p[i]=i;

    names.clear();
    for(ll i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        if(names.find(s1)==names.end())
        {
        names[s1]=cmp;
        cmp++;
        }
        if(names.find(s2)==names.end())
        {
        names[s2]=cmp;
        cmp++;
        }

        unionSet(names[s1],names[s2]);
        cout<<setSize[findSet(names[s1])]<<endl;
    }

    }

    return 0;
}
