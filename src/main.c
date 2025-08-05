#include <stdio.h>
#include "../cli_utils/lib/cli_utils.h"

int main(int argc, char** argv)
{
    char* app_name = get_exe(argv[0]);
    if (argc < 2)
    {
        usage(app_name);
    }


    
    return 0;
}