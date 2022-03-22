#include<bits/stdc++.h>
using namespace std;
//pair<string, int> p[100000];
vector< pair<string, int>> v;
bool comp(pair<string, int> p1, pair<string, int> p2) {
	return p1.second < p2.second;
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		string str;
		int n;
		cin >> str >> n;
		v.push_back({ str,n });
		//cin >> p[i].first >> p[i].second;
	}
	//sort(p, p + n, comp);
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++)
	{
		//cout << p[i].first << '\n';
		cout << v[i].first << '\n';
	}
	
}