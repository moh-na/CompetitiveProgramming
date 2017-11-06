//============================================================================
// Name : firstTrial.cpp
// Author :
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#define io  ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define file freopen("INPUT.txt", "r", stdin), freopen("OUTPUT.txt", "w", stdout);
using namespace std;
const int N = 2e5 + 20;
char str[N][5];
set<int> assign, temp;
vector<int> adj[N];
int out[N];
int main(){
	fill(out, out + N, 3);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		assign.insert(i);
		int m;
		scanf("%s%d", str[i], &m);
		for(int j = 0; j < m; j++){
			int x;
			scanf("%d", &x);
			adj[i].push_back(x);
		}
	}

	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(out[i] < 2)
			continue;


		assign.erase(assign.find(i));
		q.push(i);
		out[i] = 0;
		bool flag = 1;


		while(!q.empty()){
			int cur = q.front();
	//		cout << cur << endl;
			q.pop();

			if(str[cur][0] == 'C'){
				for(int i = 0; i < (int)adj[cur].size(); i++){
					auto it = assign.find(adj[cur][i]);
					if(it != assign.end()){
						flag = 0;
						assign.erase(it);
						out[*it] = 1 - out[cur];
						q.push(*it);
					}
				}
			}else{
				for(int i = 0; i < (int)adj[cur].size(); i++){
					auto it = assign.find(adj[cur][i]);
					if(it != assign.end()){
						temp.insert(*it);
						assign.erase(it);
					}
				}
				for(auto it = assign.begin(); it != assign.end(); it++){
					flag = 0;
					out[*it] = 1 - out[cur];
					q.push(*it);
				}
				assign.clear();
				for(auto it = temp.begin(); it != temp.end(); it++)
					assign.insert(*it);
				temp.clear();
			}
		}
		if(flag)
			out[i] = 3;
	}
	for(int i = 1; i <= n; i++)
		if(out[i] == 3)
			return printf("Impossible\n"), 0;


	for(int i = 1; i <= n; i++){
		if(out[i] == 1)
			printf("S");
		else
			printf("V");
	}
	printf("\n");
	return 0;
}
