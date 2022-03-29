#include<bits/stdc++.h>
using namespace std;
int graph[300][300] = { 0 };
int l, m, n, arriveX, arriveY;
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };


int bfs(int startX, int startY) {
	graph[startY][startX] = 1;
	queue<pair<int, int>> q;
	q.push({ startX,startY });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx >= 0 && my >= 0 && mx < l && my < l) {
				if (graph[my][mx] == 0) {
					graph[my][mx] = graph[y][x] + 1;
					q.push({ mx,my });
					if (mx == arriveX && my == arriveY)
						return graph[arriveY][arriveX]-1;
				}
			}
		}
	}
	return graph[arriveY][arriveX]-1;
}

int main() {
	int T;
	cin >> T;
	for (int p = 0; p < T; p++)
	{
		cin >> l;
		cin >> m >> n;
		cin >> arriveX >> arriveY;
		
		cout << bfs(m, n)<<'\n';
		for (int i = 0; i < l; i++)
			for (int j = 0; j < l; j++)
				graph[i][j]=0;
	}
}