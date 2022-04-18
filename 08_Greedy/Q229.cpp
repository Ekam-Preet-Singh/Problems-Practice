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
Q229.) Minimum Cost to cut a board into squares

INPUT:
1

6 4
2 1 3 1 4
4 1 2

OUTPUT:
Case #1: 42

*/

// method returns minimum cost to break board into
// m*n squares
int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
    int res = 0;

    //  sort the horizontal cost in reverse order
    sort(X, X + m, greater<int>());

    //  sort the vertical cost in reverse order
    sort(Y, Y + n, greater<int>());

    //  initialize current width as 1
    int hzntl = 1, vert = 1;

    //  loop until one or both cost array are processed
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (X[i] > Y[j])
        {
            res += X[i] * vert;

            //  increase current horizontal part count by 1
            hzntl++;
            i++;
        }
        else
        {
            res += Y[j] * hzntl;

            //  increase current vertical part count by 1
            vert++;
            j++;
        }
    }

    // loop for horizontal array, if remains
    int total = 0;
    while (i < m)
    {
        total += X[i++];
    }
    res += total * vert;

    // loop for vertical array, if remains
    total = 0;
    while (j < n)
    {
        total += Y[j++];
    }
    res += total * hzntl;

    return res;
}

void solve()
{
    int m, n;
    cin >> m >> n;
    int X[m - 1], Y[n - 1];
    for (int i = 0; i < m - 1; i++)
        cin >> X[i];
    for (int i = 0; i < n - 1; i++)
        cin >> Y[i];
    cout << minimumCostOfBreaking(X, Y, m - 1, n - 1);
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