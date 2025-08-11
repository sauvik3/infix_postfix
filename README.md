# C++ Calculator Project (CMake + GoogleTest + OpenCppCoverage)

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
| Operator | Description                                | Example                  |
|----------|--------------------------------------------|--------------------------|
| `+`      | Addition                                   | `3 + 4` = `7`            |
| `-`      | Subtraction                                | `5 - 2` = `3`            |
| `*`      | Multiplication                             | `2 * 3` = `6`            |
| `/`      | Division                                   | `10 / 2` = `5`           |
| `inv(x)` | Multiplicative inverse (1 / x)             | `inv(4)` = `0.25`        |
| `-` (unary) | Negation (change sign)                  | `-5` = `-5`              |


---

### 3. Operator Precedence and Associativity
| Precedence | Operator(s)        | Associativity | Notes                                   |
|------------|--------------------|--------------|-----------------------------------------|
| 1 (highest)| `()`               | Left-to-right| Parentheses override precedence         |
| 2          | `inv`              | Right-to-left| Unary function for multiplicative inverse|
| 3          | `-` (unary)        | Right-to-left| Negates a single operand                |
| 4          | `*`, `/`           | Left-to-right| Multiplication and division             |
| 5 (lowest) | `+`, `-` (binary)  | Left-to-right| Addition and subtraction                |


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
build\\coverage.xml
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
