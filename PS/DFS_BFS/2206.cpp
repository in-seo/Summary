#include<bits/stdc++.h>
#include "2206.h"
using namespace std;
queue<pair<int, int>> q;
int n, m;
int graph[1001][1001];
int dx[4] = { 0,1,0,-1 };//북 동 남 서
int dy[4] = { -1,0,1,0 };
bool crush[4] = { false, false, false, false };

void bfs() {
	int x = q.front().first;
	int y = q.front().second;
	q.pop();
	bool notMove = true;
	for (int i = 0; i < 4; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];
		if (mx >= 0 && my >= 0 && mx < m && my < n) {
			if (graph[my][mx] == 0) {
				q.push({ mx,my });
				graph[my][mx] = graph[y][x] + 1;
				notMove = false;
			}
		}
	}
	if (notMove) {
		for (int i = 0; i < 4; i++)
		{
			int mx = x + dx[i];
			int my = y + dy[i];
			if (mx >= 0 && my >= 0 && mx < m && my < n && !crush[i]) {
				q.push({ mx,my });
				graph[my][mx] = graph[y][x] + 1;
				crush[i] = true;
			} //먼저 도착한애가 당연히 최솟값이네
		}
	}
}




int main() {
	cin >> n >> m;  // n : 세로 , m : 가로
	string* str = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		for (int j = 0; j < m; j++)
		{
			graph[i][j] = str[i].at(j) - '0';
		}
	}
	q.push({ 0,0 });
	while (!q.empty())
		bfs();
	int temp = graph[n - 1][m - 1];
	cout << "\n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << graph[i][j];
		}
		cout << '\n';
	}
	if (graph[n - 1][m - 1] > 0)
		cout << graph[n - 1][m - 1];
	else
		cout << -1;
	
	

}