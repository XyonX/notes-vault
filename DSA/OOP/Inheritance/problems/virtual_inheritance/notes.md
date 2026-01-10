# Virtual Inheritance Version

Though we don't need virtual here as it doesn't have a diamond problem, it can still be useful.

## New hierarchy with virtual inheritance

```cpp
class A {};
class B {};

class C : virtual public A {};
class D : virtual public B {};

class E : public C, public D {};
class F : public E {};
```

ASCII diagram (virtual bases marked with `(V)`):
```
   A (V)   B (V)
     ^       ^
     |       |
     C       D
      \     /
       \   /
        \ /
         E
         |
         F
```

## Construction order (virtual bases)

C++ now changes the rule for virtual bases:
* **Virtual base classes are constructed only once**, no matter how many paths lead to them.
* They are constructed **before** non-virtual bases, starting from the **most derived** class.

So for `F f;`, the order is:
1. **A** (virtual base)
2. **B** (virtual base)
3. **C** (non-virtual base of `E`)
4. **D** (non-virtual base of `E`)
5. **E**
6. **F**

## Memory layout with virtual bases

Here's the key change:
With **virtual inheritance**, `A` and `B` live in **one place** each, not duplicated in `C` and `D`.
Instead, `C` and `D` store an **internal pointer** (or offset) to where the virtual base object is located inside `F`.

### Flattened memory (conceptual):
```
[ A (virtual base) ]
[ B (virtual base) ]
[ C members + vbptr ]   // vbptr points to A
[ D members + vbptr ]   // vbptr points to B
[ E members ]
[ F members ]
```

## ASCII layout diagram (virtual)
```
[F object]
 ├── [A subobject]   // virtual base, only 1 copy
 ├── [B subobject]   // virtual base, only 1 copy
 ├── [C subobject]   // has a pointer/offset to A
 ├── [D subobject]   // has a pointer/offset to B
 ├── [E subobject]
 └── [F's own members]
```

The **vbptr** in `C` and `D` makes sure that whenever you cast a `C*` to `A*`, the compiler adjusts the pointer correctly to land in the shared `A` subobject.