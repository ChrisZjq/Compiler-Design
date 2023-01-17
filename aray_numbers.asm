.data

x:          .word 1,2,3,4,5,6,7,8,9,10
iterator:   .word 0
size:       .word 9

promopt:    .asciiz "Total sum of array:"

.text
main:

la		$s0, promopt		# 

la		$t0, x		# 
lw		$t1, iterator		# 
lw		$t2, size		# 

begin_loop:
bgt $t1, $t3, exit_loop   
sll $t3, $t1, 2     

addu $t3,$t3, $t0

lw $t6, 0($t3)

addu $s7, $s7, $t6

addi $t1,$t1,1

j		begin_loop				# jump to begin_loop


exit_loop:

li $v0, 4
la $a0,promopt

li $v0, 1


        