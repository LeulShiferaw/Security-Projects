# Code for demonstrating ROP chains

## Succefully tested on Ubuntu 20.04

## Steps:
1. First we have to make sure that aslr is disabled: sudo sysctl -w kernel.randomize_va_space=0
2. We need to make ./stack_rop owned by root and set uid 
    1. sudo chown root ./stack_rop
    2. sudo chmod 4755 ./stack_rop
3. We need to insert "/bin/sh" as a MYSHELL envrionment variable
    1. export MYSHELL="/bin/sh"
    2. We can get the offset of "/bin/sh" by running ./stack_rop_dbg.
    3. If the Shell variable exists it will show us the address of "/bin/sh"
4. We can also get the address of ebp for foo using ./stack_rop_dbg
5. The rest of libc's functions we get using gdb
    1. gdb ./stack_rop_dbg
    2. b foo
    3. run
    4. "p C_FUNCTION" like "p system"
    5. We will disass foo to get the address of leaveret at the end of the function
6. With all of these value we can put them into exploit_shell.py and it will chain them and give us root shell!