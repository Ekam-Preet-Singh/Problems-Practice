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
Q420.) Weighted Job Scheduling

INPUT:
2

4
1 4 20 2 1 10 3 1 40 4 1 30

5
1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

OUTPUT:
Case #1: 2 60
Case #2: 2 127

*/

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends

class Solution
{
public:
    // function used for sorting all jobs according to decreasing profit.
    static bool comparison(Job a, Job b)
    {
        return (a.profit > b.profit);
    }

    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        int res = 0, count = 0;

        // sorting all jobs according to decreasing order of profit.
        sort(arr, arr + n, comparison);

        // array to store result (Sequence of jobs).
        int result[n];
        // boolean array to keep track of free time slots.
        bool slot[n];

        // initializing all slots to free.
        for (int i = 0; i < n; i++)
        {
            slot[i] = false;
        }

        // iterating through all given jobs.
        for (int i = 0; i < n; i++)
        {
            // finding a free slot for current job (Note that we start
            // from the last possible slot).
            for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
            {
                // if free slot is found, we add current job to result array
                // and make the current slot occupied.
                if (slot[j] == false)
                {
                    result[j] = i;
                    slot[j] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            // if slot is occupied, we update the counter and
            // add its profit in final result.
            if (slot[i])
            {
                count++;
                res += arr[result[i]].profit;
            }
        }

        // storing the count of jobs and max profit in a list and returning it.
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(res);
        return ans;
    }
};

void solve()
{
    int n;

    // size of array
    cin >> n;
    Job arr[n];

    // adding id, deadline, profit
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i].id = x;
        arr[i].dead = y;
        arr[i].profit = z;
    }
    Solution ob;
    // function call
    vector<int> ans = ob.JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1] << endl;
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