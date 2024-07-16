#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int value;
    node* left=NULL;
    node* right=NULL;
    node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void insert(node* root, int value)
{
    int now = root->value;
    if (now > value)
    {
        if (root->left)
        {
            insert(root->left, value);
        }
        else
        {
            root->left = new node(value);
        }
    }
    else
    {
        if (root->right)
        {
            insert(root->right, value);
        }
        else
        {
            root->right = new node(value);
        }
    }
}
void postorder(node* root)
{
    if (root->left)
        postorder(root->left);
    if (root->right)
        postorder(root->right);
    cout << root->value << endl;
}

int main()
{
    unordered_map<int, pair<int,int>> tree;
    vector<int> parent;
    vector<int> A;
    int n;
    while (true)
    {
        cin >> n;
        if (cin.eof() == true)
            break;
        A.push_back(n);
    }
    node* root=NULL;
    if (A.size() > 0)
    {
        root = new node(A[0]);
    }
    for (int i = 1; i < A.size(); i++)
    {
        insert(root, A[i]);
    }
    postorder(root);
    return 0;
}