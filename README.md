# Arbitrary Precision Calculator
A modular arbitrary-precision calculator written in C. The implementation is organized into separate source files for arithmetic operations, shared functions, and the command-line entry point.
## Features
- Arbitrary-precision arithmetic design
- Addition and division modules
- Shared declarations in `apc.h`
- Command-line interaction through `main.c`
- Modular C implementation
## Repository structure
| File | Purpose |
| --- | --- |
| `main.c` | Program entry point and command-line interaction |
| `apc.h` | Shared declarations and project definitions |
| `addition.c` | Addition implementation |
| `division.c` | Division implementation |
| `function.c` | Shared calculator functions |
## Build
The repository includes a Makefile. Use the project Makefile to build the calculator in your local C development environment:
```bash
make
```
Run the generated executable according to the command-line interface implemented in `main.c`.
## Code organization
The project separates arithmetic operations from the program entry point, making the implementation easier to extend and review. The header file provides a shared interface between the modules.
## Engineering focus
This project demonstrates:
- C programming and modular compilation
- Header/source separation
- Arithmetic algorithm implementation
- Command-line program structure
- Make-based build organization
## Repository hygiene improvements
The repository currently includes compiled artifacts such as `a.out` and `.o` files. These should ideally be removed from version control and excluded through a C-oriented `.gitignore`; builds should be reproduced locally with `make`.
## Future improvements
- Add usage examples and sample input/output
- Document the numeric representation and supported limits
- Add tests for carry, division edge cases, and large operands
- Add compiler warnings and automated build checks through GitHub Actions
## Author
**Nirmal Mohan**  
[GitHub profile](https://github.com/Nirmalnrm) · [LinkedIn](https://www.linkedin.com/in/nirmal-mohan-5426b431a)
