# 🌳 Simple B-Tree (Insert & Delete-by-Rebuild) — C Implementation

This program implements a **simple B-Tree** of minimum degree **T = 3**, supporting:  
✔ Insert  
✔ Delete (via rebuild)  
✔ Print all elements in sorted order  

It is designed for readability and educational purposes.

---

## 📌 Features
- B-Tree with **minimum degree T = 3** (modifiable)
- Supports:
  - **Insert** (standard B-Tree insert with splitting)
  - **Delete** by:
    - Extracting all keys
    - Removing the target key
    - Rebuilding the entire tree
- Always displays keys in **sorted order**
- Automatic memory management (tree freed on exit)
- Simple interactive menu

---

## 🛠️ How It Works
