#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> nums;
ll isibizi(){
ll res=0;

for(int i=1;i<=14;i++){
    for(int j=i;j<15;j++){
        ll miin=INT_MAX;
        bool ok=true;
        for(int k=i;k<=j;k++){
            miin=min(miin,nums[k]);
            if(k==i)
            continue;
            if(abs(nums[k]-nums[k-1]>1))
            ok=false;
        }
        if(miin>nums[i-1]&&miin>nums[j+1]&&ok)
        res++;
    }
}
return res;

}
int main()
{
    ll t;
    cin>>t;
    while(t--){
    ll nb_test,n;
    nums.clear();
    cin>>nb_test;

        for(int i=0;i<15;i++)
        {
        ll x;
        cin>>x;
        nums.push_back(x);
        }
    cout<<nb_test<<" "<<isibizi()<<endl;


    }
    return 0;
}
