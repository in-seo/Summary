#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n,cnt=0;
	cin >> n;  //23			0 0~59 59

	for (int i = 0; i <= n; i++)
	{
		if (to_string(i).find('3') != string::npos) {
			cnt += 3600;
			std::cout << "½ÇÇà" << '\n';
			continue;
		}	
		for (int j = 0; j < 60; j++)
		{
			if (to_string(j).find('3') != string::npos) {
				cnt += 60;
				continue;
			}
			for (int k = 0; k < 60; k++) {
				if (to_string(k).find('3') != string::npos) {
					cnt += 1;
				}
			}
		}
	}
	std ::cout << cnt << endl;


}