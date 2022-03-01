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
Q108.) Rasta and Kheshtak

INPUT:
1

3 3
1 2 0
1 2 1
1 2 3
3 3
0 1 2
1 1 2
3 1 2

OUTPUT:
Case #1: 2

*/

void solve()
{
    int n1, m1, n2, m2, i, r, c, ans = 0;
    long long ts = 1000, ml = 1000000, mr = 1000000000, nr;
    cin >> n1 >> m1;
    unordered_map<long long, vector<pair<int, int>>> d;
    int a[n1][m1];
    for (r = 0; r < n1; r++)
        for (c = 0; c < m1; c++)
            cin >> a[r][c];
    for (r = 1; r < n1; r++)
    {
        for (c = 1; c < m1; c++)
        {
            nr = a[r - 1][c - 1] * mr + a[r - 1][c] * ml + a[r][c - 1] * ts + a[r][c];
            if (d.count(nr))
                d[nr].push_back(make_pair(r, c));
            else
                d[nr] = {make_pair(r, c)};
        }
    }
    ans = 0;
    int mem[m1][n1];
    for (r = 0; r < n1; r++)
        for (c = 0; c < m1; c++)
            mem[r][c] = 0;
    cin >> n2 >> m2;
    int b[n2][m2];
    for (r = 0; r < n2; r++)
        for (c = 0; c < m2; c++)
            cin >> b[r][c];
    for (r = 1; r < n2; r++)
    {
        for (c = 1; c < m2; c++)
        {
            nr = b[r - 1][c - 1] * mr + b[r - 1][c] * ml + b[r][c - 1] * ts + b[r][c];
            if (d.count(nr))
                for (auto pr : d[nr])
                    mem[pr.first][pr.second] = 1;
        }
    }
    // identify maximum square of 2 size squares, so answer + 1
    for (r = 1; r < n1; r++)
    {
        for (c = 1; c < m1; c++)
        {
            if (mem[r][c])
            {
                mem[r][c] = 1 + min(mem[r][c - 1], min(mem[r - 1][c - 1], mem[r - 1][c]));
                if (mem[r][c] > ans)
                    ans = mem[r][c];
            }
        }
    }
    cout << ans + 1 << '\n';
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