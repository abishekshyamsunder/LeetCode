/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        vector<Node*> q;
        q.push_back(root);
        while(q.size()!=0)
        {
            vector<Node*> level;
            for(int i=0;i<q.size();i++)
            {
                if(i==q.size()-1)
                    q[i]->next == NULL;    
                else
                    q[i]->next = q[i+1];
                
                if(q[i]->left!=NULL)
                    level.push_back(q[i]->left);
                if(q[i]->right!=NULL)
                    level.push_back(q[i]->right);
            }
            q = level;
        }
        return root;
    }
};
