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
Q147.) Sort a "k" sorted Doubly Linked list.[Very IMP]

INPUT:
4

7
9 8 6 5 4 2 1
17

7
1 2 4 5 6 8 9
15

6
8 56 12 2 6 3
2

7
1 2 3 4 5 6 7
7

OUTPUT:
Case #1:
Original Doubly linked list:
1 2 4 5 6 8 9 
Doubly linked list after sorting:
1 2 4 5 6 8 9 
Case #2:
Original Doubly linked list:
9 8 6 5 4 2 1 
Doubly linked list after sorting:
1 2 4 5 6 8 9 
Case #3:
Original Doubly linked list:
3 6 2 12 56 8 
Doubly linked list after sorting:
2 3 6 8 12 56 
Case #4:
Original Doubly linked list:
7 6 5 4 3 2 1 
Doubly linked list after sorting:
1 2 3 4 5 6 7 

*/

// a node of the doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// 'compare' function used to build up the
// priority queue
struct compare
{
    bool operator()(struct Node *p1, struct Node *p2)
    {
        return p1->data > p2->data;
    }
};

// function to sort a k sorted doubly linked list
struct Node *sortAKSortedDLL(struct Node *head, int k)
{
    // if list is empty
    if (head == NULL)
    {
        return head;
    }

    // priority_queue 'pq' implemented as min heap with the
    // help of 'compare' function
    priority_queue<Node *, vector<Node *>, compare> pq;

    struct Node *newHead = NULL, *last;

    // Create a Min Heap of first (k+1) elements from
    // input doubly linked list
    for (int i = 0; head != NULL && i <= k; i++)
    {
        // push the node on to 'pq'
        pq.push(head);

        // move to the next node
        head = head->next;
    }

    // loop till there are elements in 'pq'
    while (!pq.empty())
    {

        // place root or top of 'pq' at the end of the
        // result sorted list so far having the first node
        // pointed to by 'newHead'
        // and adjust the required links
        if (newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;

            // 'last' points to the last node
            // of the result sorted list so far
            last = newHead;
        }

        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }

        // remove element from 'pq'
        pq.pop();

        // if there are more nodes left in the input list
        if (head != NULL)
        {
            // push the node on to 'pq'
            pq.push(head);

            // move to the next node
            head = head->next;
        }
    }

    // making 'next' of last node point to NULL
    last->next = NULL;

    // new head of the required sorted DLL
    return newHead;
}

// Function to insert a node at the beginning
// of the Doubly Linked List
void push(struct Node **head_ref, int new_data)
{
    // allocate node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // put in the data
    new_node->data = new_data;

    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // change prev of head node to new node
    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to print nodes in a given doubly linked list
void printList(struct Node *head)
{
    // if list is empty
    if (head == NULL)
    {
        cout << "Doubly Linked list empty";
    }

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void solve()
{
    Node *head = NULL;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        push(&head, val);
    }
    cin >> val;
    cout << "Original Doubly linked list:\n";
    printList(head);

    head = sortAKSortedDLL(head, val);

    cout << "Doubly linked list after sorting:\n";
    printList(head);
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