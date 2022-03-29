#include<bits/stdc++.h>
using namespace std;
int m, n,h;
int dx[6] = { 0, 1, 0, -1, 0 , 0 }; //ºÏ µ¿ ³² ¼­ À§ ¹Ø
int dy[6] = { -1, 0, 1, 0, 0, 0 };
int dh[6] = { 0,0,0,0, 1, -1 };
int tom[100][100][100];
queue<tuple<int, int, int>> q;

void bfs() {
	int x = get<0>(q.front());
	int y = get<1>(q.front());
	int z = get<2>(q.front());
	q.pop();
	for (int i = 0; i < 6; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];
		int mh = z + dh[i];
		if (mx >= 0 && my >= 0 && mh>=0 && mx < m && my < n && mh < h &&  tom[mh][my][mx] == 0 ) {
			tom[mh][my][mx] = tom[z][y][x] + 1;
			q.push({ mx,my,mh});
		}
	}
}

int main() {
	cin >> m >> n >> h;
	for (int f = 0; f < h; f++){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int num;
				cin >> num;
				if (num == 1) {
					q.push({ j, i, f});
				}
				tom[f][i][j] = num;
			}
		}
	}
	if (q.size() == 0) {
		cout << "-1";
		return 0;
	}
	else if (q.size() == m * n * h) {
		cout << "0";
		return 0;
	}
	while (!q.empty())
		bfs();
	int max = 0;
	bool pass = true;
	for (int f = 0; f < h; f++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (max < tom[f][i][j])
					max = tom[f][i][j];
				if (tom[f][i][j] == 0)
					pass = false;
			}
		}
	}

	if (pass)
		cout << max - 1;
	else
		cout << "-1";
}