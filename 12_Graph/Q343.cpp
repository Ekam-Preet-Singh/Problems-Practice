#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define all(n) n.begin(), n.end()
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define bitc(n) __builtin_popcount(n)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define iter(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;
template <typename T>
T gcd(T a, T b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
vs tokenizer(string str, char ch)
{
    std::istringstream var((str));
    vs v;
    string t;
    while (getline((var), t, (ch)))
    {
        v.pb(t);
    }
    return v;
}

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Q343.) Find the no. of Isalnds

INPUT:
2

4 2
0 1
1 0
1 1
1 0

9 3
0 1 0
0 1 0
0 0 0
1 1 0
1 0 1
0 1 1
1 1 1
0 1 1
1 0 1

OUTPUT:
Case #1: 1
Case #2: 2

*/

class Solution
{
public:
    // these lists are used to get row and column numbers of 8
    // neighbours of a given cell.
    vector<int> dx = {-1, 0, 1, 0, 1, -1, -1, 1};
    vector<int> dy = {0, -1, 0, 1, 1, 1, -1, -1};

    bool isValid(int x, int y, int n, int m)
    {
        return (x >= 0 and x < n and y >= 0 and y < m);
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // boolean array to mark visited cells.
        // initially all cells are unvisited.
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // using queue for BFS.
        queue<pair<int, int>> q;
        int ans = 0;

        // traversing over all cells of given matrix.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // if cell is unvisited and grid value is 1, we increment the
                // count and mark it as visited.
                if (!vis[i][j] and grid[i][j] == '1')
                {
                    ans++;
                    vis[i][j] = true;

                    // pushing it into the queue.
                    q.push({i, j});
                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 8; k++)
                        {
                            // if row and column number is in range, grid value
                            // is 1 and cell is not yet visited,
                            if (isValid(x + dx[k], y + dy[k], n, m) and !vis[x + dx[k]][y + dy[k]] and grid[x + dx[k]][y + dy[k]] == '1')
                            {
                                // we push the cell in queue and mark it
                                // visited.
                                q.push({x + dx[k], y + dy[k]});
                                vis[x + dx[k]][y + dy[k]] = true;
                            }
                        }
                    }
                }
            }
        }
        // returning the result.
        return ans;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '#'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    int ans = obj.numIslands(grid);
    cout << ans << '\n';
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    file_i_o();

    ll t = 1;
    ll case_num = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}