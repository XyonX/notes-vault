## Data Types & Variables

### Key Concepts
- **Primitive vs. Non-Primitive**: int, float, char, bool, string.
- **Memory Size**: sizeof in C/C++, sys.getsizeof() in Python.
- **Signed vs. Unsigned Integers**: Behavior and conversion.
- **Type Conversion**: Implicit and explicit casting.
- **Overflow/Underflow**: Behavior in signed and unsigned integers.

### Tricky Points
- **Character Literals**: 'A' is an int literal in C (4 bytes).
- **Signed vs. Unsigned Conversion**: Negative to unsigned wraps to max value.
- **Integer Overflow**: Wraps around in two's complement.
- **Format Specifier Mismatch**: Leads to undefined behavior.
- **Float vs. Double Precision**: Precision issues in comparisons.
- **Char Signedness**: Implementation-defined behavior.
- **Const Modification**: Undefined behavior when cast away.
- **Global Redefinition**: Compiler error for same scope.
- **Uninitialized Variables**: Contain garbage values.
- **Enum as Int**: Enums behave like integers.