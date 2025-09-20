#ifndef JSON_IO_H
#define JSON_IO_H

#include "cJSON.h"

// Load JSON from file into a cJSON object
cJSON *json_load(const char *filename);

// Save cJSON object to file (pretty-printed)
int json_save(const char *filename, const cJSON *json);

#endif
