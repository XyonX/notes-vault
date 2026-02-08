# Cognizant Cluster 2 – Interview Questions & Answers

## Python

1. **What are Python decorators and how do you use them?**
   - Decorators are special functions that let you add extra features to other functions without changing their code. You use the @ symbol before a function to apply a decorator.

2. **Explain the difference between lists and tuples in Python.**
   - Lists can be changed (mutable), but tuples cannot (immutable). Lists use [ ], tuples use ( ).

3. **How does Python's garbage collection work?**
   - Python automatically removes objects that are no longer used to free up memory. It uses reference counting and a garbage collector for unused objects.

4. **What is list comprehension? Provide an example.**
   - List comprehension is a simple way to create lists using a single line. Example: `[x*x for x in range(5)]` gives `[0, 1, 4, 9, 16]`.

5. **How do you handle exceptions in Python?**
   - You use try and except blocks. Code that might cause an error goes in try, and except handles the error.

6. **What are lambda functions and where would you use them?**
   - Lambda functions are small, anonymous functions. You use them for short tasks, like sorting or filtering lists.

7. **Explain the concept of generators and yield in Python.**
   - Generators are functions that return values one at a time using `yield`. They are memory efficient for large data.

8. **How do you manage dependencies in a Python project?**
   - You list them in a `requirements.txt` file and install them with `pip install -r requirements.txt`.

9. **What is the difference between deep copy and shallow copy?**
   - Shallow copy copies only the outer object, deep copy copies everything, including nested objects.

10. **How do you connect to a database using Python?**
    - You use libraries like `sqlite3` or `psycopg2` to connect and run SQL queries from Python.

## ANSI SQL

1. **What is the difference between INNER JOIN and LEFT JOIN?**
   - INNER JOIN returns only matching rows from both tables. LEFT JOIN returns all rows from the left table and matching rows from the right table.

2. **How do you write a query to find duplicate records in a table?**
   - Use GROUP BY and HAVING. Example: `SELECT column, COUNT(*) FROM table GROUP BY column HAVING COUNT(*) > 1;`

3. **Explain the use of GROUP BY and HAVING clauses.**
   - GROUP BY groups rows with the same values. HAVING filters groups after grouping.

4. **What is a subquery? Provide an example.**
   - A subquery is a query inside another query. Example: `SELECT name FROM students WHERE id IN (SELECT id FROM scores WHERE score > 90);`

5. **How do you update data in one table based on values from another table?**
   - Use UPDATE with JOIN or a subquery. Example: `UPDATE a SET a.value = b.value FROM a JOIN b ON a.id = b.id;`

6. **What are aggregate functions? Name a few.**
   - Aggregate functions do calculations on groups of rows. Examples: SUM, AVG, COUNT, MAX, MIN.

7. **How do you optimize a slow SQL query?**
   - Use indexes, avoid SELECT *, write efficient WHERE clauses, and check query plans.

8. **What is normalization? Explain different normal forms.**
   - Normalization organizes data to reduce duplication. 1NF: no repeating groups, 2NF: no partial dependencies, 3NF: no transitive dependencies.

9. **How do you handle NULL values in SQL queries?**
   - Use IS NULL or IS NOT NULL to check for NULLs. Use COALESCE to replace NULLs with a value.

10. **What is the difference between UNION and UNION ALL?**
    - UNION removes duplicate rows, UNION ALL keeps all rows, including duplicates.

## Cloud Fundamentals

1. **What is cloud computing and what are its main service models?**
   - Cloud computing means using remote servers on the internet to store, manage, and process data. Main models: IaaS, PaaS, SaaS.

2. **Explain the difference between IaaS, PaaS, and SaaS.**
   - IaaS: Infrastructure as a Service (servers, storage). PaaS: Platform as a Service (tools for building apps). SaaS: Software as a Service (ready-to-use apps).

3. **What is scalability in cloud computing?**
   - Scalability means the system can handle more work by adding resources.

4. **How does cloud elasticity differ from scalability?**
   - Elasticity means resources can be added or removed automatically as needed. Scalability is about growing resources, elasticity is about quick changes.

5. **What are the benefits of using cloud storage?**
   - Easy access, backup, sharing, and cost savings. You pay for what you use.

6. **What is a Virtual Private Cloud (VPC)?**
   - A VPC is a private network in the cloud that you control, like your own data center.

7. **How do you ensure security in cloud environments?**
   - Use strong passwords, encryption, firewalls, and access controls.

8. **What is serverless computing? Give an example.**
   - Serverless means you run code without managing servers. Example: AWS Lambda.

9. **Explain the concept of multi-tenancy in cloud.**
   - Multi-tenancy means one system serves many users, keeping their data separate.

10. **What are some common cloud deployment models?**
    - Public cloud, private cloud, hybrid cloud, and community cloud.

---
These answers are written in simple English to help you prepare for Cognizant Cluster 2 interviews on Python, ANSI SQL, and Cloud Fundamentals.
