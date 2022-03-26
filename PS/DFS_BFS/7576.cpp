#include<bits/stdc++.h>
using namespace std;
int m, n;
int dx[4] = { 0, 1, 0, -1 }; //ºÏ µ¿ ³² ¼­
int dy[4] = { -1, 0, 1, 0 };
int visited[1000][1000];
int tom[1000][1000]; 

queue<pair<int, int>> q;

void bfs() {
	int x = q.front().first;
	int y = q.front().second;
	visited[y][x] = 1;
	q.pop();
	for (int i = 0; i < 4; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];
		if (mx >= 0 && my >= 0 && mx < m && my < n && visited[my][mx] == 0 && tom[my][mx] == 0) {
			visited[my][mx] = 1;
			tom[my][mx] = tom[y][x] + 1;
			q.push({ mx,my });
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k;
			cin >> k;
			if (k == 1) {
				q.push({ j, i });
			}
			tom[i][j] = k;
		}
	}
	if (q.size() == 0) {
		cout << "-1";
		return 0;
	}
	else if (q.size() == m*n) {
		cout << "0";
		return 0;
	}
	while (!q.empty())
		bfs();
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < tom[i][j])
				max = tom[i][j];
		}
	}

	bool pass = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tom[i][j] == 0)
				pass = false;
		}
	}
	if (pass)
		cout << max - 1;
	else
		cout << "-1";
}