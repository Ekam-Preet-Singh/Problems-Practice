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
Q302.) Minimum time required to rot all oranges

INPUT:
2

3 3
0 1 2
0 1 2
2 1 1

10 9
2 1 1 1 2 1 2 0 2
1 2 1 1 2 1 1 2 2
2 2 1 2 2 1 1 2 1
1 0 2 0 1 2 2 1 0
2 0 0 2 2 2 2 0 2
2 1 1 1 2 0 2 1 2
2 2 1 1 0 0 1 2 2
0 2 0 2 2 2 2 2 1
2 0 2 0 1 2 2 2 2
1 1 1 2 0 1 2 2 2

OUTPUT:
Case #1: 1
Case #2: 2

*/

class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        int ct = 0, res = -1;
        // queue to store cells which have rotten oranges.
        queue<vector<int>> q;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // traversing over all the cells of the matrix.
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // if grid value is more than 0, we increment the counter.
                if (grid[i][j] > 0)
                {
                    ct++;
                }
                // if grid value is 2, we push the cell indexes into queue.
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            // incrementing result counter.
            res++;
            int size = q.size();
            for (int k = 0; k < size; k++)
            {
                // popping the front element of queue and storing cell indexes.
                vector<int> cur = q.front();
                ct--;
                q.pop();

                // traversing the adjacent vertices.
                for (int i = 0; i < 4; i++)
                {
                    int x = cur[0] + dir[i][0], y = cur[1] + dir[i][1];

                    // if cell indexes are within matrix bounds and grid value
                    // is not 1, we continue the loop else we store 2 in current
                    // cell and push the cell indexes in the queue.
                    if (x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0 || grid[x][y] != 1)
                    {
                        continue;
                    }
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
        // returning the minimum time.
        if (ct == 0)
        {
            return max(0, res);
        }
        return -1;
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
    int ans = obj.orangesRotting(grid);
    cout << ans << "\n";
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