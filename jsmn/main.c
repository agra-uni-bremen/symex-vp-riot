#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kernel_defines.h"
#include "jsmn.h"

#include "symex.h"

#define BUFFER_SIZE 16

int main(void)
{
    jsmn_parser p;
    jsmntok_t t[16];
    char buf[BUFFER_SIZE];

    vp_make_symbolic(buf, sizeof(buf));
    buf[sizeof(buf) - 1] = '\0';

    jsmn_init(&p);
    jsmn_parse(&p, buf, strlen(buf), t, ARRAY_SIZE(t));

    vp_symbolic_ctrl(SYMEX_EXIT);
    return 0;
}
