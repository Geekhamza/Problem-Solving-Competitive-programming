#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> students;
ll isibizi(){
ll res=0;

    for(int i=0;i<20;i++){
        for(int j=i+1;j<20;j++){
            if(students[i]>students[j])
            swap(students[i],students[j]),res++;

        }

    }
return res;
}
int main()
{
    freopen("out.out","w",stdout);
    ll t;
    cin>>t;
    while(t--){
    ll nb_test;
    students.clear();
    cin>>nb_test;
        for(int i=0;i<20;i++)
        {
        ll x;
        cin>>x;
        students.push_back(x);
        }
    cout<<nb_test<<" "<<isibizi()<<endl;
    }
    return 0;
}
