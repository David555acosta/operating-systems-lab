#include <stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include <unistd.h>

#define TAM 1024
int main()
{
	int segment_id; // un id del Segmento de Memoria compartida
	char* shared_memory; // un puntero a la Memoria Compartida
	//obtener un ID del segmento de memoria
	segment_id = shmget(1981, TAM, 0664 | IPC_CREAT);


	pid_t pid = getpid(); //obtener el id del proceso actual

	if (segment_id == -1) { //si surge algun problema
		fprintf(stderr, "Error al reservar la memoria");
	}
	//obtener un puntero al Segmento de memoria Compartida
	shared_memory = (char*)shmat(segment_id, NULL, 0);
	sprintf(shared_memory, "HOLA!"); //Escribir en el Shared Memory

	// Imprimir PID y contenido de la memoria
	printf("Memoria compartida escrita desde [PID %d] Contenido en memoria compartida: %s\n", pid, shared_memory);

	return 0;
}

