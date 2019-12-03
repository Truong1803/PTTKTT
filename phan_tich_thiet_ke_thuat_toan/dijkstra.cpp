#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> ii;
vector<vector<ii> > graph;//DSK
vector<lli > dist;
vector<lli > pre;
priority_queue<ii> pq;
lli n,m;
void dijkstra(lli s){
	dist.resize(n+1,999999999999999);
	pre.resize(n+1,s);
	dist[s]=0;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		lli u=pq.top().second;
		pq.pop();
		for(lli i=0;i<graph[u].size();i++){
			lli x=graph[u][i].first;
			lli dx=graph[u][i].second;
			if(dist[x]>dist[u]+dx){
				dist[x]=dist[u]+dx;
				pre[x]=u;
				pq.push(make_pair(-dist[x],x));
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	graph.resize(n+1);
	for(lli i=0;i<m;i++){
		lli u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back(make_pair(v,w));
		//graph[v].push_back(make_pair(u,w));
	}
	dijkstra(1);
	for(lli i=1;i<dist.size();i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	return 0;
}