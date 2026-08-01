#ifndef PHONE_H
#define PHONE_H

#include <stdbool.h>

bool phone_init(void);

void phone_shutdown(void);

bool phone_connect(void);

void phone_disconnect(void);

bool phone_is_connected(void);

#endif