#include <bits/stdc++.h>
using namespace std;
const int N = 25;
char a[N][N];
int cnt;
bool vis[N][N];
int n, m;
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int ci, int cj)
{
    if (ci >= 0 && cj >= 0 && ci < n && cj < m)
        return true;
    else
        return false;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (pair<int, int> child : v)
    {
        int ci = si + child.first;
        int cj = sj + child.second;
        if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
};
int main()
{
    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {

        cin >> m >> n;

        int si, sj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '@')
                {
                    si = i;
                    sj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        cnt = 0;
        dfs(si, sj);
        cout << "Case " << cs++ << ": " << cnt << endl;
    }

    return 0;
}