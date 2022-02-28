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
Q103.) print all subarrays with 0 sum

INPUT:
2

6
0 0 5 5 0 0

10
6 -1 -3 4 -2 2 4 6 -12 -7

OUTPUT:
Case #1: 6
Case #2: 4

*/

class Solution
{
public:
    // Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n)
    {

        ll sum = 0, counter = 0;

        // using map to store the prefix sum which has appeared already.
        unordered_map<ll, ll> mp;

        // iterating over the array.
        for (int i = 0; i < n; i++)
        {
            // storing prefix sum.
            sum += arr[i];

            // if prefix sum is zero that means we get a subarray with sum=0.
            if (sum == 0)
            {
                // incrementing the counter.
                counter++;
            }

            // if prefix sum is already present in map then it is repeated
            // which means there is a subarray whose summation is 0.
            if (mp.count(sum) != 0)
            {
                // we add the value at prefix sum in map to counter.
                counter += mp[sum];
            }

            // incrementing the count of prefix sum obtained in map.
            mp[sum]++;
        }
        // returning the counter.
        return counter;
    }
};

void solve()
{
    int n;
    cin >> n; // input size of array

    vector<ll> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i]; // input array elements
    Solution ob;
    cout << ob.findSubarray(arr, n) << "\n";
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