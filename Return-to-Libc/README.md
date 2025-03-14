# Return-to-libc demonstration

## Steps to run
0. Remove ASLR with sudo sysctl -w kernel.randome_va_space=0
1. Make stackLibc owned by root and suid bit set
2. Set environment variable: export MYSHELL="/bin/sh"
3. Get the address of "/bin/sh" from envaddr01 program
4. Set sh_addr value to that value in exploit.py
5. Set exit_addr to address of exit() using gdb
6. Set system_addr to address of system() using gdb
7. Temporarily run: sudo ln -sf /bin/zsh /bin/sh (Don't forget to fix back with sudo ln -sf /bin/dash /bin/sh)
8. Run ./stackLibc