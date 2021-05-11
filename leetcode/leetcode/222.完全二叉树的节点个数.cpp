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
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iostream>

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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int treeDepth = 0;
        TreeNode* treeLeft = root, *treeRight = root;
        int leftTreeDepth = 0, rightTreeDepth = 0;
        while (treeLeft) { leftTreeDepth++; treeLeft = treeLeft->left; }
        while(treeRight) { rightTreeDepth++; treeRight = treeRight->right; }
        if (leftTreeDepth == rightTreeDepth) return std::pow(2, leftTreeDepth) - 1;
        int left = 0, right = std::pow(2, leftTreeDepth - 1) - 1;
        while (left + 1 < right) {
            int middle = left + (right - left) / 2;
            if (TreeLinePosition(root, middle, leftTreeDepth)) left = middle;
            else right = middle;
            // int tmpFlag = TreeLinePosition(root, middle, leftTreeDepth);
            // if (tmpFlag == 0) return std::pow(2, leftTreeDepth) - 1 + middle;
            // else if (tmpFlag == 1) left = middle;
            // else if (tmpFlag == 2) right = middle;
            // else return 0;
        }
        return std::pow(2, rightTreeDepth) + left;
    }

    int TreeLinePosition(TreeNode* root, int number, int depth) {
        int maxCount = std::pow(2, depth - 2);
        TreeNode* top = root;
        while (maxCount) {
            if (number >= maxCount) {
            top = top->right;
            number = number - maxCount;
            } else top = top->left;
            maxCount = maxCount >> 1;
        }
        if (top) return true;
        else return false;
    }
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    std::cout << Solution().countNodes(root) << std::endl;
    return 0;
}

