#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=110,INF=1e15;
int a[M][M],dp[M][M],n,m;
int32_t main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(i!=j)
	a[i][j]=INF;
  for(int i=1;i<=m;i++)
    {
      int u,v,w;
      cin>>u>>v>>w;
      a[u][v]=w;
    }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      dp[i][j]=a[i][j];
  
  for(int k=0;k<n;k++)
    for(int u=0;u<n;u++)
      {
	if(dp[u][k]+dp[k][u]<0)
	  return cout<<"NEGATIVE CYCLE"<<endl,0;
	for(int v=0;v<n;v++)
	  if(dp[u][k]<INF && dp[k][v]<INF)
	    dp[u][v]=min(dp[u][v],dp[u][k]+dp[k][v]);
      }

  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  if(dp[i][j]==INF)
	    cout<<"INF";
	  else
	    cout<<dp[i][j];
	  if(j!=n-1)
	    cout<<" ";
	}
      //if(i!=n-1)
	cout<<endl;
    }
}
