#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int n;
	int x = 1, y = 1;
	string move;
	
	cin >> n;
	cin.ignore();
	getline(cin, move); // R R R U D D

	for (int i = 0; i < move.length(); i++)
	{
		char next = move[i];
		if (next == 'R') {
			if (y < n)
				y += 1;
		}
		else if (next == 'D') {
			if (x < n)
				x += 1;
		}
		else if (next == 'L') {
			if (y > 1)
				y -= 1;
		}
		else if (next == 'U') {
			if (x > 1)
				x -= 1;
		}
	}
	cout << x << " " << y;
}