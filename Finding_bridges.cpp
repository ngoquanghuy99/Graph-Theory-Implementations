/*
Author: Ngo Quang Huy
Problem:
*/
#include <iostream>
#include <cstring>
#define FOR(i,a,b) for(int i=a; i<=b; i++)


using namespace std;

int n, m, dem;
const int Max = 1001;
bool unused[Max];
int a[Max][Max];

void init(){
	cin >> n;
	FOR(i,1,n)
		FOR(j,1,n)
			cin >> a[i][j];
	/* 
	Or we can use this way:
	int u, v;
	while(cin >> u >> v){
		a[u][v] = 1;
		a[v][u] = 1;
	}
	FOR(i,1,n) unused[i] = true;
	*/
	
}
void DFS(int u){
	unused[u] = false;
	FOR(v,1,n)
		if(a[u][v]==1 && unused[v])
			DFS(v);
}

bool check(){
	FOR(i,1,n) if(unused[i]) return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	init(); memset(unused, true, sizeof(unused));
	FOR(i,1,n-1)
		FOR(j,i+1,n)
			if(a[i][j] == 1){
				a[i][j] = 0;
				a[j][i] = 0;
				DFS(1);
				check() ? cout << i << " " << j << " is a bridge!" << endl : cout << "";
				a[i][j] = 1; a[j][i] = 1;
				memset(unused, true, sizeof(unused));
			}
	return 0;
}
