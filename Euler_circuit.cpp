/*
Author: Ngo Quang Huy
Problem: Finding Euler circuit
*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int a[100][100];
	stack <int> S;
	vector <int> CE;
	int n, st;
	cin >> n >> st;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n; j++){
			cin >> a[i][j];
		}
	}
	S.push(st);
	while (!S.empty()){
		int u = S.top();
		int flag = 0;
		for(int v = 1; v <= n; v++){
			if(a[u][v] == 1){
				S.push(v);
				a[u][v] = 0;
				a[v][u] = 0;
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			S.pop();
			CE.push_back(u);
		}
	}
	cout << endl;
	for(vector <int>::reverse_iterator rit = CE.rbegin(); rit != CE.rend(); rit++)
		cout << *rit << " ";
}
