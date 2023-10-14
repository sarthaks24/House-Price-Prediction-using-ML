

# Check if the pattern is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <pattern>"
    exit 1
fi

# Iterate over all files in the current directory
for file in *; do
    # Check if the file is a regular file
    if [ -f "$file" ]; then
        # Search for the pattern in the file
        if grep -q "$1" "$file"; then
            echo "$file: Pattern found."
        else
            echo "$file: Pattern not found."
        fi
    fi
done

