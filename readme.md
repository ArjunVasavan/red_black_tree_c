# red_black_tree_c

Self-balancing Binary Search Tree implemented in C.

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

```
insert    O(log n)
delete    O(log n)
search    O(log n)
find min  O(log n)
find max  O(log n)
```

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

## Rules

```
1. every node is red or black
2. root is always black
3. null leaves are black
4. no two consecutive red nodes
5. equal black nodes on every root-to-null path
```
