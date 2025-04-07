#include <stdio.h>
#include <stdarg.h>

void test(int count, ...){
    va_list args;
    // typedef char* va_list;
    // char* arg;
    // args = "int count, 1, 2, 6"
    
    va_start(args, count); //arg = "1 , 2, 6" /arga = { \001, \002, \006}
    
    printf("value 1: %d\n", va_arg(args, int)); //(int)"\001" = 1
    printf("value 2: %d\n", va_arg(args, int)); //(int)"\002" = 2
    printf("value 3: %d\n", va_arg(args, int)); //(int)"\001" = 1
    printf("value 4: %f\n", va_arg(args, double)); //(int)"\001" = 1
    printf("value 5: %c\n", va_arg(args, char*)); //(int)"\001" = 1
    printf("value 6: %s\n", va_arg(args, char*)); //(int)"\001" = 1

    va_end(args); // thu hồi lại con trỏ args
}

int main (int argc, char const *argv[]){
     test(6, 1, 2, 6, 5.5, 'a', "dung");

}