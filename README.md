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
* swap
* pop
* nop
* add
* pint
* pall
* push
### More to come

