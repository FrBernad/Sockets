// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com/

#include <levels.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define M_PI 3.14159265358979323846

#define MAX 80

static int parseAnswer(char* response, char* levelAnswer);
static void gdbme();
static void printNums();
static void toInvestigate(const char* subject);

char too_easy = 1;

int level1(FILE* clientFile, char** response, size_t size) {
    printf(
        "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\n"
        "En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel."
        "Además tendrán que investigar otras preguntas para responder durante la defensa."
        "El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos"
        " y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta."
        "Además, deberán implementar otro programa para comunicarse conmigo.\n\n"
        "Deberán estar atentos a los easter eggs.\n\n"
        "Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'\n\n");

    toInvestigate("¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?");

    if (getline(response, &size, clientFile) == -1)
        return -1;

    return parseAnswer(*response, "entendido\n");
}

int level2(FILE* clientFile, char** response, size_t size) {
    printf(
        "The Wire S1E5\n"
        "5295 888 6288\n\n");

    toInvestigate("¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?");

    if (getline(response, &size, clientFile) == -1)
        return -1;

    return parseAnswer(*response, "itba\n");
}

int level3(FILE* clientFile, char** response, size_t size) {
    printf("https://ibb.co/tc0Hb6w\n\n");

    toInvestigate("¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?");

    if (getline(response, &size, clientFile) == -1)
        return -1;

    return parseAnswer(*response, "M4GFKZ289aku\n");
}

int level4(FILE* clientFile, char** response, size_t size) {
    if (write(999, "fk3wfLCm3QvS", 12) == -1) {
        perror("write");
    }

    printf("EBADF...\n\n");

    toInvestigate("¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?");

    if (getline(response, &size, clientFile) == -1)
        return -1;

    return parseAnswer(*response, "fk3wfLCm3QvS\n");
}

int level5(FILE* clientFile, char** response, size_t size) {
    if (too_easy) {
        printf("respuesta = strings:195\n\n");

        toInvestigate("¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?");

        if (getline(response, &size, clientFile) == -1)
            return -1;
    }

    return parseAnswer(*response, "too_easy\n");
}

int level6(FILE* clientFile, char** response, size_t size) {
    printf(".plt .plt.got .text ? .fini .rodata. eh_frame_hdr\n\n");

    toInvestigate("Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?");

    if (getline(response, &size, clientFile) == -1)
        return -1;

    return parseAnswer(*response, ".RUN_ME\n");
}

int level7(FILE* clientFile, char** response, size_t size) {
    printf("Filter error\n\n");

    char* answer = "K5n2UFfpFMUN";
    int length = strlen(answer);

    for (size_t i = 0; i < length; i++) {
        printf("%c", answer[i]);
        for (size_t j = 0; j < (rand() % (20 - 6 + 1)) + 6; j++) {
            char a = (rand() % (122 - 65 + 1)) + 65;
            char aux[2] = {a, 0};
            write(2, aux, 1);
        }
    }
    printf("\n\n");

    toInvestigate("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?");

    if (getline(response, &size, clientFile) == -1)
        return -1;

    return parseAnswer(*response, "K5n2UFfpFMUN\n");
}

int level8(FILE* clientFile, char** response, size_t size) {
    printf("¿?\n\n");
    printf("\033[30;40mBUmyYq5XxXGt\033[0m\n\n");

    toInvestigate("¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?");

    if (getline(response, &size, clientFile) == -1)
        return -1;

    return parseAnswer(*response, "BUmyYq5XxXGt\n");
}

int level9(FILE* clientFile, char** response, size_t size) {
    printf(
        "Latexme\n\n"
        "Si\n"
        "\\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\n"
        "entonces\n"
        "y =\n\n");

    toInvestigate("sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?");

    if (getline(response, &size, clientFile) == -1)
        return -1;

    return parseAnswer(*response, "u^v\n");
}

int level10(FILE* clientFile, char** response, size_t size) {
    printf("quine.\n\n");

    int retStat = system("gcc quine.c -o quine");

    if (!retStat) {
        printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");
        retStat = system("./quine | diff - quine.c");
        if (retStat == 0) {
            printf("La respuesta es chin_chu_lan_cha\n\n");
        } else {
            printf("\n%s\n", "diff encontró diferencias.");
        }
    }
    if (retStat)
        printf("%s\n\n", "ENTER para reintentar.");

    toInvestigate("¿Qué es un RFC?");

    if (getline(response, &size, clientFile) == -1)
        return -1;

    return parseAnswer(*response, "chin_chu_lan_cha\n");
}

int level11(FILE* clientFile, char** response, size_t size) {
    printf("b gdbme y encontrá el valor mágico ENTER para reintentar.\n\n");

    gdbme();

    toInvestigate("¿Qué es un RFC?");

    if (getline(response, &size, clientFile) == -1)
        return -1;

    return parseAnswer(*response, "gdb_rules\n");
}

static void gdbme() {
    if (getpid() == 999) {
        printf("La respuesta es: gdb_rules\n\n");
    }
}

int level12(FILE* clientFile, char** response, size_t size) {
    printf("Me conoces.\n\n");

    printNums();

    toInvestigate("¿Fue divertido?");

    if (getline(response, &size, clientFile) == -1)
        return -1;

    return parseAnswer(*response, "normal\n");
}

static void printNums() {
    double aux1, aux2, num;
    //get two normally distributed values using box muller transform
    for (size_t i = 0; i < 1000; i++) {
        aux1 = (double)rand() / (double)((unsigned)RAND_MAX + 1);
        aux2 = (double)rand() / (double)((unsigned)RAND_MAX + 1);
        num = sqrt(-2 * log(aux1)) * cos(2 * M_PI * aux2);
        printf("%.6f ", num);
    }
    printf("\n\n");
}

static int parseAnswer(char* response, char* levelAnswer) {
    return strcmp(response, levelAnswer) == 0;
}

static void toInvestigate(const char* subject) {
    static char* header = "----- PREGUNTA PARA INVESTIGAR -----";
    printf("%s\n%s\n", header, subject);
}