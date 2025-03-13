        .section .data
msg:
        .asciz "Hello, World!\n"
        .section .text
        .global _start

_start:
        # sys_write syscall
        movq $1, %rax      # 1 = sys_write for linux
        movq $1, %rdi       # 1 = file descriptor for stdout
        lea msg(%rip), %rsi # address of msg
        movq $14, %rdx      # 13 = length of msg (excluding null terminator) so we pass 14
        syscall             # call kernel
        # syscall is used for 64 bit linux machines(?)
        # we can use int 0x80 for 32 bit linux machines

        # sys_exit syscall
        movq $60, %rax      # 60 = sys_exit for linux
        xorq %rdi, %rdi     # 0 = exit status
        syscall             # call kernel

