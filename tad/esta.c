#include "esta.h"
int esta(agenda agenda, char* nome) {
    if (strcmp(agenda.nome, nome) == 0)
        return 0;
    else
        return 1;
}
