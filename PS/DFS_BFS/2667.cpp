#include<bits/stdc++.h>
using namespace std;
int n;
int visited[25][25];

void bfs() {

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

	cout << bfs(0, 0);

}