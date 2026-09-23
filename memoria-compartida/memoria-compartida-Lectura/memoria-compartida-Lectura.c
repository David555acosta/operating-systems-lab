#include <stdio.h>
#include <unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>
#define TAM 1024
int main()
{
	int segment_id; // un id del Segmento de Memoria compartida
	char* shared_memory; // un puntero a la Memoria Compartida

	pid_t pid = getpid(); //obtener el id del proceso actual


	//obtener un ID del segmento de memoria
	segment_id = shmget(1981, TAM, 0664 | IPC_CREAT);

	if (segment_id == -1) { //si surge algun problema
		fprintf(stderr, "Error al reservar la memoria");
	}


	//obtener un puntero al Segmento de memoria Compartida
	shared_memory = (char*)shmat(segment_id, NULL, 0);

	//Enviar a la Pantalla lo que hay en la memoria compartida
	printf("Memoria compartida leida desde [PID %d] Contenido en memoria compartida: %s\n", pid, shared_memory);

	shmdt(shared_memory); //Desconectar Shared Memory
	shmctl(segment_id, IPC_RMID, NULL); //Eliminar el espacio de direcciones
	return 0;
}
