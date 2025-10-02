# ATM System in C

## 📌 Problem Statement

This project implements a simple ATM system in **C**.
The program simulates basic banking operations for multiple predefined users.
Each user logs in with a **username** and a **4-digit PIN**, then can perform actions such as:

* Checking balance
* Depositing money
* Withdrawing money
* Viewing transaction history

This project demonstrates:

* Use of **variables, arrays, and strings**
* **Control structures and loops**
* **Functions** and modular program design
* **Input/output handling** in C

---

## 🔑 Assumptions

* Users are **predefined** in the system (stored in arrays).
* PINs are fixed **4-digit strings**.
* Balances start with predefined values.
* Transaction history is limited to the **last 5 operations** per user.
* Input is assumed valid (no invalid number/character error handling).

---

## ⚙️ How to Compile and Run

1. **Clone the repository**

```bash
git clone <your-repo-url>
cd advanced_atm_system
```

2. **Compile the program**

```bash
gcc main.c operations.c -o atm
```

3. **Run the program**

```bash
./atm
```

---

## 🖥️ Sample Input/Output

**Login Example**

```
==== Welcome to the ATM System ====
Enter Username: precious
Enter PIN: 5678
Login successful! Welcome, precious
```

**Menu**

```
===== ATM MENU =====
1. Check Balance
2. Deposit
3. Withdraw
4. View Transactions
5. Exit
Select an option:
```

**Deposit Example**

```
Enter amount to deposit: 200
Deposited 200.00 RWF. New balance: 1700.00 RWF
```

**Transaction History Example**

```
Last 3 transactions:
1. Deposited 200 RWF
2. Withdrew 100 RWF
3. Checked Balance
```

---

## 📂 Key Functions

* `login()` → Validates username and PIN
* `check_balance()` → Displays current user’s balance
* `deposit()` → Adds money to balance and logs transaction
* `withdraw()` → Subtracts money if sufficient funds exist
* `view_transactions()` → Shows the last 5 transactions
* `add_transaction()` → Records a new transaction in history
* `exit_program()` → Safely exits the ATM

---

## 🎨 Design Choices

* **Modular programming** → Each operation is in a separate function for clarity.
* **Arrays and strings** → Used for storing users, PINs, balances, and transaction logs.
* **Transaction history** → Implemented as a circular buffer (only last 5 saved).
* **Scalability** → Supports up to `MAX_USERS` (default = 10).

---

## 👥 Authors

* Denaton Agbikossi
* Precious Mozia

