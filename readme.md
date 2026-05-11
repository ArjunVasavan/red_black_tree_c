# Red-Black Tree (C)

Self-balancing Binary Search Tree implementation in C. Maintains O(log n) time complexity for insert, delete, and search using rotations and recoloring.

---

## Build

```bash
make
./rbt
```

## Clean

```bash
make clean
```

---

## Operations

| Operation | Time Complexity |
| --------- | --------------- |
| insert    | O(log n)        |
| delete    | O(log n)        |
| search    | O(log n)        |
| find min  | O(log n)        |
| find max  | O(log n)        |

---

## Project Structure

```
rbtree/
├── include/
│   └── rbtree.h
├── src/
│   ├── insert.c
│   ├── delete.c
│   ├── rotations.c
│   ├── rbtree.c
│   └── utils.c
├── main.c
└── Makefile
```

---

## Red-Black Properties

1. Each node is either red or black
2. Root is always black
3. All NULL leaves are black
4. No two consecutive red nodes
5. Every path from root to NULL has equal number of black nodes

---

## Implementation Details

* Insert uses standard BST insertion followed by `fix_insert` to restore properties
* Delete handles all three BST cases and resolves double-black using `fix_delete`
* Rotations (`left_rotate`, `right_rotate`) maintain tree structure fileciteturn1file0
* Level-order traversal is used for tree visualization
* Duplicate insertions are rejected

---

## Usage

Interactive CLI menu:

```
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Delete Minimum
7. Delete Maximum
8. Display Tree
9. Exit
```

---
