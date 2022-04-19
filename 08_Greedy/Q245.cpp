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
Q245.) Picking Up Chicks

INPUT:
3

5 3 10 5
0 2 5 6 7
1 1 1 1 4

5 3 10 5
0 2 3 5 7
2 1 1 1 4

5 3 10 5
0 2 3 4 7
2 1 1 1 4

OUTPUT:
Case #1: 0
Case #2: 2
Case #3: IMPOSSIBLE

*/

void solve()
{
    int swap = 0;
    int N, K;
    ll B, T, startPT[51], speed[51];
    cin >> N >> K >> B >> T;
    for (int i = 1; i <= N; i++)
    {
        cin >> startPT[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> speed[i];
    }
    int count = 0;
    int cantReach = 0;
    for (int i = N; i >= 1; i--)
    {
        ll distance = B - startPT[i];
        ll canCover = T * speed[i];
        if (distance <= canCover)
        {
            count++;
            if (cantReach > 0)
            {
                swap = swap + cantReach;
            }
        }
        else
        {
            cantReach++;
        }
        if (count == K)
            break;
    }
    if (count < K)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << swap << endl;
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
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}