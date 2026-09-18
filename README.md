# operating-systems-lab
Hands-on OS architecture lab &amp; modular kernel simulator built in C and C#. Implements CPU scheduling, IPC, memory management, and process synchronization with Docker support.


# Operating System Fundamentals & Kernel Core Simulator

![C](https://img.shields.io/badge/Language-C11-blue.svg)
![C#](https://img.shields.io/badge/Language-C%23_12-green.svg)
![Linux](https://img.shields.io/badge/Platform-Linux%20%2F%20WSL2-orange.svg)
![Docker](https://img.shields.io/badge/Deployment-Docker-blue.svg)

---

## 📌 Presentación del Proyecto

Este repositorio nace con el objetivo de llevar a la práctica los conceptos teóricos fundamentales de los **Sistemas Operativos Modernos** (basados en la literatura académica de Andrew S. Tanenbaum y la arquitectura de kernel POSIX/UNIX).

El proyecto evoluciona desde guías y laboratorios de bajo y mediano nivel desarrollados en **C** y **C#**, integrando progresivamente cada componente hasta la construcción de un **Simulador Modular de Kernel**. A través de esta herramienta se simulan las tareas críticas de un núcleo del sistema operativo: administración de procesos, mecanismos de comunicación interproceso (IPC), algoritmos de planificación de CPU, gestión de memoria virtual con paginación y manejo de dispositivos de entrada/salida.

---

## 🛠️ Tecnologías y Entorno

- **Lenguajes:** C (GCC / POSIX), C# 
- **Sistemas Operativos Base:** Linux (Ubuntu / Debian), Windows vía WSL2
- **Herramientas de Soporte:** Virtualización, Valgrind, GDB, Docker, Docker Compose

---

## 📁 Estructura del Repositorio

El código fuente está organizado en módulos temáticos que reflejan las capas internas de un sistema operativo:

```text
src/
├── 01-architecture/          # Modelos de kernel (Monolítico, Microkernel, Híbrido) y HAL
├── 02-filesystem/            # Manipulación de archivos, descriptores y estructuras
├── 03-processes-threads/     # PCB, syscall fork(), administración de hilos en C y C#
├── 04-ipc/                   # Memoria compartida, Sockets, PIPES, Mensajes y Eventos
├── 05-scheduling/            # Algoritmos FCFS, SJF, Round Robin, Colas Multinivel
├── 06-synchronization/        # Secciones críticas, Semáforos, Mutex en C y C#
├── 07-deadlocks/              # Algoritmo del Banquero, Detección y Prevención
├── 08-memory-management/     # MMU, Paginación simple/doble, Segmentación, Tablas de Páginas
├── 09-io-subsystem/          # Buffering, Caching, Spooling, Controladores y RAID
└── 10-kernel-simulator/      # Motor integrador del Simulador de Kernel


🎯 Núcleo del Proyecto: Simulador de Kernel
El objetivo integrador de este repositorio es procesar trazados de ejecución en tiempo real mediante los siguientes subsistemas simulados:

Process Control Block (PCB): Modelado de estados de procesos (NUEVO, LISTO, EJECUCIÓN, BLOQUEADO, TERMINADO).

CPU Scheduler Engine: Motor de planificación configurable (FCFS, SJF, Round Robin con quantum dinámico y métricas de CPU).

IPC & Sincronización: Control de concurrencia mediante semáforos contadores, secciones críticas y paso de mensajes.

Virtual Memory Manager (VMM): Traducción de direcciones virtuales a físicas, control de page faults y políticas de reemplazo (LRU, FIFO).

Simulación de E/S: Gestión de colas de dispositivos bloqueantes y tiempos de transferencia.

🐳 Ejecución y Portabilidad con Docker
Para asegurar la máxima portabilidad entre entornos Windows y Linux evitando conflictos de librerías locales, el proyecto incluye soporte completo para contenedores.

Requisitos previos
Docker Engine y Docker Compose instalados.

Pasos de ejecución
Clonar el repositorio:

Bash
git clone [https://github.com/tu-usuario/os-kernel-simulator.git](https://github.com/tu-usuario/os-kernel-simulator.git)
cd os-kernel-simulator
Construir y levantar el entorno:

Bash
docker compose up --build
Acceder a la consola interactiva (Entorno Linux / C):

Bash
docker compose exec c-environment bash
📜 Licencia
Distribuido bajo la Licencia MIT. Consulta el archivo LICENSE para más información.


