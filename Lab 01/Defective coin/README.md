# 🪙 Defective Coin Finder — Linear Search Approach

A C program that identifies a **defective (lighter) coin** from a set of coins by comparing their weights.  
If all coins have equal weight, the program reports that no defective coin exists.

---

## 📌 Features
- Accepts number of coins and their weights from the user.
- Uses a **linear scan** to:
  - Find the **minimum weight coin**.
  - Check if **all coins have equal weight**.
- Outputs:
  - Index and weight of the defective coin, or
  - A message stating that all coins are equal.

---

## 🛠️ How It Works
1. Scan all coins to find the **minimum weight**.
2. Check if **all weights are the same**.
3. If all weights are equal → return **-1** (no defective coin).  
4. Otherwise → return index of the **lighter defective coin**.

Time Complexity: **O(n)**  
Space Complexity: **O(1)**

---

## 🚀 Build & Run

### Compile
```bash
gcc defective_coin.c -o defective_coin
```

### Run
```bash
./defective_coin
```

---

## 📊 Example Output
```
Enter number of coins: 5
Enter weights of coins:
10 10 7 10 10
Defective (lighter) coin found at position 2 (0-based), weight = 7
```

---

## 🧠 Insight
This approach works when there is **only one lighter defective coin** among identical normal coins.  
A simple linear scan is optimal here since no additional constraints (like comparison limits or balance scale operations) are involved.

