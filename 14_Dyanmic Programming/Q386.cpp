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
Q386.) Assembly Line Scheduling Problem

INPUT:
1

OUTPUT:
Case #1: 35

*/

#define NUM_LINE 2
#define NUM_STATION 4

// Utility function to find a minimum of two numbers
int min(int a, int b)
{
    return a < b ? a : b;
}

int carAssembly(int a[][NUM_STATION], int t[][NUM_STATION], int *e, int *x)
{
    int T1[NUM_STATION], T2[NUM_STATION], i;

    // time taken to leave first station in line 1
    T1[0] = e[0] + a[0][0];

    // time taken to leave first station in line 2
    T2[0] = e[1] + a[1][0];

    // Fill tables T1[] and T2[] using the
    // above given recursive relations
    for (i = 1; i < NUM_STATION; ++i)
    {
        T1[i] = min(T1[i - 1] + a[0][i], T2[i - 1] + t[1][i] + a[0][i]);
        T2[i] = min(T2[i - 1] + a[1][i], T1[i - 1] + t[0][i] + a[1][i]);
    }

    // Consider exit times and return minimum
    return min(T1[NUM_STATION - 1] + x[0], T2[NUM_STATION - 1] + x[1]);
}

void solve()
{
    int a[][NUM_STATION] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
    int t[][NUM_STATION] = {{0, 7, 4, 5}, {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};

    cout << carAssembly(a, t, e, x);
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