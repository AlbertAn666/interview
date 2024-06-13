#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        std::unordered_map<int, TreeNode*> roots;
        std::unordered_set<int> deletes(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;

        roots[root->val] = root;
        // first dfs the tree, delete the related nodes, and add new root into roots
        dfs_delete(root, deletes, roots);

        // then dfs each trees, generate the final output
        generate(roots, ans, deletes);
        return ans;
    }

    void dfs_delete(TreeNode* root, const std::unordered_set<int>& deletes, std::unordered_map<int, TreeNode*>& roots) {
        if(root != nullptr) {
            // this node should be deleted
            dfs_delete(root->left, deletes, roots);
            dfs_delete(root->right, deletes, roots);
            if (deletes.count(root->val)) {
                if (root->left) {
                    if (!deletes.count(root->left->val)) {
                        roots[root->left->val] = root->left;
                    }
                    root->left = nullptr;
                }
                if (root->right) {
                    if (!deletes.count(root->right->val)) {
                        roots[root->right->val] = root->right;
                    } 
                    root->right = nullptr;
                }
                
                auto iter = roots.find(root->val);
                if (iter != roots.end()) {
                    roots.erase(iter);
                }
            }
            
        }
    }

    void generate(std::unordered_map<int, TreeNode*>& roots, vector<TreeNode*>& ans,  const std::unordered_set<int>& deletes) {
        for (auto& iter: roots) {
            TreeNode* new_root = iter.second;
            dfs(new_root, deletes);
            ans.push_back(new_root);
        }
    }

    void dfs(TreeNode* root, const std::unordered_set<int>& deletes) {
        if (root != nullptr) {
            if (root->left != nullptr) {
                if (deletes.count(root->left->val)) {
                    root->left = nullptr;
                }
            }
            if (root->right != nullptr) {
                if (deletes.count(root->right->val)) {
                    root->right = nullptr;
                }
            }
            dfs(root->left, deletes);
            dfs(root->right, deletes);
        }
    }

};