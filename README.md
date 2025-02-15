# Multi-Threaded Matrix Multiplication in C

## Description
This project performs matrix multiplication using **POSIX threads (pthreads)**. Each element of the resulting matrix is computed in a separate thread to achieve parallelism.

## Files
- `matrix_multiplication.c` - Main C program implementing multi-threaded matrix multiplication.
- `Makefile` - Compilation script.

## Usage

1. **Compile the code using `make`**:
   ```sh
   make
   ```

2. **Run the program**:
   ```sh
   ./matrix_multiplication
   ```

3. **Input the matrices**:
   - Enter the dimensions and elements for Matrix A and Matrix B.
   - Ensure that the **number of columns of A matches the number of rows of B**.

4. **Example Output**:

```
Enter dimensions of Matrix A (rows cols): 2 3
Enter dimensions of Matrix B (rows cols): 3 2
Enter elements of Matrix A:
1 2 3
4 5 6
Enter elements of Matrix B:
7 8
9 10
11 12
Resultant Matrix C:
58 64
139 154
```

## Cleanup
To remove compiled files:
```sh
make clean
```