# The Monty Project

* Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

#This is how the project was compiled

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

