#include <iostream>
#include <queue>

using namespace std;

void BFS(int vertex, int A[][8], int n)
{
    queue<int> q;
    int visited[8] = {0};
    cout << vertex << " ";
    visited[vertex] = 1;
    q.emplace(vertex);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v <= n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                cout << v << " ";
                visited[v] = 1;
                q.emplace(v);
            }
        }
    }
    cout << endl;
}

int main()
{
    int A[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 1, 0, 0, 0},
                    {0, 1, 0, 1, 0, 0, 0, 0},
                    {0, 1, 1, 0, 1, 1, 0, 0},
                    {0, 1, 0, 1, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1, 0, 1, 1},
                    {0, 0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 1, 0, 0}};
    
    BFS(0,A,8);
    return 0;
}