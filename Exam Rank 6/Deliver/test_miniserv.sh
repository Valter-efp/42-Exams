#!/bin/bash

# ============================================================
# mini_serv automated test script
# ============================================================

PORT=8081
EXEC=mini_serv
SRC=mini_serv.c

# ------------------------------------------------------------
# 0. Kill any old server or Valgrind process
# ------------------------------------------------------------
echo "🧹 Cleaning up old processes..."
pkill -f "$EXEC" 2>/dev/null
pkill -f valgrind 2>/dev/null
sleep 1

# ------------------------------------------------------------
# 1. Compile
# ------------------------------------------------------------
echo "🧱 Compiling $SRC..."
cc -Wall -Wextra -Werror "$SRC" -o "$EXEC"
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed."
    exit 1
fi
echo "✅ Compilation successful."

# ------------------------------------------------------------
# 2. Start the server under Valgrind in a new terminal
# ------------------------------------------------------------
echo "🚀 Starting server on port $PORT (Valgrind enabled)..."
gnome-terminal -- bash -c "valgrind --leak-check=full ./$EXEC $PORT; exec bash" &
sleep 2  # give the server time to start

# ------------------------------------------------------------
# 3. Start client 0 in a new terminal
# ------------------------------------------------------------
echo "🪟 Starting client 0..."
gnome-terminal -- bash -c "echo 'Client 0 connected. Type messages below:'; nc 127.0.0.1 $PORT; exec bash" &
sleep 1

# ------------------------------------------------------------
# 4. Start client 1 in a new terminal
# ------------------------------------------------------------
echo "🪟 Starting client 1..."
gnome-terminal -- bash -c "echo 'Client 1 connected. Type messages below:'; nc 127.0.0.1 $PORT; exec bash" &
sleep 1

# ------------------------------------------------------------
# 5. Display info
# ------------------------------------------------------------
echo "✅ All setup complete!"
echo
echo "Open terminals:"
echo " - Server running under Valgrind"
echo " - Client 0 (nc)"
echo " - Client 1 (nc)"
echo
echo "💡 Try typing in the client windows to chat."
echo "   Close a client window to trigger the 'client left' message."
echo
echo "To stop the test: close all terminals or run:"
echo "   pkill $EXEC; pkill valgrind"



#chmod +x test_miniserv.sh
#pkill mini_serv
