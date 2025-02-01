.section .text
.global _start

_start:
    movq $10, %rax           # rax = 10
    addq $5, %rax            # rax = rax + 5 => 15
    movq $4, %rbx            # rbx = 4
    imulq %rbx, %rax         # rax = rax * rbx => 15 * 4 = 60

    # Division: rax / rbx => quotient in rax, remainder in rdx
    movq $60, %rax           # Set syscall number for exit
    xorq %rdx, %rdx          # Clear rdx before signed division
    movq $4, %rbx            # rbx = 4
    idivq %rbx               # idivq divides rax by rbx. rax = quotient, rdx = remainder

    # Exit
    movq $60, %rax           # syscall number for exit
    xorq %rdi, %rdi          # exit status = 0
    syscall                  # make the syscall
