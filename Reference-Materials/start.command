#!/bin/bash

# Change directory to the project folder
cd /Users/joydipchakraborty/notes-vault/DSA-Notes

# Pull latest Git changes
git pull

# Open a new Terminal window and run 'qwen' with env loaded
osascript <<EOF
tell application "Terminal"
    activate
    do script "cd /Users/joydipchakraborty/notes-vault/DSA-Notes; set -a; source .env 2>/dev/null; set +a; qwen"
end tell
EOF

# Exit current terminal (if opened via double-click)
exit
