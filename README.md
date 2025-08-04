# C++ Template Project (CMake + GoogleTest + OpenCppCoverage)

This project demonstrates a basic C++ project setup using CMake, with:
- A library (add) containing a simple `add()` function
- A main executable using the library
- Unit tests using GoogleTest
- Code coverage generation with OpenCppCoverage (MSVC toolchain)

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
.\\build\\main\\Debug\\main.exe
```

---
## Run Tests (GoogleTest)
Run all tests:
```
ctest --test-dir build -C Debug --output-on-failure
```

Run a specific test:
```
ctest --test-dir build -C Debug -R AddTest.PositiveNumbers
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
