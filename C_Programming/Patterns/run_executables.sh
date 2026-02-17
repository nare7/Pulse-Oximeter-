#!/bin/bash
# Script to run 10 executables sequentially

# List of executables (add your actual executable names or paths)
executables=(
    "./pattern_124"
    "./pattern_125" 
    "./pattern_126" "./pattern_127" "./pattern_128" "./pattern_129" "./pattern_130" "./pattern_131" "./pattern_132" "./pattern_133"
   
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
