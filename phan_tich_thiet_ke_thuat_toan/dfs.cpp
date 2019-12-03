#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > matrix;
vector<int> visited;
vector<vector<int>> result;
int d1=0;
void DFS(int i){
	visited[i]=1;
	for(int j=0;j<matrix[i].size();j++){
		if(visited[matrix[i][j]]!=1){
			result[d1].push_back(matrix[i][j]);
			DFS(matrix[i][j]);
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	matrix.resize(n+1);
	visited.resize(n+1);
	result.resize(n+1);
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		matrix[x].push_back(y);
		//matrix[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(visited[i]!=1){
			result[d1].push_back(i);
			DFS(i);
			d1++;
		}
	}
	cout<<d1<<endl;
	for(int i=0;i<d1;i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}