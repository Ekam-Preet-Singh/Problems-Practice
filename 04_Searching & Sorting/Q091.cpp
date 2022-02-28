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
Q91.) Search in a rotated sorted array

INPUT:
2

7 0
4 5 6 7 0 1 2

7 3
4 5 6 7 0 1 2

OUTPUT:
Case #1: 4
Case #2: -1

*/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, mid, high = nums.size() - 1;
        // loop will terminate when s>e
        // means we check all the element
        // and we didn't find the target
        // so , return-1
        while (low <= high)
        {
            // find the mid
            mid = low + (high - low) / 2;

            // arr[m]==target
            // means we find the index
            // return m
            if (nums[mid] == target)
            {
                return mid;
            }
            // check that which area is increasing
            // either left part or right part
            // we check that is there
            // target lie in the increasing area

            // if the right part is increasing
            else if (nums[mid] >= nums[low])
            {
                // if the target lie in increasing area(right area)
                // go right
                if (target < nums[mid] && target >= nums[low])
                {
                    high = mid - 1;
                }
                // else left
                else
                {
                    low = mid + 1;
                }
            }
            // if the left part is increasing
            else
            {
                // if the target lie in increasing area(left area)
                // go left
                if (target > nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                // else right
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;
    Solution obj;
    cout << obj.search(nums, target) << endl;
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