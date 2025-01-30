#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+10;
int n,m,dp[M][20],g[20][20],ans;
bool mark[M][20];
int mem(int mask,int v)
{
  if(mark[mask][v])
    return dp[mask][v];
  mark[mask][v]=true;
  if(__builtin_popcount(mask)==2)
    {
      int s=__builtin_ctz(mask);
      int t=__builtin_ctz(mask^(1<<s));
      if(g[s][t])
	dp[mask][t]=1;
      return dp[mask][t];
    }
  for(int u=0;u<n;u++)
    if(g[u][v] && (mask&(1<<u)) && ((1<<u)&((mask-1)^mask))==0)
      dp[mask][v]+=mem(mask^(1<<v),u);
  return dp[mask][v];
}
int32_t main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
    {
      int u,v;
      cin>>u>>v;
      g[--v][--u]=1;
      g[u][v]=1;
    }
  for(int mask=0;mask<(1<<n);mask++)
    if(__builtin_popcount(mask)>2)
      {
	int st=__builtin_ctz(mask);
	for(int v=0;v<n;v++)
	  if((mask&(1<<v)) && g[st][v])
	    ans+=mem(mask,v);
      }
  cout<<ans/2<<endl;
}
