//
//  Solution.cpp
//  LeetCode Test
//
//  Created by ChenshuoYue on 10/29/16.
//  Copyright © 2016 Machinarium. All rights reserved.
//

#include "Solution.h"
#include <iostream>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace MyCode;
using namespace std;

int Solution::wordsTyping(const vector<string>& sentence, int rows, int cols) {
    string all = "";
    for (string word : sentence) all += (word + " ");
    int start = 0, len = int(all.size());
    for (int i = 0; i < rows; ++i) {
        start += cols;
        if (all[start % len] == ' ') {
            ++start;
        } else {
            while (start > 0 && all[(start - 1) % len] != ' ') {
                --start;
            }
        }
    }
    return start / len;
}

//--------------------------------------------------------------------
// LeetCode 46. Permutations
vector<vector<int>> Solution::permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> out;
    vector<int> visited(nums.size(), 0);
    permuteDFS(nums, 0, visited, out, res);
    return res;
}

void Solution::permuteDFS(const vector<int>& nums,
                          int level, vector<int>& visited,
                          vector<int>& out, vector<vector<int>>& res) {
    if (level == nums.size()) {
        res.push_back(out);
        return;
    } else {
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 0) {
                visited[i] = 1;
                out.push_back(nums[i]);
                permuteDFS(nums, level + 1, visited, out, res);
                out.pop_back();
                visited[i] = 0;
            }
        }
    }
}

//--------------------------------------------------------------------
// LeetCode 47. Permuations II
vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> out;
    vector<int> visited(nums.size(), 0);
    sort(nums.begin(), nums.end());
    permuteUniqueDFS(nums, 0, visited, out, res);
    return res;
}

void Solution::permuteUniqueDFS(const vector<int>& nums, int level,
                                vector<int>& visited,
                                vector<int>& out,
                                vector<vector<int>>& res) {

    if (level >= nums.size()) {
        res.push_back(out);
        return;
    } else {
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 0) {
                if (i > 0 && nums[i] == nums[i - 1]
                    && visited[i - 1] == 0) continue;

                visited[i] = 1;
                out.push_back(nums[i]);
                permuteUniqueDFS(nums, level + 1, visited, out, res);
                out.pop_back();
                visited[i] = 0;
            }
        }
    }
}

//--------------------------------------------------------------------
// LeetCode 60. Permuation Sequence
string Solution::getPermutation(int n, int k) {
    string res;
    string num = "123456789";
    vector<int> f(n, 1);
    // n!
    for (int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
    k = k - 1;
    for (int i = n; i >= 1; --i) {
        int j = k / f[i - 1];
        res.push_back(num[j]);
        k = k % f[i - 1];
        num.erase(j, 1);  // starting index: j length: 1
    }
    return res;
}

//--------------------------------------------------------------------
// LeetCode 498. Diagonal Traverse
vector<int> Solution::findDiagonalOrder(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
    int m = (int)matrix.size(), n = (int)matrix[0].size(), r = 0, c = 0, k = 0;
    vector<int> res(m * n);
    // {-1, 1} right corner direction
    // {1, -1} left corner direction
    vector<vector<int>> dirs{{-1, 1}, {1, -1}};
    for (int i = 0; i < m * n; ++i) {
        res[i] = matrix[r][c];
        r += dirs[k][0];
        c += dirs[k][1];
        if (r >= m) {  // out of max row
            r = m - 1;
            c += 2;
            k = 1 - k;
        }
        if (c >= n) {  // out of max column
            c = n - 1;
            r += 2;
            k = 1 - k;
        }
        if (r < 0) {  // out of min row
            r = 0;
            k = 1 - k;
        }
        if (c < 0)  {  // out of min column
            c = 0;
            k = 1 - k;
        }
    }
    return res;
}

//--------------------------------------------------------------------
// LeetCode 543. Diameter of Binary Tree
int Solution::diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    maxDepth(root, res);
    return res;
}

