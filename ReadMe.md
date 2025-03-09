
# Plot Drawing Tool

![License](https://img.shields.io/badge/license-MIT-blue.svg)  
![C Language](https://img.shields.io/badge/language-C-blue)  
![GCC Compiler](https://img.shields.io/badge/compiler-GCC-green)  

The **Plot Drawing Tool** is a command-line application written in C that allows users to plot mathematical functions in a terminal-based grid. It supports a variety of mathematical operations, including trigonometric functions, logarithms, and basic arithmetic. The tool evaluates expressions provided by the user and generates a graphical representation of the function within a specified range.

---

## Features

- **Mathematical Expression Evaluation**: Supports arithmetic operations (`+`, `-`, `*`, `/`), trigonometric functions (`sin`, `cos`, `tan`, `ctg`), logarithms (`ln`), and square roots (`sqrt`).
- **Terminal-Based Plotting**: Renders the graph in a terminal using ASCII characters.
- **Customizable Range**: Allows users to define the range for the x-axis (`X_MIN` to `X_MAX`) and y-axis (`Y_MIN` to `Y_MAX`).
- **Error Handling**: Detects invalid expressions, such as division by zero or unbalanced parentheses.
- **Stack-Based Evaluation**: Uses a stack data structure to evaluate expressions in Reverse Polish Notation (RPN).

---

## Installation

To build and run the Plot Drawing Tool, follow these steps:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/dmitrii-gbe/PlotDrawingTool.git
   cd PlotDrawingTool
   ```

2. **Compile the Code**:
   Ensure you have `gcc` installed. Then, compile the project using the provided Makefile:
   ```bash
   make all
   ```

3. **Run the Application**:
   After compilation, the executable will be located in the `build` directory. Run it with:
   ```bash
   ./build/graph
   ```

---

## Usage

1. **Enter a Mathematical Expression**:
   When prompted, enter a mathematical expression using the variable `x`. For example:
   ```
   sin(x) + cos(x)
   ```

2. **View the Plot**:
   The tool will evaluate the expression and render the graph in the terminal using ASCII characters. The x-axis ranges from `0` to `4π`, and the y-axis ranges from `-1` to `1`.

3. **Supported Operations**:
   - Arithmetic: `+`, `-`, `*`, `/`
   - Trigonometric: `sin(x)`, `cos(x)`, `tan(x)`, `ctg(x)`
   - Logarithms: `ln(x)`
   - Squar

## Algorithms and Data Structures

### 1. **Stack Data Structure**
The stack is a fundamental data structure used throughout the application for expression evaluation and parsing. It follows the **Last-In-First-Out (LIFO)** principle.

#### Implementation:
- Two stacks are implemented:
  - **`c_Stack`**: A stack of characters (`char`) used for parsing and converting infix expressions to postfix notation (Reverse Polish Notation).
  - **`Stack`**: A stack of doubles (`double`) used for evaluating postfix expressions.

#### Key Operations:
- **`push`**: Adds an element to the top of the stack.
- **`pop`**: Removes the top element from the stack.
- **`top`**: Returns the top element without removing it.
- **`empty`**: Checks if the stack is empty.
- **`destroy`**: Frees the memory allocated for the stack.

#### Usage:
- The stack is used in:
  - **Expression Parsing**: To convert infix expressions (e.g., `sin(x) + cos(x)`) to postfix notation (e.g., `x sin x cos +`).
  - **Expression Evaluation**: To evaluate postfix expressions by pushing and popping operands and operators.

---

### 2. **Shunting Yard Algorithm**
The **Shunting Yard Algorithm** is used to convert infix mathematical expressions (e.g., `3 + 4 * 2`) into postfix notation (e.g., `3 4 2 * +`). This algorithm is implemented in the `GetPostfixNotation` function.

#### Steps:
1. Initialize a stack for operators and a queue (or output list) for the postfix expression.
2. Iterate through the input expression:
   - If the token is a number or variable (`x`), add it to the output.
   - If the token is an operator or function (e.g., `+`, `sin`), push it onto the stack while respecting operator precedence and associativity.
   - If the token is an opening parenthesis `(`, push it onto the stack.
   - If the token is a closing parenthesis `)`, pop from the stack to the output until an opening parenthesis is encountered.
3. Pop any remaining operators from the stack to the output.

#### Usage:
- This algorithm is used in the `expression_processing.c` file to process user input and generate postfix notation for evaluation.

---

### 3. **Postfix Expression Evaluation**
Postfix notation (also known as Reverse Polish Notation) is evaluated using a stack-based approach. This is implemented in the `SolveExpression` function.

#### Steps:
1. Initialize a stack for operands.
2. Iterate through the postfix expression:
   - If the token is a number or variable (`x`), push it onto the stack.
   - If the token is an operator (e.g., `+`, `*`), pop the top two operands from the stack, apply the operator, and push the result back onto the stack.
   - If the token is a unary function (e.g., `sin`, `sqrt`), pop the top operand, apply the function, and push the result back onto the stack.
3. The final result is the only value remaining on the stack.

#### Usage:
- This algorithm is used in the `evaluation.c` file to evaluate postfix expressions and compute the value of the function at a given `x`.

---

### 4. **Graph Plotting Algorithm**
The graph plotting algorithm is implemented in the `draw.c` file. It generates a 2D grid of characters (`HEIGHT` x `WIDTH`) and plots points corresponding to the evaluated function.

#### Steps:
1. Initialize a 2D grid (`char grid[HEIGHT][WIDTH]`) with dots (`.`) as placeholders.
2. Define the range for the x-axis (`X_MIN` to `X_MAX`) and y-axis (`Y_MIN` to `Y_MAX`).
3. For each x-value in the range:
   - Compute the corresponding y-value using the evaluated function.
   - Map the (x, y) coordinates to the grid indices.
   - Plot the point on the grid using an asterisk (`*`).
4. Print the grid row by row to display the graph in the terminal.

#### Usage:
- This algorithm is used in the `draw_graph` function to render the graph of the user-provided function.

---

### 5. **Expression Processing**
The input expression is processed to remove whitespace, shorten function names (e.g., `sin` → `s`), and validate the expression. This is implemented in the `expression_processing.c` file.

#### Key Functions:
- **`RemoveWhiteSpaces`**: Removes all whitespace characters from the input string.
- **`ShortenOperations`**: Replaces function names (e.g., `sin`, `cos`) with single-character representations (e.g., `s`, `c`).
- **`InValidExpression`**: Checks for invalid expressions, such as division by zero or invalid function calls.

#### Usage:
- These functions are used to preprocess the input expression before parsing and evaluation.

---

### 6. **Error Handling**
The application includes basic error handling to detect and report invalid expressions. For example:
- Unbalanced parentheses.
- Division by zero.
- Invalid function calls (e.g., `ln(0)`).

#### Implementation:
- Errors are detected during expression parsing and evaluation, and the program terminates with an appropriate error message.

---

## Summary of Algorithms and Data Structures

| **Component**               | **Algorithm/Data Structure**       | **Purpose**                                                                 |
|-----------------------------|------------------------------------|-----------------------------------------------------------------------------|
| Stack                       | LIFO Stack                        | Used for parsing and evaluating expressions.                                |
| Shunting Yard Algorithm     | Infix to Postfix Conversion       | Converts user input into postfix notation for evaluation.                  |
| Postfix Evaluation          | Stack-Based Evaluation            | Evaluates postfix expressions to compute function values.                   |
| Graph Plotting              | 2D Grid Mapping                   | Renders the graph of the function in the terminal.                         |
| Expression Processing       | String Manipulation               | Preprocesses and validates user input.                                     |
| Error Handling              | Conditional Checks                | Detects and reports invalid expressions.                                   |

---

## Example Workflow

1. **Input**: The user provides an expression, e.g., `sin(x) + cos(x)`.
2. **Processing**:
   - Whitespace is removed.
   - Function names are shortened (e.g., `sin` → `s`).
   - The expression is converted to postfix notation (e.g., `x s x c +`).
3. **Evaluation**:
   - The postfix expression is evaluated for each x-value in the range.
4. **Plotting**:
   - The computed (x, y) points are mapped to a 2D grid and displayed in the terminal.



4. **Example Input**:
   ```
   sin(x) * cos(x)
   ```

---

## Code Structure

The project is organized into several source files:

- **`draw.c`**: Handles the plotting of the graph in the terminal.
- **`evaluation.c`**: Evaluates mathematical expressions using a stack-based approach.
- **`expression_processing.c`**: Processes the input expression, converts it to Reverse Polish Notation (RPN), and validates it.
- **`stack.c`**: Implements the stack data structure used for expression evaluation.
- **`graph.c`**: Contains the `main` function and drives the application.

---

## Example Output

Here’s an example of what the output might look like for the expression `sin(x) * cos(x)`:
```
................................................................................
................................................................................
................................................................................
................................................................................
................................................................................
................................................................................
..............***.................***.................***.................***...
.............*...*...............*...*...............*...*...............*...*..
............*.....*.............*.....*.............*.....*.............*.....*.
................................................................................
...........*.......*...........*.......*...........*.......*...........*.......*
................................................................................
*.........*.........*.........*.........*.........*.........*.........*.........
................................................................................
.*.......*...........*.......*...........*.......*...........*.......*..........
................................................................................
..*.....*.............*.....*.............*.....*.............*.....*...........
...*...*...............*...*...............*...*...............*...*............
....***.................***.................***.................***.............
................................................................................
................................................................................
................................................................................
................................................................................
................................................................................
................................................................................

```
---

## Contributing

Contributions are welcome! If you'd like to contribute to the Plot Drawing Tool, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Commit your changes and push to your fork.
4. Submit a pull request with a detailed description of your changes.

---

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more details.

---

## Acknowledgments

- Special thanks to the contributors (annabelm and motherje) who helped make this project possible.
- Built with ❤️ by [Dmitrii Gbe](https://github.com/dmitrii-gbe).

---

## Contact

For questions, suggestions, or issues, please open an issue on GitHub or contact the maintainer directly.

**Maintainer**: Dmitrii Gbe  
**GitHub**: [dmitrii-gbe](https://github.com/dmitrii-gbe)  

---

Happy Plotting! 📊

---

