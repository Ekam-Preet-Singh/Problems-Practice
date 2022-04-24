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
Q351.) Graph ColouringProblem

INPUT:
2

5 7
0 1
1 3
2 3
0 2
2 4
1 4
0 4

5 6
0 1
1 3
2 3
0 2
2 4
1 4

OUTPUT:
Case #1:
3
0 1 1 0 2
Case #2:
2
0 1 1 0 0

*/

void solve()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    int res[v];
    bool available[v];
    res[0] = 0;

    for (int i = 1; i < v; i++)
    {
        res[i] = -1;
    }

    for (int i = 0; i < v; i++)
    {
        available[i] = false;
    }

    int cn = 0;
    for (int i = 1; i < v; i++)
    {
        for (auto X : g[i])
        {
            if (res[X] != -1)
            {
                available[res[X]] = true;
            }
        }
        int cr;
        for (cr = 0; cr < v; cr++)
        {
            if (available[cr] == false)
            {
                break;
            }
        }

        res[i] = cr;
        cn = max(cn, cr + 1);
        for (auto X : g[i])
        {
            if (res[X] != -1)
            {
                available[res[X]] = false;
            }
        }
    }
    cout << cn << endl;
    for (int i = 0; i < v; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
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