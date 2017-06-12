//
//  Solution.h
//  LeetCode Test
//
//  Created by ChenshuoYue on 10/29/16.
//  Copyright © 2016 Machinarium. All rights reserved.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>


namespace MyCode {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:

        int wordsTyping(const std::vector<std::string>& sentence, int rows, int cols);
        // LeetCode 46. Permutations
        std::vector<std::vector<int>> permute(std::vector<int>& nums);
        // LeetCode 47. Permuations II
        std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums);
        // LeetCode 60. Permutation Sequence
        std::string getPermutation(int n, int k);
        // LeetCode 498. Diagonal Traverse
        std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>>& matrix);
        // LeetCode 543. Diameter of Binary Tree
        int diameterOfBinaryTree(TreeNode* root);
        int maxDepth(TreeNode* node, int& res);
        // LeetCode 164. Maximum Gap
        int maximumGap(const std::vector<int>& nums);
        // LeetCode 301. Remove Invalid Parentheses
        std::vector<std::string> removeInvalidParentheses(std::string input);
        // LeetCode 449. Serialize and Deserialize BST
        std:: string serialize(TreeNode* root);
        TreeNode* deserialize(std::string data);
        // LeetCode 329. Longest Increasing Path in Matrix
        int longestIncreasingPath(std::vector<std::vector<int>>& matrix);
        // LeetCode 333. Largest BST Subtree
        int largestBSTSubtree(TreeNode* root);
        // LeetCode 130. Surrounded Regions
        void solve(std::vector<std::vector<char>>& board);
        // LeetCode 325. Maximum Size Subarray Sum Equals k
        int maxSubArrayLen(std::vector<int>& nums, int k);
        // LeetCode 314. Binary Tree Vertical Order Traversal
        std::vector<std::vector<int>> verticalOrder(TreeNode* root);
        // LeetCode 139. Word Break
        bool wordBreak(std::string s, std::unordered_set<std::string> &dict);
        // LeetCode 276. Paint Fence
        int numWays(int n, int k);
        // LeetCode 315. Count of Smaller Numbers After Self
        std::vector<int> countSmaller(std::vector<int>& nums);
        // LeetCode 293. Flip Game
        std::vector<std::string> generatePossibleNextMoves(std::string s);
        // LeetCode 294. Flip Game II
        bool canWin(std::string s);
        // LeetCode 358. Rearrange String k Distance Apart
        std::string rearrangeString(std::string s, int k);
        // LeetCode 400. Nth Digit
        int findNthDigit(int n);
        // LeetCode 143. Reorder List
        void reorderList(ListNode* head);
        // LeetCode 144. Binary Tree Preorder Traversal
        std::vector<int> preorderTraversal(TreeNode* root);
        // LeetCode 147. Insertion Sort List
        ListNode* insertionSortList(ListNode* head);
    private:
        // LeetCode 46. Permutations
        void permuteDFS(const std::vector<int>& nums,
                        int level, std::vector<int>& visited,
                        std::vector<int>& out,
                        std::vector<std::vector<int>>& res);
        // LeetCode 47. Permutations II
        void permuteUniqueDFS(const std::vector<int>& nums, int level,
                              std::vector<int>& visited,
                              std::vector<int>& out,
                              std::vector<std::vector<int>>& res);

        // LeetCode 543. Diameter of Binary Tree
        std::unordered_map<TreeNode*, int> m;
        // LeetCode 301. Remove Invalid Parentheses
        bool isValid(const std::string& str);
        // LeetCode 449. Serialize and Deserialize BST
        void serializeHelper(TreeNode* root, std::ostringstream& os);
        TreeNode* deserializeHelper(std::istringstream& is);
        // LeetCode 329. Longest Increasing Path in Matrix
        int longestIncreasingPathDFS(const std::vector<std::vector<int>>& matrix,
                                     std::vector<std::vector<int>>& dp, int i, int j);
        // LeetCode 333. Largest BST Subtree
        bool isValidBST(const TreeNode* root, int& mn, int& mx, int& res);
        // LeetCode 130. Surrounded Regions
        void solveDFS(std::vector<std::vector<char>>& board, int i, int j);
    };
}


#endif //CPP_SOLUTION_H
