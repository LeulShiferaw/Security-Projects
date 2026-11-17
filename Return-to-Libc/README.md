# Return-to-libc demonstration

## Steps to run
0. Remove ASLR (temporarily) with sudo sysctl -w kernel.randome_va_space=0
1. Make stackLibc owned by root (sudo chown root ./stackLibc) and suid bit set (sudo chmod 4755 ./stackLibc_dbg)
2. Set environment variable: export MYSHELL="/bin/sh"
3. Get the address of "/bin/sh" from envaddr01 program (just execute it after the previous step)
4. Set sh_addr value to that value in exploit.py
5. Set exit_addr to address of exit() using gdb
    1. "gdb ./stackLibc_dbg"
    2. "b foo"
    3. "run"
    4. "p exit"
6. Set system_addr to address of system() using gdb as shown for exit above
7. Temporarily run: sudo ln -sf /bin/zsh /bin/sh (Don't forget to fix back with sudo ln -sf /bin/dash /bin/sh)
8. Run ./stackLibc