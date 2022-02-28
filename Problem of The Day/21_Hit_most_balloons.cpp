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

class Solution
{
public:
    int mostBalloons(int N, pair<int, int> arr[])
    {

        if (N <= 2)
        {
            return N;
        }
        int maxBalloons = 2;

        for (int i = 0; i < N; i++)
        {
            int horizontal = 0, vertical = 0, identical = 0;
            map<pair<int, int>, int> slope;

            for (int j = 0; j < N; j++)
            {
                // ignore same pair again
                if (i != j)
                {
                    // If both point are equal then just
                    // increase overlapPoint count
                    if (arr[i] == arr[j])
                    {
                        identical++;
                    }
                    // If x co-ordinate is same, then both
                    // point are vertical to each other
                    else if (arr[i].first == arr[j].first)
                    {
                        vertical++;
                    }
                    // If y co-ordinate is same, then both
                    // point are horizontal to each other
                    else if (arr[i].second == arr[j].second)
                    {
                        horizontal++;
                    }
                    else
                    {
                        int ydiff = arr[i].second - arr[j].second;
                        int xdiff = arr[i].first - arr[j].first;
                        int gcd = __gcd(abs(ydiff), abs(xdiff));
                        // reducing the difference by their gcd
                        ydiff /= gcd;
                        xdiff /= gcd;
                        if (xdiff < 0)
                        {
                            xdiff *= -1;
                            ydiff *= -1;
                        }
                        // increasing the frequency of current slope
                        // in map
                        slope[{ydiff, xdiff}]++;
                    }
                }
            }
            int mostPointsOnSameLine = 1;
            for (auto item : slope)
            {
                mostPointsOnSameLine = max(mostPointsOnSameLine, item.second);
            }
            // updating global maximum by current point's maximum
            maxBalloons = max({maxBalloons, 1 + identical + mostPointsOnSameLine, 1 + identical + max(horizontal, vertical)});
        }

        return maxBalloons;
    }
};

void solve()
{
    int N;
    cin >> N;
    pair<int, int> arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].second;
    }
    Solution ob;
    cout << ob.mostBalloons(N, arr) << endl;
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