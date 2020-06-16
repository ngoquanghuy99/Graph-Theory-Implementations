/*
Author: Ngo Quang Huy
Problem: Finding a path between two points in an undirected unweighted graph
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int const Max = 100001;
bool unused[Max];
int n, m, s, t;
vector <int> ke[Max];
int trace[Max];
void init(){
	int u, v;
	cin >> n >> m >> s >> t;
	for(int i=1; i<=m; i++){
		cin >> u >> v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
	for(int i=1; i<=n; i++)
		unused[i] = true;
}

void BFS(int u){
	queue <int> q;
	q.push(u);
	unused[u] = false;
	while(!q.empty()){
		u = q.front();
		q.pop();
	//	cout << u << " ";
		for(int i=0; i<ke[u].size(); i++){
			int v = ke[u][i];
			if(unused[v]){
				q.push(v);
				unused[v] = false;
				trace[v] = u;
			}
		}
	}
}

void Shortest_path(){
	int u = t;
	int p[Max];
	int d = 0;
	while(u!=s){
		p[++d] = u;
		u = trace[u];
	}
	d++;
	p[d] = s;
	for(int i=d; i>=1; i--)
		cout << p[i] << " "; 
}
int main(){
	init();
	BFS(s);
	Shortest_path();
}
