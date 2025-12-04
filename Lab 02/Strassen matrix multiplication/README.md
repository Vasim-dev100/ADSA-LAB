# ✨ Strassen’s Matrix Multiplication (2×2) in C

This program multiplies two **2×2 matrices** using **Strassen’s Algorithm**, which reduces the number of multiplications from **8 to 7**.  
It demonstrates the core idea behind Strassen’s divide-and-conquer method for faster matrix multiplication.

---

## 📌 Features
- Accepts two **2×2 matrices** as input.
- Uses Strassen’s **7 computed products** instead of 8.
- Computes and prints the resulting matrix **C = A × B**.
- Shows how Strassen’s algorithm works on the smallest non-trivial case.

---

## 🛠️ Strassen’s 7 Multiplications

Given matrices:

\[
A = \begin{pmatrix} a & b \\ c & d \end{pmatrix},\quad 
B = \begin{pmatrix} e & f \\ g & h \end{pmatrix}
\]

Strassen computes:

- \( M1 = (a + d)(e + h) \)
- \( M2 = (c + d)e \)
- \( M3 = a(f - h) \)
- \( M4 = d(g - e) \)
- \( M5 = (a + b)h \)
- \( M6 = (c - a)(e + f) \)
- \( M7 = (b - d)(g + h) \)

Then the result matrix:

\[
C = \begin{pmatrix}
C_{11} & C_{12} \\
C_{21} & C_{22}
\end{pmatrix}
\]

where:

- \( C_{11} = M1 + M4 - M5 + M7 \)
- \( C_{12} = M3 + M5 \)
- \( C_{21} = M2 + M4 \)
- \( C_{22} = M1 - M2 + M3 + M6 \)

---

## 🚀 Build & Run

### Compile
```bash
gcc strassen.c -o strassen
```

### Run
```bash
./strassen
```

---

## 📊 Example Output
```
Enter elements of 2x2 Matrix A:
1 2 3 4
Enter elements of 2x2 Matrix B:
5 6 7 8

Resultant Matrix C (A x B):
19 22
43 50
```

---

## 🧠 Insight
Strassen’s algorithm reduces multiplication count from **8 to 7**, improving performance for large matrices using recursion.  
This 2×2 implementation demonstrates the core concept behind fast matrix multiplication methods.

