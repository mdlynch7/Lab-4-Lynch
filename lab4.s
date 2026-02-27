.section .text
.global sum_array

sum_array:
    movl $0, %eax # running total
    movl $0, %ecx #i for the for loop

sum_loop:
    cmpl %esi, %ecx # compares i with counter (esi)
    jge loop_end

    # if not greater than or equal to
    addl (%rdi, %rcx, 4), %eax

    incl %ecx # increases i by one
    jmp sum_loop # jumps to beginning of loop

loop_end:
    ret # returns to the C code

.section .note.GNU-stack,"",@progbits
