#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100
#define MAX_HISTORY 10

//command history management

char *history[MAX_HISTORY];
int history_count=0;

void add_to_history(char *command){
    //printf("%s\n", command);
    if(history_count<MAX_HISTORY){
        history[history_count] = strdup(command);
    }else{
        free(history[0]);
        for(int i=0; i<MAX_HISTORY; i++){
            history[i-1]=history[i];
        }
        history[MAX_HISTORY-1]=strdup(command);
    }
    history_count=(history_count<MAX_HISTORY) ? history_count+1 : MAX_HISTORY;
}

void print_history(){
    for(int i=0;i<history_count;i++){
        printf("[%d] %s\n", i+1, history[i]);
    }
}


// handling the cd command

void handle_cd(char **args){
    if(args[1]==NULL){
        fprintf(stderr, "cd: expected argument\n");
    }else{
        if(chdir(args[1])!=0){
                perror("cd failed");
        }                
    }
}

// built in programs

void built_in_programs(char **args){
    if(strcmp(args[0], "hello") == 0){
        printf("Hello, welcome to my shell!\n");
    }
    else if(strcmp(args[0], "add") == 0){
        if(args[1] && args[2]){
            int sum = atoi(args[1])+atoi(args[2]);
            printf("Sum: %d\n", sum);
        }
        else{
            printf("Usage: add <num1> <num2>\n");
        }
    }
    else if(strcmp(args[0], "subtract") == 0){
        if(args[1] && args[2]){
            int diff  = atoi(args[1])-atoi(args[2]);
            printf("Difference: %d\n", diff);
        }
        else{
            printf("Usage: subtract <num1> <num2>\n");
        }
    }
    else{
        printf("Unknown command: %s\n", args[0]);
    }
}


// Help command
void print_help(char **args){
    if(args[1] == NULL){
        printf("Available commands: \nhello \nadd \nsubtract \ncd \nhistory \nquit\nType help <command> to get more information about a specific command\n");
    } else if(strcmp(args[1], "hello") == 0){
        printf("hello: Prints a greeting message.\n");
    } else if(strcmp(args[1], "add") == 0){
        printf("add <num1> <num2>: Adds two integers.\n");
    } else if(strcmp(args[1], "subtract") == 0){
        printf("subtract <num1> <num2>: Subtracts the second integer from the first.\n");
    } else if(strcmp(args[1], "cd") == 0){
        printf("cd <path>: Changes the current directory to the specified path.\n");
    } else if(strcmp(args[1], "history") == 0){
        printf("history: Displays the last 10 commands entered.\n");
    } else if(strcmp(args[1], "quit") == 0){
        printf("quit: Exits the shell.\n");
    }else if(strcmp(args[1], "exit") == 0){
        printf("exit: Exits the shell.\n");
    }else {
        printf("No help available for '%s'.\n", args[1]);
    }
}


// executing external commands

void execute_external(char **args, int is_background){
    pid_t pid = fork();
    if (pid<0){
        perror("Fork failed");
        return;
    }
    if(pid==0){
        // exec is family of functions used to replace current process 
        // with a different one...
        // they donot execute C code but execute another program
        if(execvp(args[0], args)==-1){
            perror("Execution failed");
        }
        exit(EXIT_FAILURE);
    }else{
        // parent process
        if(!is_background){
            waitpid(pid, NULL,0);
        }else{
            printf("Process running in background with PID: %d\n",pid);
        }
    }
}


// signal handling

void signal_handler(int sig){
    if(sig==SIGINT){
        printf("\nCaught SIGINT (Ctrl+C), shell continuing...\n");
    }else if(sig == SIGCHLD){
        while(waitpid(-1, NULL, WNOHANG) > 0);
    }
}


void execute_command(char *input){
    char *args[MAX_ARG_SIZE];
    char *token = strtok(input, " ");
    int i = 0;
    int is_background = 0;  // Flag to check if the command is background

    while (token!=NULL){
        args[i] = token;
        i++;
        token=strtok(NULL," ");
    }
    args[i]=NULL;
    
    // Check if the last argument is '&'
    if (i > 0 && strcmp(args[i - 1], "&") == 0) {
        is_background = 1;
        args[i - 1] = NULL;  // Remove '&' from the argument list
    }


    if (args[0] ==NULL){
        return;
    }
    add_to_history(input);
    if(strcmp(args[0], "cd")==0){
        handle_cd(args);
    }else if(strcmp(args[0], "history")==0){
        print_history();
    }else if(strcmp(args[0], "hello")==0 || strcmp(args[0], "add")==0 || strcmp(args[0],"subtract")==0){
        built_in_programs(args);
    }else if(strcmp(args[0], "quit")==0 || strcmp(args[0], "exit")==0){
        printf("Thank you for using the shell...\nBye 😉\n");
        exit(0);
    }else if(strcmp(args[0], "help") == 0){
        print_help(args);
    }else{
        execute_external(args, is_background);
    }
}

// main shell loop

int main(){
    char input[MAX_INPUT_SIZE];
    signal(SIGINT, signal_handler);
    signal(SIGCHLD, signal_handler); // to handle zombie processes
    printf("Welcome to MY Shell!! \nThis is a coustom shell implemented in C!\nSay hello and wait for magic to happen 😄\nType `help` to get list of commands!!\n");
    
    while(1){
        printf("my_shell> ");
        fflush(stdout);
        if(fgets(input, MAX_INPUT_SIZE, stdin)==NULL){
            break;
        }
        size_t len = strlen(input);
        if(input[len-1]=='\n'){
            input[len-1]='\0';
        }
        execute_command(input);
    }
    return 0;
}