#include "busca.h"
char* busca(agenda agenda, char* nome)  {
        if (strcmp(agenda.nome, nome) == 0)
            return agenda.endereco;
        else
            return 1;
}
