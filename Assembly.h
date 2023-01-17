
// Set of functions to emit MIPS code
FILE *MIPScode;

int nextRegister = -1;

void initAssemblyFile()
{
    // Creates a MIPS file with a generic header that needs to be in every file

    MIPScode = fopen("MIPScode.asm", "w+");
    fprintf(MIPScode, ".data\n");

    // fprintf(MIPScode, ".text\n");
    // fprintf(MIPScode, "main:\n");
}

void emitMIPSFunction(char func[100])
{
    fprintf(MIPScode, "\n%s:\n", func);
}

void emitMIPSCallFunction(char func[100]){

    fprintf(MIPScode,"jal %s\n",func);
    //jump and link, which it is used to call a function in MIPS assembly language
}

void emitMIPSEndFunction(){
    fprintf(MIPScode,"jr $ra\n");
    //jump register, which in this case, jump to $ra
}
void emitMIPSArray(char array[100], int position_space)
{
    fseek(MIPScode, 5, SEEK_SET);
    // rewind(MIPScode);
    //  mips needs sized 4 for each spaced in element
    int initialized_space = position_space * 4;
    // fputs("la inside main --- ", MIPScode);
    // fseek(MIPScode, 1, SEEK_SET);
    // fputs("la inside data --- ", MIPScode);
    // fseek(MIPScode, 1, SEEK_END);
    fprintf(MIPScode, "\n%s: .space %d\n", array, initialized_space);
    fprintf(MIPScode, ".text \n");
    fprintf(MIPScode, "main:\n");
    fprintf(MIPScode, "la $t0,%s\n", array);

    // fprintf(MIPScode, "la $t0, %s\n\n", array);
}


void emitMIPSIntegerAssignmentArray(int position_space, int value)
{

    int initialized_space = position_space * 4;
    fprintf(MIPScode, "la $t1, %d\n", value);
    fprintf(MIPScode, "sw $t1, %d($t0)\n", initialized_space);
}

void emitMIPSAssignment(char *id1, char *id2)
{
    // This is the temporary approach, until register management is implemented

    // open file
    // the return found() of > id1 assign to a variable
    // *get value function with char  add to symbol table
    // orint everthing as normal below

    // int wasAdded = found(atoi(id1),0);
    fprintf(MIPScode, "li $t1,%s\n", id1);
    fprintf(MIPScode, "li $t2,%s\n", id2);
    fprintf(MIPScode, "li $t2,$t1\n");
}

int allocateRegister()
{
    // this should match the item table for now

    nextRegister += 1;
    return nextRegister;
}

void emitMIPSConstantIntAssignment(char id1[50], char id2[50])
{
    // This is the temporary approach, until register management is implemented
    // The parameters of this function should inform about registers
    // For now, this is "improvised" to illustrate the idea of what needs to
    // be emitted in MIPS

    int allocate = allocateRegister();

    // This is conceptual to inform what needs to be done later
    fprintf(MIPScode, "li $t%i,%s\n", id1, id2);
}

void emitMIPSWriteId(char *id)
{
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS

    fprintf(MIPScode, "li $v0,1\n");
    fprintf(MIPScode, "move $a0, $t%s\n", id);
    
}

void emitMIPSWriteArray(char name[100], int position_space)
{
    int initialized_space = position_space * 4;

    fprintf(MIPScode, "\nli $v0,1\n");
    fprintf(MIPScode, "lw $a0, %d($t0)\n", initialized_space);
    fprintf(MIPScode, "syscall   # system call\n");
    fprintf(MIPScode, "li $v0,10  # system call\n\n");

}

void emitEndOfAssemblyCode()
{
    // fprintf(MIPScode, "# -----------------\n");
    // fprintf(MIPScode, "#  Done, terminate program.\n\n");
    // fprintf(MIPScode, "li $v0,1   # call code for terminate\n");
    // fprintf(MIPScode, "syscall      # system call (terminate)\n");
    //Tell the progam is done
    // fprintf(MIPScode, "li $v0,10   # call code for terminate\n");
    // fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fclose(MIPScode);
}