int Solution::maxDepth(TreeNode* node, int& res) {
    if (node == NULL) return 0;
    if (m.count(node) != 0) return m[node];
    int left = maxDepth(node->left, res);
    int right = maxDepth(node->right, res);
    res = max(res, left + right);
    m[node] = (max(left, right) + 1);
    return m[node];
}

//--------------------------------------------------------------------
// LeetCode 164. Maximum Gap
int Solution::maximumGap(const vector<int>& nums) {
    if (nums.size() < 2) return 0;

    int mx = INT_MIN, mn = INT_MAX, n = (int)nums.size();
    for (auto i : nums) {
        mx = max(i, mx);
        mn = min(mn, i);
    }

    int size = (mx - mn) / n  + 1;
    int bucket_nums = (mx - mn) / size + 1;
    vector<int> bucket_min(bucket_nums, INT_MAX);
    vector<int> bucket_max(bucket_nums, INT_MIN);
    set<int> s;
    for (int i : nums) {
        int idx = (i - mn) / size;
        bucket_min[idx] = min(bucket_min[idx], i);
        bucket_max[idx] = max(bucket_max[idx], i);
        s.insert(idx);
    }
    int pre = 0, res = 0;
    for (int i = 0; i < bucket_nums; ++i) {
        if (s.count(i) == 0) continue;
        res = max(res, bucket_min[i] - bucket_max[pre]);
        pre = i;
    }
    return res;

}

//--------------------------------------------------------------------
// LeetCode 301. Remove Invalid Parentheses
vector<string> Solution::removeInvalidParentheses(string input) {
    vector<string> res;
    unordered_set<string> visited;
    queue<string> q;
    q.push(input);
    visited.insert(input);
    bool found = false;
    while (!q.empty()) {
        input = q.front();
        q.pop();
        if (isValid(input)) {
            res.push_back(input);
            found = true;
        }
        // get minimum deletion
        if (found) continue;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] != '(' && input[i] != ')') continue;
            string t = input.substr(0, i) + input.substr(i + 1);
            if (visited.find(t) == visited.end()) {
                q.push(t);
                visited.insert(t);
            }
        }

    }
    return res;
}

bool Solution::isValid(const string& str) {
    int cnt = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') ++cnt;
        if (str[i] == ')' && cnt-- == 0) return false;
    }
    return cnt == 0;
}

//--------------------------------------------------------------------
// LeetCode 449. Serialize and Deserialize BST
string Solution::serialize(TreeNode* root) {
    ostringstream os;
    serializeHelper(root, os);
    return os.str();
}

// Decodes your encoded data to tree.
TreeNode* Solution::deserialize(string data) {
    istringstream is(data);
    return deserializeHelper(is);
}

void Solution::serializeHelper(TreeNode* root, ostringstream& os) {
    if (root == NULL) os << "# ";
    else {
        os << root->val << " ";
        serializeHelper(root->left, os);
        serializeHelper(root->right, os);
    }
}

TreeNode* Solution::deserializeHelper(istringstream& is) {
    string val = "";
    is >> val;
    if (val == "#") return NULL;
    TreeNode* node = new TreeNode(stoi(val));
    node->left = deserializeHelper(is);
    node->right = deserializeHelper(is);
    return node;
}

//--------------------------------------------------------------------
// LeetCode 329. Longest Increasing Path in a Matrix
int Solution::longestIncreasingPath(vector<vector<int>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
    int res = 1, m = (int)matrix.size(), n = (int)matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            res = max(res, longestIncreasingPathDFS(matrix, dp, i, j));
        }
    }
    return res;
}

int Solution::longestIncreasingPathDFS(const vector<vector<int>>& matrix,
                                       vector<vector<int>>& dp, int i, int j) {
    if (dp[i][j] != 0) return dp[i][j];
    // dirs left, up, right, down
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int mx = 1, m = (int)matrix.size(), n = (int)matrix[0].size();
    for (auto a : dirs) {
        int x = i + a[0], y = j + a[1];
        if (x < 0 || x >= m || y < 0 || y >= n
            || matrix[x][y] <= matrix[i][j]) continue;
        int len = 1 + longestIncreasingPathDFS(matrix, dp, x, y);
        mx = max(mx, len);
    }
    dp[i][j] = mx;
    return mx;
}

