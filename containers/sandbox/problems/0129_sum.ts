/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function sumNumbers(root: TreeNode | null): number {
    // var helper = function(node, curr) {
    function helper(node: TreeNode | null, curr: number): number {
        if (node == null)
            return 0
        let res = curr * 10 + node.val
        if (node.left == null && node.right == null)
            return res
        return helper(node.left, res) + helper(node.right, res)
    }
    return helper(root, 0)
};
