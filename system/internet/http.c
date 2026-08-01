#include "http.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int initialized = 0;

bool http_init(void)
{
    initialized = 1;

    printf("[HTTP] Ready\n");

    return true;
}

void http_shutdown(void)
{
    initialized = 0;

    printf("[HTTP] Shutdown\n");
}

bool http_request(
    int method,
    const char *url,
    const char *body,
    HTTPResponse *response
)
{
    if(!initialized)
        return false;

    if(response == NULL)
        return false;

    memset(response,0,sizeof(HTTPResponse));

    response->status = 200;

    strcpy(response->contentType,"text/plain");

    snprintf(
        response->body,
        sizeof(response->body),
        "HTTP Stub\nMethod=%d\nURL=%s\nBody=%s",
        method,
        url,
        body ? body : ""
    );

    printf("[HTTP] %s\n",url);

    return true;
}

bool http_get(
    const char *url,
    HTTPResponse *response
)
{
    return http_request(
        HTTP_GET,
        url,
        NULL,
        response
    );
}

bool http_post(
    const char *url,
    const char *json,
    HTTPResponse *response
)
{
    return http_request(
        HTTP_POST,
        url,
        json,
        response
    );
}