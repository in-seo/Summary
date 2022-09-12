#include<bits/stdc++.h>
using namespace std;
int c, n;  //���� ����
int dx[4] = { 0, 1, 0, -1 };//�� �� �� ��
int dy[4] = { -1, 0, 1, 0 };

void bfs(bool visited[50][50], int graph[50][50], int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = true;
	while (!q.empty()) {
		x= q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx >= 0 && my >= 0 && mx < c && my < n) {
				if (!visited[my][mx] && graph[my][mx] == 1) {
					visited[my][mx] = true;
					q.push({ mx, my });
				}
			}
		}
	}
}

int main() {
	int T,k;
	cin >> T;
	for (int p = 0; p < T; p++)  //T�� ����
	{
		cin >> c >> n >> k;
		int result = 0;
		int graph[50][50]={0};
		bool visited[50][50] = { false };
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			graph[y][x] = 1;  //�ʱ� ���� ����
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (!visited[i][j] && graph[i][j]==1) {
					bfs(visited, graph, j, i);
					result++;
				}
			}
		}
		cout << result << '\n';
	}
}