#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
ios_base::sync_with_stdio(false);
    string s,s1;
    cin>>s>>s1;

    string res="";
    for(ll i=0;i<s.length();i++){
    if(s[i]==s1[i]){
    res+="z";
    }
    else{
        if(s[i]>s1[i])
        res+=s1[i];
        else{
            cout<<"-1"<<endl;
            return 0;
        }
    }
    }
    cout<<res<<endl;
    return 0;
}
