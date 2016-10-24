//Tree
#include <iostream>

using namespace std;

struct t_node
{
    int data;
    t_node *left;
    t_node *right;
};

t_node* new_t_node()
{
    t_node *temp = new t_node;
    temp->data = 0;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void insert_tnode(t_node*& root, int newItem)
{
    if (root==NULL)
    {
        root = new_t_node();
        root->data = newItem;
        return;
    }
    else if (newItem < root->data)
        insert_tnode(root->left, newItem);
    else
        insert_tnode(root->right, newItem);
}

void print_tree(t_node *root)
{
    if (root==NULL)
        return;
    print_tree(root->left);
    cout << root->data << " ";
    print_tree(root->right);
    return;
}

bool search_tree(t_node* c, int target)
{
    if (c==NULL)
        return false;
    if (target==c->data)
    {
        cout << target << " found" << endl;
        return true;
    }

    if (target < c->data)
        search_tree(c->left, target);
    else
        search_tree(c->right, target);
}

void search_tree2(t_node*c, int target)
{
    if (search_tree(c, target)==false)
        cout << target << " not found" << endl;
}

int main()
{
    t_node *root = NULL;
    insert_tnode(root, 2);
    insert_tnode(root, 5);
    insert_tnode(root, 3);
    insert_tnode(root, 10);
    insert_tnode(root, 1);
    print_tree(root);
    cout << endl;
    search_tree2(root, 6);
    search_tree2(root, 10);


    return 0;
}
