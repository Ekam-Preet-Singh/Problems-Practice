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
Q303.) Distance of nearest cell having 1 in a binary matrix

INPUT:
2

3 4
0 1 1 0
1 1 0 0
0 0 1 1

3 3
1 0 1
1 1 0
1 0 0

OUTPUT:
Case #1:
1 0 0 1
0 0 1 1
1 1 0 0
Case #2:
0 1 0
0 0 1
0 1 2

*/

class Solution
{
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    // Function to check whether the cell is within the matrix bounds.
    bool isValid(int x, int y, int n, int m)
    {
        return (x >= 0 and x < n and y >= 0 and y < m);
    }

    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // queue to store the cell indexes which have grid value 1.
        queue<pair<int, int>> q;

        // using dp list which will store the output.
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        // traversing all the cells of the matrix.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // if grid value is 1, we update the dp value at same cell as 0
                // and push the cell indexes into queue.
                if (grid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            // storing the cell indexes at top of queue and popping them.
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // iterating over the adjacent cells.
            for (int i = 0; i < 4; i++)
            {
                int n_x = x + dx[i];
                int n_y = y + dy[i];
                if (isValid(n_x, n_y, n, m) and dp[n_x][n_y] > dp[x][y] + 1)
                {
                    // updating dp and pushing cell indexes in queue.
                    dp[n_x][n_y] = dp[x][y] + 1;
                    q.push({n_x, n_y});
                }
            }
        }
        // returning the dp list.
        return dp;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    vector<vector<int>> ans = obj.nearest(grid);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
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
        cout << "Case #" << case_num++ << ":\n";
        solve();
    }

    return 0;
}