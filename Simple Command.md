#Simple Command
* Try ctrl-D in a prompt after you wrote some stuff / **##TODO : multiple time, not exit it**
* Try ctrl-\ in a prompt after you wrote some stuff / **##TODO : check in mac**
> * [o] Check if env shows you the current environment variables
> * [o] Check them with env unset
> * [o] Use unset to remove some of them
> * [o] Check the result with env Environment Variables
> * [o] Execute echo with some $ variables as arguments
> * [o] Check if double quotes around $ variables is working correctly (like in bash) cd
> * [o] Use the command cd to move the working directory and check if you are in the right directory with /bin/ls
> * [o] Repeat multiple times with working and not working cd
> * [o] try '.' '..' as arguments too pwd
> * [o] Use the command pwd
> * [o] Repeat multiple times in multiple directories
* [o] try '.' '..' as arguments too Relative Path **##?**
> * [o] Execute commands but this time use a relative path
> * [o] Repeat multiple times in multiple directories with complex relative path (lots of ..) Environment Path
> * [o] Execute commands but this time without any path. (ls, wc, awk etc...)
> * [o] Unset the $PATH and check if it is not working anymore
* [o] Set the $PATH to a multiple directory value (directory1:directory2) and check that directories are checked in order from left to right Simple Quotes **#?**
> * [o] Execute commands with simple quotes as argument
> * [o] Try empty arguments
> * [o] Try environment variables, whitespaces and semicolons in the simple quotes echo '\' bash-3.2$ echo '$PATH' $PATH Redirection
> * [o] Execute commands with redirections < and/or >
> * [o] Repeat multiple times with different commands and arguments and sometimes change > with >>
> * [o] Check if multiple of the same redirections fail Pipes
> * [o] Execute commands with pipes like 'cat file | grep bla | more'
> * [o] Repeat multiple times with different commands and arguments
> * [o] Try some failing commands like 'ls filethatdoesntexist | grep bla | more'
* [o] Try to mix pipes and redirections. Go Crazy **##TODO : piping & redi error `echo 1 > 2 | echo 2 >> 2`**
> * [o] Execute commands that should not work like 'dsbksdgbksdghsd' and check if the shell doesn't crash and prints an error
* [o] Try to execute a really really really long command with a ton of arguments **##TODO : maybe out?**


