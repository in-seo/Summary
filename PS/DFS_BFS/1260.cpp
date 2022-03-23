#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1001];
bool visitDfs[1001];
bool visitBfs[1001];

void dfs(int x) {
	visitDfs[x] = true;
	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++)
	{
		//cout << '(' << x << ", " << graph[x][i] << ')' << '\n';
		if (!visitDfs[graph[x][i]]) {
			dfs(graph[x][i]);
		}
	}
}  
void bfs(int x){
	queue<int> q;
	q.push(x);   //3
	visitBfs[x] = true;
	while (!q.empty()) {
		int n = q.front();
		cout << n << " ";
		q.pop(); // 4
		for (int i = 0; i < graph[n].size(); i++)
		{
			//cout << '(' << n << ", " << graph[n][i] << ')' << '\n';
			if (!visitBfs[graph[n][i]]) {
				q.push(graph[n][i]); //1 4
				visitBfs[graph[n][i]] = true;
			}
		}
	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);  //(1,2) (1,3), (1,4), (2,4), (3,4)
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
		
	dfs(v);
	cout << '\n';
	bfs(v);
}
