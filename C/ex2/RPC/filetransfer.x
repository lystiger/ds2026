const MAXFNAME = 256;
const MAXCHUNK = 4096;

typedef string filename<MAXFNAME>;

struct upload_chunk {
    filename name;
    opaque data<MAXCHUNK>;
    int offset;
    bool is_last;
};

typedef upload_chunk upload_arg;
typedef int upload_res;

struct download_arg_s {
    filename name;
    int offset;
};
typedef struct download_arg_s download_arg;

struct chunk_reply {
    opaque data<MAXCHUNK>;
    int data_len;
    bool is_last;
};

typedef chunk_reply download_res;

program FILE_TRANSFER_PROG {
    version FILE_TRANSFER_VERS {
        upload_res UPLOAD_FILE(upload_arg) = 1;
        download_res DOWNLOAD_FILE(download_arg) = 2;
    } = 1;
} = 0x20000001;
