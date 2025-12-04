# 🔢 LUP Decomposition in C (LU with Partial Pivoting)

This C program performs **LUP Decomposition** of a square matrix using **partial pivoting**.  
It decomposes a matrix **A** into:

\[
P \cdot A = L \cdot U
\]

Where:  
- **L** = Lower triangular matrix (with 1s on diagonal)  
- **U** = Upper triangular matrix  
- **P** = Permutation array representing pivot row swaps  

---

## 📌 Features
- Supports matrices up to **10×10** (`MAX = 10`)
- Performs **partial pivoting** for numerical stability
- Computes the **L**, **U**, and **P** matrices
- Displays:
  - Lower triangular matrix **L**
  - Upper triangular matrix **U**
  - Permutation vector **P**

---

## 🛠️ How the Algorithm Works

### 1. **Pivot Selection**
- For each column `k`, find the row with the largest `|A[i][k]|` value.
- Swap this row with row `k` (update permutation array `P`).

### 2. **LU Factorization**
- Convert entries below pivot into multipliers:
  ```
  A[i][k] /= A[k][k]
  ```
- Eliminate elements below pivot:
  ```
  A[i][j] -= A[i][k] * A[k][j]
  ```

### 3. **Extract L and U**
- `L` takes the lower part (multipliers) + diagonal = 1  
- `U` takes the upper triangular part  

---

## 🚀 Build & Run

### Compile
```bash
gcc lup.c -o lup -lm
```

### Run
```bash
./lup
```

---

## 📊 Example Output
```
L matrix:
  1.00   0.00   0.00
  0.50   1.00   0.00
  0.20   0.33   1.00

U matrix:
 10.00   2.00   3.00
  0.00   9.00   1.50
  0.00   0.00   8.33

P (permutation order):
2 0 1
```

---

## 🧠 Insight
LUP decomposition is used in:
- Solving **linear equations**
- Computing **matrix inverse**
- Computing **determinants**
- Improving numerical stability compared to simple LU decomposition

It is a fundamental algorithm in numerical linear algebra.

