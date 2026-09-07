# Linear System Solver in C

A robust, modular implementation of a linear system solver ($Ax = b$) built from scratch in C. The project utilizes **Gaussian elimination with partial pivoting** to guarantee numerical stability and manages augmented matrices dynamically.

## Features

* **Partial Pivoting**: Minimizes rounding errors and prevents division by zero by tracking and swapping row pointers based on the maximum absolute value in each column.
* **Modular Architecture**: Clean separation of concerns across dedicated modules for matrix operations, mathematical solving logic, and the user interface.
* **Dynamic Memory Management**: Allocates matrix structures and rows using pointer-to-pointers (`double **data`) with strict clean-up routines to prevent memory leaks.
* **Singularity Detection**: Automatically detects singular or near-singular matrices during execution and handles errors safely.

## Project Structure

* `matrix.h` / `matrix.c`: Core data structures and functions for dynamic matrix allocation, file parsing (`popolaDaFile`), display, and safe deallocation.
* `solver.h` / `solver.c`: Mathematical engine containing the forward elimination and back-substitution algorithms.
* `main.c`: Entry point handling command-line arguments, file input verification, solver execution, and user interaction.

## Compilation and Usage

Compile all source files together using `gcc` (link the math library with `-lm`):

```bash
gcc main.c matrix.c solver.c -o linear_solver -lm
