# C++ Calculator Project (CMake + GoogleTest + OpenCppCoverage)

[![Build status](https://ci.appveyor.com/api/projects/status/wm4wo8p7im7frq61/branch/main?svg=true)](https://ci.appveyor.com/project/sauvik3/infix-postfix/branch/main)
[![codecov](https://codecov.io/github/sauvik3/infix_postfix/graph/badge.svg?token=MBZSWKKJUQ)](https://codecov.io/github/sauvik3/infix_postfix)

## Project Overview

This project demonstrates a well-structured **C++** application built with **CMake**, showcasing the following components:

- **Library (`calc`)** : Implements the core calculator functionality, including parsing, operator handling, and evaluation.
- **Main Executable** : Provides a user-facing interface that links against the `calc` library.
- **Unit Tests with GoogleTest** : Ensures correctness of operations, edge case handling, and mathematical precision.
- **Code Coverage Analysis** : Integrated with **OpenCppCoverage** (for the MSVC toolchain) to measure and report test coverage of the codebase.

The goal is to serve as both a working calculator application and a reference for:
1. Modular C++ library design.
2. CMake-based build configuration for multiple targets.
3. Writing and running GoogleTest-based unit tests.
4. Measuring and improving code coverage in a Windows/MSVC environment.


---

## Calculator Specifications

### 1. Operand Types
| Type                       | Example(s)              | Notes                               |
| -------------------------- | ----------------------- | ----------------------------------- |
| Integer                | `42`, `-7`                  | Leading zeros allowed (e.g., `005`) |
| Floating-Point         | `3.14`, `-0.25`, `.5`, `3.` | Decimal point optional for integers |
| Unary Function Operand | `inv(x)`                    | `inv` denotes reciprocal (`1/x`)    |
| Signed Literals        | `+5`, `-0.2`                | Sign is part of the literal         |


---

### 2. Supported Operations
| Operator     | Description                                        | Example                     |
|--------------|----------------------------------------------------|-----------------------------|
| `+`          | Addition                                           | `3 + 4` = `7`               |
| `-`          | Subtraction                                        | `5 - 2` = `3`               |
| `*`          | Multiplication                                     | `2 * 3` = `6`               |
| `/`          | Division                                           | `10 / 2` = `5`              |
| `^`          | Power (exponentiation)                             | `2 ^ 3` = `8`               |
| `sqrt(x)`    | Square root                                        | `sqrt(9)` = `3`             |
| `inv(x)`     | Multiplicative inverse (1 / x)                     | `inv(4)` = `0.25`           |
| `-` (unary)  | Negation (change sign)                             | `-5` = `-5`                 |
| `abs(x)`     | Absolute value                                     | `abs(-5)` = `5`             |
| `sin(x)`     | Sine (x in radians)                                | `sin(1.5707)` = `1`         |
| `cos(x)`     | Cosine (x in radians)                              | `cos(0)` = `1`              |
| `tan(x)`     | Tangent (x in radians)                             | `tan(0.7853)` = `1`         |
| `log(x)`     | Base-10 logarithm                                  | `log(100)` = `2`            |
| `ln(x)`      | Natural logarithm (base e)                         | `ln(2.7183)` = `1`          |
| `(`, `)`     | Parentheses (grouping to control precedence)       | `(2 + 3) * 4` = `20`        |


---

### 3. Operator Precedence and Associativity
| Precedence | Operator(s)                                     | Associativity   | Notes                                                            |
|------------|-------------------------------------------------|-----------------|------------------------------------------------------------------|
| 0 (highest)| `()`, `(`, `)`                                  | Left-to-right   | Parentheses override precedence                                  |
| 1          | `-` (unary), `^`, `sqrt`, `inv`, `abs`, `sin`, `cos`, `tan`, `log`, `ln` | Right-to-left | Unary negation, exponentiation, functions                        |
| 2          | `*`, `/`                                        | Left-to-right   | Multiplication and division                                      |
| 3 (lowest) | `+`, `-` (binary)                               | Left-to-right   | Addition and subtraction                                         |


---
## Prerequisites
- **CMake (>= 3.20)**
- **MSVC (Visual Studio 2022 Build Tools)**
- **GoogleTest** (auto-fetched by CMake)
- **OpenCppCoverage** ([download here](https://github.com/OpenCppCoverage/OpenCppCoverage/releases))

Verify installation:
```
cmake --version
OpenCppCoverage --version
```


---
## Build Instructions
Configure and build (Debug mode):
```
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Debug
```

Run the executable:
```
.\build\main\Debug\main.exe
```


---
## Run Tests (GoogleTest)
Run all tests:
```
ctest --test-dir build -C Debug --output-on-failure
```

Run a specific test:
```
ctest --test-dir build -C Debug -R CalcTest.PositiveNumbers
```


---
## Generate Code Coverage (OpenCppCoverage)
Generate Cobertura XML coverage report:
```
cmake --build build --target coverage --config Debug
```

Output:
```
build\coverage.xml
```

Test sources, main sources, and Visual Studio system files are excluded.


---
## One Command: Build + Test + Coverage
```
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Debug --target coverage
```


---
## Notes
- Temporary files (like `Testing/`) are generated inside the `build` folder.
- `LastCoverageResults.log` is automatically overwritten for each run.
- Ensure **Debug** builds are used to retain PDB symbols required by OpenCppCoverage.


---
## Troubleshooting
- If `cmake` or `OpenCppCoverage` is not recognized, add them to your system **PATH**.
- Use **PowerShell** or **Developer Command Prompt for VS** to ensure MSVC environment variables are set.
