-assumption: input is only one line
-clist array is the element, i.e. alphabet, existed in the input
-clist_count array is the number of times it occurs
-clist and clist_array matches. Meaning that index the number of times clist[i] occurs is clist_count[i]
-then insert into queue

-addingToTree sorts the queue into a tree, connecting the the two least existed using Extract_Min_Node(), connecting using the left and right node pointers
-they are then added back into the tree
-then recursively run, until there's only one node left, i.e. the total (only root left, tree constructed). This happens when the second extraction returns NULL (first extraction will return the root node, hence there will always be at least one node inside)

-char c and string clist1 acts similarly to clist and clist_count
-char c is the character and clist1 is the code generate, e.g. b and 100, a and 0