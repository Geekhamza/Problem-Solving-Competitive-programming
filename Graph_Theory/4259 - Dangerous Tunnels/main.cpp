#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vector<vii> Adjlist;
vi p,path,vis;
vector<vi> paths;
ll danger[210][210];
int res[210][210];

int n,T,k,t,s,mf,f,m;
ll maxdanger;
void augment(int v,int minEdge){
if(v==s){f=minEdge;return;}
else if(p[v]!=-1){

            augment(p[v],min(res[p[v]][v],minEdge));
            if(v!=t)
            vis[v]=1;
            res[p[v]][v]-=f;
            res[v][p[v]]+=f;
}
}

void Edmon_karp(){
mf=0;
while(1){
f=0;
p.assign(n,-1);
vi dis(n,INT_MAX);
priority_queue<ii,vector<ii>,greater<ii> > q;q.push(ii(0,0));
dis[0]=0;
    while(!q.empty()){
        ii u=q.top();
        q.pop();
        if(dis[u.second]<u.first)
        continue;
        if(u.second==t)
        {
        maxdanger=max(maxdanger,u.first);
        break;
        }

        for(int i=0;i<n;i++){
            if(res[u.second][i]>0&&dis[i]>(max(u.first,danger[u.second][i]))&&vis[i]==0){
                    q.push(ii(max(u.first,danger[u.second][i]),i));
                    dis[i]=max(danger[u.second][i],u.first);
                    p[i]=u.second;
                }
        }
    }
augment(t,INT_MAX);
if(f==0)
break;
mf+=f;
if(mf==k)
return;

}

}

int main()
{
    int j=0;
    while(cin>>n&&n>0){
    cin>>m;
     s=0;
    t=n+1;
    n+=2;
    memset(res,0,sizeof res);
    memset(danger,0,sizeof danger);
    vis.assign(n,0);
    maxdanger=0;
    for(int i=0;i<m;i++){
    int p,q;
    ll d;
    cin>>p>>q>>d;

    res[min(p,q)][max(p,q)]=INT_MAX;
    if(max(p,q)==n-1)
    res[min(p,q)][max(p,q)]=1;
    danger[min(p,q)][max(p,q)]=d;
    }
    cin>>k;
    Edmon_karp();
    if(mf<k)
    cout<<"Case "<<j+1<<": no solution \n";
    else
    cout<<"Case "<<j+1<<": "<<maxdanger<<"\n";
    j++;
    }

    return 0;
}
