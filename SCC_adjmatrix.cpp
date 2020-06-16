#include <iostream>
#include <stack>
#include <queue>

using namespace std;
int n, m, a[100][100];
bool unused[100];

void init(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
}

void reinit(){
	for(int i = 1; i <= n; i++) unused[i] = true;
}

void DFS(int u){
	unused[u] = false;
	for(int i = 1; i <= n; i++){
		int v = a[u][i];
		if(a[u][i] == 1 && unused[i])
			DFS(v);
	}
}

bool UnVisitedVertex(){
	for(int i = 1; i <= n; i++)
		if(unused[i]) return true;
	return false;
}
bool SCC(){
	init(); reinit();
	for(int i = 1; i <= n; i++){
		DFS(i);
		if(UnVisitedVertex()) return false;
		reinit();
	}
	return true;
}
int main(){
	if(SCC()) cout << "Strongly connected!";
	else cout << "Weakly connected!";
}
