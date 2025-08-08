#include <stdio.h>
#include "../cli_utils/includes/cli_utils.h"

void process(ParsedArgs* pa)
{
    
    printf("Flags:\n");
    while (!Flag_ll_empty(&pa->flag_head))
    {
        Flag* f = Flag_ll_pop(&pa->flag_head);
        printf("\t%s\n", f->name);
    }

    printf("KWArgs:\n");
    while (!KWArg_ll_empty(&pa->kwarg_head))
    {
        KWArg* kwarg = KWArg_ll_pop(&pa->kwarg_head);
        printf("\t%s\n", kwarg->name);
    }

    printf("Args:\n");
    while (!Arg_ll_empty(&pa->arg_head))
    {
        Arg* arg = Arg_ll_pop(&pa->arg_head);
        printf("\t%s\n", arg->name);
    }
}

int main(int argc, char** argv)
{
    App_t* app = new_app(
        "Synk",
        "synk",
        "0.0.1",
        process
    );

    Arg source = {
        .name = "source",
        .description = "Where the files are copied from",
    };
    push_arg(app, &source);

    Arg target = {
        .name = "target",
        .description = "Where the files are copied",
    };
    push_arg(app, &target);
    
    parse(app, argc, argv);
    
    free_app(app);

    return 0;
}