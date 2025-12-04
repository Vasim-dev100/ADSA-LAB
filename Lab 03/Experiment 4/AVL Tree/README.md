# 🌲 AVL Tree Implementation in C (Insert, Delete, Inorder Traversal)

This program implements a **self-balancing AVL Tree** with all major operations:  
✔ Insert  
✔ Delete  
✔ Inorder Traversal  
✔ Automatic Rebalancing (LL, RR, LR, RL rotations)  
It provides a clean, menu-driven interface for interactive usage.

---

## 📌 Features
- Fully functional **AVL Tree** with balancing
- Height updates and all 4 rotation cases:
  - LL (Right Rotation)  
  - RR (Left Rotation)  
  - LR (Left-Right Rotation)  
  - RL (Right-Left Rotation)
- Insert multiple keys at once
- Delete any key while preserving AVL balance
- Inorder traversal (sorted output)
- Memory cleanup before exit

---

## 🛠️ Core Concepts

### ✔ AVL Tree Rules
A node is **balanced** if:
```
balance = height(left subtree) - height(right subtree)
```
Valid range:
```
-1, 0, +1
```
If balance goes outside this range → perform a rotation.

### ✔ Rotations Implemented
- `rightRotate()` – fixes LL imbalance  
- `leftRotate()` – fixes RR imbalance  
- Combined rotations:
  - LR: leftRotate(child) → rightRotate(node)  
  - RL: rightRotate(child) → leftRotate(node)

### ✔ Insert Operation
- Standard BST insert  
- Update height  
- Check balance  
- Perform appropriate rotation case  

### ✔ Delete Operation
Handles:
- No child  
- One child  
- Two children → replace with inorder successor  
Then rebalance the tree

---

## 🚀 Build & Run

### Compile
```bash
gcc -std=c99 avl_readable.c -o avl_readable
```

### Run
```bash
./avl_readable
```

---

## 📊 Example Session
```
=== AVL Tree (Insert, Delete, Inorder) ===

1) Insert  2) Delete  3) Show Inorder  4) Exit
Choice: 1
How many keys to insert? 4
Enter 4 integer(s): 30 20 40 10
 [Inserted 30] [Inserted 20] [Inserted 40] [Inserted 10]
Current (inorder): 10 20 30 40

Choice: 2
Key to delete: 20
Deleted (if existed): 20
Current (inorder): 10 30 40

Choice: 3
Inorder: 10 30 40
```

---

## 🧠 Insight
AVL trees ensure:
- **O(log n)** time for search, insert, delete  
- Strict height balance via rotations  
- Faster lookups compared to unbalanced BSTs  

This implementation is great for learning balanced trees and practicing rotation logic.

