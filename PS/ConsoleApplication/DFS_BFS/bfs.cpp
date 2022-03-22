#include <bits/stdc++.h>
using namespace std;
bool visited[9];
vector<int> graph[9];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front();
        cout << x << "�� �湮" << '\n';
        q.pop();
        visited[x] = true;

        for (int i = 0; i < graph[x].size(); i++)
        {
            if (visited[graph[x][i]] == false) {
                q.push(graph[x][i]);
                visited[graph[x][i]] = true;
            }
        }
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

    bfs(1);
}