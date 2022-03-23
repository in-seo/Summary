#include<bits/stdc++.h>
using namespace std;

int n, m;
int visited[101][101];
int dx[4] = {-1,0,1,0};//�� �� �� ��
int dy[4] = {0,1,0,-1};

int bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx >= 0 && my >= 0 && mx < n && my < m) {
				if (visited[mx][my] == 1) {
					q.push({ mx,my });
					visited[mx][my] = visited[x][y] + 1;
				}
				if (mx == n && my == m)
					return visited[n - 1][m - 1];
			}
			
		}
	}
	return visited[n - 1][m - 1];
}

int main() {
	cin >> n >> m;  // n : ���� , m : ����
	string* str = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = str[i].at(j) - '0';
		}
	}

	cout << bfs(0, 0);

}