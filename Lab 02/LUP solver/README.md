# 🔢 LUP Decomposition + Linear System Solver in C

This C program performs **LUP Decomposition** (LU with partial pivoting) on matrix **A**, then solves the linear system:

\[
A x = b
\]

by using forward and backward substitution.  
The method is numerically stable and efficient for solving systems of linear equations.

---

## 📌 Features
- Supports square matrices up to **10×10** (`MAX = 10`)
- Computes **L**, **U**, and **P** in-place using LUP decomposition
- Uses the permutation array **P** to correctly reorder entries of **b**
- Solves the system using:
  - **Forward substitution** (Ly = Pb)
  - **Backward substitution** (Ux = y)
- Prints the final solution vector **x**

---

## 🛠️ How the Algorithm Works

### **1. LUPDecompose(A, P, n)**
- Initializes permutation array `P`
- Performs **partial pivoting** to ensure stability
- Decomposes A into **L and U in a single matrix**
  - Lower part (below diagonal) → multipliers (L)
  - Upper part (on/above diagonal) → U
- Updates permutation array during row swaps

### **2. solve(A, b, P, x, n)**
- Computes forward substitution:
  \[
  Ly = Pb
  \]
- Computes backward substitution:
  \[
  Ux = y
  \]
- Stores final solution in **x**

---

## 🚀 Build & Run

### Compile
```bash
gcc lup_solver.c -o lup_solver -lm
```

### Run
```bash
./lup_solver
```

---

## 📊 Example Output
```
Enter size of matrix: 3
Enter matrix A (3x3):
2 1 1
4 -6 0
-2 7 2
Enter vector b (3 values):
5 -2 9

Solution x:
x[1] = 1.00
x[2] = 1.00
x[3] = 2.00
```

---

## 🧠 Insight
LUP decomposition is widely used in:
- Solving linear systems efficiently  
- Computing matrix inverse  
- Determinant computation  
- Numerical scientific computing  

It provides **better accuracy** than standard LU decomposition due to pivoting.

