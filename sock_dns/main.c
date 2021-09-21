#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <net/af.h>
#include <net/sock/dns.h>

#include "symex.h"

int main(void)
{
    void *addr;
    uint8_t addr_buf[16];

    sock_dns_server.port = 2342;

    addr = &addr_buf[0];
    sock_dns_query("example.org", addr, AF_UNSPEC);

    vp_symbolic_ctrl(SYMEX_EXIT);
    return 0;
}
