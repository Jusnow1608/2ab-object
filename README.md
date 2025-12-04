# BudgetApp – Simple Budget Management Application

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

## Table of Contents
- [Project Structure](#project-structure)
- [Data Storage](#data-storage)
- [Users](#users)
   - [Login and Registration](#login-and-registration)
   - [Password change](#password-change)
- [Financial Operations](#financial-operations)
   - [Adding Operations](#adding-operations)
   - [Display balance](#display-balance)
- [UML Diagram](#uml-diagram)
- [Tests](#tests)

---

## Project Structure

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

## Data Storage

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

---

## Users

### Login and Registration

Registration creates a new user in users.xml.
Login verifies credentials and assigns LOGGED_IN_USER_ID.

Registration console view:

<img src="assets/images/user-register.png" alt="User register" width="600" />

Login console view:

<img src="assets/images/user-login.png" alt="User login" width="600" />

### Password change

Password change console view:

<img src="assets/images/password-change.png" alt="Password change" width="600" />

## Financial Operations
Operations are displayed in a table with columns: Date, Item, Amount.

## Adding Operations

Adding an income or expense is done through a console form.  
Below are screenshots showing the actual console output:

### Add Income

<img src="assets/images/add-income.png" alt="Add Income" width="600" />

### Add Expense

<img src="assets/images/add-expense.png" alt="Add Expense" width="600" />

---

### Display balance
Balance can be displayed for:
- Current month,
- Previous month,
- Custom date range.
Current month balance console output:

<img src="assets/images/current-month-balance.png" alt="Current month balance" width="600" />

Previous month balance console output:

<img src="assets/images/previous-month-balance.png" alt="Previous month balance" width="600" />

Previous month balance console output:

<img src="assets/images/balance-for-selected-period.png" alt="Balance for selected period" width="600" />

## UML Diagram
The following UML diagram was created using UMLet version 15.1 and illustrates the main classes and their relationships:

<img src="assets/images/planUMLAB.v2.png" alt="UML Diagram" width="1000" /> 

## Tests
Unit tests cover:
- Date and amount validation,
- Adding and filtering operations,
- XML file handling,
- Balance calculation logic.

## Future Improvements
- Better table formatting with dynamic column widths,
- Extended test coverage,
- Exporting data to external formats.


