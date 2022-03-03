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
Q118.) Painters Partition Problem:

INPUT:
2

3 5
5 10 30 20 15

2 4
10 20 30 40

OUTPUT:
Case #1: 35
Case #2: 60

*/

class Solution
{
public:
    // return the maximum element from the array
    int getMax(int arr[], int n)
    {
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }

    // return the sum of the elements in the array
    ll getSum(int arr[], int n)
    {
        ll total = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }
        return total;
    }

    // find minimum required painters for given maxlen
    // which is the maximum length a painter can paint
    int numberOfPainters(int arr[], int n, ll maxLen)
    {
        ll total = 0, numPainters = 1;

        for (int i = 0; i < n; i++)
        {
            total += arr[i];

            if (total > maxLen)
            {
                // for next count
                total = arr[i];
                numPainters++;
            }
        }

        return numPainters;
    }

    ll minTime(int arr[], int n, int k)
    {
        ll lo = getMax(arr, n);
        ll hi = getSum(arr, n);

        while (lo < hi)
        {
            ll mid = lo + (hi - lo) / 2;
            ll requiredPainters = numberOfPainters(arr, n, mid);

            // find better optimum in lower half
            // here mid is included because we
            // may not get anything better
            if (requiredPainters <= k)
            {
                hi = mid;
            }

            // find better optimum in upper half
            // here mid is excluded because it gives
            // required Painters > k, which is invalid
            else
            {
                lo = mid + 1;
            }
        }

        // required
        return lo;
    }
};

void solve()
{
    int k, n;
    cin >> k >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Solution obj;
    cout << obj.minTime(arr, n, k) << endl;
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