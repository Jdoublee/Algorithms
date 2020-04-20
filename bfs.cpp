#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void bfs(int s,vector<int> graph[],bool visited[]){
	queue<int> q;
	
	q.push(s);
	visited[s]=true;
	
	while(!q.empty()){
		int start=q.front();
		q.pop();
		cout<<start<<" ";
		
		for(int i=0;i<graph[start].size();i++){
			int next=graph[start][i];
			
			if(!visited[next]){
				q.push(next);
				visited[next]=true;
			}
		}
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
	
	bfs(v,graph,visited);
	cout<<"\n";
	
	return 0;
}