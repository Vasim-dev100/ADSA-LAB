# 🌳 Binary Search Tree (BST) Implementation in C (Insert, Delete, Search, Traversals)

This program implements a full **Binary Search Tree (BST)** with a menu-driven interface.  
It supports insertion, deletion, searching, traversals, and clearing the tree.

---

## 📌 Features
- **Insert** single or multiple keys
- **Delete** any key (handles all 3 cases: leaf, one child, two children)
- **Search** for a key in BST
- **Recursive traversals**:
  - Inorder  
  - Preorder  
  - Postorder  
- **Memory-safe**: frees entire tree on request or exit
- **Menu-driven interactive interface**

---

## 🛠️ BST Operations

### ✔ Insert  
Recursive insertion maintaining BST property.  
Duplicate keys are ignored.

### ✔ Search  
Recursive search returning 1 (found) or 0 (not found).

### ✔ Delete  
Handles:
- Node with **no child**
- Node with **one child**
- Node with **two children** (uses inorder successor)

### ✔ Traversals  
- **Inorder** → sorted order  
- **Preorder** → root-left-right  
- **Postorder** → left-right-root  

### ✔ Free Tree  
Recursively frees all nodes.

---

## 🚀 Build & Run

### Compile
```bash
gcc bst.c -o bst
```

### Run
```bash
./bst
```

---

## 📊 Example Usage
```
--- BST Menu ---
1. Create (insert multiple keys)
2. Insert key
3. Delete key
4. Inorder traversal
5. Preorder traversal
6. Postorder traversal
7. Clear tree
8. Exit
Enter choice: 1
How many keys to insert? 5
Enter 5 integers:
10 4 15 2 7

Enter choice: 4
Inorder: 2 4 7 10 15
```

---

## 🧠 Insight
This program demonstrates core BST concepts:
- Ordered insertion
- Efficient search (O(log n) average)
- Structural deletion using inorder successor
- Tree traversal patterns  
Perfect for learning tree-based data structures in C.

