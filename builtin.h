#ifndef BUILTIN
#define BUILTIN

int num_builtins();
void builtin_cd(char**);
void builtin_pwd(char**);
void builtin_echo(char**);

extern char *builtin_str[];
extern void (*builtin_func[]) (char**);

#endif
