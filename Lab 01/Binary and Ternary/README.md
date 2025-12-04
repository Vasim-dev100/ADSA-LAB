# 🔍 Binary Search vs Ternary Search — Comparison Counter

A C program that compares **Binary Search** and **Ternary Search** by counting the total number of comparisons performed while searching for a key in a sorted array.

---

## 📌 Features
- Accepts user input for array size, sorted elements, and key.
- Implements:
  - **Binary Search** with comparison counting
  - **Ternary Search** with comparison counting
- Displays:
  - Whether the key is found
  - The index of the key (if found)
  - Total number of comparisons made by each search algorithm

---

## 🛠️ Algorithms Implemented

### **1. Binary Search**
- Divides search space into 2 halves.
- Compares:
  - Loop condition
  - Equality check with mid
  - Less/greater check
- Time Complexity: **O(log₂ n)**

### **2. Ternary Search**
- Divides search space into 3 parts.
- Compares:
  - Equality with mid1
  - Equality with mid2
  - Range checks
- Time Complexity: **O(log₃ n)** but more comparisons per iteration.

---

## 🚀 Build & Run

### Requirements
- C compiler (e.g., gcc)

### Steps
```bash
gcc search_compare.c -o search_compare
./search_compare
```

---

## 📊 Example Output
```
Binary Search: Found at index 4
Binary Search Comparisons: 5
Ternary Search: Found at index 4
Ternary Search Comparisons: 7
```

---

## 🧠 Insight
Although Ternary Search splits the array more finely, it performs **additional comparisons** each iteration, often making **Binary Search faster in practice**.

