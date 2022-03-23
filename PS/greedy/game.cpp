#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int d;
int turnleft() {
	d++;
	if (d > 3)
		d = 0;
	return d;
}

int main() {
	int n, m,move=0;
	cin >> n >> m;  // n : 세로 , m : 가로
	int** coor = new int* [n];
	int x, y;
	cin >> x >> y >> d;
	
	/*
	1 1 1 1
	1 0 0 1
	1 1 0 1
	1 1 1 1
	*/
	int dx[4] = { -1,0,1,0 }; //세로
	int dy[4] = { 0,1,0,-1 }; //가로
	
	for (int i = 0; i < m; i++)
	{
		coor[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cin >> coor[i][j];
		}
	}
	coor[x][y] = 1;
	move++;
	int turnCnt = 0;
	while (true) {
		turnleft();
		turnCnt++;
		int tempX = x + dx[d];
		int tempY = y + dy[d];
		
		if (coor[tempX][tempY] == 0) {
			x = tempX;	y = tempY;
			move++;
			coor[x][y] = 1;
			std::cout << "x = " << x << "y = " << y << '\n';
		}
		else {
			if (turnCnt == 4) {
				x = x - dx[d];
				y = y - dy[d];
				if (coor[x][y] == 0) {
					move++;
					coor[x][y] = 1;
					turnCnt = 0;
				}
				else 
					break;
					
				}
					
			}
		}
	std::cout << move << endl;
	
	
}