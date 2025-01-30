#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10,INF=1e9;
int dp[M][20],n,m,w[20][20],ans=INF;
bool mark[M][20],g[20][20];
int mem(int mask,int v)
{
  if(mark[mask][v])
    return dp[mask][v];
  mark[mask][v]=true;
  dp[mask][v]=INF;
  if(__builtin_popcount(mask)==2)
    {
      if(g[0][v])
	dp[mask][v]=w[0][v];
      return dp[mask][v];
    }
  for(int u=1;u<n;u++)
    if(g[u][v] && (mask&(1<<u)))
      dp[mask][v]=min(dp[mask][v],mem(mask^(1<<v),u)+w[u][v]);
  return dp[mask][v];
}
int32_t main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    {
      int s,t,d;
      cin>>s>>t>>d;
      g[s][t]=1;
      w[s][t]=d;
    }
  for(int v=1;v<n;v++)
    if(g[v][0])
      ans=min(mem((1<<n)-1,v)+w[v][0],ans);
  if(ans==INF)
    cout<<-1<<endl;
  else
    cout<<ans<<endl;
}
