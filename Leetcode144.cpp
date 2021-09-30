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
     vector< int > preorderTraversal_recursive(TreeNode* root) {
        vector< int > result;
        if( root == nullptr )
            return result;
        else
        {
            result.push_back( root -> val );
            vector< int > left = preorderTraversal( root -> left );
            result.insert( result.end(), left.begin(), left.end() );
            vector< int > right = preorderTraversal( root -> right );
            result.insert( result.end(), right.begin(), right.end() );
        }
        return result;
    } 
    
    vector< int > preorderTraversal_iterative( TreeNode* root )
    {
        vector< int > result;
        stack< TreeNode* > roots;
        
        while( root != nullptr || !roots.empty() )
        {
            while( root != nullptr )
            {
                result.push_back( root -> val );
                roots.push( root );
                root = root -> left;
            }
            
            TreeNode* pNode = roots.top();
            roots.pop();
            if( pNode -> right != nullptr )
                root = pNode -> right;
        }
        return result;
        
    }
};
