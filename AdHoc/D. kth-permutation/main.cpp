#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n ,k;
vector<int> res;
ll fact(ll n) {
      if(n==0||n==1)
      return 1;
      return n*fact(n-1);
    }

void generate_all( ll k,vector<int> v){

if(v.size()==0)
return;
ll f=fact(v.size()-1);
ll pos=k/f;
//cout<<pos<<" ";
k%=f;
res.push_back(v[pos]);
v.erase(v.begin()+pos);
generate_all(k,v);

}
int main()
{
    //freopen("permutation.in","r",stdin);
    int t;
    cin>>t;
    while(t--){
    res.clear();
    cin>>n>>k;
    vector<int> tab;
    for(int i=1;i<=n;i++)
    tab.push_back(i);

    generate_all(k-1,tab);
    for(int i=0;i<n-1;i++)
    cout<<res[i]<<" ";
    cout<<res[n-1]<<endl;




}

    return 0;
}
