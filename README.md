ATM System in C

# Problem Statement

This project implements a simple ATM system in C. The program simulates basic banking operations for multiple predefined users. Each user can log in with a username and a 4-digit PIN, then perform actions such as checking balance, depositing, withdrawing, and viewing transaction history.

This project aims to demonstrate the use of variables, control structures, arrays, strings, and modular functions in C, as well as handling input/output operations.

# Assumptions
- Users are predefined in the system (stored in arrays).
- PINs are fixed 4-digit numbers.
- Balances start with predefined values.
- Transaction history is limited to the last 5 operations.
- Input is assumed to be valid (no handling of non-numeric deposits/withdrawals or non positive deposits/withdrawals).

# How to Compile and Run
1. Clone the repository:
```bash
git clone 
cd advanced_atm_system
```

2. Compile the program:
```bash
gcc operations.c -o operations
```

3. Run the program:
```bash
./operations
```

# Sample Input/Output

Login:

Enter Username: john  
Enter PIN: 1234  
Login Successful!


Menu:

1. Check Balance  
2. Deposit  
3. Withdraw  
4. View Transactions  
5. Logout  


Example Transaction:

Enter amount to deposit: 200  
Deposit successful. New Balance: 1200


Transaction History Example:

Transactions:  
1. Deposited 200  
2. Withdrew 100  
3. Checked Balance  

# Key Functions


# Design Choices
- Modular functions are used for each ATM operation for clarity and reusability.