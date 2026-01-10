# Composition vs Aggregation Discussion

## composition_vs_aggregation

Explained the difference between composition and aggregation with C++ code examples:

1. **Composition** - Strong "has-a" relationship:
   - Contained object's lifetime is tied to the owner
   - When the owner is destroyed, the part is destroyed too
   - Implementation uses member objects

2. **Aggregation** - Weak "has-a" relationship:
   - The contained object is passed in; it's not owned
   - It can exist before and after the owner is destroyed
   - Implementation uses pointers or references

Provided a clear analogy to remember the concepts:
> Composition = "My heart is part of me."
> Aggregation = "I have a phone, but I can change it anytime."