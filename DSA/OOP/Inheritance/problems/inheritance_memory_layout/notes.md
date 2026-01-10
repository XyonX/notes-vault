# Instance Creation Sequence and Memory Layout

## The class relationships

Given hierarchy:
* **A** → no base
* **B** → no base
* **C** : public **A**
* **D** : public **B**
* **E** : public **C**, **D**
* **F** : public **E**

Inheritance diagram:
```
   A       B
   |       |
   C       D
    \     /
     \   /
      \ /
       E
       |
       F
```

## Construction sequence (non-virtual bases)

When you create `F`, C++ does:
1. Figure out `F`'s **direct bases** → (`E`)
2. Look at `E`'s direct bases → (`C`, `D`) in the order declared.
3. For each base, go *down* its chain until hitting independent base classes.
4. Construct in **base-to-child** order.

So the call order is:
```
A  (base of C)
C  (base of E)
B  (base of D)
D  (base of E)
E  (base of F)
F  (final most-derived)
```

## Memory layout (non-virtual)

An `F` object's memory is basically a **contiguous block** containing subobjects for each base and the most-derived part.

Layout in memory (top to bottom):
```
+----------------+
| A subobject    |  <- From C
+----------------+
| C subobject    |  <- Contains A above
+----------------+
| B subobject    |  <- From D
+----------------+
| D subobject    |  <- Contains B above
+----------------+
| E subobject    |  <- Contains C and D above
+----------------+
| F's own data   |
+----------------+
```

Important notes:
* The **A** inside `C` and the **B** inside `D` are *physically stored* inside the `F` object's memory, inlined as subobjects.
* There is **no separate heap allocation** for these bases unless you explicitly allocate with `new`.
* Memory is laid out in the order **bases first, then derived members**.
* For *multiple inheritance*, each base subobject is placed one after the other, not "nested inside" the derived's own section — but the derived's members are after all its bases.

## ASCII Memory Diagram for `F`

```
[F object]
 ├── [E subobject]
 │    ├── [C subobject]
 │    │     └── [A subobject]
 │    └── [D subobject]
 │          └── [B subobject]
 └── [F's own members]
```

Or flattened as memory:
```
[ A ][ C members ][ B ][ D members ][ E members ][ F members ]
```