//--------------------------------------------------------------------
// LeetCode 333. Largest BST Subtree
int Solution::largestBSTSubtree(TreeNode* root) {
    int res = 0, mn = INT_MIN, mx = INT_MAX;
    isValidBST(root, mn, mx, res);
    return res;
}

bool Solution::isValidBST(const TreeNode* root, int& mn, int& mx, int& res) {
    if (root == NULL) return true;
    // left_n: nodes of left subtree
    // right_n: nodes of right subtree
    // left_mn, left_mx: minimum & maximum of left subtree
    // right_mn, right_mx: minmum & maximum of right subtree
    int left_n = 0, right_n = 0, left_mn = INT_MIN;
    int right_mn = INT_MIN, left_mx = INT_MAX, right_mx = INT_MAX;
    bool left = isValidBST(root->left, left_mn, left_mx, left_n);
    bool right = isValidBST(root->right, right_mn, right_mx, right_n);
    if (left && right) {
        if ((root->left == NULL || root->val > left_mx) &&
            (root->right == NULL || root->val < right_mn)) {
            res = left_n + right_n + 1;
            mn = root->left ? left_mn : root->val;
            mx = root->right ? right_mx : root->val;
            return true;
        }

    }
    res = max(left_n, right_n);
    return false;
}

//--------------------------------------------------------------------
// LeetCode 130. Surrounded Regions
void Solution::solve(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) return;
    int r = (int)board.size(), c = (int)board[0].size();

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if ((i == 0 || i == r - 1 || j == 0 || j == c - 1)
                && board[i][j] == 'O')
                solveDFS(board, i, j);
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == '$') board[i][j] = 'O';
        }
    }
}

void Solution::solveDFS(vector<vector<char>>& board, int i, int j) {
    if (board[i][j] == 'O') {
        board[i][j] = '$';
        // up
        if (i > 0 && board[i - 1][j] == 'O') {
            solveDFS(board, i - 1, j);
        }
        // right
        if (j < board[i].size() - 1 && board[i][j + 1] == 'O') {
            solveDFS(board, i, j + 1);
        }
        // down
        if (i < board.size() - 1 && board[i + 1][j] == 'O') {
            solveDFS(board, i + 1, j);
        }
        // left
        if (j > 1 && board[i][j - 1] == 'O') {
            solveDFS(board, i, j - 1);
        }
    }
}
//--------------------------------------------------------------------
// LeetCode 325. Maximum Size Subarray Sum Equals k

int Solution::maxSubArrayLen(vector<int>& nums, int k) {
    int sum = 0, res = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (sum == k) res = i + 1;
        else if (m.count(sum - k) != 0) res = max(res, i - m[sum - k]);
        if (m.count(sum) == 0) m[sum] = i;
    }
    return res;
}

//--------------------------------------------------------------------
// LeetCode 314. Binary Tree Vertical Order Traversal
vector<vector<int>> Solution::verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL) return res;
    map<int, vector<int>> m;
    queue<pair<int, TreeNode*>> q;
    q.push({0, root});
    while (!q.empty()) {
        auto a = q.front();
        q.pop();
        m[a.first].push_back(a.second->val);
        if (a.second->left != NULL) q.push({a.first - 1, a.second->left});
        if (a.second->right != NULL) q.push({a.first + 1, a.second->right});
    }
    for (auto a : m) {
        res.push_back(a.second);
    }
    return res;
}

