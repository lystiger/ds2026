/*filetransfer.x*/

const MAXFNAME = 256;
const MAXCHUNK = 4096;

typedef string filename<MAXFNAME>;

struct file_chunk {
    filename name;
    opaque data<MAXCHUNK>;
    bool is_last;
};

typedef file_chunk upload_arg;

typedef int upload_res;

typedef filename download_arg;

struct chunk_reply {
    opaque data<MAXCHUNK>;
    bool is_last;
};

typedef chunk_reply download_res;

program FILE_TRANSFER_PROG {
    version FILE_TRANSFER_VERS {
        upload_res UPLOAD_FILE(upload_arg) = 1;
        download_res DOWNLOAD_FILE(download_arg) = 2;
    } = 1;
} = 0x20000001;