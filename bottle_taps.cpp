#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e6+10;
int n,m,dp[M];
bool mark[M];
vector<pair<int,int> >off;
int mem(int mask)
{
  if(mark[mask])
    return dp[mask];
  if(mask==0)
    return dp[mask]=0;
  mark[mask]=true;
  dp[mask]=M;
  for(auto p:off)
    if(p.first&mask)
      dp[mask]=min(dp[mask],mem(mask^(mask&p.first))+p.second);
  return dp[mask];
}
int32_t main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      off.push_back({(1<<i),x});
    }
  cin>>m;
  for(int i=0;i<m;i++)
    {
      int x,k,mask=0;
      cin>>x>>k;
      for(int j=0;j<k;j++)
	{
	  int a;
	  cin>>a;
	  mask|=(1<<(--a));
	}
      off.push_back({mask,x});
    }
  int k,mask=0;
  cin>>k;
  for(int i=1;i<=k;i++)
    {
      int a;
      cin>>a;
      mask|=(1<<(--a));
    }
  cout<<mem(mask)<<endl;
}
