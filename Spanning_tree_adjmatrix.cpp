#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, a[105][105];
bool unused[105];
vector < vector <int> > tree(105);
init(){
	cin >> n;
	for(int i = 1; i <= n; i++){ unused[i] = true; for(int j = 1; j <= n; j++) cin >> a[i][j];	}
}
void DFS(int u){
	unused[u] = false;
	for(int i = 1; i <= n; i++){
		if(a[u][i] && unused[i]){
			tree[u].push_back(i);
			tree[i].push_back(u);
			DFS(i);
		}
	}
}
int main(){
	init();
	DFS(1);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < tree[i].size(); j++){
			cout << tree[i][j] << " ";
		}
		cout << endl;
	}
}
