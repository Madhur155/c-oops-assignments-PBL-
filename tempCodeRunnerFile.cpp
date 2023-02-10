#include <iostream>
using namespace std;
class node
{
public:
    int data;
    int lch;
    int rch;
    node *l;
    node *r;

    node(int val = -1)
    {
        data = val;
        lch = rch = 0;
        l = r = nullptr;
    }
};
class tbt
{
public:
    node *root;
    node *dummy;

    tbt()
    {
        root = nullptr;
        dummy = new node();
    }

    void insert(int key);
    void inorder();
};
void tbt::insert(int key)
{
    if (root == nullptr)
    {
        node *temp = new node(key);
        root = temp;
        dummy->lch = 1;
        dummy->l = root;
        root->l = root->r = dummy;
        return;
    }
    else
    {
        node *p = nullptr;
        node *t = root;
        while (t)
        {
            p = t;
            if (key < t->data)
            {
                if (t->lch == 1)
                    t = t->l;
                else
                    t = nullptr;
            }
            else if (key > t->data)
            {
                if (t->rch == 1)
                    t = t->r;
                else
                    t = nullptr;
            }
            else
                return;
        }
        node *temp = new node(key);
        if (key < p->data)
        {
            temp->l = p->l;
            temp->r = p;
            p->l = temp;
            p->lch = 1;
        }
        else
        {
            temp->r = p->r;
            temp->l = p;
            p->r = temp;
            p->rch = 1;
        }
    }
}
void tbt::inorder()
{
    node *t = root;
    while (1)
    {
        while (t->lch == 1)
        {
            t = t->l;
        }
        cout << t->data << " ";
        while (t->rch == 0)
        {
            if (t->r == dummy)
                return;
            else
            {
                t = t->r;
                cout << t->data << " ";
            }
        }
        t = t->r;
    }
}
int main()
{

    tbt t;

    t.insert(5);
    t.insert(6);
    t.insert(1);
    t.insert(10);
    t.inorder();
    return 0;
}