Minishell
--------
For this assignment,you will be adding to your mini bash to make it more functional.

Implement the following features:

Backspace: Since you will not be using buffered input you will need to re-implement the backspace key.
Left and Right Arrow Keys: should move the cursor back and forth.
Up and Down Arrow Keys: should swap between previous and the current command.For this feature you will most likely need to use you linked list

CTRL+"L": Clear the terminal except for the current command
CTRL+"A": Move to the start of the current command
CTRL+"E": Move to the end of the current command
CTRL+"W": Cut a word into the clipboard.You should be able to cut multiple words.(Try using it in bash!)
CTRL+"Y": Paste
Color: Make it look pretty!The prompt and directory should be different colors.
Saved History: When you exit,save your command history to a file called .nsmshistory and load the command history when you start
Dollar Sign: Program the ability to usr the $() to pass output from one program into another(i.e. more $(myselect *.c))

Extra Credit ideas:
Control Statements: Create the ability to use if and while loops akin to BASH
Multiple Windows: be able to split your terminal into multiple windows
Cool Things: Come up with something challenging and interesting to add to your shell and we'll give you what we feel is comparable extra credit
