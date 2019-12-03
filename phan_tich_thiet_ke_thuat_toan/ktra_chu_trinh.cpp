#include <iostream>
#include <vector>
using namespace std;
int v,e;
int pre[1000],post[1000],Clock=1;
vector<int> visited;
vector<vector<int> > matrix;
void check(){
	int s=0;
	for(int i=1;i<=v;i++){
		for(int j=0;j<matrix[i].size();j++){
			if(pre[matrix[i][j]]<pre[i]&&pre[i]<post[i]&&post[i]<post[matrix[i][j]]){
				s=1;
				cout<<pre[matrix[i][j]]<<" "<<pre[i]<<" "<<post[i]<<" "<<post[matrix[i][j]]<<endl;
			}
		}
	}
	if(s==1)
		cout<<"co chu trinh"<<endl;
	else
		cout<<"ko co chu trinh"<<endl;
}
void previsit(int temp){
	pre[temp]=Clock;
	Clock++;
}
void postvisit(int temp){
	post[temp]=Clock;
	Clock++;
}
void dfs(int i){
	visited[i]=1;
	previsit(i);
	for(int j=0;j<matrix[i].size();j++){
		if(visited[matrix[i][j]]!=1)
			dfs(matrix[i][j]);
	}
	postvisit(i);
}
int main()
{
	cin>>v>>e;
	matrix.resize(v+1);
	visited.resize(v+1);
	for(int i=1;i<=e;i++){
		int x,y;cin>>x>>y;
		matrix[x].push_back(y);
	}
	for(int i=1;i<=v;i++){
		if(visited[i]!=1){
			dfs(i);
			
		}
	}
	for(int i=1;i<=v;i++)
		cout<<i<<"   ";
	cout<<endl;
	for(int i=1;i<=v;i++){
		cout<<pre[i]<<"   ";
	}
	cout<<endl;
	for(int i=1;i<=v;i++){
		cout<<post[i]<<"   ";
	}
	cout<<endl;
	check();
	/*for(int i=0;i<=v;i++){
		for(int j=0;j<matrix[i].size();j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}*/
	//check();
	return 0;
}