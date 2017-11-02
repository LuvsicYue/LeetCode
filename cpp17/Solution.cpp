//
// Created by ChenshuoYue on 11/1/17.
//

#include "Solution.hpp"
#include <iostream>
#include <algorithm>


// Internal Helper Function



// Member Function
bool Solution::isMatch(string s, string p) {
    // p is pattern, s is matching string
    if (p.empty())
        return s.empty();
    if (p.size() == 1)
        return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
    // p[1] is not '*'
    if (p[1] != '*') {
        if (s.empty()) return false;
        return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }
    // p[1] is '*'
    while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
        if (isMatch(s, p.substr(2))) // * is used as 0
            return true;
        s = s.substr(1);  // * is used as 1 or more
    }
    // * is used as 0 since not match with starting of s
    return isMatch(s, p.substr(2));
}


vector<int> Solution::countBits(int num) {
    // 0 : 0
    // ------
    // 1 : 1
    // ------
    // 0 + 1 : 1
    // 1 + 1 : 2
    // ------
    // 0 + 1 : 1
    // 1 + 1 : 2
    // 1 + 1 : 2
    // 2 + 1 : 3
    // ------
    vector<int> res = {0};
    int i = 1;
    while (i <= num) {
        vector<int> tmp = res;
        for (auto j : tmp) {
            res.push_back(j + 1);
            if (++i > num)
                return res;
        }

    }
    return res;
}

int Solution::numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty())
        return 0;
    int rows = grid.size(), cols = grid[0].size(), res = 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == '1' && !visited[r][c]) {
                numIslandsDFS(grid, visited, r, c);
                ++res;
            }
        }
    }
    return res;
}

void Solution::numIslandsDFS(vector<vector<char>>& grid,
                             vector<vector<bool>>& visited,
                             int r, int c) {
    if (r < 0 || r >= grid.size()) return;
    if (c < 0 || c >= grid[r].size()) return;
    if (grid[r][c] != '1' || visited[r][c]) return;
    visited[r][c] = true;
    numIslandsDFS(grid, visited, r - 1, c);
    numIslandsDFS(grid, visited, r, c + 1);
    numIslandsDFS(grid, visited, r + 1, c);
    numIslandsDFS(grid, visited, r, c - 1);
}

vector<string> Solution::generateParenthesis(int n) {

}

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {

}

TreeNode* Solution::mergeTrees(TreeNode* t1, TreeNode* t2) {

}

vector<Interval> Solution::merge(vector<Interval>& intervals) {

}

int Solution::maxProduct(vector<int>& nums) {

}

void Solution::rotate(vector<vector<int>>& matrix) {

}

ListNode* Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {

}





// Implementation of static Internal Helper Function

