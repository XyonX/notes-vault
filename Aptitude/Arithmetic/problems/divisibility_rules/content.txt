## Divisibility Rules (Apti Quick Check)

| Number  | Rule                                                                                              |
| ------- | ------------------------------------------------------------------------------------------------- |
| **2**   | Last digit is even (0, 2, 4, 6, 8).                                                               |
| **3**   | Sum of digits divisible by 3.                                                                     |
| **4**   | Last **2 digits** divisible by 4.                                                                 |
| **5**   | Last digit is **0 or 5**.                                                                         |
| **6**   | Divisible by **both 2 and 3**.                                                                    |
| **8**   | Last **3 digits** divisible by 8.                                                                 |
| **9**   | Sum of digits divisible by 9.                                                                     |
| **10**  | Last digit is **0**.                                                                              |
| **11**  | Difference between the sum of digits at odd positions and even positions is 0 or divisible by 11. |
| **12**  | Divisible by **both 3 and 4**.                                                                    |
| **15**  | Divisible by **both 3 and 5**.                                                                    |
| **18**  | Divisible by **both 2 and 9**.                                                                    |
| **20**  | Last digit is **0**, and the tens digit is even (or simply divisible by 4 after removing last 0). |
| **25**  | Last **2 digits** are 00, 25, 50, or 75.                                                          |
| **45**  | Divisible by **both 9 and 5**.                                                                    |
| **50**  | Last **2 digits** are 00 or 50.                                                                   |
| **75**  | Last **2 digits** are 00, 25, 50, or 75 **and** divisible by 3.                                   |
| **100** | Last **2 digits** are 00.                                                                         |

### How to use the factor trick (like 45 example)

If a number **N** can be factored into smaller numbers **a × b**,
then to be divisible by **N**, it must be divisible by **both a and b**.

Examples:

* **45 = 9 × 5** → check **9-rule** and **5-rule**.
* **15 = 3 × 5** → check **3-rule** and **5-rule**.
* **12 = 3 × 4** → check **3-rule** and **4-rule**.
* **18 = 2 × 9** → check **2-rule** and **9-rule**.

### Pro tip for apti speed

* For **big numbers**, don't actually divide — use last digits / sum of digits rule.
* Always test the **easier factor** first (e.g., for 45, checking "ends in 0 or 5" is much faster than adding digits).
* If the easy check fails, you can skip the harder one entirely.