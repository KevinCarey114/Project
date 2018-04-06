#include <stdio.h>
#include <stdlib.h>


#define SHELLSCRIPT "\
#/bin/bash \n\
echo \"hello\" \n\
echo \"how are you\" \n\
echo \"today\" \n\
"

int main()
{
    system(SHELLSCRIPT);    //it will run the script inside the c code. 
    return 0;
}
