# Comparison of Virtual and Non-Virtual Inheritance

We'll use this hierarchy (A and B are independent bases; C derives from A, D derives from B; E derives from C and D; F derives from E):

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

> Important nuance: there is **no diamond** on a single base here (A and B are different), so you won't get duplicated A or duplicated B even **without** virtual inheritance. Virtual inheritance still changes **who constructs what, when**, and the **object layout mechanics** (adds virtual-base machinery), but it does not reduce duplicates in this particular graph.

## 1) Non-virtual inheritance (typical, simpler layout)

### Classes

```cpp
#include <iostream>
using namespace std;

struct A { A(){ cout<<"A()\n"; } ~A(){ cout<<"~A()\n"; } int a=1; };
struct B { B(){ cout<<"B()\n"; } ~B(){ cout<<"~B()\n"; } int b=2; };

struct C : public A { C(){ cout<<"C()\n"; } ~C(){ cout<<"~C()\n"; } int c=3; };
struct D : public B { D(){ cout<<"D()\n"; } ~D(){ cout<<"~D()\n"; } int d=4; };

struct E : public C, public D { E(){ cout<<"E()\n"; } ~E(){ cout<<"~E()\n"; } int e=5; };
struct F : public E { F(){ cout<<"F()\n"; } ~F(){ cout<<"~F()\n"; } int f=6; };

int main(){
    F obj;
}
```

### Construction sequence (`F obj;`)

* C++ plans from most-derived downwards, but **executes** base → derived:

```
A()    // for C's base
C()
B()    // for D's base
D()
E()
F()
```

### Destruction sequence (reverse):

```
~F()
~E()
~D()
~B()
~C()
~A()
```

### Memory layout (conceptual, contiguous in one block)

Hierarchical view inside an `F` object:

```
[F object]
 └─[E subobject]
    ├─[C subobject]
    │   └─[A subobject]
    └─[D subobject]
        └─[B subobject]
 (plus F's own members)
```

Flattened (order is compiler-defined but typically follows base declaration order):

```
[A members][C members][B members][D members][E members][F members]
```

### Pointer conversions (address adjustments)

```cpp
int main(){
    F obj;

    // Upcasts across the tree (compile-time pointer adjustments where needed):
    E* pe = &obj;
    C* pc = static_cast<C*>(pe);  // likely same address as E if C is first base of E
    D* pd = static_cast<D*>(pe);  // typically pe + offset
    A* pa = static_cast<A*>(pc);  // into A subobject (often offset 0 within C)
    B* pb = static_cast<B*>(pd);  // into B subobject

    // Print addresses to observe subobject placement
    cout << " &obj(F) = " << (void*)&obj << "\n";
    cout << " E*      = " << (void*)pe  << "\n";
    cout << " C*      = " << (void*)pc  << "\n";
    cout << " D*      = " << (void*)pd  << "\n";
    cout << " A*      = " << (void*)pa  << "\n";
    cout << " B*      = " << (void*)pb  << "\n";
}
```

* Expect `C*` to be equal to `E*` if `C` is the first base of `E`.
* `D*` usually differs by a positive offset.
* `A*` and `B*` point into their respective subobjects.

**Takeaway:** In non-virtual MI, each direct base is a real subobject placed at a fixed offset; upcasts are compile-time **pointer + offset** adjustments.

## 2) Virtual inheritance on the independent bases (adds sharing machinery, even if not needed)

Now make `C` and `D` inherit their bases **virtually**:

```cpp
#include <iostream>
using namespace std;

struct A { A(){ cout<<"A()\n"; } ~A(){ cout<<"~A()\n"; } int a=1; };
struct B { B(){ cout<<"B()\n"; } ~B(){ cout<<"~B()\n"; } int b=2; };

struct C : virtual public A { C(){ cout<<"C()\n"; } ~C(){ cout<<"~C()\n"; } int c=3; };
struct D : virtual public B { D(){ cout<<"D()\n"; } ~D(){ cout<<"~D()\n"; } int d=4; };

struct E : public C, public D { E(){ cout<<"E()\n"; } ~E(){ cout<<"~E()\n"; } int e=5; };
struct F : public E { F(){ cout<<"F()\n"; } ~F(){ cout<<"~F()\n"; } int f=6; };

int main(){
    F obj;
}
```

### What changes conceptually?

* `A` is a **virtual base of C**; `B` is a **virtual base of D**.
* Virtual bases are **constructed by the most-derived type** (here, `F`) exactly **once** each and typically placed in a special "virtual base area" of the object.
* `C` and `D` no longer **contain** their own A/B subobjects directly; instead they carry hidden metadata (e.g., a **vbptr**) that lets the runtime find the shared A/B within `F`.

> In this hierarchy there were not multiple paths to A or to B to begin with, so you still end up with one A and one B. The difference is **who constructs them and how they're located**.

