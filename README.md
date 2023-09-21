# The Monty Project

* Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files
* Files containing Monty byte codes usually have the ```.m ``` extension.There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```bash
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```

## This is how the project was compiled

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
## Opcodes handled
* push: Add element to stack
* pop: Remove element from stack
* nop: Do nothing in the stack
* add: Add first two element of the stack, push the result to top
* pint: Print top elemets of the stack
* pall: Print all elements of the stack
* swap: Swap first two elements of the stack
* sub: Subtract the first two element of stack, push the result to the top
* div: Divide first two element of the stack, push the result to top
* mul: Multiply first two element of the stack, push the result to top
* pchar: Print character at the top of stack
* pstr: prints the string starting at the top of the stack
* rotl: Rotates the stack to the top
* rotr: Rotates the stack to the bottom
### More to come

> [!WARNING]
> Use this monty program without guarantee!
