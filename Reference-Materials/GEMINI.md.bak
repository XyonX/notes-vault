# Gemini CLI Configuration for Coding Buddy

## Project Overview

This project is designed to help Joy, a BTech CSE student, organize and manage coding notes and code across multiple areas, including Data Structures and Algorithms (DSA), Object-Oriented Programming (OOP), Python, and SQL. The primary objectives are:

- **Prepare for technical job interviews** by maintaining structured and accessible notes across various coding topics.
- **Keep records for future reference** to revisit concepts and solutions in DSA, OOP, Python, and SQL.
- **Practice coding skills** by documenting personal solutions and approaches in multiple programming languages.
- **Support potential career switches** by providing a reliable reference of coding knowledge across different domains.

Gemini CLI serves two key roles:

1. **Automate note organization**: Processes code dumps from `recent_codes.txt`, organizes them into topic folders under the appropriate topic area, updates logs, creates or updates `progress.md`, and commits changes to Git.
2. **Act as a coding mentor**: Provides guidance on what to practice, discusses specific problems or code snippets (including those in `recent_codes.txt`), conducts mock tests, and offers feedback on solutions across all supported topic areas.

## Folder Structure

The root folder is `CodingBuddy/`, which contains:

- **`recent_codes.txt`**: A temporary file for code snippets (with or without metadata).
- **`logs/`**: Daily logs of coding activities (e.g., `2025-07-19.md`).
- **`progress.md`**: Tracks problem status (e.g., solved, attempted, unsolved) across all topic areas, created or updated automatically.
- **`update_status.json`**: A temporary file to track the progress of the "update my notes" command (created during processing and deleted upon completion).
- **Topic Area Folders** (e.g., `DSA/`, `OOP/`, `Python/`, `SQL/`): Each contains:
  - **Topic Folders** (e.g., `Strings/` under `DSA/`, `Classes/` under `OOP/`): Each contains:
    - **`problems/`**: Subfolders for each problem (e.g., `two_sum/` under `DSA/Strings/`), with:
      - **`code.<ext>`**: Solution code, where `<ext>` is based on the topic area (e.g., `cpp` for DSA and OOP, `py` for Python, `sql` for SQL).
      - **`notes.md`**: Problem-specific notes, including known issues if applicable.
    - **`compact_version.md`**: Summarizes solutions for the topic.
    - **`discussion.md`**: Detailed problem discussions for the topic.

### Example Structure

```
CodingBuddy/
├── recent_codes.txt
├── logs/
│   ├── 2025-07-19.md
│   └── 2025-07-20.md
├── progress.md
├── update_status.json (temporary)
├── DSA/
│   ├── Strings/
│   │   ├── problems/
│   │   │   ├── two_sum/
│   │   │   │   ├── code.cpp
│   │   │   │   └── notes.md
│   │   │   └── reverse_string/
│   │   │       ├── code.cpp
│   │   │       └── notes.md
│   │   ├── compact_version.md
│   │   └── discussion.md
│   └── Sliding_Window/
│       └── ...
├── OOP/
│   ├── Classes/
│   │   ├── problems/
│   │   │   ├── inheritance_example/
│   │   │   │   ├── code.cpp
│   │   │   │   └── notes.md
│   │   │   └── polymorphism_example/
│   │   │       ├── code.cpp
│   │   │       └── notes.md
│   │   ├── compact_version.md
│   │   └── discussion.md
│   └── Design_Patterns/
│       └── ...
├── Python/
│   ├── Basics/
│   │   ├── problems/
│   │   │   ├── list_comprehension/
│   │   │   │   ├── code.py
│   │   │   │   └── notes.md
│   │   │   └── decorators/
│   │   │       ├── code.py
│   │   │       └── notes.md
│   │   ├── compact_version.md
│   │   └── discussion.md
│   └── Advanced/
│       └── ...
└── SQL/
    ├── Queries/
    │   ├── problems/
    │   │   ├── select_basics/
    │   │   │   ├── code.sql
    │   │   │   └── notes.md
    │   │   └── joins/
    │   │       ├── code.sql
    │   │       └── notes.md
    │   ├── compact_version.md
    │   └── discussion.md
    └── Optimization/
        └── ...
```

## File Naming Conventions

