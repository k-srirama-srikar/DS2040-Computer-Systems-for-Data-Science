.text
.global asm_func

asm_func:
    # Parameters:
    # a -> %rdi
    # b -> %rsi
    # Return value in %rax

    movq %rdi, %rax        # Copy the value of a (in %rdi) to %rax (return register)
    addq %rsi, %rax        # Add b (in %rsi) to the value in %rax (a + b)
    ret                    # Return to the caller, result is now in %rax
