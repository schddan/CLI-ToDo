## To-do app CLI
A To-do app made for Command Line

### Cloning, building and compiling
``` bash
  # Clone the repository:
  $ https://github.com/schddan/CLI-todo.git

  # Enter directory:
  $ cd CLI-todo

  # Build with CMake:
  $ cmake build
  $ cmake -S src/ -B build/

  #Compiling
  $ cd build/
  $ cmake --build .
```

### Commands
- todo list: lists all current tasks
- todo add: adds a new task
- todo edit: edits a task
- todo finish: finish a task