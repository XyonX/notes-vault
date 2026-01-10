# Second Highest Salary

This is a classic SQL interview problem that tests understanding of:
- Sorting and ordering data
- Handling duplicates
- Using subqueries
- Window functions
- LIMIT and OFFSET

## Multiple Approaches

1. **LIMIT and OFFSET**: Simple but may not handle NULLs properly if there's no second highest salary
2. **Subquery with MAX**: More explicit about finding the second highest value
3. **ROW_NUMBER()**: Uses window functions to rank salaries
4. **DENSE_RANK()**: Better for handling duplicate salary values

## Key Points
- DISTINCT is important when using LIMIT/OFFSET to avoid duplicate salaries
- Subquery approach handles edge cases better (like when there's no second highest salary)
- Window functions provide more flexibility and are often preferred in modern SQL
- DENSE_RANK vs ROW_NUMBER: DENSE_RANK is better when you want the second distinct salary value regardless of duplicates