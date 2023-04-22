# Minishell
This project is about making a small shell taking bash as reference.

Welcome to my minishell part project, I’ll try to give you an idea about how I did the parsing.
Parsing refers to the process of taking the input from the user, which is typically a command line, and breaking it down into individual components that can be understood by the executor; it is an essential component that allows the executor to understand and execute the user’s commands easily.

## Separation
I create a linked list where I push char by char.

While pushing I check for the special chars < > << >> |.

I push a space before and after, each time it’s one (or two <<,>>) of them.

But not those inside “double quotes” or ‘single quotes’.

I have now a linked list with a space separation between important elements.

I transfer the list into a char*.

I split it by space in a char**.

Split should not split inside “double quotes” or ‘single quotes’.

ex :

    cmd : echo "  here is | a test > of >>a " | cmd -to | show >how | <Makefile is >> done

    **array : ["echo" , "  here is | a test > of >>a " , "|" , "cmd" , "-to" , "|" , "show" , ">" , "how" , "|" , "<" , "split" , "is" , ">>" , "done"]

## Checking for syntax error

I suggest trying them in bash to know all the cases.

ex :

    nothing before or after the pipe.

    more than one pipe.
 
    same for redirections.
 
## From **array to linked list

I have now a clean char** that needs to be sent to the executor.

It needs to be transferred into a linked list.

Everything between pipes must be filled in a new node.

Here is the struct that will be filled.

Using ft_lstnew to create and initialize a new node.

```
typedef struct s_cmd
{
   char            **heredoc;
   int             *herepipe;
   int             in;
   int             out;
   int             wf;
   char            **args;
   struct s_cmd    *next;
}                   t_cmd;
```

And ft_lstaddback to push it to the list.

Each node will hold the data from the start to the pipe or pipe to pipe.

The args** is for the command and its parameters.

Heredoc** is for storing <<delimiters.

In/out are the file descriptors of the infile/outfile.

I open fds during the filling of the list.

Herepipe* and wf are used by the executor for heredoc manipulation.