### Construction sequence (`F obj;`)

With virtual bases:

```
A()   // virtual base of C, constructed by most-derived (F)
B()   // virtual base of D, constructed by most-derived (F)
C()
D()
E()
F()
```

### Destruction sequence (reverse):

```
~F()
~E()
~D()
~C()
~B()
~A()
```

### Memory layout (conceptual)

Hierarchical view:

```
[F object]
 ├─[A virtual-base subobject]   // constructed once by F
 ├─[B virtual-base subobject]   // constructed once by F
 ├─[C subobject]  (contains vbptr/offsets to find A)
 ├─[D subobject]  (contains vbptr/offsets to find B)
 ├─[E subobject]
 └─[F members]
```

Flattened (conceptual ordering):

```
[ A (virtual base) ][ B (virtual base) ][ C (with vbptr) ][ D (with vbptr) ][ E ][ F ]
```

* Exact placement is **implementation-defined**, but virtual bases are typically grouped and reachable via hidden pointers/offsets from intermediate bases.

### Pointer conversions (now may be runtime-assisted)

```cpp
int main(){
    F obj;
    E*  pe = &obj;
    C*  pc = static_cast<C*>(pe);     // may need hidden fixups
    D*  pd = static_cast<D*>(pe);
    A*  pa = static_cast<A*>(pc);     // uses vbptr/vbtable to locate the shared A
    B*  pb = static_cast<B*>(pd);     // uses vbptr/vbtable to locate the shared B

    cout << " &obj(F) = " << (void*)&obj << "\n";
    cout << " E*      = " << (void*)pe  << "\n";
    cout << " C*      = " << (void*)pc  << "\n";
    cout << " D*      = " << (void*)pd  << "\n";
    cout << " A*      = " << (void*)pa  << "  (virtual base)\n";
    cout << " B*      = " << (void*)pb  << "  (virtual base)\n";
}
```

* The compiler emits pointer adjustments that may consult the virtual-base metadata to compute the correct address for `A*`/`B*`.

**Costs vs. benefits**

* ✅ Ensures **one** construction of each virtual base even if multiple paths exist (solves diamonds).
* ⚠️ Adds some **space** (hidden pointers) and potential **runtime indirections** for base access.
* In this **non-diamond** graph, virtual inheritance doesn't reduce duplication (there wasn't any), but still changes construction rules and layout.

## 3) All scenarios at a glance

| Aspect                          | Non-virtual MI (`E : C,D` where `C:A`, `D:B`)                      | Virtual MI (`C : virtual A`, `D : virtual B`)                     |
| ------------------------------- | ------------------------------------------------------------------ | ----------------------------------------------------------------- |
| Number of `A` subobjects in `F` | 1                                                                  | 1                                                                 |
| Number of `B` subobjects in `F` | 1                                                                  | 1                                                                 |
| Who constructs `A`/`B`          | Constructed when building `C`/`D` respectively                     | Constructed by **most-derived** (`F`) first                       |
| Base construction order (F)     | `A → C → B → D → E → F`                                            | `A (virt) → B (virt) → C → D → E → F`                             |
| Destruction order               | reverse                                                            | reverse                                                           |
| Layout feel                     | Fixed offsets for each base; upcasts are simple offset adjustments | Virtual-base area + vbptr/vbtables; some upcasts may use metadata |
| When to use                     | Simple MI without shared base diamonds                             | Required for **diamond** sharing; optional elsewhere              |

## 4) Visual cheat-sheets

### Non-virtual (what you likely compile most of the time)

```
[F]
 └─[E]
    ├─[C]
    │   └─[A]
    └─[D]
        └─[B]
 (then F's own data)
```

Flattened (conceptual):

```
[A][C][B][D][E][F]
```

### Virtual (same graph, but with virtual bases)

```
[F]
 ├─[A] (virtual base, once)
 ├─[B] (virtual base, once)
 ├─[C] (vbptr → A)
 ├─[D] (vbptr → B)
 ├─[E]
 └─[F's own data]
```

Flattened (conceptual):

```
[A(virt)][B(virt)][C(vbptr)][D(vbptr)][E][F]
```

## 5) Practical rules of thumb

* **Construction**: always base → derived. With **virtual** bases, all virtual bases come **first**, built by the **most-derived** object.
* **Destruction**: reverse order.
* **Upcasts** (`Derived*` → `Base*`): always safe; compiler does the right pointer fixup (offset or virtual-base lookup).
* **Downcasts** (`Base*` → `Derived*`): use `dynamic_cast` (requires a virtual function in the base) when the dynamic type may vary.
* **Virtual inheritance**: use it when a base appears along **multiple paths** (true diamond) and you need **one shared** base subobject.

If you'd like, I can also craft a tiny runnable demo that prints **addresses** of each subobject for both versions (non-virtual vs. virtual) so you can literally see how the pointers differ.