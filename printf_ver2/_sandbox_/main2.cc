#include "stdio.h"

//  %|flag: -+# 0|width: number or *|precision: .number|length: h|specifier: cdsux...

int main()
{
    /*

    // Regular %d
    //%|non|5|non|non|d

    printf("%5d\n", 12);
    printf("%6d\n", -24);
    printf("%7d\n\n", 36);

    //   12 --- (3 spaces 12)(5d)
    //   -24 --- (3 spaces -24)(6d)(minus sign counts as 1 digit)
    //     36 --- (5 spaces 36)(7d)



    //  flag 0 (0-padding): use 0 as a padding character
    //%|0|5|non|non|d

    printf("%05d\n", 12);
    printf("%06d\n", -24);
    printf("%07d\n\n", 36);

    //00012 --- (3 zeros 12)(5d)
    //-00024 --- (minus_sign 3 zeros 24)(6d)
    //0000036 --- (5 zeros 36)



    //  flag - : Left Alignment
    //%|-|5|non|non|d

    printf("%-5d\n", 12);
    printf("%-6d\n", -24);
    printf("%-7d\n\n", 36);

    //12    --- (12 then 3 spaces)(5d)
    //-24   --- (-24 then 3 spaces)(6d)
    //36      --- (36 then 5 spaces)(7d)


    */



/*

*/




    //  flag + : - for negative or + for positive 
    //%|+|5|non|non|d

    printf("%d\n", 12);
    printf("%+d\n", 12);
    printf("%+05d\n", 12);
    printf("%d\n", -24);
    printf("%+d\n", -24);
    printf("%+0d\n", -24);
    printf("%7d\n", -36);
    printf("%+7d\n", -36);
    printf("%+07d\n\n", -36);


    //12 --- (regular +int)
    //+12 --- (add positive sign, %+d)
    //+0012 --- (positive sign & 0-padding, %+05d)
    //-24 --- (regular -int)
    //-24 --- (add negative sign, %+d)
    //-24 --- (negative sign & non-effective 0-padding, %+0d)
    //    -36 --- (%7d)
    //    -36 --- (%+7d)
    //-000036 --- (sign - 4 zeros - 36)(%+07d)



    //flag # : o be added to octal or 0x to hexadecimal  
    //%|#|5|non|non|d	
    printf("%o\n", 0xFFFF);
    printf("%#o\n", 0xFFFF);
    printf("%x\n", 0xFFFF);
    printf("%#x\n", 0xFFFF);
    printf("%X\n", 0xFFFF);
    printf("%#X\n\n", 0xFFFF);

    /*
    177777
    0177777
    ffff
    0xffff
    FFFF
    0XFFFF
    */

    //flag  : - for negative or space for positive
    //%| | |non|non|d
    printf("%d\n", 12);
    printf("% d\n", 12);
    printf("%d\n", -24);
    printf("% d\n", -24);

    /*
    12
     12
    -24
    -24
    */
}

