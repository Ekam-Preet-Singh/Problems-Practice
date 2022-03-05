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
Q128.) Write a program to Delete loop in a linked list.

INPUT:
6

5
1 2 3 4 5
2

10
0 1 2 3 4 5 6 7 8 9
0

5
1 2 3 4 5
3

8
1 2 2 4 5 6 7 8
4

3
1 3 4
2

4
1 8 3 4
0

OUTPUT:
Case #1: 1
Case #2: 1
Case #3: 1
Case #4: 1
Case #5: 1
Case #6: 1

*/

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
    {
        return;
    }

    Node *walk = head;
    for (int i = 1; i < position; i++)
    {
        walk = walk->next;
    }
    tail->next = walk;
}

// Floyd's Cycle-Finding Algorithm
bool isLoop(Node *head)
{
    // using two pointers and moving one pointer(slow) by one node and
    // another pointer(fast) by two nodes in each iteration.
    Node *fast = head->next, *slow = head;

    while (slow && fast && fast->next)
    {
        // Move one pointer(slow_p) by one and another pointer(fast_p) by two.
        fast = fast->next->next;
        slow = slow->next;

        // If these pointers meet at the same node then there is a loop
        if (slow == fast)
        {
            return true;
        }
    }
    // If pointers do not meet then linked list doesn't have a loop.
    return false;
}

int length(Node *head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        if (!head)
        {
            return;
        }

        // using two pointers and moving one pointer(slow) by one node and
        // another pointer(fast) by two nodes in each iteration.
        Node *fast = head->next;
        Node *slow = head;

        while (fast != slow)
        {
            // if the node pointed by first pointer(fast) or the node
            // next to it is null, then loop is not present.
            if (!fast || !fast->next)
            {
                return;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        // both pointers now point to the same node in the loop.

        int size = 1;
        fast = fast->next;

        // we start iterating the loop with first pointer and continue till
        // both pointers point to same node again.
        while (fast != slow)
        {
            // incrementing the counter which stores length of loop.
            size++;
            fast = fast->next;
        }

        // updating the pointers again to starting node.
        slow = head;
        fast = head;

        // moving pointer (fast) by (size-1) nodes.
        for (int i = 0; i < size - 1; i++)
        {
            fast = fast->next;
        }

        // now we keep iterating with both pointers till fast reaches a node such
        // that the next node is pointed by slow. At this situation slow is at
        // the node where loop starts and first at last node so we simply
        // update the link part of first.
        while (fast->next != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // storing null in link part of the last node.
        fast->next = NULL;
    }
};

void solve()
{
    int n, num;
    cin >> n;

    Node *head, *tail;
    cin >> num;
    head = tail = new Node(num);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> num;
        tail->next = new Node(num);
        tail = tail->next;
    }

    int pos;
    cin >> pos;
    loopHere(head, tail, pos);

    Solution ob;
    ob.removeLoop(head);

    if (isLoop(head) || length(head) != n)
        cout << "0\n";
    else
        cout << "1\n";
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