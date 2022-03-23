#include<bits/stdc++.h>
using namespace std;
int n, m;
bool visited[1001][1001];


bool dfs(int x, int y) {

	if (x <= -1 || x >= n || y <= -1 || y >= m)
		return false;

	if (visited[x][y] == 0) {
		visited[x][y] = 1;
		cout << "x = " << x << "y = " << y << "진입" << '\n';
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		return true;
	}

	return false;
}

int main() {
	cin >> n >> m;  // n : 세로 , m : 가로
	int** coor = new int* [n];
	string *str= new string[n];
	/*
	4 5
	00110
	00011
	11111
	00000
	*/
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = str[i].at(j) - '0';
		}
	}
	
	int ice = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dfs(i, j)) {
				ice++;
				cout << ice << "추가\n";
			}
		}
	}
	cout << ice;
}