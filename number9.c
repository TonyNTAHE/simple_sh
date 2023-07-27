#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int compare(const char *arg1, const char *arg2);
/**
 * main - This will do the whole thing
 *
 * Return: 0;
 */
int main(void)
{

	size_t n = 0;
	char *buf = NULL;
	char *exi = "exit";
	ssize_t chsize;
	int exi_ar = 0;

	while (1)
	{
		printf("$ ");
		chsize = getline(&buf, &n, stdin);
	if (chsize == -1)
	{
		perror("An Error occurred");
		break;
	}
	else
	{
		buf[chsize - 1] = '\0';
	if (compare(buf, exi))
	{
		char *extra_arg = buf + strlen(exi);

		while (*extra_arg == ' ')
		{
			extra_arg++;
		}
		if (*extra_arg != '\0')
		{
			exi_ar = atoi(extra_arg);
		}
		printf("Exiting the program with status: %d\n", exi_ar);
		free(buf);
		exit(exi_ar);
	}
	else
	{
		char *argv[10];
		char *token;
		int arg_count = 0;

		token = strtok(buf, " ");
		while (token != NULL && arg_count < 10 - 1)
		{
			argv[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		argv[arg_count] = NULL;
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
		}
		else if (child_pid == 0)
		{
			char *path = getenv("PATH");
			char *dir = path;

			while (*dir != '\0')
			{
				char cmd_path[200];
				int i = 0;

				while (*dir != '\0' && *dir != ':')
				{
					cmd_path[i++] = *dir;
					dir++;
				}
				cmd_path[i] = '/';
				strcpy(cmd_path + i + 1, argv[0]);
				execve(cmd_path, argv, NULL);
				if (*dir == ':')
				{
					dir++;
				}
			}
			printf("Command not found: %s\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			wait(&status);
		}
	}
	}
	}
	free(buf);
	return (0);
}
/**
 * compare - this will compare the arguments
 * @arg1:The first argument
 * @arg2:The second argument
 *
 * Return: a value
 */
int compare(const char *arg1, const char *arg2)
{
	while (*arg1 != '\0' && *arg2 != '\0')
	{
		if (*arg1 != *arg2)
		{
			return (0);
		}
		arg1++;
		arg2++;
	}
	return (*arg1 == '\0' && *arg2 == '\0');
}
