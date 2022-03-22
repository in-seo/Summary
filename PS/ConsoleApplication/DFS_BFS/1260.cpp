#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1001];

void dfs(int x) {

}  //정렬까지 배우고 시작하자.

int main() {
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);  //(1,2) (1,3), (1,4), (2,4), (3,4)
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << '('<< i << ", " << graph[i][j] << ')';
		}
		cout << "\n";
	}
}