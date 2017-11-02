//
// Created by ChenshuoYue on 11/1/17.
//

#ifndef LEETCODEC17_SOLUTION_HPP
#define LEETCODEC17_SOLUTION_HPP
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {

public:
    bool isMatch(string s, string p);
    vector<int> countBits(int num);
    int numIslands(vector<vector<char>>& grid);
    vector<string> generateParenthesis(int n);
    vector<vector<string>> groupAnagrams(vector<string>& strs);
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);
    vector<Interval> merge(vector<Interval>& intervals);
    int maxProduct(vector<int>& nums);
    void rotate(vector<vector<int>>& matrix);
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

private:
    void numIslandsDFS(vector<vector<char>>& grid,
                       vector<vector<bool>>& visited,
                       int r, int c);
};


#endif //LEETCODEC17_SOLUTION_HPP
