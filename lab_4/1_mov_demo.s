        .section .data
msg :
        .asciz " Data movement demo \ n "
        .section .text
.global _start
_start :
        # Move immediate values into registers
        movq $10 , % rax # % rax = 10
        movq $20 , % rbx # % rbx = 20
        # Move between registers
        movq % rax , % rcx # % rcx = 10
        # Move data from memory to register
        lea msg (% rip ) , % rdx # % rdx = address of msg
        # Exit syscall
        movq $60 , % rax # 60 = exit syscall
        xorq % rdi , % rdi # % rdi = 0 ( exit status )
        syscall

