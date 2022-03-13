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

class Solution
{
public:
    int add(int a, int b)
    {
        return ((a % mod) + (b % mod)) % mod;
    }
    int FindWays(int n, int m, vector<vector<int>> blocked_cells)
    {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (auto i : blocked_cells)
        {
            int x = i[0];
            int y = i[1];
            matrix[x - 1][y - 1] = 1;
        }
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            if (!matrix[i][0])
            {
                dp[i][0] = 1;
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (!matrix[0][i])
            {
                dp[0][i] = 1;
            }
            else
            {
                break;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (!matrix[i][j])
                {
                    dp[i][j] = add(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> blocked_cells;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        blocked_cells.push_back({x, y});
    }
    Solution obj;
    int ans = obj.FindWays(n, m, blocked_cells);
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