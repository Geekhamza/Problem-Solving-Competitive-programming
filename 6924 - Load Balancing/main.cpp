#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

vector<int> scores;
long long  n;
double sum(int i,int j,int k){


return abs(((n*1.0)/4.0)-scores[i])+abs(((n*1.0)/4.0)-(scores[j]-scores[i]))+abs(((n*1.0)/4.0)-(scores[k]-scores[j]))+abs(((n*1.0)/4.0)-(scores[160]-scores[k]));


}
int main()
{
        int t;
        scanf("%d",&t);
        for(int i=1;i<=t;i++){
        scores.clear();
        scores.resize(161);
        scanf("%lld",&n);
        for(long long  i=0;i<n;i++){
            long long x;
            scanf("%lld",&x);
            scores[x]++;
        }
        for(int i=1;i<=160;i++)scores[i]+=scores[i-1];
        iii res;
        double miin=(10000000.00);
        for(int i=1;i<=160;i++){
            for(int j=i+1;j<=160;j++){
                for(int k=j+1;k<=160;k++){
                double tmp=sum(i,j,k);
                    if(tmp<miin){
                        res.first=i,res.second.first=j,res.second.second=k,miin=tmp;
                    }
                }
            }
        }

        cout<<"Case "<<i<<": "<<res.first<<" "<<res.second.first<<" "<<res.second.second<<endl;
        }
    return 0;
}