//--------------------------------------------------------------------
// LeetCode 139. Word Break
bool Solution::wordBreak(string s, unordered_set<string> &dict) {
    int len = (int)s.size();
    vector<bool> res(s.size() + 1, false);
    res[0] = true;
    for (int i = 0; i < len + 1; ++i) {
        for (int j = 0; j < i; ++j) {
            if (res[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                res[i] = true;
                break;
            }
        }
    }
    return res[len];
}

//--------------------------------------------------------------------
// LeetCode 276. Paint Fence
int Solution::numWays(int n, int k) {
    if (n == 0) return 0;
    int same = 0, diff = k;
    for (int i = 2; i <= n; ++i) {
        int t = diff;
        diff = (same + diff) * (k - 1);
        same = t;
    }
    return same + diff;
}

//--------------------------------------------------------------------
// LeetCode 315. Count of Smaller Numbers After Self
vector<int> Solution::countSmaller(vector<int>& nums) {
    vector<int> t, res(nums.size());
    for (int i = (int)nums.size() - 1; i >= 0; --i) {
        int left = 0, right = (int)t.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (t[mid] >= nums[i]) right = mid;
            else left = mid + 1;
        }
        res[i] = right;
        t.insert(t.begin() + right, nums[i]);
    }
    return res;
}
//--------------------------------------------------------------------
// LeetCode 293. Flip Game
vector<string> Solution::generatePossibleNextMoves(string s) {
    vector<string> res;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '+' && s[i - 1] == '+' ) {
            res.push_back(s.substr(0, i - 1) + "--" + s.substr(i + 1));
        }
    }
    return res;

}

//--------------------------------------------------------------------
// LeetCode 294. Flip Game II
bool Solution::canWin(string s) {
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '+' && s[i - 1] == '+' && !canWin(s.substr(0, i - 1) + "--" + s.substr(i + 1))) {
            return true;
        }
    }
    return false;
}

//--------------------------------------------------------------------
// LeetCode 358. Rearrange String k Distance Apart
string Solution::rearrangeString(string s, int k) {
    if (k == 0) return s;
    string res;
    int len = (int)s.size();
    unordered_map<char, int> m;
    priority_queue<pair<int, char>> q;
    for (auto a : s) ++m[a];

    for (auto it = m.begin(); it != m.end(); ++it) {
        q.push({it->second, it->first});
    }

    while (!q.empty()) {
        vector<pair<int, int>> v;
        int cnt = min(k, len);
        for (int i = 0; i < cnt; ++i) {
            if (q.empty()) return "";
            auto t = q.top(); q.pop();
            res.push_back(t.second);
            if (--t.first > 0) v.push_back(t);
            --len;
        }
        for (auto a : v) q.push(a);
    }
    return res;
}

//--------------------------------------------------------------------
// LeetCode 400. Nth Digit
int Solution::findNthDigit(int n) {
    long long len = 1, cnt = 9, start = 1;
    while (n > len * cnt) {
        n -= len * cnt;
        ++len;
        cnt *= 10;
        start *= 10;
    }
    start += (n - 1) / len;
    string t = to_string(start);
    return t[(n - 1) % len] - '0';
}

//--------------------------------------------------------------------
// LeetCode 143. Reorder List
void Solution::reorderList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = NULL;
    ListNode* last = mid;
    ListNode* pre = NULL;
    // reverse the right half of list
    while (last) {
        ListNode *next = last->next;
        last->next = pre;
        pre = last;
        last = next;
    }
    while (head && pre) {
        ListNode *next = head->next;
        head->next = pre;
        pre = pre->next;
        head->next->next = next;
        head = next;
    }
}

//--------------------------------------------------------------------
// LeetCode 144. Binary Tree Preorder Traversal
vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    if (!root) return res;
    s.push(root);
    while (!s.empty()) {
        TreeNode *p = s.top();
        s.pop();
        res.push_back(p->val);
        if (p->right) s.push(p->right);
        if (p->left) s.push(p->left);
    }
    return res;
}

//--------------------------------------------------------------------
// LeetCode 147. Insertion Sort List
ListNode* Solution::insertionSortList(ListNode* head) {
    ListNode *res = new ListNode(-1);
    ListNode *cur = res;
    while (head) {
        ListNode *next = head->next;
        cur = res;
        while (cur->next && cur->next->val <= head->val) {
            cur = cur->next;
        }
        head->next = cur->next;
        cur->next = head;
        head = next;
    }
    return res->next;
}