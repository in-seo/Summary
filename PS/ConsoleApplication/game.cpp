#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Coordinate {
public:
	int x;
	int y;
	int bl;

	/*Coordinate(int a, int b) {
		x = a;
		y = b;
	};*/
};

int nextmove(int direction) {
	direction++;
	if (direction > 3)
		direction = 0;
	return direction;
}

int main() {
	int n, m,cnt=0;
	cin >> n >> m;  // n : 가로 , m : 세로
	int x, y, d;
	cin >> x >> y >> d;
	Coordinate** coor = new Coordinate*[m];
	/*
	1 1 1 1
	1 0 0 1
	1 1 0 1
	1 1 1 1
	*/
	for (int i = 0; i < m; i++)
	{
		coor[i] = new Coordinate[n];
		for (int j = 0; j < n; j++)
		{
			cin >> coor[i][j].bl;     
		}
	}
	
	coor[x][y].bl = true;
	cnt++;  //start
	int direction = nextmove(d);
	while (true) {
		bool possible = false;
		if (direction == 0) {
			if (coor[x - 1][y].bl == 0) {
				coor[x - 1][y].bl = 1;
				x -= 1;
				cnt++;
				possible = true;
			}
				direction = nextmove(direction);
		}
		else if (direction == 1) {
			if (coor[x][y+1].bl == 0) {
				coor[x][y + 1].bl = 1;
				y -= 1;
				cnt++;
				possible = true;
			}
			direction = nextmove(direction);
		}
		else if (direction == 2) {
			if (coor[x+1][y].bl == 0) {
				coor[x+1][y].bl = 1;
				x +=1 ;
				cnt++;
				possible = true;
			}
			direction = nextmove(direction);
		}
		else if (direction == 3) {
			if (coor[x][y-1].bl == 0) {
				coor[x][y-1].bl = 1;
				y-=1;
				cnt++;
				possible = true;
			}
			direction = nextmove(direction);
		}
		if(!possible)

	}
	
	
}