#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;


ll choose(ll n, ll k) {
//cout<<" choose "<<k<<" n "<<n<<endl;
    if (k > n||k==0) {
        return 0LL;
    }
    int  r = 1;
    for (ll d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

ll isibizi(ll nb_ouv,ll nb_ferm,ll nb_ferm1,ll pos){
if(pos>s.length())
return 0;

    ll res=0;
    if(s[pos]==')'){
    nb_ferm++;
    for(ll i=1;i<=nb_ferm;i++){
    res+=choose(nb_ouv,i);
    }
    return res+isibizi(nb_ouv,nb_ferm+1,nb_ferm1,pos+1);
    }
    if(s[pos]=='(')
    return isibizi(nb_ouv+1,0,nb_ferm1+1,pos+1);

}
int main()
{
    cin>>s;
    cout<<isibizi(0,0,0,0)<<endl;
    return 0;
}
