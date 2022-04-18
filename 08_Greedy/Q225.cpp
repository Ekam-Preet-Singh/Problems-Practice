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
Q225.) Minimum Platforms Problem

INPUT:
2

6
0900 0940 0950 1100 1500 1800
0910 1200 1120 1130 1900 2000

3
0900 1100 1235
1000 1200 1240

OUTPUT:
Case #1: 3
Case #2: 1

*/

class Solution
{
public:
    // Function to sort vector elements first according to time and if time is
    // same for two events, then arrival comes first followed by departure.
    static bool customsort(const pair<int, char> &a, const pair<int, char> &b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    }

    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int, char>> order;

        // inserting all the values of time(arrival and departure)
        // in the vector of pairs.
        for (int i = 0; i < n; i++)
        {

            // if the time is of arrival then we keep second value
            // of pair as 'a' else 'd'.
            order.push_back(make_pair(arr[i], 'a'));
            order.push_back(make_pair(dep[i], 'd'));
        }

        // using custom sort vector, first according to time and if time is
        // same for two events, then arrival comes first followed by departure.
        sort(order.begin(), order.end(), customsort);

        int result = 1;
        int plat_needed = 0;

        // using an iterator on vector of pairs.
        vector<pair<int, char>>::iterator it = order.begin();

        for (; it != order.end(); it++)
        {
            // if the second value of vector element is 'a' which stands
            // for arrival then we add 1 to platform needed else we
            // subtract 1 from platform needed.
            if ((*it).second == 'a')
            {
                plat_needed++;
            }
            else
            {
                plat_needed--;
            }

            // we keep updating the value of result.
            if (plat_needed > result)
            {
                result = plat_needed;
            }
        }
        // returning the minimum number of platforms required.
        return result;
    }
};

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int dep[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int j = 0; j < n; j++)
    {
        cin >> dep[j];
    }
    Solution ob;
    cout << ob.findPlatform(arr, dep, n) << endl;
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