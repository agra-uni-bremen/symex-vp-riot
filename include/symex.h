#ifndef RIOT_SYMEX_H
#define RIOT_SYMEX_H

#include <stdint.h>
#include <stddef.h>

typedef enum {
    SYMEX_ERROR,
    SYMEX_EXIT,
} vp_ctrl_t;

static inline void
vp_make_symbolic(void *ptr, size_t size)
{
    static volatile uint32_t* const SYMCTRL_ADDR = (uint32_t*)0x02020000;
    static volatile uint32_t* const SYMCTRL_SIZE = (uint32_t*)0x02020004;

    *SYMCTRL_ADDR = (uintptr_t)ptr;
    *SYMCTRL_SIZE = size;
}

static inline void
vp_symbolic_ctrl(vp_ctrl_t ctrl)
{
    static volatile uint32_t* const SYMCTRL_CTRL = (uint32_t*)0x02020008;
    uint32_t v;

    switch (ctrl) {
        case SYMEX_ERROR:
            v = (1 << 31);
            break;
        case SYMEX_EXIT:
            v = (1 << 30);
            break;
    }

    *SYMCTRL_CTRL = v;
}

#endif