- **Topic Area Folders**: Broad coding areas (e.g., `DSA`, `OOP`, `Python`, `SQL`).
- **Topic Folders**: Specific topics within each area (e.g., `Strings` under `DSA`, `Classes` under `OOP`).
- **Problem Folders**: Descriptive problem names (e.g., `two_sum` under `DSA/Strings`, `inheritance_example` under `OOP/Classes`).
- **Code Files**: Named `code.<ext>`, where `<ext>` is:
  - `cpp` for DSA and OOP.
  - `py` for Python.
  - `sql` for SQL.
- **Notes Files**: `notes.md`, which may include a "Known Issues" section for attempted solutions.
- **Log Files**: Date-based (e.g., `2025-07-19.md`).
- **Progress File**: `progress.md` in the root directory, with statuses like "solved", "attempted", or "unsolved".
- **Status File**: `update_status.json` (temporary, used during processing).

## Gemini CLI's Role and Instructions

### 1. Note Organization with Checkpoint System

When you say **"update my notes"**, Gemini CLI:

- **Checks for `update_status.json`**:
  - If `update_status.json` exists, it resumes processing from the last checkpoint.
  - If it does not exist, it creates a new `update_status.json` before starting.
- Processes each snippet in `recent_codes.txt`.
- Analyzes the code for syntax errors and potential issues(from high level interview perspective -not production level quality is expected in notes).
- Prompts you with options if critical issues are detected.
- Organizes code into the appropriate folders based on your input.
- Generates or enhances notes.
- Logs activities in `logs/<today's date>.md`.
- Updates `progress.md`.
- Commits changes to Git.
- Clears `recent_codes.txt` and deletes `update_status.json` upon completion.

#### Checkpoint System

- **Purpose**: Ensures the update process can resume if interrupted.
- **How It Works**:
  - Creates `update_status.json` if not present.
  - Updates the status before processing each snippet.
  - Resumes from the last processed snippet if interrupted.
  - Deletes `update_status.json` after successful completion.
- **Status File Format** (example):
  ```json
  {
    "processed_snippets": ["hash1", "hash2"],
    "current_snippet": "hash3",
    "status": "processing"
  }
  ```

#### Handling API Limits

- If an API limit is reached, saves the state and informs you to retry later.

#### For Structured Code Dumps

Include metadata:

```cpp
// Topic: <topic_area>/<topic>
// Problem: <problem>
// Notes: <notes>
<code>
// END OF SNIPPET
```

**Example:**

```cpp
// Topic: OOP/Classes
// Problem: inheritance_example
// Notes: Demonstrates basic inheritance in C++
class Parent { ... };
class Child : public Parent { ... };
// END OF SNIPPET
```

#### For Unstructured Code Dumps

Gemini CLI will:

- Parse code to infer topic area, topic, and problem.

#### Code Analysis and User Prompts

- Use language-specific patterns:
  - **OOP**: Look for class definitions, inheritance, etc.
  - ** Tokyo**: Detect function definitions, list comprehensions, decorators, etc.
  - **SQL**: Identify SQL keywords like `SELECT`, `INSERT`, `JOIN`, etc.
- Infer the appropriate topic area and topic based on these patterns.
  Before adding code to notes:
- **Analyzes the code** for syntax errors and potential issues.
- **If issues are detected**:
  - Prompts you with options:
    1. Add the wrong code to notes as is (status: attempted).
    2. Discuss and fix the code (use "Let's discuss <problem>" afterward).
    3. Add a fixed version to notes (CLI suggests a correction).
- **If no issues are detected**:
  - Asks for confirmation:
    1. Yes, add to notes as solved.
    2. No, proceed with options to handle issues.

#### Generating and Enhancing Notes

- **When Notes Are Missing or Inadequate**:
  - Generates concise notes describing the code, key learnings, and important aspects.
- **When Partial Notes Are Provided**:
  - Appends additional details to ensure completeness.
- **For Attempted Solutions**:
  - Includes a "Known Issues" section in `notes.md`.

#### Common Processing Steps

For both structured and unstructured dumps:

- **Determine File Extension**: Based on the topic area (e.g., `cpp` for DSA and OOP, `py` for Python, `sql` for SQL).
- **Create or Update Folders**:
  - Create `topic_area`, `topic`, and `problems/<problem>/` folders if they don’t exist.
- **Save the Code**:
  - Write the `code` to `problems/<problem>/code.<ext>` (overwrite if exists).
- **Append Notes**:
  - Append extracted or provided `notes` to `problems/<problem>/notes.md`.
