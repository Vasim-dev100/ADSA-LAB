# 🔄 Quick Sort, Merge Sort & Heap Sort — Multi-Algorithm Sorting Program in C

This program allows the user to enter an array and choose **one of three sorting algorithms**:  
✅ Quick Sort  
✅ Merge Sort  
✅ Heap Sort  

It then sorts the data using the selected algorithm and prints the result.

---

## 📌 Features
- User chooses any one of the three sorting techniques
- Each algorithm implemented separately:
  - **Quick Sort** (divide-and-conquer, uses partition)
  - **Merge Sort** (stable, recursive merging)
  - **Heap Sort** (max-heap based)
- Original array is preserved (sorted using a copied version)
- Clean modular design with separate functions for each algorithm

---

## 🛠️ Algorithm Breakdown

### **1. Quick Sort**
- Selects last element as pivot
- Partitions array so:
  - Elements ≤ pivot → left  
  - Elements > pivot → right  
- Recursively sorts partitions  
- Time Complexity:  
  - Best/Average → **O(n log n)**  
  - Worst → **O(n²)**  

---

### **2. Merge Sort**
- Recursively splits array into two halves
- Merges them in sorted order  
- Requires extra temporary arrays  
- Time Complexity:  
  - Always **O(n log n)**  
- Stable sorting algorithm

---

### **3. Heap Sort**
- Builds a **max-heap**
- Repeatedly extracts largest element
- Maintains heap using `heapify()`  
- Time Complexity:  
  - Always **O(n log n)**  
- In-place but not stable

---

## 🚀 Build & Run

### Compile
```bash
gcc multisort.c -o multisort
```

### Run
```bash
./multisort
```

---

## 📊 Example Output
```
Enter number of elements: 6
Enter 6 integers:
9 4 2 7 6 1

Choose Sorting Method:
1. Quick Sort
2. Merge Sort
3. Heap Sort
2

Sorted using Merge Sort: 1 2 4 6 7 9
```

---

## 🧠 Insight
This program is great for comparing different sorting strategies:  
- **Quick Sort** is fast in practice  
- **Merge Sort** is stable  
- **Heap Sort** guarantees worst-case O(n log n)  

A useful tool for understanding the strengths and trade-offs of each algorithm.

