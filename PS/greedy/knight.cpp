#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Move {
public:
	int x;
	int y;

	Move(int a, int b) {
		x = a;
		y = b;
	};
};
int main() {
	string str;
	getline(cin, str);
	int x, y,cnt=0;
	x = str.at(0) - 'a' + 1;
	y = str.at(1) - '0';

	Move move[8] = { Move(2,1),Move(2,-1),Move(-2,1),Move(-2,-1),Move(1,2),Move(1,-2),Move(-1,2),Move(-1,-2) };
	cout << "x=" << x << " " << "y=" << y << '\n';

	for (int i = 0; i < 8; i++)
	{
		cout << "x= " << move[i].x << " " << move[i].y << '\n';
	}

	for (int i = 0; i < 8; i++)
	{
		int tempx = x + move[i].x;
		int tempy = y + move[i].y;
		if (tempx > 0 && tempx < 9 && tempy>0 && tempy < 9) {
			cout << tempx << "  " << tempy << '\n';
			cnt++;
		}
			
		
	}	
	

	cout << cnt << endl;

}
