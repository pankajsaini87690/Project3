# Bank Management System

A small console-based bank account management program written in C++.

## Features

- Create an account with an account number, holder name, and initial balance
- Deposit and withdraw money with basic amount and balance checks
- Display account details
- Save account details to a local text file

## Requirements

- A C++ compiler such as `g++` or `clang++`

## Build and run

From this directory, compile the program:

```sh
g++ -std=c++17 "bank management system.cpp" -o bank-management-system
```

Run it:

```sh
./bank-management-system
```

On Windows, run the generated `bank-management-system.exe` instead.

## Data storage

Choose **Save Account** in the program to append the current account details to
`accounts.txt` in the current working directory. This file is local runtime
data and is intentionally excluded from version control.

> This is a learning project, not production banking software. It does not
> provide secure storage or load previously saved accounts.
