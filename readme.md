# Bank Management System

## Overview

The Bank Management System is a simplified application developed in C++ that allows users to manage multiple bank accounts. The system provides functionalities for creating accounts, depositing and withdrawing funds, transferring money between accounts, and displaying account details. This project demonstrates the use of concepts such as Composition, Aggregation, Friend Function, and Friend Class.

## Features

- **Create Account:** Dynamically create a new bank account with a unique account number.
- **Deposit Funds:** Deposit money into an account.
- **Withdraw Funds:** Withdraw money from an account, with checks for sufficient balance.
- **Transfer Funds:** Transfer money between accounts.
- **Find Account:** Locate an account by its account number.
- **Delete Account:** Remove an account from the system.
- **Display Accounts:** View details of all accounts, including account number, account holder name, and balance.
- **Total Accounts:** Keep track of the total number of accounts created.

## Requirements

To compile and run the project, you need:

- A C++ compiler (e.g., g++, clang++)
- Basic knowledge of C++ programming concepts

## Code Structure

The project consists of two main classes:

1. **BankAccount Class**
   - Manages individual bank accounts.
   - Private members: `accountNumber`, `accountHolder`, `balance`.
   - Static member to track total accounts created.
   - Member functions for account operations (deposit, withdraw, transfer, etc.).

2. **BankManager Class**
   - Manages a collection of `BankAccount` objects.
   - Functions to create, delete, find, and display accounts.

## Usage

1. Compile the code using a C++ compiler:

   ```bash
   g++ -o BankManagementSystem main.cpp

**Welcome to Bank Management System***
    Press[1]. Create Account
    
    Press[2]. Deposit Amount
    
    Press[3]. Withdraw Amount
    
    Press[4]. Transfer Funds
    
    Press[5]. Find Account
    
    Press[6]. Delete Account
    
    Press[7]. Display All Accounts
    
    Press[0]. Exit
