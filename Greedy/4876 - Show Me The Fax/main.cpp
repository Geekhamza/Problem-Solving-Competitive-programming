#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
string s;
map<char,ll> hexa;


ii run(string a){
    //cout<<" a "<<a<<endl;
    int tmp=hexa[a[1]]+16*hexa[a[0]];

    ii res;
    res.first=((tmp&1<<7)>0);
    res.second=0;
    for(ll i=0;i<7;i++)
    if(tmp&(1<<i))
    res.second+=(pow(2,i));
    if(res.first==1)
    res.second+=3;
    else
    res.second+=1;
    //cout<<" res "<<res.first<<" "<<res.second<<endl;
    return res;

}
string solve(){

string res="";
ll i=0;
while(i<s.length()){
string a="";
a+=s[i];
a+=s[i+1];
ii tmp=run(a);
i+=2;
    if(tmp.first==1){
        for(ll j=0;j<tmp.second;j++)
        {
            res+=s[i];
            res+=s[i+1];
        }
        i+=2;

    }
    else{
        for(ll j=0;j<tmp.second;j++)
        {
            res+=s[i];
            res+=s[i+1];
            i+=2;
        }


    }

}

return res;

}
int main()
{
//    freopen("out.out","w",stdout);
    hexa['0']=0;
    hexa['1']=1;
    hexa['2']=2;
    hexa['3']=3;
    hexa['4']=4;
    hexa['5']=5;
    hexa['6']=6;
    hexa['7']=7;
    hexa['8']=8;
    hexa['9']=9;
    hexa['A']=10;
    hexa['B']=11;
    hexa['C']=12;
    hexa['D']=13;
    hexa['E']=14;
    hexa['F']=15;

    int T;
    cin>>T;
    while(T--){
    //cout<<T<<endl;
    s="";
    int nb_test;
    cin>>nb_test;
    int length;
    cin>>length;
    cin.ignore();
    string l;
    while(length>(s.length()/2)){

    cin>>l;
    s+=l;
    }


    string qqq=solve();
    cout<<nb_test<<" "<<(qqq.length()/2)<<endl;
    ll j=0;
    for(int i=0;i<qqq.length();i++)
    {
    j++;
    cout<<qqq[i];
    if((j==80))
    j=0,cout<<endl;
    }
    if(j!=0)
    cout<<endl;


    }
    return 0;

}
