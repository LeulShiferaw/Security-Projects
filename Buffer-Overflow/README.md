## Code for demonstrating Stack-Based buffer overflow

# This code was tested on Ubuntu 20.04

# Steps to run
1. Make sure that stackOverFlow and its debug version are owned by root and have suid bit set
2. Get $ebp of foo by using gdb
3. Modify the exploit.py ret hex value to your ebp
4. Disable kernel randomize with this command: sudo sysctl -w kernel.randomize_va_space=0
5. Make sure that the ret value doesn't have a 0 as one of its bytes in the final calculation