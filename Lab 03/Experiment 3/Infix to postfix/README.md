# 🔁 Infix to Postfix Conversion in C (Using Stack)

This program converts a given **infix expression** into a **postfix expression** using the stack-based Shunting Yard algorithm.  
It supports operators, parentheses, and single-character operands.

---

## 📌 Features
- Converts infix → postfix notation
- Supports:
  - Operators: `+ - * / ^`
  - Parentheses: `()`
  - Single-character operands (letters or digits)
- Handles operator precedence and associativity correctly
- Ignores spaces in input
- Warns about unsupported characters

---

## 🛠️ How It Works

### ✔ Stack-Based Algorithm
Uses a stack to temporarily hold operators until they can be safely added to the postfix output.

### ✔ Operator Precedence
Highest → lowest:
1. `^`
2. `* /`
3. `+ -`

### ✔ Associativity
- Right-associative: `^`
- Left-associative: `+ - * /`

### ✔ Steps
1. Read infix expression left to right  
2. If operand → append to postfix  
3. If operator → pop operators with higher/equal precedence (except right-associative)  
4. If `(` → push  
5. If `)` → pop until `(`  
6. Pop remaining operators at the end  

---

## 🚀 Build & Run

### Compile
```bash
gcc infix_to_postfix.c -o infix_to_postfix
```

### Run
```bash
./infix_to_postfix
```

---

## 📊 Example Output
```
Enter infix expression (single-char operands, operators ^*/+- and parentheses):
A*(B+C)/D

Postfix: ABC+*D/
```

---

## 🧠 Insight
This program is a classic example of how compilers convert expressions into postfix (RPN) for easier evaluation.  
Postfix eliminates parentheses and operator precedence by design.

