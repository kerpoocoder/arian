#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5;
int n,dp[M],cnt;
bool mark[M];
int mem(int mask)
{
  if(mark[mask])
    return dp[mask];
  mark[mask]=true;
  dp[mask]=n+1;
  for(int submask=mask;submask;submask=mask&(submask-1))
    dp[mask]=min(dp[mask],mem(submask)+mem(mask^submask));
  return dp[mask];
}
void update(int mask)
{
  if(mark[mask])
    return;
  mark[mask]=true;
  dp[mask]=1;
  for(int i=0;i<16;i++)
    if((mask&(1<<i)))
      update(mask^(1<<i));
}
int32_t main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    {
      int x;
      cin>>x;
      if(x==0)
	cnt++;
      update(((1<<16)-1)^x);
    }
  if(cnt!=0)
    {
      cout<<n-cnt<<endl;
      return 0;
    }
  //cout<<mem((1<<16)-1)<<endl;
  cout<<mem((1<<16)-1)-1+n-1<<endl;
}
