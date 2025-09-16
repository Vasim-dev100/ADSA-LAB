# Function Growth Comparator

A C program that compares the growth of different mathematical functions at a given input size `n` and prints them in increasing order of their evaluated values.  
This is useful for understanding asymptotic growth and complexity analysis concepts.

---

## 📌 Features
- Evaluates **11 mathematical functions** including logarithmic, polynomial, root, and exponential.
- Compares them at a chosen `n` (default: `1024`).
- Sorts and displays them in increasing order of growth.
- Helps visualize why certain complexities dominate others as `n` increases.

---

## 🛠️ Functions Implemented
The program computes the following functions:
1. `n * log2(n)`
2. `12 * sqrt(n)`
3. `1/n`
4. `n^(log2(n))`
5. `100*n^2 + 6n`
6. `n^0.51`
7. `n^2 - 324`
8. `50*sqrt(n)`
9. `2*n^3`
10. `3^n`
11. `log2(n)`

---

## 🚀 Build & Run

### Requirements
- C compiler (e.g., `gcc`)
- `math.h` library (standard in C)

### Steps
```bash
# Compile
gcc main.c -o func_growth -lm

# Run
./func_growth
```

## 📊 Example Output (n = 1024)

```text
Functions in increasing order of growth (n = 1024):
1. 1/n
2. log2(n)
3. n^0.51
4. 12*sqrt(n)
5. 50*sqrt(n)
6. n*log2(n)
7. n^2-324
8. 100*n^2+6n
9. 2*n^3
10. n^(log2(n))
11. 3^n

