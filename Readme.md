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

- **Singly Linked List:**  
  Implemented Singly Linked List by creating struct `NODE` containing the data `int data` and pointer to next node `struct node * next`. The _head_ pointer is used to point to the starting node of the linked list. Each node points to the next node and the last node points to _NULL_.
- **Doubly Linked List:**  
  Implemented Doubly Linked List by creating struct `NODE` containing the data `int data`, pointer to next node `struct node * next` and pointer to the previous node `struct node * prev`. The _head_ pointer is used to point to the starting node of the linked list and the _end_ pointer is used to point to the last node of the linked list. Each node points to its next and previous node and the last node points to _NULL_ as next.
- **Singly Circular Linked List:**  
  Implemented Singly Circular Linked List similar almost in same manner as Singly Lined List, the difference being here the **last** node's **next** pointer points back at the **starting** node.
- **Doubly Circular Linked List:**  
  Implemented Doubly Circular Linked List similar almost in same manner as Doubly Lined List, the difference being here the **last** node's **next** pointer points back at the **starting** node and the **starting** node's **previous** pointer points at the **last** node.

### Stack

- **Stack using Array:**  
  Implemented Stack using Array by creating struct `STACK` similar to the struct of _Static Array_. The `int top` in the struct stores the index of the topmost element. **Push** and **Pop** functions are implemented with proper overflow/underflow checks.

(_❕ This repository is a practise in progress and more data-structures will be added in future_)
