#include<bits/stdc++.h>
using namespace std;
int m, n;
int dx[4] = { 0, 1, 0, -1 }; //북 동 남 서
int dy[4] = { -1, 0, 1, 0 };
int visited[1000][1000];
int tom[1000][1000]; 
// 큐를 반환해서 더한다음 한 텀으로 묶어서 실행시키기

int bfs(int x, int y) {

	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[y][x] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx >= 0 && my >= 0 && mx < m && my < n && visited[my][mx] == 0 && tom[my][mx] == 0) {
				visited[my][mx] = 1;
				tom[my][mx] = tom[y][x]+1;
				q.push({ mx,my });
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < tom[i][j])
				max = tom[i][j];
		}
	}
	return max - 1;
}

int main() {
	cin >> m >> n;
	int max = 0;
	bool start = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int n;
			cin >> n;
			if (n == 0)
				start = true;  //첫 시작 시 모두 1 방지
			tom[i][j] = n;
		}
	}

	if (!start) {
		cout << "0";
		return 0;
	}
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 && tom[i][j]==1) {
				bfs(j, i);
			}
		}
	}
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tom[i][j] == 0) {
				cout << -1;
				return 0;
			}
			cout << tom[i][j] << " ";
		}
		cout << '\n';
	}

	

			
}