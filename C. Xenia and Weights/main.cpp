#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
set<int> weights;
ll m;
bool ok=false;
string res;
void  isibizi(ll left,ll right,ll to_add,ll last_weight,string tmp){
    if(ok)
    return ;
    if(to_add==0)
    {
        ok=true;
        res=tmp;
        return ;
    }
    if(tmp!="")
    tmp+=" ";
    if((m-to_add)%2==0){
        ///add to left
        for(auto i:weights)
        if((i)!=last_weight&&((left+i)>right))
        isibizi(left+i,right,to_add-1,i,tmp+to_string(i));



    }
    else{
        ///add to right
        for(auto i:weights)
        if((i)!=last_weight&&((right+i)>left))
        isibizi(left,right+i,to_add-1,i,tmp+to_string(i));
    }
}
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<10;i++)
    if(s[i]=='1')
    weights.insert(i+1);
    cin>>m;
    isibizi(0,0,m,-1,"");
    if(ok)
    cout<<"YES"<<endl<<res<<endl;
    else
    cout<<"NO"<<endl;
    return 0;
}
