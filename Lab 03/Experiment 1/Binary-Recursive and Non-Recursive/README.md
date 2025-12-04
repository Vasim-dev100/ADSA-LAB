# 🔍 Recursive & Iterative Binary Search in C

This program implements **both Recursive and Iterative Binary Search** to locate a key in a sorted array.  
It demonstrates the difference between two common search approaches while producing the same result.

---

## 📌 Features
- Accepts a sorted array from the user
- Performs:
  - **Recursive Binary Search**
  - **Iterative Binary Search**
- Displays:
  - Whether the key is found
  - The index of the key for each method

---

## 🛠️ How the Algorithms Work

### **1. Recursive Binary Search**
- Divides array into halves recursively.
- Base case:  
  - If `left > right` → key not found  
  - If `arr[mid] == key` → found
- Recursively searches:
  - Left half if key < arr[mid]
  - Right half otherwise

### **2. Iterative Binary Search**
- Uses a loop instead of recursion
- Continues while `left <= right`
- Updates bounds based on comparison with `arr[mid]`

Both methods run in **O(log n)** time.

---

## 🚀 Build & Run

### Compile
```bash
gcc binary_search.c -o binary_search
```

### Run
```bash
./binary_search
```

---

## 📊 Example Output
```
Enter number of elements: 6
Enter 6 sorted integers:
2 5 8 12 19 23
Enter the key to search: 12

Recursive: Key 12 found at index 3
Iterative: Key 12 found at index 3
```

---

## 🧠 Insight
Recursive search is intuitive and elegant, while iterative search avoids function-call overhead.  
Both have identical time complexity, but iterative is often more memory-efficient.

