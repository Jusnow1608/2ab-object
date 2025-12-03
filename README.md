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
- [Adding Operations](#adding-operations)
- [Users](#users)
   - [Login and Registration](#login-and-registration)
   - [Logout](#logout)
- [Financial Operations](#financial-operations)
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

Each operation contains:
- `id` – unique identifier,
- `userId` – ID of the user who owns the operation,
- `date` – operation date,
- `item` – description,
- `amount` – value of the operation.

Operations are filtered by `userId`, so each user sees only their own data.

---

## Adding Operations

Adding an income or expense is done through a console form.  
Below are screenshots showing the actual console output:

### Add Income

<img src="assets/images/add-income.png" alt="Add Income" width="600" />

### Add Expense

<img src="assets/images/add-expense.png" alt="Add Expense" width="600" />

---

## Users

### Login and Registration

Registration creates a new user in users.xml.
Login verifies credentials and assigns LOGGED_IN_USER_ID.

Registration console view:

Login console view:

### Logout

Logout console view:


## Financial Operations
Operations are displayed in a table with columns: Date, Item, Amount.

### Display Incomes
Example console table:

### Display balance
Balance can be displayed for:
- Current month,
- Previous month,
- Custom date range.
Balance console output:

## UML Diagram
The following UML diagram illustrates the main classes and their relationships:
UML Diagram

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


