/*
    This question was asked in the first round interview of Exotel for SDE 2 role
    https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

    I am pasting just the function that solves this problem. This solution does not include accepting input,
    and creating the binary tree using the input.
*/

#include<iostream>

using namespace std;

// Definition of Binary Tree
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
    
    bool checkPseudoPalindrome(int countOdd){
        
        if(countOdd > 1)
            return false;
        return true;
            
    }
    
    int countOfOddFrequencyNumbers(int countOdd, int arr[], int val){
        
        if(arr[val]%2 == 0)
            countOdd--;
        else
            countOdd++;
        return countOdd;
    }
    
    int countPseudoPalindromicPaths(TreeNode* root, int arr [], int count, int &countOdd){
        
        // v.push_back(root->val);
        arr[root->val]++;
        countOdd = countOfOddFrequencyNumbers(countOdd, arr, root->val);
        
        if(root->left == NULL && root->right == NULL){
            if(checkPseudoPalindrome(countOdd))
                count++;
        }
        
        if(root->left != NULL)
            count = countPseudoPalindromicPaths(root->left, arr, count, countOdd);
        
        if(root->right != NULL)
            count = countPseudoPalindromicPaths(root->right, arr, count, countOdd);        
        
        // v.pop_back();
        arr[root->val]--;
        countOdd = countOfOddFrequencyNumbers(countOdd, arr, root->val);
        
        return count;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        // vector<int> v;
        int arr[10] = {0};
        int countOdd = 0;
        return countPseudoPalindromicPaths(root, arr, count, countOdd);
    }
};