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
Q113.) Book Allocation Problem

INPUT:
2

4
12 34 67 90
2

3 15 17 20
2

OUTPUT:
Case #1: 113
Case #2: 32

*/

class Solution
{
public:
    // Function to check if current minimum value is feasible or not.
    bool isPossible(int arr[], int n, int m, long long int curMin)
    {
        int studentsRequired = 1;
        int curSum = 0;

        // iterating over all the books.
        for (int i = 0; i < n; i++)
        {
            // if current number of pages are greater than curMin, return false
            if (arr[i] > curMin)
            {
                return false;
            }

            // counting number of students required to distribute curMin pages
            if (curSum + arr[i] > curMin)
            {
                // incrementing student count and updating curSum.
                studentsRequired++;
                curSum = arr[i];

                // if students required becomes greater than given number
                // of students, we return false.
                if (studentsRequired > m)
                {
                    return false;
                }
            }
            // else updating curSum
            else
            {
                curSum += arr[i];
            }
        }
        return true;
    }

    // Function to find minimum number of pages.
    int findPages(int arr[], int n, int m)
    {
        long long sum = 0;

        // returning -1 if no. of books is less than no. of students.
        if (n < m)
        {
            return -1;
        }

        // counting total number of pages.
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
        }

        // initializing start as 0 pages and end as total pages.
        long long start = 0;
        long long end = sum, mid;
        long long int ans = int(1e15);

        while (start <= end)
        {
            mid = (start + end) / 2;

            // checking if it is possible to distribute books
            // by using mid as current minimum.
            if (isPossible(arr, n, m, mid))
            {
                // if yes, then we find the minimum distribution.
                ans = ans < mid ? ans : mid;

                // as we are finding minimum and books are sorted
                // so reducing end as end = mid -1.
                end = mid - 1;
            }
            // if not possible means pages should be increased so
            // updating start = mid + 1.
            else
            {
                start = mid + 1;
            }
        }
        // returning minimum number of pages.
        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int m;
    cin >> m;
    Solution ob;
    cout << ob.findPages(A, n, m) << endl;
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