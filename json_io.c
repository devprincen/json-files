#include <stdio.h>
#include <stdlib.h>
#include "json_io.h"

cJSON *json_load(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return NULL;
    }

    // Find file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Allocate buffer
    char *data = (char *)malloc(size + 1);
    if (!data) {
        fclose(file);
        return NULL;
    }

    // Read file
    fread(data, 1, size, file);
    data[size] = '\0';
    fclose(file);

    // Parse JSON
    cJSON *json = cJSON_Parse(data);
    free(data);

    return json;
}

int json_save(const char *filename, const cJSON *json) {
    if (!json) return -1;

    char *data = cJSON_Print(json); // pretty-print
    if (!data) return -1;

    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        free(data);
        return -1;
    }

    fwrite(data, 1, strlen(data), file);
    fclose(file);
    free(data);

    return 0; // success
}
