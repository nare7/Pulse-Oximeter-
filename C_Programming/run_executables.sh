#!/bin/bash
# Script to run 10 executables sequentially

# List of executables (add your actual executable names or paths)
executables=(
    "./program1"
    "./program2"
    "./program3"
    "./program4"
    "./program5"
    "./program6"
    "./program7"
    "./program8"
    "./program9"
    "./program10"
)

# Loop through each executable and run sequentially
for exe in "${executables[@]}"; do
    echo "Running $exe ..."
    
    if [ -x "$exe" ]; then
        $exe
        if [ $? -ne 0 ]; then
            echo "Error: $exe failed!"
            exit 1
        fi
    else
        echo "Error: $exe not found or not executable!"
        exit 1
    fi
    
    echo "$exe completed successfully."
    echo "-----------------------------------"
done

echo "✅ All executables have been run successfully."

