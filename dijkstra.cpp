#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e5+10,INF=1e9;
int n,m,dis[M],r;
bool mark[M];
vector<pair<int,int> >g[M];
set<pair<int,int> >s;
void dijkstra(int R)
{
  fill(dis,dis+n,INF);
  dis[R]=0;
  s.insert({0,R});
  while(s.size())
    {
      auto p=*s.begin();
      s.erase(p);
      int v=p.second;
      mark[v]=true;
      for(auto x:g[v])
	{
	  int u=x.first,w=x.second;
	  if(!mark[u] && dis[u]>dis[v]+w)
	    {
	      s.erase({dis[u],u});
	      dis[u]=dis[v]+w;
	      s.insert({dis[u],u});
	    }
	}
    }
}
int32_t main()
{
  cin>>n>>m>>r;
  for(int i=1;i<=m;i++)
    {
      int u,v,w;
      cin>>u>>v>>w;
      g[u].push_back({v,w});
      //g[v].push_back({u,w});
    }
  dijkstra(r);
  for(int i=0;i<n;i++)
    if(dis[i]==INF)
      cout<<"INF"<<endl;
    else
      cout<<dis[i]<<endl;
}
