#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	bool minus = false;
	string num = "";
	int sum = 0;
	cout << str.length()<<'\n';
	cout << str.size()<<'\n';
	for (int i = 0; i <= str.length(); i++)
	{
		
		
		if (str[i] == '+' || str[i] == '-' || i == str.length())
		{
			if (minus) {
				sum -= stoi(num);
			}
			else
				sum += stoi(num);
			num = "";
		}
		else
			num += str[i];

		if (str[i] == '-')
			minus = true;
		cout << sum << '\n';
	}
	cout << sum;

}