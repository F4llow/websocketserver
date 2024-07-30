#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libwebsockets.h>

#define MAX_CLIENTS 1024

struct per_session_data {
    struct lws *wsi;
    int client_id;
};

static struct per_session_data *clients[MAX_CLIENTS];
static int num_clients = 0;
static int next_client_id = 1;

static int callback_example(struct lws *wsi, enum lws_callback_reasons reason,
                            void *user, void *in, size_t len) {
    struct per_session_data *psd = (struct per_session_data *)user;

    switch (reason) {
        case LWS_CALLBACK_ESTABLISHED:
            printf("Connection established\n");
            if (num_clients < MAX_CLIENTS) {
                clients[num_clients++] = psd;
                psd->wsi = wsi;
                psd->client_id = next_client_id++;
            } else {
                printf("Max clients reached, rejecting connection\n");
                lws_close_reason(wsi, LWS_CLOSE_STATUS_NORMAL, (unsigned char *)"Max clients", 12);
                return -1;
            }
            break;

        case LWS_CALLBACK_RECEIVE: {
            printf("Received data from client %d: %.*s\n", psd->client_id, (int)len, (char *)in);
            char buffer[LWS_PRE + 512];
            int n;
            snprintf(buffer + LWS_PRE, sizeof(buffer) - LWS_PRE, "From %d: %.*s", psd->client_id, (int)len, (char *)in);
            n = strlen(buffer + LWS_PRE);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i]->wsi != wsi) {
                    lws_write(clients[i]->wsi, (unsigned char *)buffer + LWS_PRE, n, LWS_WRITE_TEXT);
                }
            }
            break;
        }

        case LWS_CALLBACK_CLOSED:
            printf("Connection closed for client %d\n", psd->client_id);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i] == psd) {
                    for (int j = i; j < num_clients - 1; j++) {
                        clients[j] = clients[j + 1];
                    }
                    num_clients--;
                    break;
                }
            }
            break;

        default:
            break;
    }
    return 0;
}

static struct lws_protocols protocols[] = {
    {
        "example-protocol",
        callback_example,
        sizeof(struct per_session_data),
        4096,
    },
    { NULL, NULL, 0, 0 }
};

int main(void) {
    struct lws_context_creation_info info;
    struct lws_context *context;

    memset(&info, 0, sizeof(info));
    info.port = 8080;
    info.protocols = protocols;
    info.gid = -1;
    info.uid = -1;

    context = lws_create_context(&info);
    if (!context) {
        fprintf(stderr, "Failed to create context\n");
        return 1;
    }

    printf("Starting server...\n");
    while (lws_service(context, 1000) >= 0) {
    }

    lws_context_destroy(context);
    return 0;
}

