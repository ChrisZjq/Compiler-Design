.data
    myArray: .space 12              #12 bytes for 3 integers

    Ryan:       .asciiz "Ryan\n"
    Edward:     .asciiz "Edward\n"
    Talbert:    .asciiz "Talbert\n"
    Bobby:      .asciiz "Bobby\n"

    names:      .word    Ryan Edward Talbert Bobby

    iterator:   .word   0
    size:       .word   3



.text
main:

    la $t0,names
    lw $t1, iterator
    lw $t2, size

begin_loop:
    bgt $t1, $t2, exit_loop     #loop if T1 > T2
    
        sll $t3, $t1, 2     #T3 = 4*iterator
        addu $t3,$t3,$t0    #4i = 4i + memory location of the name array ---> 1000 + 4 = 1004

        li $v0,4
        lw $a0, 0($t3)
        syscall
        
        addi $t1, $t1, 1

        j begin_loop
    exit_loop:



        

        