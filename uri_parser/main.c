#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <uri_parser.h>

#include "symex.h"

#define BUFFER_SIZE 15

int main(void)
{
    char buf[BUFFER_SIZE];
    size_t len = BUFFER_SIZE;
    uri_parser_result_t result;

    vp_make_symbolic(buf, len);
    uri_parser_process(&result, buf, len);

    vp_symbolic_ctrl(SYMEX_EXIT);
    return 0;
}
