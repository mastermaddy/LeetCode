/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public TreeNode SearchBST(TreeNode root, int searchKey) {
        if(root==null || root.val == searchKey) return root;
        return (root.val > searchKey)?SearchBST(root.left, searchKey):SearchBST(root.right, searchKey);
    }
}
