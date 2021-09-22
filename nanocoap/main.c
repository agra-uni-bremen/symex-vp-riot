#include <stdio.h>
#include <stdlib.h>

#include "net/nanocoap.h"
#include "symex.h"

#define COAP_INBUF_SIZE (20U)

const coap_resource_t coap_resources[] = {
    COAP_WELL_KNOWN_CORE_DEFAULT_HANDLER,
};

const unsigned coap_resources_numof = ARRAY_SIZE(coap_resources);

int main(void)
{
    coap_pkt_t pkt;
    uint8_t buf[COAP_INBUF_SIZE];
    size_t len = COAP_INBUF_SIZE;

    vp_make_symbolic(buf, len);
    coap_parse(&pkt, buf, len);

    vp_symbolic_ctrl(SYMEX_EXIT);
    return 0;
}
