#include <bits/stdc++.h>

using namespace std;
typedef pair<string,string> ii;
int main()
{
    int n;
    cin>>n;
    map<ii,int> flight;
    string home;
    cin>>home;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        string dep=s.substr(0,3);
        string arr=s.substr(5,3);
        ii this_flight=ii(dep,arr);
        ii reverse_this_flight=ii(arr,dep);
        bool found=false;
        for(auto i=flight.begin();i!=flight.end();i++)
        {
            if(found)
            break;
            if(i->first==reverse_this_flight&&i->second>0)
            {
            flight[i->first]--;
            if(flight[i->first]==0)
            flight.erase(i);
            found=1;
            }
        }
        if(!found)
        flight[this_flight]++;

    }
    if(flight.size()==0)
    cout<<"home"<<endl;
    else
    cout<<"contest"<<endl;
    return 0;
}
