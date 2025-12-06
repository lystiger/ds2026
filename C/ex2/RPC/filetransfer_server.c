#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "filetransfer.h"

// -----------------------------
// UPLOAD FILE
// -----------------------------
upload_res *upload_file_1_svc(upload_arg *arg, struct svc_req *rqstp) {
    static upload_res result;
    result = 0;

    char path[512];
    snprintf(path, sizeof(path), "server_files/%s", arg->name);

    int fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        result = -1;
        return &result;
    }

    write(fd, arg->data.data_val, arg->data.data_len);
    close(fd);

    return &result;
}

// -----------------------------
// DOWNLOAD FILE
// -----------------------------
download_res *download_file_1_svc(download_arg *arg, struct svc_req *rqstp) {
    static download_res reply;
    static char buffer[MAXCHUNK];
    reply.data.data_val = buffer;

    char path[512];
    snprintf(path, sizeof(path), "server_files/%s", arg->name);

    FILE *f = fopen(path, "rb");
    if (!f) {
        perror("fopen");
        reply.data.data_len = 0;
        reply.is_last = 1;
        return &reply;
    }

    fseek(f, arg->offset, SEEK_SET);

    reply.data.data_len = fread(reply.data.data_val, 1, MAXCHUNK, f);
    reply.is_last = feof(f);

    fclose(f);

    return &reply;
}
