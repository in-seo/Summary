#include<bits/stdc++.h>
using namespace std;

int n,house;
int visited[25][25];
int dx[] = { -1, 0, 1, 0 }; //ºÏ µ¿ ³² ¼­
int dy[] = { 0, 1, 0, -1 };

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	if (visited[x][y] == 0)
		return 0;
	int cnt = 1;
	visited[x][y] = 0;
	q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx >= 0 && my >= 0 && mx < n && my < n) {
				if (visited[mx][my] == 1) {
					visited[mx][my] = 0;
					cnt++;
					q.push({ mx,my });
				}
				if (mx == n && my == n)
					return cnt;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n; 
	string* str = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = str[i].at(j) - '0';
		}
	}

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int n = bfs(i, j);
			if (n > 0) {
				house++;
				v.push_back(n);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << house << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}