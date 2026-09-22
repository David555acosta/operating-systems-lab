#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	pid_t pid = fork(); // Crear un proceso hijo
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		return EXIT_FAILURE;
	}
	else if (pid == 0)
	{
		// Código del proceso hijo
		printf("Soy el proceso hijo con PID %d\n", getpid());
		sleep(2); // Simular trabajo del hijo
		printf("Proceso hijo termina\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		// Código del proceso padre
		printf("Soy el proceso padre esperando al hijo...\n");
		int status;
		wait(&status); // Esperar a que el hijo termine
		printf("Proceso hijo finalizado con estado %d\n",
			WEXITSTATUS(status));
	}
	return EXIT_SUCCESS;
}