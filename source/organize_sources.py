import os
import shutil

# Set the directory containing the source files
base_dir = os.path.dirname(os.path.abspath(__file__))

# List all files in the directory
for file_name in os.listdir(base_dir):
    # Skip CMakeLists.txt or any non-source file
    if file_name == "CMakeLists.txt":
        continue

    # Check for .c or .cpp files
    if file_name.endswith(".c") or file_name.endswith(".cpp"):
        file_path = os.path.join(base_dir, file_name)
        base_name = os.path.splitext(file_name)[0]
        target_dir = os.path.join(base_dir, base_name)

        # Create directory if it doesn't exist
        if not os.path.exists(target_dir):
            os.makedirs(target_dir)

        # Move file into the newly created directory
        new_file_path = os.path.join(target_dir, file_name)
        shutil.move(file_path, new_file_path)
        print(f"Moved {file_name} to {target_dir}/")
