.section .text
.global _start

_start:
    movq $0, %rax           # Clear rax
    movq $5, %rbx           # rbx = 5
    cmpq $0, %rbx           # Compare rbx with 0
    je equal_label          # Jump if rbx == 0
    jg greater_label        # Jump if rbx > 0 (signed)

less_label:
    # If rbx < 0
    movq $1, %rax
    jmp end_label

equal_label:
    # If rbx == 0
    movq $2, %rax
    jmp end_label

greater_label:
    # If rbx > 0
    movq $3, %rax

end_label:
    # Exit
    movq %rax, %rdi          # Exit status in rdi
    movq $60, %rax           # Syscall number for exit
    syscall                  # Trigger syscall
