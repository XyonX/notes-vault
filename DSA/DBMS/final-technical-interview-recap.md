
01 what is dbms:

A **Database Management System (DBMS)** is software that allows users to **store, organize, manage, and retrieve data efficiently**. It provides an interface between the database and end-users or application programs, ensuring that data is **consistently organized, secure, and easily accessible**.

**Main functions of DBMS:**

1. **Data Storage Management** – Efficiently stores data and metadata.
    
2. **Data Retrieval** – Uses query languages like SQL to retrieve information.
    
3. **Data Manipulation** – Allows inserting, updating, and deleting data.
    
4. **Security Management** – Controls access and ensures data privacy.
    
5. **Transaction Management** – Maintains consistency even in concurrent access or failures.
    
6. **Backup and Recovery** – Protects data from loss or corruption.


02 What are the differences between a DBMS and an RDBMS?

**DBMS (Database Management System)** is software used to store and manage data. It can handle data but **doesn’t necessarily maintain relationships** between data entities.

**RDBMS (Relational Database Management System)** is an advanced type of DBMS that **stores data in tables (relations)** and allows relationships between them using **primary keys** and **foreign keys**.


**Key Differences:**

| Feature            | DBMS                                              | RDBMS                                       |
| ------------------ | ------------------------------------------------- | ------------------------------------------- |
| **Data Storage**   | Stores data as files or non-relational structures | Stores data in tables (rows and columns)    |
| **Relationships**  | No relationships between data                     | Relationships are maintained via keys       |
| **Normalization**  | Not supported                                     | Supports normalization to reduce redundancy |
| **Example**        | File System, dBase                                | MySQL, PostgreSQL, Oracle, SQL Server       |
| **Data Integrity** | Low (manual handling)                             | Enforced using constraints (PK, FK, etc.)   |
### 03 What are keys in DBMS (or RDBMS)? Explain different types of keys and their purposes.

In DBMS/RDBMS, **keys** are attributes (or combinations of attributes) that help in **uniquely identifying records** and **defining relationships** between tables.  
They ensure **data integrity** and **uniqueness**.

---

### 🔑 **Types of Keys:**

1. **Primary Key**
    
    - A column (or set of columns) that **uniquely identifies** each record in a table.
        
    - Cannot have `NULL` values and cannot be duplicated.
        
    - Each table can have **only one** primary key.
        
    - 📘 Example:  
        In a `Students` table, `student_id` could be a primary key.
        

---

2. **Candidate Key**
    
    - All attributes that could potentially serve as a primary key.
        
    - The **primary key** is chosen from the **candidate keys**.
        
    - 📘 Example:  
        A `Students` table might have both `student_id` and `email` as unique identifiers → both are candidate keys.
        

---

3. **Alternate Key**
    
    - The **candidate keys that are not chosen** as the primary key.
        
    - 📘 Example:  
        If `student_id` is the primary key, then `email` is an alternate key.
        

---

4. **Foreign Key**
    
    - A column that **links one table to another** by referencing the **primary key** of another table.
        
    - Ensures **referential integrity** — a foreign key value must match an existing primary key in the related table.
        
    - 📘 Example:  
        In an `Enrollments` table, `student_id` can be a foreign key referencing `Students(student_id)`.
        

---

5. **Composite Key**
    
    - A key made up of **two or more columns** used together to uniquely identify a record.
        
    - Used when no single attribute is unique by itself.
        
    - 📘 Example:  
        In a `Course_Enrollments` table, the combination `(student_id, course_id)` could be a composite key.
        

---

6. **Super Key**
    
    - Any attribute (or combination of attributes) that can **uniquely identify a row**.
        
    - Includes all candidate keys plus any supersets of them.
        
    - 📘 Example:  
        `student_id` alone is a super key, but so is `(student_id, name)` — though redundant.
        

---

### 🧩 Summary Table

|Key Type|Purpose|
|---|---|
|Primary|Unique identification of a row|
|Candidate|All possible unique identifiers|
|Alternate|Candidate keys not selected as primary|
|Foreign|Maintains relationship between tables|
|Composite|Combines multiple attributes for uniqueness|
|Super|Any set of attributes that uniquely identifies rows|

04 What is referential integrity in RDBMS? How is it maintained, and what happens when a referenced record is deleted or updated?

