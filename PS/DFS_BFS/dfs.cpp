#include <bits/stdc++.h>
using namespace std;


vector<int> graph[9];
bool visitDfs[9];

void dfs(int x) {
    visitDfs[x] = true;
    cout << x << "�� �湮" <<'\n';

    for (int i = 0; i < graph[x].size(); i++)
    {
        cout << graph[x][i] << "�� üũ��" << '\n';
        if (visitDfs[graph[x][i]] == false) {
            cout << graph[x][i] << "�� üũ��" << '\n';
            dfs(graph[x][i]);
        }
        else
            cout << graph[x][i] << "�� �н�" << '\n';
         
    }
}
int main() {
	
    // ��� 1�� ����� ��� ���� ���� 
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    // ��� 2�� ����� ��� ���� ���� 
    graph[2].push_back(1);
    graph[2].push_back(7);

    // ��� 3�� ����� ��� ���� ���� 
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    // ��� 4�� ����� ��� ���� ���� 
    graph[4].push_back(3);
    graph[4].push_back(5);

    // ��� 5�� ����� ��� ���� ���� 
    graph[5].push_back(3);
    graph[5].push_back(4);

    // ��� 6�� ����� ��� ���� ���� 
    graph[6].push_back(7);

    // ��� 7�� ����� ��� ���� ���� 
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    // ��� 8�� ����� ��� ���� ���� 
    graph[8].push_back(1);
    graph[8].push_back(7);

    dfs(1);


}