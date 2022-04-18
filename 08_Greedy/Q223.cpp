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
Q223.) Greedy Algorithm to find Minimum number of Coins

INPUT:
2

4 0
2 2 2 2

6 3
1 5 1 2 5 1

OUTPUT:
Case #1: 0
Case #2: 2

*/

class Solution
{
public:
    int minSteps(int A[], int N, int K)
    {

        vector<int> a(N), p(N, 0);
        for (int i = 0; i < N; i++)
        {
            a[i] = A[i];
        }

        sort(a.begin(), a.end());

        p[0] = a[0];

        for (int i = 1; i < N; i++)
        {
            p[i] = p[i - 1] + a[i];
        }

        int ans = INT_MAX, prev = 0;

        for (int i = 0; i < N; i++)
        {
            int pos = upper_bound(a.begin() + i, a.end(), a[i] + K) - a.begin();

            if (i > 0 && a[i] != a[i - 1])
            {
                prev = p[i - 1];
            }

            ans = min(ans, prev + p[N - 1] - p[pos - 1] - (N - pos) * (a[i] + K));
        }
        return ans;
    }
};

void solve()
{
    int N, K;
    cin >> N >> K;

    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solution ob;
    cout << ob.minSteps(A, N, K) << endl;
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