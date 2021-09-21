#include <panic.h>

#include "symex.h"

/* Register custom panic handler, catches failing asserts etc. */
void panic_app(core_panic_t crash_code, const char *message)
{
    (void)crash_code;
    (void)message;

    vp_symbolic_ctrl(SYMEX_ERROR);
}


