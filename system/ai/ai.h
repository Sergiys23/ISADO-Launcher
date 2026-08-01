#ifndef AI_H
#define AI_H

#include <stdbool.h>

#define AI_MAX_COMMAND_LENGTH 256
#define AI_MAX_RESPONSE_LENGTH 2048

typedef struct
{
    char command[AI_MAX_COMMAND_LENGTH];
    char response[AI_MAX_RESPONSE_LENGTH];

} AIRequest;

bool ai_init(void);

void ai_shutdown(void);

bool ai_execute(
    const char *command,
    char *response,
    int responseSize
);

bool ai_open_browser(const char *url);

bool ai_open_explorer(void);

bool ai_open_terminal(void);

bool ai_connect_phone(void);

bool ai_download_file(const char *url);

bool ai_shutdown_system(void);

#endif