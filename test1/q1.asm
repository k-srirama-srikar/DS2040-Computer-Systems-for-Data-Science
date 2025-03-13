    .section .text
    .global main

main:
    # prologue
    pushq %rbp
    movq %rsp, %rbp

    # 1) Reserve space for one local pointer (8 bytes): [rbp-8]
    subq $8, %rsp

    # 2) Save 'n' (the desired array size) in the %edi
    movl $5, %edi

    # 3) Call the function 'allocate_array' with the desired size
    call allocate_array

    # 4) Save the return value (the pointer to the allocated array) into local var at -8(%rbp)
    move %rax, -8(%rbp)

    # 5) Now we call fill_array with the pointer to the allocated array and fill value 10
    #    we place the pointer in %rdi, length in %esi and fill value in %edx
    movq -8(%rbp), %rdi
    movl $5, %esi
    movl $10, %edx
    call fill_array

    # 6) now we want to read the 3rd element from the array into %eax
    #    the local pointer is at -8(%rbp)
    #   each element is 4 bytes (int). Index 2 => offset 8 bytes
    #   fill in the correct instructions here
    
    ########################################
    movq -8(%rbp), %rsi        # Load the array pointer into %rsi
    movl $2, %ecx              # Load the index (2) into %ecx
    movl (%rsi, %ecx, 4), %eax  # Load the 3rd element (index 2) into %eax
    ########################################

    # 7) clean up and return 
    leave 
    ret


allocate_array:
    pushq %rbp
    movq %rsp, %rbp

    # arg n in %edi
    # we need n*4 bytes

    leal 0(, %edi, 4), %esi
    movl %esi, %edi 
    call malloc@PLT 

    popq %rbp
    ret


# fill_array(ptr, length, fill_value)
#   ptr in %rdi, length in %esi, fill_value in %edx


fill_array:
    pushq %rbp
    movq %rsp, %rbp

    # 1) Save the fill value in %eax
    movl %edx, %eax

    # 2) Save the pointer to the array in %ecx
    movq %rdi, %rcx

    # 3) Save the length in %edx
    movl %esi, %edx

    # 4) Loop over the array and fill each element with the fill value
    #    we use the following registers:
    #    %ecx: pointer to the current element
    #    %edx: remaining length
    #    %eax: fill value
    #    fill in the correct instructions here

    ########################################
    fill_loop:
        movl %eax, (%rcx)  # Store the fill value in the current element
        addq $4, %rcx      # Move the pointer to the next element
        subq $1, %edx      # Decrement the length
        jnz fill_loop      # Jump back to fill_loop if length is not zero
    ########################################

    # 5) clean up and return
    leave
    ret