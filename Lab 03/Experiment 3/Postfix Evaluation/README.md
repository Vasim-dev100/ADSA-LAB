# 🔢 Postfix Expression Evaluation in C (Using Stack)

This program evaluates a **postfix expression** (Reverse Polish Notation – RPN) using a stack.  
It supports single-digit operands and the operators `+ - * / ^`.

---

## 📌 Features
- Evaluates postfix expressions of any length (up to MAX = 100)
- Supports operators:
  - `+` (addition)  
  - `-` (subtraction)  
  - `*` (multiplication)  
  - `/` (division)  
  - `^` (power)
- Uses a stack to evaluate expressions correctly
- Ignores spaces in the input
- Reports errors like stack overflow/underflow or invalid operators

---

## 🛠️ How It Works

### ✔ Operands
- If character is a **digit**, convert to integer (`c - '0'`) and push onto stack.

### ✔ Operators
- Pop the top **two** values from the stack → `val1`, `val2`
- Apply the operator:  
  - Example: for `+`, compute `val1 + val2`
- Push the result back onto the stack.

### ✔ Final Result
- After processing entire expression, the last value in the stack is the result.

### Time Complexity
- **O(n)** where n = length of postfix expression.

---

## 🚀 Build & Run

### Compile
```bash
gcc postfix_eval.c -o postfix_eval -lm
```

### Run
```bash
./postfix_eval
```

---

## 📊 Example Output
```
Enter postfix expression (single-digit operands): 53+82-*4/
Result = 3
```

---

## 🧠 Insight
Postfix evaluation is simpler than infix because:
- No parentheses
- No precedence rules
The stack-based method ensures operators always act on the correct operands.

