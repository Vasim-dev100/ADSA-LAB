# ⚡ Quick Sort with Median-of-Three Pivot + Insertion Sort Cutoff (C Implementation)

This program implements an optimized **Quick Sort** using the **Median-of-Three** pivot selection strategy and switches to **Insertion Sort** for small subarrays to improve performance.

---

## 📌 Features
- Uses **Median-of-Three** pivot selection (first, middle, last elements).
- Reduces worst-case behavior on already sorted or nearly sorted data.
- Uses **Insertion Sort** when subarray size ≤ 10 for better efficiency.
- Includes:
  - `swap()` — swap helper  
  - `medianOfThree()` — computes pivot  
  - `partition()` — partition logic  
  - `quickSort()` — optimized sorting  
  - `printArray()` — prints result  

---

## 🛠️ How the Algorithm Works

### **1. Median-of-Three Pivot**
- Compares `arr[low]`, `arr[mid]`, `arr[high]`
- Orders them so: `arr[low] ≤ arr[mid] ≤ arr[high]`
- Places the median at `arr[high - 1]`
- Reduces bad pivot choices

### **2. Partitioning**
- Pivot = median-of-three value
- Elements < pivot moved left, > pivot moved right

### **3. Insertion Sort Cutoff**
- When subarray size ≤ 10:
  - Quick Sort becomes inefficient
  - Switch to Insertion Sort for improved performance

### **Time Complexity**
- Average: **O(n log n)**
- Worst (rare with median-of-three): **O(n²)**
- Space: **O(log n)** (due to recursion)

---

## 🚀 Build & Run

### Compile
```bash
gcc quicksort_median.c -o quicksort_median
```

### Run
```bash
./quicksort_median
```

---

## 📊 Example Output
```
Enter number of elements: 8
Enter 8 integers:
9 3 7 1 6 2 8 4
Sorted array (using Quick Sort with Median Pivot):
1 2 3 4 6 7 8 9
```

---

## 🧠 Insight
The **median-of-three** method and **insertion sort cutoff** make this one of the most practical and efficient Quick Sort variants, widely used in real-world libraries.

