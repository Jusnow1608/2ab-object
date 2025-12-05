# BudgetApp – Simple budget management application

BudgetApp is a console-based application written in **C++**, designed to help users manage their personal finances.  
It allows tracking incomes and expenses, calculating balances for different time periods, and storing data in XML files.

---

### Description
This application enables users to:
- Register and log in to the system,
- Add incomes and expenses,
- View a list of financial operations,
- Display balance for the current month, previous month, or a custom date range,
- Manage user accounts (change password, log out).

All data is stored in XML files and filtered by the logged-in user ID, ensuring that each user sees only their own operations.

---

## Table of contents
- [Project Structure](#project-structure)
- [UML Diagram](#uml-diagram)
- [Data Storage](#data-storage)
- [Menu](#menu)
- [Users](#users)
   - [Login and Registration](#login-and-registration)
   - [Password change](#password-change)
   - [Logout](#logout)
- [Financial Operations](#financial-operations)
   - [Adding Operations](#adding-operations)
   - [Operations and balance view](#operations-and-balance-view)
   - [Display balance](#display-balance)
- [Tests](#tests)
- [Future Improvements](#future-improvements)

---

## Project structure

The project consists of several classes and helper structures:

- **BudgetMainApp** – main application class, handles menus and control flow.  
- **UserManager** – manages users (registration, login, password change).  
- **BudgetManager** – manages financial operations (adding, displaying, calculating balance).  
- **OperationFile** – handles saving and loading operations from XML files.  
- **UserFile** – manages persistence of user accounts in XML.  
- **File** – base class for file handling.  
- **AuxiliaryMethods** – helper functions for input/output validation.
- **DateMethods** – helper functions for date validation and conversion.  
- **CashMethods** – helper functions for amount validation.  

**Data structures:**
- `struct User` – represents a user account and contains id, login, password, name, surname.  
- `struct Operation` – represents a financial operation and contains id, userId, date, item, amount, type.  
- `enum class Type` – defines `INCOME` and `EXPENSE`.

---

## UML diagram
The following UML diagram was created using UMLet version 15.1 and illustrates the main classes and their relationships:

<img src="assets/images/planUMLAB.v2.png" alt="UML Diagram" width="1000" /> 

---

## Data storage

The application uses XML files:
- `users.xml` – stores user accounts,
- `incomes.xml` – stores incomes,
- `expenses.xml` – stores expenses,

Each user account contains:
- `id` – unique user identifier,
- `login` – unique user login,
- `password` – password to user account,
- `name` – user name,
- `surname` – user surname.

Each operation contains:
- `id` – unique operation identifier,
- `userId` – ID of the user who owns the operation,
- `date` – operation date,
- `item` – description,
- `amount` – value of the operation.

Operations are filtered by `userId`, so each user sees only their own data.

### XML file views
<div style="display: flex; gap: 20px;">
  <img src="assets/images/user-file.png" alt="User file" width="250" />
  <img src="assets/images/income-file.png" alt="Income file" width="250" />
  <img src="assets/images/expense-file.png" alt="Expense file" width="250" />
</div>
---

## Menu

Main menu allows a new user to select basic operations related with registation and login.

Main menu console view:

<img src="assets/images/main-menu.png" alt="Main menu" width="600" />

User menu is available only for logged user and allows to select operations related with finance and user account management.

User menu console view:

<img src="assets/images/user-menu.png" alt="User menu" width="600" />

---

## Users

### Login and registration

- Registration creates a new user in `users.xml`.
- Login verifies credentials and assigns `LOGGED_IN_USER_ID`.
- Login attempts are limited to 3 trials before lockout.

<img src="assets/images/user-register.png" alt="User register" width="600" />
<img src="assets/images/user-login.png" alt="User login" width="600" />

### Password change

- Password change updates a user password in `users.xml`.
- Empty passwords are rejected by validation.

<img src="assets/images/password-change.png" alt="Password change" width="600" />

### Logout

- Logging out resets the session and clears the active `BudgetManager`.

<img src="assets/images/Logout.png" alt="Logout" width="400" />

---

## Financial Operations

For a logged in user the following financial operations are available:
- Adding operations,
- Viewing operations and balance tables,
- Displaying balance for selected period.

### Adding Operations

- Adding an income or expense is done through a console form.
- Dates can be today or user-provided (`YYYY-MM-DD`).
- Amounts are validated (dot/comma accepted, must be numeric).
- Operations are saved in `incomes.xml` or `expenses.xml`.

<img src="assets/images/add-income.png" alt="Add Income" width="600" />
<img src="assets/images/add-expense.png" alt="Add Expense" width="600" />

### Operations and balance view

Operations are displayed in a table with columns: Date, Item, Amount.  
Tables are sorted chronologically (oldest first).

<img src="assets/images/income-view.png" alt="Income view" width="600" />
<img src="assets/images/expense-view.png" alt="Expense view" width="600" />
<img src="assets/images/balance-view.png" alt="Balance view" width="600" />

### Display balance
Balance can be displayed for:
- Current month,
- Previous month,
- Custom date range.

When displaying balance:
- All operations are **filtered by date range**,
- Then **sorted chronologically** (oldest first),
- Then **grouped by type** (`INCOME` or `EXPENSE`),
- Each group is **summed** and shown in a formatted table.

<img src="assets/images/current-month-balance.png" alt="Current month balance" width="600" />
<img src="assets/images/previous-month-balance.png" alt="Previous month balance" width="600" />
<img src="assets/images/balance-for-selected-period.png" alt="Balance for selected period" width="600" />

---

## Tests
Unit tests cover:
- **Date validation**:
  - Format check (`YYYY-MM-DD`),
  - Leap year detection,
  - Range validation,
- **Amount validation**:
  - Accepts both dot and comma,
  - Rejects non-numeric input,
- **Operation logic**:
  - Adding operations,
  - Filtering by date,
  - Sorting by date,
- **File handling**:
  - XML read/write,
  - ID generation,
- **Balance calculation**:
  - Correct summing of filtered operations,
  - Accurate difference between incomes and expenses.

---

## Future Improvements
- Better table formatting with dynamic column widths,
- Extended test coverage with controller-level tests,
- Exporting data to external formats,
- Error handling views (invalid input, failed file operations),
- Coverage reports.


