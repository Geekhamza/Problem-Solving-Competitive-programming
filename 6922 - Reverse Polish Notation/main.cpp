#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
string s;

ll solve(stack<ll> q,ll i){

if(i==s.length())
    return  q.top()-1;
 ///ok cases
        if(s[i]=='+'&&q.top()>=2){
            while(q.top()>=2&&i<s.length()&&s[i]=='+'){
            q.top()--;
            i++;
            }
            return solve(q,i);
        }
        if(s[i]=='a'){
            while(i<s.length()&&s[i]=='a')
            {q.top()++;i++;}
            return solve(q,i);
        }
        ll res=LLONG_MAX;
         if(s[i]=='+'&&q.top()<2){
        ///i can swap ?
        if(i!=s.length()-1&&s[i+1]!='+'){
        swap(s[i],s[i+1]);
        res=min(res, 1+solve(q,i));
        swap(s[i],s[i+1]);
        }
        ///nnn ++ exist
        q.top()++;
        res=min(res, 1+solve(q,i));
        }
    return res;


}


int main()
{
    freopen("in.in","r",stdin);
        int t;
        cin>>t;
        for(int i=1;i<=t;i++){
        cin>>s;

        stack<ll> q;
        q.push(0);
        cout<<"Case "<<i<<": "<<solve(q,0)<<endl;
        }
    return 0;
}
