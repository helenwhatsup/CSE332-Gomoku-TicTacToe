Group members:
1. Andy Wang	464458 - coding debugging testing
2. Roger Wang	458799 - coding debugging testing
3. Helen Jiang	464082 - coding debugging testing

=======================================================================================================

1. LSCommand
-------------------------------------------------------------------------------------------------------
[Without opion]
H:\cse332\lab5.final\lab5-lab5-preschoolprogrammer\monaster_lab_5_final\Debug>monaster_lab_5_final.exe
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
dir
image.img

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ lsfsijoa
invalid command
-------------------------------------------------------------------------------------------------------
[With opion]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls -l
dir     directory        size: 14
image.img       image    size: 0

=======================================================================================================

2. RemoveCommand
1)
root $ ls
dir
image.img

root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ls
test.txt
dir1
-------------------------------------------------------------------------------------------------------
[Without opion]
root $ rm dir
Error: this directory is not empty therefore cannot be deleted!
-------------------------------------------------------------------------------------------------------
[With opion]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir -r
test.txt
dir1

=======================================================================================================

3. CatCommand
1)
-------------------------------------------------------------------------------------------------------
{TextFile}
[Without opion]
root $ cat text.txt
root/text.txt
Please enter input data for the file and then enter either :q to quit without saving or :wq to quit with saving
Can I get a 100 in lab5?
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds text.txt
root/text.txt
Can I get a 100 in lab5?
-------------------------------------------------------------------------------------------------------
[With opion]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat text.txt -a
root/text.txt
Can I get a 100 in lab5?
Please enter input data for the file and then enter either :q to quit without saving or :wq to quit with saving
Yes I can!
:wq
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds text.txt
root/text.txt
Can I get a 100 in lab5?
Yes I can!
-------------------------------------------------------------------------------------------------------
{ImageFile}
[Without opion]
root $ cat image.img
root/image.img
Please enter input data for the file and then enter either :q to quit without saving or :wq to quit with saving
X X X X X3
:wq
-------------------------------------------------------------------------------------------------------
Image successfully edited!
[With option]
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cat image.img -a
root/image.img
X X X X X
Error: this file type does not support append!
command failed

=======================================================================================================

4. DisplayCommand
1)
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds ccc.img
root/ccc.img
X X
 X
X X

2)
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds ccc.img -d
root/ccc.img
X X X X X

3)
root $ ds text.txt
root/text.txt
Can I get a 100 on lab5?

4)
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds text.txt -d
root/text.txt
Can I get a 100 on lab5?

=======================================================================================================

5. CopyCommand
root $ cp image.img root/dir
Copying image.img to: root/dir/
Copied!
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds image.img
root/image.img
X X
 X
X X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ cat image.img
root/dir/image.img
Please enter input data for the file and then enter either :q to quit without saving or :wq to quit with saving
X X 2
:wq
Image successfully edited!
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ds image.img
root/dir/image.img
X
X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ cd ..
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds image.img
root/image.img
X X
 X
X X

=======================================================================================================

6. SymCommand
root $ cat image.img
root/image.img
Please enter input data for the file and then enter either :q to quit without saving or :wq to quit with saving
X X X X X3
:wq
Image successfully edited!
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds image.img
root/image.img
X X
 X
X X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ sym image.img root/dir
Making proxy of image.img to: root/dir/
Proxy set!
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ cat image.img
root/dir/image.img
Please enter input data for the file and then enter either :q to quit without saving or :wq to quit with saving
X X 2
:wq
Image successfully edited!
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ ds image.img
root/dir/image.img
X
X

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir $ cd ..
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ds image.img
root/image.img
X
X

Errors and bugs:
There are no major bugs we encountered.

