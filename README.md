# CLI-Interpreter
A simple shell program written in C that mimics the behavior of a basic Unix shell. This shell can execute commands, handle output redirection, and manage multiple arguments.
Features

    Command Execution: Execute commands entered by the user.

    Output Redirection: Redirect output of commands to a file using the > operator.

    Exit Command: Type exit to exit the shell.

    Basic Command Parsing: Parse and tokenize input into arguments.

    Forking and Executing Commands: Use fork() and execvp() to handle child processes.

Requirements

    C Compiler (GCC or Clang)

    Linux/Unix environment (or compatible)

Compilation

To compile the program, use the following command:

gcc -o mini-shell mini-shell.c

This will produce an executable named mini-shell.
Usage

Once compiled, run the mini-shell with:

./mini-shell

This will start the shell, and you can begin entering commands.
Example Usage

    Executing a Command:

mini-shell> ls -l

This will execute the ls -l command and display the directory listing.

Output Redirection:

mini-shell> echo "Hello World" > output.txt

This will execute the echo "Hello World" command and redirect the output to the output.txt file.

Exit:

    mini-shell> exit

    This will exit the shell.

Functions
parse_input(char* input, char** args)

    Splits the input string into arguments based on spaces and newlines.

    Stores the parsed arguments in the args array.

main()

    Runs the main shell loop.

    Prompts the user for input, parses it, forks a child process, and executes the command.

    Handles output redirection if the > operator is used.

Key Concepts

    Forking: Uses the fork() system call to create a child process.

    Exec: The execvp() function is used to execute commands in the child process.

    Redirection: Handles output redirection with the > operator by redirecting stdout to a file.

    Waiting for Child: The parent process waits for the child to complete using waitpid().

Limitations

    No Input Redirection: The program does not handle input redirection (< operator).

    No Pipelines: It doesn't support piping (|) between commands.

    Limited Argument Count: The shell can only handle up to MAX_ARGS arguments.

    Basic Parsing: It doesn't handle complex parsing like quoted strings or escaped characters.
