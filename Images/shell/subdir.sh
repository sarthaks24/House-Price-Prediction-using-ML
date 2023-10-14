

# List all directories in the current directory
for dir in */; do
    # Check if the directory is a subdirectory
    if [ -d "$dir" ]; then
        # Extract the directory name and print it
        dirname=${dir%/}
        echo "$dirname"
    fi
done

