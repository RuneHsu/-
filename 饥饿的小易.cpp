// ref: http://www.nowcoder.com/test/question/done?tid=5245966&qid=45843#summary

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define MAX 100000
int main(){
    unordered_map<long long,int> vist;
    for(long long x;cin>>x;vist.clear()){
        queue<long long> q;
        for(long long xx=vist[x]=1,q.push(x);q.size();){
            x = q.front();
            q.pop();
            if (x==0) break;
            if (vist[x]>MAX) continue;           
            xx=((x<<2)+3)%MOD;
            if (vist.find(xx)==vist.end()) {
                q.push(xx);
                vist[xx]=vist[x]+1;
            }
            xx=((x<<3)+7)%MOD;
            if (vist.find(xx)==vist.end()){
                q.push(xx);
                vist[xx]=vist[x]+1;
            }
        }
        cout<<(q.size()?vist[x]-1:-1)<<endl;
    }
    return 0;
}


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
 
const int mod=1e9+7;
 
int main(){
    int n;
    while(~scanf("%d",&n)){
        int times=4;
        int ans=100001;
        for(int i=1;i<=300000;++i){
            int x=((long long)(n)*times+times-1)%mod;
            if(x==0){
                ans=(i+1)/3+((i+1)%3?1:0);
                break;
            }
            times=times*2%mod;
        }
        printf("%d\n",ans>100000?-1:ans);
    }
    return 0;
}
