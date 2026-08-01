#ifndef HTTP_H
#define HTTP_H

#include <stdbool.h>

#define HTTP_GET     1
#define HTTP_POST    2
#define HTTP_PUT     3
#define HTTP_DELETE  4

typedef struct
{
    int status;

    char contentType[64];

    char body[65536];

} HTTPResponse;

bool http_init(void);

void http_shutdown(void);

bool http_request(
    int method,
    const char *url,
    const char *body,
    HTTPResponse *response
);

bool http_get(
    const char *url,
    HTTPResponse *response
);

bool http_post(
    const char *url,
    const char *json,
    HTTPResponse *response
);

#endif