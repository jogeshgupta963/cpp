#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int sumTree(node *root, int level)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int count = 0;
    int sum = 0;
    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            if (count == level)
            {
                sum += temp->data;
            }
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            count++;
        }
    }
    return sum;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << sumTree(root, 1);
    return 0;
}