**Referential integrity** is a rule in **RDBMS** that ensures the **relationship between two tables remains consistent**.

### ⚙️ When and how referential integrity is set up

Referential integrity **is not automatic** —  
you have to **explicitly define** it when creating (or later altering) a table using a **foreign key constraint**.

It’s the _foreign key definition itself_ that tells the RDBMS:

1. which column in the child table refers to which column in the parent table, and
    
2. what actions to take if the parent row changes or gets deleted.
    

---

### 🧱 Example — Define it while creating a table

`CREATE TABLE Students (   student_id INT PRIMARY KEY,   name VARCHAR(50) );  CREATE TABLE Enrollments (   enroll_id INT PRIMARY KEY,   student_id INT,   course VARCHAR(50),    FOREIGN KEY (student_id)   REFERENCES Students(student_id)   ON DELETE CASCADE   ON UPDATE CASCADE );`

Here’s what happens:

- The line
    
    `FOREIGN KEY (student_id) REFERENCES Students(student_id)`
    
    sets up the **referential integrity rule** — linking `Enrollments.student_id` to `Students.student_id`.
    
- The options:
    
    - `ON DELETE CASCADE` → If a student is deleted, all their enrollments are also deleted automatically.
        
    - `ON UPDATE CASCADE` → If a student’s ID is updated, that change automatically reflects in all linked enrollments.
        

Without those, by default, most databases **block** the delete/update if child records exist (to prevent orphan rows).

---

### 🧩 You can also add it later

If you already have tables, you can add the foreign key constraint afterward using:

`ALTER TABLE Enrollments ADD CONSTRAINT fk_student FOREIGN KEY (student_id) REFERENCES Students(student_id) ON DELETE CASCADE ON UPDATE CASCADE;`

---

### 🧠 In summary

|Step|Action|
|---|---|
|1️⃣|Referential integrity is defined **manually**, not automatic|
|2️⃣|You set it using **FOREIGN KEY** constraints|
|3️⃣|You can define **ON DELETE / ON UPDATE** actions for control|
|4️⃣|You can add or modify it later using **ALTER TABLE**|

---

Would you like me to show a quick example of the **different ON DELETE / ON UPDATE behaviors** (like CASCADE, SET NULL, RESTRICT, etc.) before we go to the next question?



05 What is normalization in DBMS? Why is it needed, and what are the different normal forms?

### 💡 Correct concept:

**Normalization** is a **process** (not a constraint) in database design used to:

> organize data into multiple related tables in such a way that redundancy is minimized and data integrity is maintained.

It’s basically about _structuring_ the database efficiently — not just for optimization, but for **consistency**, **clarity**, and **scalability**.

---

### 🧩 Why normalization is needed:

Without normalization, problems like these can occur:

- **Data redundancy** – same data stored in multiple places.
    
- **Update anomalies** – you change one record, but another copy remains outdated.
    
- **Insertion anomalies** – can’t insert data because another unrelated field is missing.
    
- **Deletion anomalies** – deleting one record accidentally removes important related data.
    

Normalization solves this by breaking large tables into smaller, related ones using **keys**.

---

### ⚙️ Different Normal Forms (the “rules” or stages)

Each **normal form (NF)** is a level of database organization.

|Normal Form|Rule|Example Purpose|
|---|---|---|
|**1NF (First Normal Form)**|Each cell must contain a single atomic value (no multiple values in one column).|Remove repeating groups.|
|**2NF (Second Normal Form)**|Be in 1NF **and** every non-key attribute must depend on the whole primary key (no partial dependency).|Applies to composite keys.|
|**3NF (Third Normal Form)**|Be in 2NF **and** have no transitive dependency (non-key attributes should not depend on other non-key attributes).|Removes derived or indirect dependencies.|
|**BCNF (Boyce-Codd Normal Form)**|Stronger version of 3NF; every determinant must be a candidate key.|Fixes some rare 3NF edge cases.|

There are higher forms (4NF, 5NF) for very complex databases, but most systems aim for **3NF or BCNF** in practice.

---

### ✅ In short:

> Normalization is the process of splitting data logically into smaller, related tables to eliminate redundancy, improve consistency, and make updates efficient.

---

Would you like to move to the **next question (Question 6)** on _denormalization and when we intentionally break normalization rules_? It’s often the immediate follow-up in interviews.