.data
    mark: .space 12              #12 bytes for 3 integers
.text
main:

la	$t0, mark
la  $t1,6
sw  $t1, 4($t0)

la	$t1, 5		
sw	$t1, 8($t0)		

li  $v0, 1 
lw  $a0, 4($t0)
jal fun	
syscall
li $v0,10

fun:
li $t6,10
jr $ra
        
    

        