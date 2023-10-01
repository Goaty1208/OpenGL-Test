import subprocess

def main():
    # Set the file name for the executable
    file_name = "main"

    # Specify the include directory for GLFW and GLEW
    include_dir = "dependencies/include"

    # Specify the library directory for GLFW and GLEW
    lib_dir = "dependencies/lib"

    # Define your compiler and linker commands
    compile_command = f"g++ main.cpp glad.c -o {file_name} -I{include_dir} -L{lib_dir} -lglfw3 -lglew32s -lopengl32 -lgdi32"

    # Compile the C++ code
    compilation_result = subprocess.run(compile_command, shell=True, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    # Check if the compilation was successful
    if compilation_result.returncode == 0:
        print("Compilation successful.")
        # Run the generated executable
        run_command = f"./{file_name}"
        subprocess.run(run_command, shell=True)
    else:
        print("Compilation failed:")
        print(compilation_result.stderr)

if __name__ == "__main__":
    main()
