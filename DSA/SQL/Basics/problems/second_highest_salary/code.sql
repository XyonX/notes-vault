-- Solution 1: Using LIMIT and OFFSET
SELECT DISTINCT salary 
FROM Employee 
ORDER BY salary DESC 
LIMIT 1 OFFSET 1;

-- Solution 2: Using Subquery
SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee);

-- Solution 3: Using ROW_NUMBER() window function
SELECT salary AS SecondHighestSalary
FROM (
    SELECT salary, ROW_NUMBER() OVER (ORDER BY salary DESC) as rn
    FROM Employee
    GROUP BY salary
) ranked
WHERE rn = 2;

-- Solution 4: Using DENSE_RANK() for handling duplicates
SELECT DISTINCT salary AS SecondHighestSalary
FROM (
    SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) as rank
    FROM Employee
) ranked
WHERE rank = 2;