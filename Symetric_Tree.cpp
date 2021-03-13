/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q; //que of node pointers
        q.push(root); // push the head
        int size = 0; 
        while(!q.empty()) // continue while que is not empty
        {
            size = q.size();
            vector<int> v; // create a vector to store the left and right value.
            //perform the BFS and also add value to the vector v;
            for(int i=0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                    v.push_back(temp->left->val);
                }
                else
                    v.push_back(-1);
                if(temp->right)
                {
                    q.push(temp->right);
                    v.push_back(temp->right->val);
                }
                else
                    v.push_back(-1);
            }
           //one one layer(breath) is loaded into the vector v, check if the vector is palindrom
            for(int i=0; i<v.size()/2; i++)
            {
                cout << v[i] << " " << v[v.size()-1-i] << endl;
                if(v[i] != v[v.size()-1-i])
                    return false;
            }//for
        }//while
        return true;
    }
};
