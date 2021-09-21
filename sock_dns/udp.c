#include "net/sock/udp.h"
#include "sock_types.h"

#include "symex.h"

/**
 * Stub implementation of sock_udp which returns symbolic data on read.
 */

int sock_udp_create(sock_udp_t *sock, const sock_udp_ep_t *local,
                    const sock_udp_ep_t *remote, uint16_t flags)
{
    (void)sock;
    (void)local;
    (void)remote;
    (void)flags;

    return 0;
}

ssize_t sock_udp_send_aux(sock_udp_t *sock, const void *data, size_t len,
                          const sock_udp_ep_t *remote, sock_udp_aux_tx_t *aux)
{
    (void)sock;
    (void)data;
    (void)remote;
    (void)aux;

    return len;
}

ssize_t sock_udp_recv_aux(sock_udp_t *sock, void *data, size_t max_len,
                          uint32_t timeout, sock_udp_ep_t *remote,
                          sock_udp_aux_rx_t *aux)
{
    (void)sock;
    (void)timeout;
    (void)remote;
    (void)aux;

    vp_make_symbolic(data, max_len);
    return max_len;
}

void
sock_udp_close(sock_udp_t *sock)
{
    (void)sock;
    return;
}
