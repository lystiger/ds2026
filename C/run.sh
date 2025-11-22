#!/bin/bash

# Start the server in the background
./ex1/server &
SERVER_PID=$!

# Wait a moment for the server to start
sleep 1

# Start the client
./ex1/client

# Optional: kill the server after client finishes
kill $SERVER_PID

# i used gpt for this script because i cant write bash code do not blame me