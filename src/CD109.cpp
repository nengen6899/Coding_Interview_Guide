/* CD109: 环形链表的约瑟夫问题(普通解法) */

/* filename: CD109.cpp
 * author:  leisy
 * date: 2020.10.5
 * version: 1.0
 * description: 《Programmer interview guide》, charpter 2, CD109,
 *     Josephus problem of circular linked lists.
 */
 
 
#include <iostream>
using namespace std;
 
 
struct node{
 	int val;
 	struct node *next;
};

/* create circular list, the node val is from 1 to n */
node *do_circular_list(int n) {
	node *head = NULL;
 	node *back = NULL;
 	
	 if (n <= 0) {
 		return head;
	}
	
	for (int i = 1; i <= n; i++) {
		node *ptr = new node();
		ptr->val = i;
		ptr->next = NULL;
		if (i == 1) {
			head = ptr;
			back = ptr;
		} else {
			back->next = ptr;
			back = ptr;
		}
	}
	
	back->next = head;
 	
 	return head;
 }
 
 
node *remove_node(node *p_rm_node, node *rm_node) {
	
	
	
	
	
}
 
 
/* get live node's value */
int get_live(node *head, int m) {
	/* assert(head != NULL), and the list is circular */
	node *begin = head;
	node *back = head;
	
	if (head == NULL) {
		return -1;
	}
	
	/* if kill the m-th node, the live node is the last node of list */
	if (m == 1) {
		while (back->next != head) {
			back = back->next;
		}
		
		return back->val;
	}
	
	while (begin != begin->next) {
		
		for (int i = 1; i < m - 1; i++) {
			begin = begin->next;
		}
		node *p_rm_node = begin;
		node *rm_node = begin->next;
		begin = remove_node(p_rm_node, rm_node);
	}
	
	
	return begin->val;
}


 
int main()
{
	int n, m;
 	int live_val;
 	node *head;
 	
	cin>>n>>m;
	head = do_circular_list(n);
	
//	node *ptr = head;
//	for (int i = 1; i < n + 4; i++) {
//		cout<<ptr->val<<" ";
//		ptr = ptr->next;
//	}
	
	live_val = get_live(head, m);
	cout<<live_val;
 	
 	return 0;
 }
