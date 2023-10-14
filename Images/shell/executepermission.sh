

# Prompt the user to enter the file path
echo "Enter the path to the file: "
read file_path

# Check if the file exists
if [ ! -e "$file_path" ]; then
    echo "File not found."
    exit 1
fi

# Check if the file has execute permission
if [ -x "$file_path" ]; then
    echo "The file already has execute permission."
else
    # Add execute permission to the file
    chmod +x "$file_path"
    echo "Execute permission added to the file."
fi

