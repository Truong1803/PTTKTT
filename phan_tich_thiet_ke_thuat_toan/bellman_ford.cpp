#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef tuple<lli,lli,lli> ii;
vector<ii> graph;
vector<lli> dist;
vector<lli> visited;
vector<vector<lli> > dsk;
lli n,m;
void update(lli u,lli v,lli d){
	dist[v]=min(dist[v],dist[u]+d);
}
void dfs(lli u){
	if(u==n){
		cout<<-1<<endl;
		exit(0);
	}
	visited[u]=1;
	for(int i=0;i<dsk[u].size();i++){
		if(visited[dsk[u][i]]!=1)
			dfs(dsk[u][i]);
	}
}
lli bellman_ford(){
	dist[1]=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(dist[get<0>(graph[j])]!=9999999999999999)
				update(get<0>(graph[j]),get<1>(graph[j]),get<2>(graph[j]));
		}
	}
	lli check=0;
	lli x1=dist[n];
	for(int i=0;i<m;i++){
		lli x=dist[get<1>(graph[i])];
		if(dist[get<0>(graph[i])]!=9999999999999999)
			update(get<0>(graph[i]),get<1>(graph[i]),get<2>(graph[i]));
		if(x!=dist[get<1>(graph[i])]){
			dfs(get<0>(graph[i]));
		}
	}
	cout<<-dist[n]<<endl;
}
int main()
{
	cin>>n>>m;
	dsk.resize(n+1);
	visited.resize(n+1,0);
	dist.resize(n+1,9999999999999999);
	for(int i=0;i<m;i++){
		lli u,v,w;cin>>u>>v>>w;
		graph.push_back(make_tuple(u,v,-w));
		dsk[u].push_back(v);
	}
	bellman_ford();
	return 0;
}