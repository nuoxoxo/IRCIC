#ifndef __RED_BLACK_TREE__
#define __RED_BLACK_TREE__

/**
 *  rules
 * 
 *  - a single node is either Red || Black
 *
 *  - the root is Black
 *  - all leaves (NIL) are black
 *  
 *  - if a node is Red, its children are Black
 *  
 *  - all paths from a node to its NIL descendants
 * 	contain the same amount of black nodes
 * 
 *          10                            10
 *         /   \                        /    \			//
 *        /     \                      /       \
 *       7       18                   B         R               
 * 	/ \     /   \                / \      /   \		//
 *    nil nil  14     21           nil nil   B      B               
 *            /  \   /   \                 /  \    / \		//
 *          11   16 nil  42              R     R  nil R    
 *         /  \  / \     / \            /  \  /  \    / \		//  
 *      nil nil nil nil nil nil      nil nil nil nil nil nil
 *  
 *  
 *  * The longest path (root to farthest NIL) is no more
 *  	than twice the length of shortest path (root to nearest NIL)
 *  
 *  ** SHortest path: all black nodes
 *  ** Longest path: alernating red and black
 *
 */




/*	Rotation rules		*/


/*      y   right rotate     x
/      / \  ------------>   / \ 	// 
/     x	  c                a   y 
/    / \     left rotate      / \ 	//
/   a   b   <------------    b   c
*/

#endif
