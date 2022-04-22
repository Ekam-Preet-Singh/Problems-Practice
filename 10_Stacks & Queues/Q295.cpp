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
Q295.) Implement "n" queue in an array

INPUT:
1

OUTPUT:
Case #1:
Dequeued element from queue 2 is 15
Dequeued element from queue 1 is 17
Dequeued element from queue 0 is 11

*/

// A C++ class to represent k queues in a single array of size n
class kQueues
{
    // Array of size n to store actual content to be stored in queue
    int *arr;

    // Array of size k to store indexes of front elements of the queue
    int *front;

    // Array of size k to store indexes of rear elements of queue
    int *rear;

    // Array of size n to store next entry in all queues
    int *next;
    int n, k;

    int free; // To store the beginning index of the free list

public:
    // constructor to create k queue in an array of size n
    kQueues(int k1, int n1)
    {
        // Initialize n and k, and allocate memory for all arrays
        k = k1, n = n1;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // Initialize all queues as empty
        for (int i = 0; i < k; i++)
            front[i] = -1;

        // Initialize all spaces as free
        free = 0;
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1; // -1 is used to indicate end of free list
    }

    // A utility function to check if there is space available
    bool isFull() { return (free == -1); }

    // To enqueue an item in queue number 'qn' where qn is from 0 to k-1
    void enqueue(int item, int qn)
    {
        // Overflow check
        if (isFull())
        {
            cout << "\nQueue Overflow\n";
            return;
        }

        int i = free; // Store index of first free slot

        // Update index of free slot to index of next slot in free list
        free = next[i];

        if (isEmpty(qn))
            front[qn] = i;
        else
            next[rear[qn]] = i;

        next[i] = -1;

        // Update next of rear and then rear for queue number 'qn'
        rear[qn] = i;

        // Put the item in array
        arr[i] = item;
    }

    // To dequeue an from queue number 'qn' where qn is from 0 to k-1
    int dequeue(int qn)
    {
        // Underflow checkSAS
        if (isEmpty(qn))
        {
            cout << "\nQueue Underflow\n";
            return INT_MAX;
        }

        // Find index of front item in queue number 'qn'
        int i = front[qn];

        front[qn] = next[i]; // Change top to store next of previous top

        // Attach the previous front to the beginning of free list
        next[i] = free;
        free = i;

        // Return the previous front item
        return arr[i];
    }

    // To check whether queue number 'qn' is empty or not
    bool isEmpty(int qn) { return (front[qn] == -1); }
};

void solve()
{
    // Let us create 3 queue in an array of size 10
    int k = 3, n = 10;
    kQueues ks(k, n);

    // Let us put some items in queue number 2
    ks.enqueue(15, 2);
    ks.enqueue(45, 2);

    // Let us put some items in queue number 1
    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);

    // Let us put some items in queue number 0
    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(7, 0);

    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;
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