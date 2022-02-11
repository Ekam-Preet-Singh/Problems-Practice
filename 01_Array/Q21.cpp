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
#define log(args...)                         \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }
#define logarr(arr, a, b)          \
  for (int z = (a); z <= (b); z++) \
    cout << (arr[z]) << " ";       \
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

/*
Q21.) Find if there is any subarray with sum equal to 0

INPUT:
2

5
4 2 -3 1 6

5
4 2 5 1 6

OUTPUT:
Case #1: Yes
Case #2: No

*/

class Solution
{
public:
  // Function to check whether there is a subarray present with 0-sum or not.
  bool subArrayExists(int arr[], int n)
  {
    // using map to store the prefix sum which has appeared already.
    unordered_map<int, bool> sumMap;

    int sum = 0;
    // iterating over the array.
    for (int i = 0; i < n; i++)
    {
      // storing prefix sum.
      sum += arr[i];

      // if prefix sum is 0 or if it is already present in map then it is
      // repeated which means there is a subarray whose summation is 0,
      // so we return true.
      if (sum == 0 || sumMap[sum] == true)
      {
        return true;
      }

      // storing true in map for every prefix sum obtained.
      sumMap[sum] = true;
    }
    // returning false if we don't get any subarray with 0 sum.
    return false;
  }
};

void solve()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  Solution obj;
  if (obj.subArrayExists(arr, n))
    cout << "Yes\n";
  else
    cout << "No\n";
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
  clock_t begin = clock();
  file_i_o();
#endif

  ll t = 1;
  ll case_num = 1;
  cin >> t;
  while (t--)
  {
    cout << "Case #" << case_num++ << ": ";
    solve();
  }

#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
  return 0;
}