# cpp-debug-examples
<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [cpp-debug-examples](#cpp-debug-examples)
    - [Core dump setup](#core-dump-setup)
    - [GDB commands](#gdb-commands)
    - [GDB shortcuts](#gdb-shortcuts)

<!-- markdown-toc end -->


A few things to keep in mind:
* During development, always build project with RelWithDebInfo to create core file when segmentation fault happens.
* Research on how to create core files without terminating the program.

## Core dump setup

```sh
# Change core file name format.
sudo sysctl -w kernel.core_pattern=/tmp/core-%e.%p.%h.%t

# Dumping core file is activated after the following command.
# It must be called in every shell session.
ulimit -c unlimited

# To debug a program with dumped core file with gdb, run
gdb program core
```


## GDB commands

| Command               | Description                                                                           |
| :--                   | :--                                                                                   |
| break [file:]function | Set a breakpoint at function (in file).                                               |
| run [arglist]         | Start your program (with arglist, if specified).                                      |
| bt                    | Backtrace: display the program stack.                                                 |
| print expr            | Display the value of an expression.                                                   |
| c                     | Continue running your program (after stopping, e.g. at a breakpoint).                 |
| next                  | Execute next program line (after stopping); step over any function calls in the line. |
| edit [file:]function  | look at the program line where it is presently stopped.                               |
| list [file:]function  | type the text of the program in the vicinity of where it is presently stopped.        |
| step                  | Execute next program line (after stopping); step into any function calls in the line. |
| help [name]           | Show information about GDB command name, or general information about using GDB.      |
| quit                  | Exit from GDB.                                                                        |


## GDB shortcuts

| Keybinding          | Description                                                                              |
| :--                 | :--                                                                                      |
| C-x a               | Enter or leave the TUI mode.                                                             |
| C-x 1               | Use a TUI layout with only one window. The layout will be either 'source' or 'assembly'. |
| C-x 2               | Use a TUI layout with at least two windows.                                              |
| C-x o               | Change the active window.                                                                |
| C-x s               | Switch in and out of the TUI SingleKey mode that binds single keys to GDB commands.      |
| *Only in TUI mode:* |                                                                                          |
| PgUp                | Scroll the active window one page up.                                                    |
| PgDn                | Scroll the active window one page down.                                                  |
| Up                  | Scroll the active window one line up.                                                    |
| Down                | Scroll the active window one line down.                                                  |
| Left                | Scroll the active window one column left.                                                |
| Right               | Scroll the active window one column right.                                               |
| C-L                 | Refresh the screen.                                                                      |
