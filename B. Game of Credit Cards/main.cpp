#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    int cmp_min=0,cmp_max=0;
    int next_to_play_max=-1,next_to_play_min=-1;
    for(int i=0;i<n;i++){
    next_to_play_max++;
    next_to_play_min++;
     while(next_to_play_min<n&&s1[i]>s2[next_to_play_min])
    next_to_play_min++;
    if(next_to_play_min<n)
    cmp_min++;

    while(next_to_play_max<n&&s1[i]>=s2[next_to_play_max])
    next_to_play_max++;
    if(next_to_play_max<n)
    cmp_max++;
    }
    cout<<n-cmp_min<<endl<<cmp_max<<endl;
    return 0;
}
