#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(int s,vector<int> graph[],bool visited[]){
	visited[s]=true;
	cout<<s<<" ";
	
	for(int i=0;i<graph[s].size();i++){
		int next=graph[s][i];
		
		if(!visited[next])
			dfs(next,graph,visited);
	}
}
int main() {
	int n,m,v;
	cin>>n>>m>>v;
	
	vector<int> graph[n+1];
	bool visited[n+1];
	fill(visited,visited+(n+1),false);//bool false로 값 초기화
	
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for(int i=0;i<n;i++)
		sort(graph[i+1].begin(),graph[i+1].end());//순차적 접근 위해 정렬
	
	dfs(v,graph,visited);
	cout<<"\n";
	
	return 0;
}