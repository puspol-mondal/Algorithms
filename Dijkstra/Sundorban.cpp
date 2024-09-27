#include <bits/stdc++.h>
using namespace std;
char a[50][50];
bool vis[50][50];
int dis[50][50];
int n;
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int ci, int cj)
{
    if (ci >= 0 && cj >= 0 && ci < n && cj < n)
        return true;
    else
        return false;
};

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        for (pair<int, int> child : v)
        {
            int ci = par.first + child.first;
            int cj = par.second + child.second;

            if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] != 'T')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;
            }
        }
    }
};
int main()
{
    while (cin >> n)
    {
        int si, sj;
        int di, dj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (a[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }

        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        cout << dis[di][dj];
    }

    return 0;
}