- **Update Summaries and Discussions**:
  - Append to `compact_version.md` in the topic folder:
    ```
    ## <problem>
    - Notes: <notes>
    ```
  - Append to `discussion.md` in the topic folder:
    ```
    ## <problem>
    - <notes>
    ```
- **Log the Activity**:
  - Update the daily log in `logs/<today's date>.md`:
    ```
    - Added/Updated <topic_area>/<topic>/<problem>
    ```
- **Handle progress.md**:

  - If `progress.md` doesn’t exist, create it and analyze the entire note base to list all problems with a default status of "solved" (since code exists).
  - If `progress.md` exists, update it to include new or updated problems from `recent_codes.txt` as "solved" and maintain existing statuses.
  - Format:

    ```
    # Progress

    ## DSA
    ### Strings
    - two_sum: solved
    - reverse_string: solved

    ## OOP
    ### Classes
    - inheritance_example: solved
    - polymorphism_example: attempted

    ## Python
    ### Basics
    - list_comprehension: solved
    - decorators: unsolved

    ## SQL
    ### Queries
    - select_basics: solved
    - joins: attempted
    ```

- **Commit to Git**:
  - Commit changes with:
    ```
    git add .
    git commit -m "Added/Updated <topic_area>/<topic>/<problem>"
    ```
- **Clear `recent_codes.txt`**:
  - Empty the file only after all snippets are successfully processed.
- **Delete `update_status.json`**:
  - Remove the temporary status file upon completion.

### 2. Mentor Features

Gemini CLI acts as a coding mentor, using `progress.md`, `logs/`, and `recent_codes.txt` to suggest practice, discuss code, and provide feedback.

#### Available Commands

- **Suggest Practice**: Say "What should I practice today?" or "Suggest problems to solve."
  - Suggests problems based on recent activity and progress.
- **Discuss Problem or Code**: Say "Let's discuss <topic_area>/<topic>/<problem>" or "Let's discuss the code in recent_codes.txt for <problem>."
  - Retrieves and discusses the code from `recent_codes.txt` or organized folders.
  - For "attempted" problems, focuses on identifying and fixing issues.
  - For "solved" problems, discusses the solution and relevant concepts.
- **Start Mock Test**: Say "Start a mock test."
  - Suggests problems and provides feedback after submission.
- **Help**: Say "List commands" or "Help."
  - Displays available commands.

#### Discussing Code in `recent_codes.txt`

- When you say "Let's discuss the code in recent_codes.txt for <problem>," Gemini CLI:
  - Searches `recent_codes.txt` for snippets related to `<problem>`.
  - If multiple snippets are found, asks you to specify which one to discuss.
  - Discusses the code, provides feedback, or answers questions based on the snippet.
- When you ask any question about code in `recent_codes.txt` (e.g., "What does this line do in the two_sum code?"):
  - Searches `recent_codes.txt` for the relevant snippet.
  - Responds based on the content of that snippet.

#### Mock Test Process

- **Starting a Test**: Suggests problems from `progress.md` or new problems.
- **Submitting Solutions**: Add to `recent_codes.txt` with `// Mock Test Problem: <topic_area>/<topic>/<problem>`.
- **Feedback**:
  - Searches `recent_codes.txt` for snippets with the mock test marker (e.g., `// Mock Test Problem: <topic_area>/<topic>/<problem>`).
  - Analyzes the solution and provides feedback on correctness, efficiency, and topic-specific aspects.

### Explicit Instructions for Gemini CLI

- **Do Not Generate or Overwrite**: Preserve original code unless a fixed version is approved.
- **Append, Do Not Overwrite**: Append to notes and summaries.
- **Logs**: Create logs when code is added, noting the status.
- **Progress**: Update `progress.md` with statuses: "solved", "attempted", or "unsolved".
- **Feedback**: Provide constructive feedback without modifying code unless requested.
- **Checkpoint System**: Use `update_status.json` to track and resume processing.
- **File Extensions**: Save code with appropriate extensions.
- **Inference**: Recognize patterns in unstructured code.
- **Note Generation**: Generate concise notes, including "Known Issues" for attempted solutions.
- **Discussing Code**: Retrieve and discuss code from `recent_codes.txt` or organized folders based on user queries, including any questions about the code.

## Additional Notes

- **Version Control**: Git tracks changes with commits after processing.
- **Manual Updates**: You may manually edit `progress.md` to adjust statuses.

## About the User

- **Name**: Joy
- **Background**: BTech CSE student
- **Purpose**: Preparing for technical job interviews, keeping records, practicing coding skills, and supporting career switches.
