/*
Author: Ngo Quang Huy
Problem: Counting the number of paths in an unweighted undirected graph
*/
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int const MAX = 1001;
int n, m;
vector <int>  ke[MAX];
bool unused[MAX];
void init(){
	cin >> n >> m;
	memset(unused, true, n);
	while (m--){
		int u, v; cin >> u >> v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
}
void DFS(int u){
	stack <int> s;
	s.push(u);
	cout<<u<<" ";
	unused[u] = false;
	while(!s.empty()){
		u = s.top();
		s.pop();
		for(int i=0; i<ke[u].size(); i++){
			int v;
			v = ke[u][i];
			if(unused[v]){
				cout<<v<<" ";
				unused[v] = false;
				s.push(u);
				s.push(v);
				break;
			}
		}
	}
}
int main(){
	int count = 0;
	init();
	for(int i=1; i<=n; i++)
		if(unused[i]){
			count++;
			cout<<"TPLT "<<count<<": ";
			DFS(i);
			cout<<endl;
		}
}
