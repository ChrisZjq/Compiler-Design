.data
mark: .space 12
.text 
main:
la $t0,mark
la $t1, 7
sw $t1, 4($t0)
la $t1, 5
sw $t1, 8($t0)

li $v0,1
lw $a0, 4($t0)
syscall   # system call
li $v0,10  # system call


fun:
li $t6,10
jr $ra
