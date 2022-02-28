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
Q99.) find four elements that sum to a given value

INPUT:
4

6 78
5 20 3 2 5 80

5 45
90 70 20 80 50

5 3
0 0 2 1 1

7 23
10 2 3 4 5 7 8

OUTPUT:
Case #1:
-1
Case #2:
-1
Case #3:
0 0 1 2 $
Case #4:
2 3 8 10 $2 4 7 10 $3 5 7 8 $

*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &a, int k)
    {
        if (a.size() < 4)
        {
            return {};
        }
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size() - 3; ++i)
        {
            // current element is greater than k then no quadruplet can be found
            if (a[i] > 0 && a[i] > k)
            {
                break;
            }
            // removing duplicates
            if (i > 0 && a[i] == a[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < a.size() - 2; ++j)
            {
                // removing duplicates
                if (j > i + 1 && a[j] == a[j - 1])
                {
                    continue;
                }

                // taking two pointers
                int left = j + 1;
                int right = a.size() - 1;
                while (left < right)
                {
                    int old_l = left;
                    int old_r = right;
                    // calculate current sum
                    int sum = a[i] + a[j] + a[left] + a[right];
                    if (sum == k)
                    {
                        // add to answer
                        ans.push_back({a[i], a[j], a[left], a[right]});

                        // removing duplicates
                        while (left < right && a[left] == a[old_l])
                        {
                            left++;
                        }
                        while (left < right && a[right] == a[old_r])
                        {
                            right--;
                        }
                    }
                    else if (sum > k)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};

void solve()
{
    int n, k, i;
    cin >> n >> k;
    vector<int> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution ob;
    vector<vector<int>> ans = ob.fourSum(a, k);
    for (auto &v : ans)
    {
        for (int &u : v)
        {
            cout << u << " ";
        }
        cout << "$\n";
    }
    if (ans.empty())
    {
        cout << -1;
    }
    cout << "\n";
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
        cout << "Case #" << case_num++ << ":\n";
        solve();
    }

    return 0;
}