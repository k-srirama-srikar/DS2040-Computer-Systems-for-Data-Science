# Graded Lab - 1 (lab_3)

5 questions... 2 marks each...

## Q1

Parity is 0 if a binary number has even number of 1s and 1 if it has odd number of 1s. Write a program to compute the parity of an unsigned32-bit integer using only **bitwise operations**.
- Use XOR operation to combine bits progressively
- Start with the least significant bit and propagate through to the most significant bit.

**Deliverables:**
- Write a program that computes the parity of values like 0x80000000, 0xFFFFFFFF, 0x00000001.
- Print the binary representation of each number and its parity.


## Q2
Use bitwise operations and the IEEE 754 standard to extract the **sign**,**exponent** and **mantissa** from a `float` variable.
1. Accept the `float` from the user.
2. Interpret the `float` as an unsigned integer (`uint_32`) via pointer casting.
3. Extract and print:
    - The **sign bit** (1 for negative, 0 for positive).
    - The **exponent** as a decimal number.
    - The **mantissa** in hexadecimal
  

## Q3

In certain systems, integer overflow doesnot wrap around; it **saturates** at `INT_MAX` or `INT_MIN`. Implement a function that:
- Performs addition of two signed 32-bit integers, returning `INT_MAX` if overflow occurs.
- Performs subtraction of two signed 32-bit integers, returning `INT_MIN` if underflow occurs.

**Example:**
1. `int saturating_add(int a, int b);`
2. `int saturating_sub(int a, int b);`
    - Test your functions with examples such as:
       - `saturating_add(INT_MAX, 1)`
       - `saturating_sub(INT_MIN, 1)`
       - A normal case like `saturating_add(10, 20)`


## Q4

Write two functions for a 32-bit unsigned integer:
1. `count_leading_zeros(uint32_t x)`
2. `count_tailing_zeros(uint32_t x)`

Return the number of bits befor the first 1-bit and after the last 1-bit, respectively.

**Example:**
- Input 0x000000F0
   - Leading zeros: 20
   - Tailing zeros: 8
- Provide your code and results for:
   - 0x00000001
   - 0x80000000
   - 0x000000F0
- Briefly explain the algorithm used (e.g., a loop, binary search, or built-in functions).


## Q5
Write a program to compare two `float` numbers without using the standard operators, ==, <, or >. Instead:
- Reinterpret the bit patterns as `uint32_t`.
- For **positive** floats, a larger bit pattern indicates a larger number.
- For **negative** floats, a smaller bit pattern indicates a larger number(due to sign).
  
**Deliverables:**
- Implement:
    ```c
    int compare_floats(float a, float b);
    // returns -1 if a<b, 1 if a>b and 0 if equal
    ```
- Test it with:
  - 0.5 and 1.0
  - -1.0 and 1.0
  - Special cases like `NaN` and `Inf`.