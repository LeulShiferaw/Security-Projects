# Code for demonstrating Stack-Based buffer overflow

## This code was tested on Ubuntu 20.04

## Prerequistes 
1. Make sure that stackOverFlow owned by root (sudo chown root ./stackOverFlow) and have suid bit set (sudo chmod 4755 ./stackOverflow)
2. Get $ebp of foo by using gdb
    1. run "gdb ./stackOverflow_dbg"
    2. "b foo" - break on foo
    3. "n" - next instruction (so that we have already gone through function prologue)
    4. "p $ebp"
3. Modify the exploit.py's ret hex value to your ebp value
4. Disable kernel randomize with this command (temporarily resets after restart): sudo sysctl -w kernel.randomize_va_space=0

## Steps to run
1. Run "python3 exploit.py"
2. run ./stackOverFlow
    1. You should get a root shell. Congratulations you have escalated your privileges to root!!