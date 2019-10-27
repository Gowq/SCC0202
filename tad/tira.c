#include "tira.h"
int tira(agenda agenda,char* nome)  {
    if (strcmp(agenda.nome, nome) == 0) {
        agenda.nome = "";
        return 0;
    } else
        return 1;
}
