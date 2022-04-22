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
Q288.) Largest rectangular Area in Histogram

INPUT:
2

7
6 2 5 4 5 1 6

8
7 2 8 9 1 3 6 5

OUTPUT:
Case #1: 12
Case #2: 16

*/

class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long hist[], long long n)
    {

        // creating an empty stack. The stack holds indexes of hist[] array.
        // the bars stored in stack are always in increasing order of their heights.
        stack<long long> s;

        long long max_area = 0;
        long long tp;
        long long area_with_top;

        long long i = 0;

        // traversing the array.
        while (i < n)
        {
            // if current bar is greater than or equal to bar on top
            // of stack, we push the index into stack.
            if (s.empty() || hist[s.top()] <= hist[i])
            {
                s.push(i++);
            }

            // if current bar is lower than bar on top of stack, we calculate
            // area of rectangle with top of stack as the smallest bar.
            // i is rightindex for top and element before top in stack is leftindex
            else
            {
                tp = s.top();
                // popping the top element of stack.
                s.pop();

                // calculating the area with hist[tp] stack as smallest bar.
                area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

                // updating maximum area, if needed.
                if (max_area < area_with_top)
                    max_area = area_with_top;
            }
        }

        // now popping the remaining bars from stack and calculating
        // area with every popped bar as the smallest bar.
        while (s.empty() == false)
        {
            tp = s.top();
            s.pop();

            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            // updating maximum area, if needed.
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
        // returning the maximum area.
        return max_area;
    }
};

void solve()
{
    int n;
    cin >> n;

    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Solution ob;
    cout << ob.getMaxArea(arr, n) << endl;
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