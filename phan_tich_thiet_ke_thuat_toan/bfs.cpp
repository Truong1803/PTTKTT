#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
queue <int> q;
vector<int> dist;

int v,e,s;
void BFS(int s)
{
    dist.resize(v+1,9999);
    dist[s]=0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i=0;i<graph[u].size();i++){
            if (dist[graph[u][i]]==9999){
                dist[graph[u][i]]=dist[u]+1;
                q.push(graph[u][i]);
            }
        }
    }
}
int main()
{
    cin>>v>>e>>s;
    graph.resize(e+1);
    for (int i=1; i<=e; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    BFS(s);
    for(int i=1;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}