#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> res;
    ll current_somme=0;

    for(int i=0;i<n;i++){
    if(i==0)
    res.push_back(1);
        else{
            if(b>0){
            res.push_back(current_somme+1);
            b--;
            }
            else{
                if(a>0){

                    ll tmp=res[i-1];
                    res.push_back(tmp);
                    if(tmp<=current_somme-1) {
                    res[i]++;
                    a--;
                    }

                }
                else
                res.push_back(res[i-1]);
            }

        }

         current_somme+=res[i];
    }
        if(a>0||b>0||res[res.size()-1]>50000)
        cout<<"-1";
        else
    for(ll i=0;i<n;i++)
    cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}
