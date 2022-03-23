#include<bits/stdc++.h>
using namespace std;
int n, m;
int visited[201][201];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x, y });
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx <= 0 || my <= 0 || mx > n || mx > m)
				continue;
			if (visited[mx][my] == 1) {
				cout << "x= " << mx << "y= " << my << "방문,  값 : ";
				q.push({ mx,my });
				visited[mx][my] = visited[x][y] + 1;
				cout << visited[mx][my] << '\n';
			}
			if (mx == n && my == m)
				return visited[mx][my];
		}
	}
	return visited[n - 1][m - 1];
}


int main() {
	cin >> n >> m;  // n : 세로 , m : 가로
	int** coor = new int* [n];
	string* str = new string[n];
	/*
	5 6
	101010
	111111
	000001
	111111
	111111
	*/
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i-1];
		for (int j = 1; j <= m; j++)
		{
			visited[i][j] = str[i-1].at(j-1) - '0';
		}
	}
	cout << bfs(1, 1);
}