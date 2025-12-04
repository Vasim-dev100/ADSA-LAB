# 🔺 Heap Sort Implementation in C

A C program that implements the **Heap Sort** algorithm using a **max-heap**.  
The program reads an array from the user, builds a heap, sorts it, and prints the final sorted output.

---

## 📌 Features
- Builds a **max-heap** from the input array.
- Sorts the array using **heap sort**.
- Includes helper functions:
  - `swap()` – swaps two elements
  - `heapify()` – ensures max-heap property
  - `heapSort()` – performs full heap sort process
  - `printArray()` – prints the array

---

## 🛠️ How Heap Sort Works
1. **Build Max-Heap**:  
   Convert the array into a max-heap by calling `heapify()` bottom-up.

2. **Extract Max & Heapify**:  
   Repeatedly:
   - Swap the first (largest) element with the last unsorted element.
   - Reduce heap size.
   - Restore max-heap using `heapify()`.

Time Complexity:  
- **O(n log n)** (worst, average, best)  
Space Complexity:  
- **O(1)** (in-place)

---

## 🚀 Build & Run

### Compile
```bash
gcc heapsort.c -o heapsort
```

### Run
```bash
./heapsort
```

---

## 📊 Example Output
```
Enter number of elements: 6
Enter 6 elements: 12 3 19 5 7 2
Original array: 12 3 19 5 7 2
Sorted array:   2 3 5 7 12 19
```

---

## 🧠 Insight
Heap Sort is an efficient in-place sorting algorithm that guarantees **O(n log n)** time.  
It is widely used when memory usage must remain low and worst-case performance must be predictable.

