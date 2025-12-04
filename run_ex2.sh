#!/bin/bash

pkill -f server_app

echo "[RPC] Starting server and client for file transfer"
echo

# Paths
SERVER_DIR="C/ex2/RPC/server"
CLIENT_DIR="C/ex2/RPC/client"

SERVER_APP="server_app"
CLIENT_APP="client_app"

# Check server directory
if [[ ! -d "$SERVER_DIR" ]]; then
    echo "ERROR: Server directory not found: $SERVER_DIR"
    exit 1
fi

# Check client directory
if [[ ! -d "$CLIENT_DIR" ]]; then
    echo "ERROR: Client directory not found: $CLIENT_DIR"
    exit 1
fi

echo "[RPC] Launching server..."
(cd "$SERVER_DIR" && ./"$SERVER_APP") &
SERVER_PID=$!

sleep 3
echo "[RPC] Server running with PID $SERVER_PID"
echo

echo "[RPC] Running client (example: download file 'test.txt')"
(cd "$CLIENT_DIR" && ./"$CLIENT_APP" "127.0.0.1" download "test.txt" "test.txt")

echo
echo "[RPC] Client finished"
echo

# Stop server
echo "[RPC] Killing server..."
kill $SERVER_PID 2>/dev/null
echo "[RPC] Server stopped."

echo
echo "[RPC] Done."
