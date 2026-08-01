#ifndef INTERNET_H
#define INTERNET_H

#include <stdbool.h>

bool internet_init(void);

void internet_shutdown(void);

bool internet_is_online(void);

const char *internet_version(void);

#endif