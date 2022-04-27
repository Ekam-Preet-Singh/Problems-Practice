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
Q399.) Maximum Length Chain of Pairs

INPUT:
2

5
5 24 39 60 15 28 27 40 50 90

34
778 887 794 916 336 387 493
650 363 422 28 691 60 764 541
927 173 427 212 737 369 568 430
783 531 863 68 124 136 930 23 803
59 70 168 394 12 457 43 230 374 422
785 920 199 538 316 325 371 414 92 527
957 981 863 874 171 997 282 306 85 926
328 337 506 847 314 730

OUTPUT:
Case #1: 3
Case #2: 8

*/

struct val
{
    int first;
    int second;
};

bool cmp(struct val p1, struct val p2)
{
    if (p1.first < p2.first)
    {
        return 1;
    }
    else if (p1.first == p2.first and p1.second < p2.second)
    {
        return 1;
    }
    return 0;
}
int dp[100001];
int maxChainLen(struct val p[], int n)
{
    sort(p, p + n, cmp);

    for (int i = 0; i < 10001; i++)
    {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (p[i].first > p[j].second and dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        m = max(dp[i], m);
    }

    return m;
}

void solve()
{
    int n;
    cin >> n;
    val p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    cout << maxChainLen(p, n) << endl;
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