# Employee Overtime Management System

## Overview
This is a C-based console application for managing employee overtime hours. The system allows users to:
- Register employees
- Track overtime hours
- Approve/reject overtime requests
- Generate reports to a text file

## Project Structure
- `main.c` - Main program entry point with the menu system
- `funcoes.c` - Implementation of core functions (employee management, overtime tracking, reporting)
- `funcoes.h` - Header file with struct definitions and function declarations
- `dados.txt` - Output file for generated reports (created at runtime)
- `Makefile` - Build configuration for compiling the project

## Technical Details
- **Language**: C
- **Compiler**: GCC (clang)
- **Type**: Console/TUI Application
- **Data Storage**: In-memory (array of structs) with file output for reports

## How to Build and Run
The project uses a Makefile for easy compilation:

```bash
make        # Compile the program
make run    # Compile and run the program
make clean  # Remove compiled files
```

Alternatively, compile manually:
```bash
gcc -o programa main.c funcoes.c
./programa
```

## Features
1. **Employee Registration** - Add new employees with ID, name, overtime hours, hourly rate, and date
2. **Overtime Tracking** - Add additional overtime hours to existing employees
3. **List Records** - View all employee records with current status
4. **Approval System** - Approve or reject overtime requests
5. **Report Generation** - Export detailed reports to `dados.txt`

## Menu Options
- 1: Register new employee
- 2: Add overtime hours
- 3: List all records
- 4: Approve/reject overtime
- 5: Generate final report
- 0: Exit system

## Recent Changes
- **2025-10-29**: Initial Replit environment setup
  - Installed C compiler (GCC via c-clang module)
  - Created Makefile for build automation
  - Configured workflow for console application
  - Updated .gitignore for C build artifacts

## Architecture
The application uses a simple struct-based architecture:
- `struct funcionario` holds employee data (ID, name, overtime hours, hourly rate, date, approval status)
- Array of up to 100 employees stored in memory
- File I/O for report generation only
- Interactive menu-driven interface
