# 📖 Learning Data Structures in C

This is my _Practice_ repository of implementing various ``Data Structures`` from **Scratch** in **C** to develop a fundamental understanding of core data-structures, most of which are abstracted in high-level languages.

## 🖇️ Resources

- [“Data Structures Using C” by Aaron M. Tanenbaum](https://archive.org/details/data-structures-using-c-aaron-m.-tanenbaum?utm_source=chatgpt.com)

- [“Fundamentals of Data Structures in C” (Horowitz, Sahni, Ellis)](https://mrajacse.wordpress.com/wp-content/uploads/2012/08/data-structures-and-algorithm-analysis-in-c-mark-allen-weiss.pdf?utm_source=chatgpt.com)

## 📂 Repository Structure

Every Data-Structure has its own folder and each of them has more folders in them for the sub-type / variant  of each data-structure. Inside every data-structure sub-type / variant folder, there is `code.c` file containing the implementation of the respective data-strucuture.

```plain
.
└── 📂 Learning-DS-C/
    ├── 📂 Array/
    │   ├── 📂 Dynamic/
    │   │   └── 📄 code.c
    │   └── 📂 Static/
    │       └── 📄 code.c
    ├── 📂 LinkedList/
    │   ├── 📂 CircularDoubly/
    │   │   └── 📄 code.c
    │   ├── 📂 CircularSingly/
    │   │   └── 📄 code.c
    │   ├── 📂 Doubly/
    │   │   └── 📄 code.c
    │   └── 📂 Singly/
    │       └── 📄 code.c
    ├── 📂 Stack/
    │   ├── 📂 Array/
    │   │   └── 📄 code.c
    │   └── 📂 LinkedList/
    │       └── 📄 code.c
    ├── 📂 Queue/
    │   ├── 📂 Linear/
    │   │   ├── 📂 Array/
    │   │   │   └── 📄 code.c
    │   │   └── 📂 LinkedList/
    │   │       └── 📄 code.c
    │   ├── 📂 Circular/
    │   │   ├── 📂 Array/
    │   │   │   └── 📄 code.c
    │   │   └── 📂 LinkedList/
    │   │       └── 📄 code.c
    │   ├── 📂 DoubleEnded/
    │   │   ├── 📂 Array/
    │   │   │   └── 📄 code.c
    │   │   └── 📂 LinkedList/
    │   │       └── 📄 code.c
    │   └── 📂 Priority/
    │       ├── 📂 Unsorted/
    │       │   ├── 📂 Array/
    │       │   │   └── 📄 code.c
    │       │   └── 📂 LinkedList/
    │       │       └── 📄 code.c
    │       └── 📂 Sorted/
    │           ├── 📂 Array/
    │           │   └── 📄 code.c
    │           └── 📂 LinkedList/
    │               └── 📄 code.c
    ├── 📂 Tree/
    │   ├── 📂 Binary/
    │   │   └── 📄 code.c
    │   ├── 📂 BST/
    │   │   └── 📄 code.c
    │   └── 📂 AVL/
    │       └── 📄 code.c
    ├── (more to be added...)
    ├── ❗ .gitignore
    └── 📘 Readme.md
```

## ⛓️ Implemented Data Structures

Since this repository focuses on Data Structures, **creation**, **insertion**, **removal** and **displaying** functions have been implemented for each data structure. As of now, this repository does not concern with Algorithms such as searching and sorting.

### Array

- **Static Array:**  
  Implemented Static Array by creating struct `Array` containing a fixed sized array ``int arr[MAX_SIZE]`` and an end index ``int end``. The end pointer keeps track of number of elements present in the array and helps avoiding overflow condition.
- **Dynamic Array:**  
  Implemented Dynamic Array by creating struct `Array` containing an integer pointer `int *arr`, capacity `int capacity`, and end index `int end`. Memory for array in the struct is allocated dynamically using _malloc_. Everytime the number of elements in the array reaches its capacity and new element is to be added, the array is reallocated with a new size of 2 (_MUL_) times as much as previous one using _realloc_.

### Linked List

- **Linear:**  
  - **Singly Linked List:**  
    Implemented Singly Linked List by creating struct `NODE` containing the data `int data` and pointer to next node `struct node * next`. The _head_ pointer is used to point to the starting node of the linked list. Each node points to the next node and the last node points to _NULL_.
  - **Doubly Linked List:**  
    Implemented Doubly Linked List by creating struct `NODE` containing the data `int data`, pointer to next node `struct node * next` and pointer to the previous node `struct node * prev`. The _head_ pointer is used to point to the starting node of the linked list and the _end_ pointer is used to point to the last node of the linked list. Each node points to its next and previous node and the last node points to _NULL_ as next.
- **Circular:**  
  - **Singly Circular Linked List:**  
    Implemented Singly Circular Linked List similar almost in same manner as Singly Lined List, the difference being here the **last** node's **next** pointer points back at the **starting** node.
  - **Doubly Circular Linked List:**  
    Implemented Doubly Circular Linked List similar almost in same manner as Doubly Lined List, the difference being here the **last** node's **next** pointer points back at the **starting** node and the **starting** node's **previous** pointer points at the **last** node.

### Stack

- **Stack using Array:**  
  Implemented Stack using Array by creating struct `STACK` similar to the struct of _Static Array_. The `int top` in the struct stores the index of the topmost element. **Push** and **Pop** functions are implemented with proper overflow/underflow checks.
- **Stack using Linked List:**  
  Implemented Stack using Linked List by creating struct `STACK` containing Node pointer `NODE *top`. The Nodes follow _Singly Linked List_ behaviour. The _head/root_ pointer of the _Linked List_ is treated as the _Top_ pointer which makes **Push** and **Pop** easy at the beginning of the Linked List.

### Queue

- **Linear:**  
  - **Queue using Array:**  
    Implemented Queue using Array by creating struct QUEUE with a fixed sized array `int arr[MAX_SIZE]`. The `int front` in the stuct stores the index of the first element (_where deletion happens_) and the `int rear` stores the position of the last element (_where insertion happens_). When every element is removed the _rear_ and _front_ indexes are reverted back to _-1_.
  - **Queue using Linked List:**  
  Implemented Queue using Linked List by creating struct `QUEUE` containing Node pointers `NODE *front` and `NODE *rear`. The Nodes follow _Singly Linked List_ behaviour. The _head/root_ node pointer of the _Linked List_ is treated as the _front_ pointer (_where deletion happens_) and the _end/last_ node pointer is treated as the _rear_ pointer (_where insertion happnes_).
- **Circular:**  
  - **Circular Queue using Array:**  
    Implemented Circular Queue using Array similar to _Linear Queue using Array_, the fundamental difference being the use of `% - modulo` operator to wrap _front_ and _rear_ indexes making them increment circularly to prevent wastage of space.
  - **Circular Queue using Linked List:**  
  Implemented Circular Queue using Linked List similar to _Linear Queue using Linked List_, the fundamental difference being the _rear_ pointer i.e. the last node points next back to the _front_ pointer i.e. the first node.
- **Double Ended:**  
  - **Circular Deque using Array:**  
    Implemented Circular Deque using Array similar to _Circular Queue using Array_ (_to avoid wastage of space_), the fundamental difference being **insertion** and **deletion** can happen at both _front_ and _rear_.
  - **Deque using Linked List:**  
    Implemented Deque using Linked List similar to _Linear Queue using Linked List_, but, _Doubly Linked List_ was used instead of the _Singly Linked List_ so that _insertion_ and _deletion_ at both _front_ and _rear_ are quick.
- **Priority:**  
  - **Unsorted:**  
    - **Array:**  
      Implemented Unsorted Priority Queue using Array similar to _Circular Queue using Array_. The fundamental difference being, there is an extra array `int prio[MAX_SIZE]` which stores the **priority** of every element at the same index as of them in the `int arr[MAX_SIZE]`. During **insertion** a priority value is entered for the element. During **deletion** the element with the least corresponding priority value is deleted.  
      Here, `Lower Priority Value = Higher Priority to Delete`. e.g. _Element with priority 3 will be deleted before than element with priority 7_.
    - **Linked List:**  
     Implemented Unsorted Priority Queue using Linked List similar to _Linear Queue using Linked List_, but, used _Doubly Linked List_ instead of _Singly Linked List_. The `NODE` struct additionally contains `int priority`. During **insertion** a priority value is entered for the element. During **deletion** the element with the least priority value is deleted.
  - **Sorted:**  
    - **Array:**  
      Implemented Sorted Priority Queue using Array similar to _Circular Queue using Array_. The fundamental difference being, there is an extra array `int prio[MAX_SIZE]` which stores the **priority** of every element at the same index as of them in the `int arr[MAX_SIZE]`. During **insertion** a priority value is entered and the element is stored in order of priority. The elements with higher priority value are shifted right and the element to be inserted is placed just after the lower priority valued element. **Deletion** is performed at the front removing the highest priority valued element in the queue.
    - **Linked List:**  
     Implemented Sorted Priority Queue using Linked List similar to _Linear Queue using Linked List_, but, used _Doubly Linked List_ instead of _Singly Linked List_. The `NODE` struct additionally contains `int priority`. During **insertion** a priority value is entered and the element is stored in order of priority. The elements with higher priority value are shifted right and the element to be inserted is placed just after the lower priority valued element. **Deletion** is performed at the front removing the highest priority valued element in the queue.

### Tree

- **Binary:**  
  Implemented Binary Tree by creating struct `typedef struct node{...} NODE` with data pointer `int data`, `struct node *left` as left pointer and and `struct node *right` as right pointer. Additionally **Queue** was implemented (_using Singly Linked List like before_) to support **BFS** traversal. Implemented Binary Tree functions:  
  - **create** : recursively creates the tree by asking where to add nodes at every point.  
  - **display_inorder** : displays the tree in **inorder** sequence.  
  - **display_preorder** : displays the tree in **preorder** sequence.  
  - **display_postorder** : displays the tree in **postorder** sequence.  
  - **display_levelorder** : displays the tree in **level order** sequence (_using the implemented Queue_).  
  - **count_nodes** : counts the total nodes in the tree.  
  - **count_leaves** : counts the total leaves in the tree.  
  - **count_internal** : counts the total internal nodes in the tree.  
  - **count_height** : counts the total no. of edges from root to the deepest leaf (_height_) in the tree.  
  - **free_all** : frees all the dynamically allocated nodes in the tree in post order traversal.
- **Binary Search Tree:**  
  Implemented Binary Search Tree by creating struct similar to that of _Binary Tree_. The fundamental difference being the logic of insertion and deletion. Implemented Binary Search Tree functions:
  - **create** : allocates memory for _NODE_ and returns its address.
  - **insert** : inserts a new node at the correct position in the BST through recursion by following the BST insertion rules and returns the address of the root.
  - **search** : searches for a value in the BST recursively using the BST rules. Returns _NULL_ if value not present.
  - **find_min** : finds the minimum value in the BST using the BST rules through recursion.
  - **find_max** : finds the maximum value in the BST using the BST rules through recursion.
  - **delete_node** : deletes the node with specified value using recursion and handling proper replacement and structure of nodes by following the BST rules.
  - **display_inorder** : displays the tree in **inorder** sequence. This prints the values in ascending order.
  - **free_all** : frees all the dynamically allocated nodes in the BST in post order traversal.
- **AVL:**  
  Implemented AVL Tree similar to that of _Binary Search Tree_. The fundamental difference being, now every node stores its height in the struct with `int height`. The _insert_ function and _delete_ function are now modified to recalculate _height_ of every node in each operation and if the subtree is imbalanced, it is balanced using the AVL Tree rules, all of which is achieved through recursion and helper functions. Implemented AVL Tree functions:
  - **create** : allocates memory for _NODE_ and returns its address.
  - **update_height** : helper function to update height of the node using the heights of its left and right subtree.
  - **get_balance** : helper function to get the balance factor of the subtree using the heights of its left and right subtrees.
  - **right_rotate** : helper function that implements right rotation following the AVL Tree rules.
  - **left_rotate** : helper function that implements left rotation following the AVL Tree rules.
  - **balance_nodes** : balances _LL_, _LR_, _RR_ and _RL_ conditions following the AVL Tree rules.
  - **insert** : inserts a new node at the correct position in the BST through recursion by following the BST insertion rules and then updates the height of every node and balances the tree if required by following the AVL Tree rules. It returns the address of the root.
  - **search** : searches for a value in the BST recursively using the BST rules. Returns _NULL_ if value not present.
  - **find_min** : finds the minimum value in the BST using the BST rules through recursion.
  - **find_max** : finds the maximum value in the BST using the BST rules through recursion.
  - **delete_node** : deletes the node with specified value using recursion and handling proper replacement and structure of nodes by following the BST rules and then updates the height of every node and balances the tree if required by  following the AVL Tree rules.
  - **display_inorder** : displays the tree in **inorder** sequence. This prints the values in ascending order.
  - **free_all** : frees all the dynamically allocated nodes in the BST in post order traversal.
- **Red Black:**
  Implemented Red Black Tree similar to that of _Binary Search Tree_. The fundamental difference being, now, instead of height, every node stores a color which is implemented by _typedef enum {...} Color_ (_DOUBLE\_BLACK, BLACK, RED_). Insertion and Deletion follow the BST and Red Black Tree rules. Implemented Red Black Tree funcrtions:
  - **create** : allocates memory for _NODE_ and returns its address.
  - **is_red** : helper function to know if a node is red.
  - **flip_color** : helper function to flip the color of a node from red to black and vice versa.
  - **color_check** : helper function to maintain color balance during insertion following the Red Black Tree rules.
  - **right_rotate** : helper function that implements right rotation.
  - **left_rotate** : helper function that implements left rotation.
  - **fix_black** : helper function to fix the black height imbalance during deletion with the help of recursion and following the Red Black Tree rules.
  - **insert_recursive** : inserts a new node at the correct position in the BST through recursion by following the BST insertion rules and then fixes color imbalance with _color\_check_.
  - **insert** : Wrapper function for _insert\_recursive_ to always keep the root as black.
  - **search** : searches for a value in the BST recursively using the BST rules. Returns _NULL_ if value not present.
  - **find_min** : finds the minimum value in the BST using the BST rules through recursion.
  - **find_max** : finds the maximum value in the BST using the BST rules through recursion.
  - **delete_recursive** : deletes the node with specified value using recursion and handling proper replacement and structure of nodes by following the BST rules and maintains black height according to Red Black Tree rules using _fix\_black_.
  - **delete_node** : Wrapper function for _delete\_recursive_ to always keep the root as black.
  - **display_inorder** : displays the tree in **inorder** sequence. This prints the values in ascending order.
  - **free_all** : frees all the dynamically allocated nodes in the BST in post order traversal.
  - **validate_color** : validates that there are no Red-Red structure in the tree through recursion.
  - **validate_black_height** : validates that the number of black nodes accross all paths from any node are consistent.

(_❕ This repository is a practise in progress and more data-structures will be added in future_)
