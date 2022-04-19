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
Q246.) CHOCOLA – Chocolate

INPUT:
1

6 4
2 1 3 1 4
4 1 2

OUTPUT:
Case #1: 42

*/

bool comp(ll a, ll b) { return a > b; }

ll x[1001], y[1001], dp[1001][1001];

void solve()
{
    ll i, j, m, n;
    cin >> m >> n;
    m--;
    n--;
    for (i = 1; i <= m; i++)
        cin >> x[i];
    for (i = 1; i <= n; i++)
        cin >> y[i];
    sort(x + 1, x + 1 + m, comp);
    sort(y + 1, y + n + 1, comp);
    dp[0][0] = 0;
    for (i = 1; i <= m; i++)
        dp[i][0] = x[i] + dp[i - 1][0];
    for (i = 1; i <= n; i++)
        dp[0][i] = y[i] + dp[0][i - 1];
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            ll t1 = dp[i - 1][j] + x[i] * (j + 1);
            ll t2 = dp[i][j - 1] + y[j] * (i + 1);
            dp[i][j] = min(t1, t2);
        }
    }
    cout << dp[m][n] << endl;
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