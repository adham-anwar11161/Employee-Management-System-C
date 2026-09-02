# 🏢 Employee Management System (C / Console UI)

A lightweight CLI-based **Employee Management System** built in C. It features interactive console menu navigation using arrow keys, file persistence, dynamic searching, sorting, and field-level data validation.

---

## ✨ Features

* **Interactive Menu Navigation:** Navigable CLI menu built using Windows API (`conio.h`, `SetConsoleTextAttribute`, `gotoxy`).
* **CRUD Operations:**
  * **Add Employee:** With auto-generated enrollment date using system time (`time.h`).
  * **Query / Search:** Search employees by name substring matching (`strstr`).
  * **Modify:** Edit specific fields (Name, Salary, Address, Mobile, Email).
  * **Delete:** Remove employee records by ID.
  * **Print:** View all employees sorted alphabetically.
* **Data Validation:**
  * Strict ID uniqueness checks.
  * Mobile number format verification (11 digits).
  * Email format parsing (`@` and domain check).
* **File Persistence:** Read and write employee records to `emp.txt` using CSV tokenization (`strtok`).
* **Sorting Algorithm:** Built-in Bubble Sort algorithm to structure data alphabetically by name.

---

## 🛠️ Tech Stack

* **Language:** C (C99 standard)
* **Libraries:** `stdio.h`, `stdlib.h`, `string.h`, `time.h`, `windows.h`, `conio.h`
* **IDE / Compiler:** Code::Blocks / GCC (MinGW)

---

## 🚀 Getting Started

### Prerequisites
* Windows OS (uses Windows Console API)
* GCC Compiler / Code::Blocks

### Compilation & Execution

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/adham-anwar11161/Employee-Management-System-C.git](https://github.com/adham-anwar11161/Employee-Management-System-C.git)
