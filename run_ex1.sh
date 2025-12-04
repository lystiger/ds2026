#!/bin/bash

# Kill any lingering server processes
pkill -f "C/ex1/server"

# Get absolute path of the script
DIR="$(cd "$(dirname "$0")" && pwd)"

# Compile server
gcc -I"$DIR/C/ex1/headers" -o "$DIR/C/ex1/server" "$DIR/C/ex1/server.c" "$DIR/C/ex1/functions/mon_socket.c" "$DIR/C/ex1/functions/mon_bind.c" "$DIR/C/ex1/functions/mon_listen.c" "$DIR/C/ex1/functions/mon_accept.c" "$DIR/C/ex1/functions/mon_read.c" "$DIR/C/ex1/functions/mon_write.c" "$DIR/C/ex1/functions/mon_close.c"

# Compile client
gcc -I"$DIR/C/ex1/headers" -o "$DIR/C/ex1/client" "$DIR/C/ex1/client.c" "$DIR/C/ex1/functions/mon_socket.c" "$DIR/C/ex1/functions/mon_connect.c" "$DIR/C/ex1/functions/mon_read.c" "$DIR/C/ex1/functions/mon_write.c" "$DIR/C/ex1/functions/mon_close.c"

# Run server in background
"$DIR/C/ex1/server" &
SERVER_PID=$!
sleep 1

# Run client
"$DIR/C/ex1/client"

# Kill server
kill $SERVER_PID 2>/dev/null
