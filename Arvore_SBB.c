/*
    Autor: Fernando Lafetá

    Descrição: Programa com funções de árvore SBB e com o diferencial da possibilidade
               de mostrar a árvore no formato visual de árvore (até 5 níveis)


    Nota 1: Para a inserção por arquivo, criar arquivo com nome "dados.txt" e colocar
            apenas uma chave por linha no arquivo.

    Nota 2: É necessário ter instalada a biblioteca conio2.h


*/

#include <sys/time.h>
#include<stdlib.h>
#include<stdio.h>
#include <conio2.h>
#include <math.h>
#define TRUE  1
#define FALSE 0
#define max  10

typedef int TipoChave;

typedef struct Registro {
	/* outros componentes */
	TipoChave Chave;
} Registro;
typedef enum {
	Vertical, Horizontal
} Inclinacao;

typedef struct No* Apontador;

typedef struct No {
	Registro Reg;
	Apontador Esq, Dir;
	Inclinacao BitE, BitD;
	int Nivel;
	int Indice;
} No;

void EE(Apontador *Ap){
	Apontador Ap1;
	Ap1 = (*Ap)->Esq;
	(*Ap)->Esq = Ap1->Dir;
	Ap1->Dir = *Ap;
	Ap1->BitE = Vertical;
	(*Ap)->BitE = Vertical;
	*Ap = Ap1;
}

void ED(Apontador *Ap){
	Apontador Ap1, Ap2;
	Ap1 = (*Ap)->Esq;
	Ap2 = Ap1->Dir;
	Ap1->BitD = Vertical;
	(*Ap)->BitE = Vertical;
	Ap1->Dir = Ap2->Esq;
	Ap2->Esq = Ap1;
	(*Ap)->Esq = Ap2->Dir;
	Ap2->Dir = *Ap;
	*Ap = Ap2;
}

void DD(Apontador *Ap){
	Apontador Ap1;
	Ap1 = (*Ap)->Dir;
	(*Ap)->Dir = Ap1->Esq;
	Ap1->Esq = *Ap;
	Ap1->BitD = Vertical;
	(*Ap)->BitD = Vertical;
	*Ap = Ap1;
}

void DE(Apontador *Ap){
	Apontador Ap1, Ap2;
	Ap1 = (*Ap)->Dir;
	Ap2 = Ap1->Esq;
	Ap1->BitE = Vertical;
	(*Ap)->BitD = Vertical;
	Ap1->Esq = Ap2->Dir;
	Ap2->Dir = Ap1;
	(*Ap)->Dir = Ap2->Esq;
	Ap2->Esq = *Ap;
	*Ap = Ap2;
}

void IInsere(Registro x, Apontador *Ap, Inclinacao *IAp, short *Fim){
	if (*Ap == NULL){
		*Ap = (Apontador)malloc(sizeof(No));
		*IAp = Horizontal;
		(*Ap)->Reg = x;
		(*Ap)->BitE = Vertical;
		(*Ap)->BitD = Vertical;
		(*Ap)->Esq = NULL;
		(*Ap)->Dir = NULL;
		(*Ap)->Indice = -1;
		*Fim = FALSE;
		return;
	}
	if (x.Chave < (*Ap)->Reg.Chave){
		IInsere(x, &(*Ap)->Esq, &(*Ap)->BitE, Fim);
		if (*Fim)
			return;
		if ((*Ap)->BitE != Horizontal){
			*Fim = TRUE;
			return;
		}
		if ((*Ap)->Esq->BitE == Horizontal){
			EE(Ap);
			*IAp = Horizontal;
			return;
		}
		if ((*Ap)->Esq->BitD == Horizontal){
			ED(Ap);
			*IAp = Horizontal;
		}
		return;
	}
	if (x.Chave <= (*Ap)->Reg.Chave){
		printf("Erro: Chave ja esta na arvore\n");
		getch();
		*Fim = TRUE;
		return;
	}
	IInsere(x, &(*Ap)->Dir, &(*Ap)->BitD, Fim);
	if (*Fim)
		return;
	if ((*Ap)->BitD != Horizontal){
		*Fim = TRUE;  return;
	}
	if ((*Ap)->Dir->BitD == Horizontal){
		DD(Ap);
		*IAp = Horizontal;
		return;
	}
	if ((*Ap)->Dir->BitE == Horizontal){
		DE(Ap);
		*IAp = Horizontal;
	}
}

void Insere(Registro x, Apontador *Ap){
	short Fim;
	Inclinacao IAp;
	IInsere(x, Ap, &IAp, &Fim);
}

void Inicializa(Apontador *Dicionario){
	*Dicionario = NULL;
}

void EsqCurto(Apontador *Ap, short *Fim){
	/* Folha esquerda retirada => arvore curta na altura esquerda */
	Apontador Ap1;
	if ((*Ap)->BitE == Horizontal){
		(*Ap)->BitE = Vertical;
		*Fim = TRUE;
		return;
	}
	if ((*Ap)->BitD == Horizontal){
		Ap1 = (*Ap)->Dir;
		(*Ap)->Dir = Ap1->Esq;
		Ap1->Esq = *Ap;
		*Ap = Ap1;
		if ((*Ap)->Esq->Dir->BitE == Horizontal){
			DE(&(*Ap)->Esq);
			(*Ap)->BitE = Horizontal;
		}
		else
			if ((*Ap)->Esq->Dir->BitD == Horizontal){
				DD(&(*Ap)->Esq);
				(*Ap)->BitE = Horizontal;
			}
			*Fim = TRUE;
			return;
	}
	(*Ap)->BitD = Horizontal;
	if ((*Ap)->Dir->BitE == Horizontal){
		DE(Ap);
		*Fim = TRUE;
		return;
	}
	if ((*Ap)->Dir->BitD == Horizontal){
		DD(Ap);
		*Fim = TRUE;
	}
}

void DirCurto(Apontador *Ap, short *Fim){
	/* Folha direita retirada => arvore curta na altura direita */
	Apontador Ap1;
	if ((*Ap)->BitD == Horizontal){
		(*Ap)->BitD = Vertical;
		*Fim = TRUE;
		return;
	}
	if ((*Ap)->BitE == Horizontal){
		Ap1 = (*Ap)->Esq;
		(*Ap)->Esq = Ap1->Dir;
		Ap1->Dir = *Ap;
		*Ap = Ap1;
		if ((*Ap)->Dir->Esq->BitD == Horizontal){
			ED(&(*Ap)->Dir);
			(*Ap)->BitD = Horizontal;
		}
		else if ((*Ap)->Dir->Esq->BitE == Horizontal){
			EE(&(*Ap)->Dir);
			(*Ap)->BitD = Horizontal;
		}
		*Fim = TRUE;
		return;
	}
	(*Ap)->BitE = Horizontal;
	if ((*Ap)->Esq->BitD == Horizontal){
		ED(Ap);
		*Fim = TRUE;
		return;
	}
	if ((*Ap)->Esq->BitE == Horizontal){
		EE(Ap);
		*Fim = TRUE;
	}
}

void Antecessor(Apontador q, Apontador *r, short *Fim){
	if ((*r)->Dir != NULL){
		Antecessor(q, &(*r)->Dir, Fim);
		if (!*Fim)
			DirCurto(r, Fim);
		return;
	}
	q->Reg = (*r)->Reg;
	q = *r;
	*r = (*r)->Esq;
	free(q);
	if (*r != NULL)
		*Fim = TRUE;
}

void IRetira(Registro x, Apontador *Ap, short *Fim){
	No *Aux;
	if (*Ap == NULL){
		printf("Chave nao esta na arvore\n");
		*Fim = TRUE;
		return;
		}
	if (x.Chave < (*Ap)->Reg.Chave){
		IRetira(x, &(*Ap)->Esq, Fim);
		if (!*Fim)
			EsqCurto(Ap, Fim);
		return;
	}
	if (x.Chave > (*Ap)->Reg.Chave){
		IRetira(x, &(*Ap)->Dir, Fim);
		if (!*Fim)
			DirCurto(Ap, Fim);
		return;
	}
	*Fim = FALSE;
	Aux = *Ap;
	if (Aux->Dir == NULL){
		*Ap = Aux->Esq;
		free(Aux);
		if (*Ap != NULL)
			*Fim = TRUE;
		return;
	}
	if (Aux->Esq == NULL){
		*Ap = Aux->Dir; free(Aux);
		if (*Ap != NULL)
			*Fim = TRUE;
		return;
	}
	Antecessor(Aux, &Aux->Esq, Fim);
	if (!*Fim)
		EsqCurto(Ap, Fim); /* Encontrou chave */
}

void Retira(Registro x, Apontador *Ap){
	short Fim;
	IRetira(x, Ap, &Fim);
}

void Pesquisa(Registro *x, Apontador *p, int *sucesso){
	if (*p == NULL){
		printf("\n\n ==> Chave nao encontrada\n\n");
		*sucesso = 0;
		return;
	}
	if (x->Chave < (*p)->Reg.Chave){
		Pesquisa(x, &(*p)->Esq,sucesso);
		return;
	}
	else if (x->Chave > (*p)->Reg.Chave){
		Pesquisa(x, &(*p)->Dir,sucesso);
        return;
	}
	else{
		*x = (*p)->Reg;
		*sucesso = 1;
		return;
	}
}

void Testa1(Apontador p, int nivel, int *NivelFolhas, short *PrimeiraFolha){
	if (p == NULL)
		return;
	if (*PrimeiraFolha)
		if (*NivelFolhas < nivel)
			*NivelFolhas = nivel;
	if (p->Esq == NULL && p->Dir == NULL){
		if (*PrimeiraFolha == TRUE)
			*PrimeiraFolha = FALSE;
		else{
			if (nivel != *NivelFolhas){
				printf("Erro: Folhas em niveis diferentes\n");
				exit(1);
			}
		}
	}
	if (p->BitE == Horizontal)
		Testa1(p->Esq, nivel, NivelFolhas, PrimeiraFolha);
	else
		Testa1(p->Esq, nivel + 1, NivelFolhas, PrimeiraFolha);
	if (p->BitD == Horizontal)
		Testa1(p->Dir, nivel, NivelFolhas, PrimeiraFolha);
	else
		Testa1(p->Dir, nivel + 1, NivelFolhas, PrimeiraFolha);
}

void Testa2(Apontador p, int *NivelFolhas, short *PrimeiraFolha){
	if (p == NULL)
		return;
	if (p->Esq != NULL){
		if (p->Reg.Chave < p->Esq->Reg.Chave){
			printf("Erro: %d < que filho a esquerda \n", p->Reg.Chave);
			exit(1);
		}
		Testa2(p->Esq, NivelFolhas, PrimeiraFolha);
	}
	if (p->Dir == NULL)
		return;
	if (p->Reg.Chave > p->Dir->Reg.Chave){
		printf("Erro: %d > que filho a direita \n", p->Reg.Chave);
		exit(1);
	}
	Testa2(p->Dir, NivelFolhas, PrimeiraFolha);
}

void Testa(Apontador Arvore){
	int NivelFolhas = 0;
	short PrimeiraFolha = TRUE;
	Testa1(Arvore, 1, &NivelFolhas, &PrimeiraFolha);
	Testa2(Arvore, &NivelFolhas, &PrimeiraFolha);
}



double rand0a1() {
	double resultado=  (double) rand()/ RAND_MAX; /* Dividir pelo maior inteiro */
	if(resultado>1.0) resultado= 1.0;
	return resultado;
}

void Permut(int *A, int n){
    /* Obtem permutacao randomica dos numeros entre 1 e n */
	int  i, j, b;

	for (i = n; i >= 1; i--) {
		j = (int)(i * rand0a1()  + 1);
		b = A[i-1];
		A[i-1] = A[j-1];
		A[j-1] = b;
	}
}

void Em_Ordem(Apontador No){

    if(No == NULL)
       return;

    Em_Ordem(No->Esq);
    printf("\n%d", No->Reg.Chave);
    Em_Ordem(No->Dir);

    return;
}

void Pre_Ordem(Apontador No){

    if(No == NULL)
       return;

    printf("\n%d", No->Reg.Chave);
    //printf("\n%d", No->Indice);
    Pre_Ordem(No->Esq);
    Pre_Ordem(No->Dir);


    return;
}

void Pos_Ordem(Apontador No){

    if(No == NULL)
       return;

    Pos_Ordem(No->Esq);
    Pos_Ordem(No->Dir);
    printf("\n%d", No->Reg.Chave);

    return;
}



void DesalocarArvore(Apontador *No){

    if((*No) == NULL)
       return;

    DesalocarArvore(&((*No)->Esq));
    DesalocarArvore(&((*No)->Dir));
    free(*No);

    return;
}


void Formato_Arvore(Apontador Aux){
    int Espaco,i,s,y;

    if(Aux == NULL  || Aux->Nivel>=6)
       return;

    Espaco = 80/pow(2,Aux->Nivel);
    i= pow(2,Aux->Nivel-1);

    if(Aux->Nivel==1)
        gotoxy(1,2);
    else if (Aux->Nivel==2)
        gotoxy(1,10);
    else if (Aux->Nivel==3)
        gotoxy(1,14);
    else if (Aux->Nivel==4)
        gotoxy(1,16);
    else if (Aux->Nivel==5)
        gotoxy(1,18);


    while(i<Aux->Indice){

         gotoxy(Espaco+wherex(),wherey());
         gotoxy(Espaco+wherex(),wherey());
         i++;
    }

    if(Espaco==2) Espaco++;

    if(Aux->Indice == 18) Espaco+=2;
    else if(Aux->Indice == 19) Espaco+=2;
    else if(Aux->Indice == 20) Espaco+=4;
    else if(Aux->Indice == 21) Espaco+=4;
    else if(Aux->Indice == 22) Espaco+=6;
    else if(Aux->Indice == 23) Espaco+=6;
    else if(Aux->Indice == 24) Espaco+=8;
    else if(Aux->Indice == 25) Espaco+=8;
    else if(Aux->Indice == 26) Espaco+=10;
    else if(Aux->Indice == 27) Espaco+=10;
    else if(Aux->Indice == 28) Espaco+=12;
    else if(Aux->Indice == 29) Espaco+=12;
    else if(Aux->Indice == 30) Espaco+=14;
    else if(Aux->Indice == 31) Espaco+=14;
    else if(Aux->Indice == 32) Espaco+=14;


    s=Espaco+wherex();
    y=wherey();


    if(Aux->Indice%2==0){
        if(Aux->Nivel == 2){
            gotoxy(s+15,wherey()-8);
            printf("____");
            gotoxy(s+13,wherey()+1);
            printf("/");
            gotoxy(s+11,wherey()+1);
            printf("/");
            gotoxy(s+9,wherey()+1);
            printf("/");
            gotoxy(s+7,wherey()+1);
            printf("/");
            gotoxy(s+5,wherey()+1);
            printf("/");
            gotoxy(s+3,wherey()+1);
            printf("/");
            gotoxy(s+1,wherey()+1);
            printf("/");
        }
        if(Aux->Nivel == 3){
            gotoxy(s+7,wherey()-4);
            printf("__");
            gotoxy(s+6,wherey()+1);
            printf("/");
            gotoxy(s+4,wherey()+1);
            printf("/");
            gotoxy(s+2,wherey()+1);
            printf("/");
        }
        if(Aux->Nivel == 4){
            gotoxy(s+3,wherey()-2);
            printf("_");
            gotoxy(s+2,wherey()+1);
            printf("/");
        }
        if(Aux->Nivel == 5){
            gotoxy(s+1,wherey()-1);
            printf("/");
        }


    }
    else if(Aux->Indice!=1){
        if(Aux->Nivel == 2){
            gotoxy(s-17,wherey()-8);
            printf("___");
            gotoxy(s-13,wherey()+1);
            printf("\\");
            gotoxy(s-11,wherey()+1);
            printf("\\");
            gotoxy(s-9,wherey()+1);
            printf("\\");
            gotoxy(s-7,wherey()+1);
            printf("\\");
            gotoxy(s-5,wherey()+1);
            printf("\\");
            gotoxy(s-3,wherey()+1);
            printf("\\");
            gotoxy(s-1,wherey()+1);
            printf("\\");
        }
        if(Aux->Nivel == 3){
            gotoxy(s-9,wherey()-4);
            printf(" __");
            gotoxy(s-6,wherey()+1);
            printf("\\");
            gotoxy(s-4,wherey()+1);
            printf("\\");
            gotoxy(s-2,wherey()+1);
            printf("\\");
        }
        if(Aux->Nivel == 4){
            gotoxy(s-3,wherey()-2);
            printf(" _");
            gotoxy(s,wherey()+1);
            printf("\\");
        }
        if(Aux->Nivel == 5){
            gotoxy(s,wherey()-1);
            printf("\\");
        }
    }

    if(Aux->Esq != NULL)
        Formato_Arvore(Aux->Esq);

    if(Aux->Dir != NULL)
        Formato_Arvore(Aux->Dir);
        gotoxy(s,y);
    if(Aux->BitE == Horizontal)
        printf("(H)");
    printf("%2d",Aux->Reg.Chave);
    if(Aux->BitD == Horizontal)
        printf("(H)");
}

void ColocaNivel(Apontador *No, int Nivel){
    if(*No == NULL)
       return;

    if((*No)->Esq != NULL)
        ColocaNivel(&((*No)->Esq),Nivel+1);

    if((*No)->Dir != NULL)
        ColocaNivel(&((*No)->Dir),Nivel+1);

    (*No)->Nivel = Nivel;
}

void ColocaIndice(Apontador *No, int filho,Apontador Aux){
    if(*No == NULL)
       return;
    if( (*No)->Indice == -1 )
        (*No)->Indice = Aux->Indice*2+filho;

    if((*No)->Esq != NULL)
        ColocaIndice(&((*No)->Esq),0,*No);

    if((*No)->Dir != NULL)
        ColocaIndice(&((*No)->Dir),1,*No);

}

void ReiniciaIndice(Apontador *No){
    if(*No == NULL)
       return;

    (*No)->Indice = -1 ;


    if((*No)->Esq != NULL)
        ReiniciaIndice(&((*No)->Esq));

    if((*No)->Dir != NULL)
        ReiniciaIndice(&((*No)->Dir));

}

int main(int argc, char *argv[]){
	Apontador Arvore;
	Registro x;
	int  vetor[max];
	int i, j, k, n;
	int opcao,sucesso,linhas;
	char s[10],c;
	FILE *dados;
	Inicializa(&Arvore);

	while(1){
        system("cls");
        printf("\n     ARVORE\n\n\n [0] Ler dados do arquivo \n [1] Inserir n%c \n [2] Remover n%c \n [3] Buscar n%c \n "
               "[4] Mostrar arvore \n [5] Desalocar arvore \n [6] Sair",162,162,162);
        while(1){
            printf("\n\n Opcao: ");
            opcao = 0;
            fflush(stdin);
            if( (scanf("%d",&opcao)) != 0){
                if(opcao >=0 && opcao<=6){
                    break;
                }
            }
            printf("\n\n\n ====> OPCAO INVALIDA <===== \n\n");

        }
        if(opcao == 0){
            if( (dados = fopen("dados.txt","r")) != NULL){
                linhas=0;
                while( (c = fgetc(dados)) != EOF){
                    if(c == '\n')
                        linhas++;
                }
                rewind(dados);
                for(i=0; i<linhas; i++){
                    fgets(s,10,dados);
                    sscanf(s,"%d",&x.Chave);
                    Insere(x, &Arvore);
                }
                fclose(dados);
                printf("\n As chaves no arquivo foram inseridas na arvore");
            }
            else{
                printf("\n Nao foi possivel ler do arquivo");
            }
            getch();
        }

        if(opcao == 1){
            printf("\n Inserir chave: ");
            scanf("%d",&x.Chave);
            Insere(x, &Arvore);
            Testa(Arvore);
        }
        else if(opcao == 2){
            printf("\n Remover chave: ");
            scanf("%d",&x.Chave);
            Retira(x, &Arvore);
            Testa(Arvore);
            getch();
        }
        else if(opcao == 3){
            printf("\n Buscar chave: ");
            scanf("%d",&x.Chave);
            Pesquisa(&x, &Arvore, &sucesso);
            if(sucesso){
                printf("\n\n\n O registro de chave %d foi encontrado\n\n",x.Chave);
            }
            getch();
        }
        else if(opcao == 4){
            system("cls");
            printf("\n MOSTRAR ARVORE EM: \n\n [1] Pre-ordem \n [2] Pos-ordem \n [3] Em ordem  \n [4] Formato arvore\n\n\n");

            while(1){
                printf("\n\n Opcao: ");
                opcao = 0;
                fflush(stdin);
                if( (scanf("%d",&opcao)) != 0){
                    if(opcao >=1 && opcao<=4){
                        break;
                    }
                }
                printf("\n\n\n ====> OPCAO INVALIDA <===== \n\n");
            }
            system("cls");
            printf("\n\n Arvore: \n\n");
            if(opcao == 1){
                Pre_Ordem(Arvore);
            }
            else if(opcao == 2){
                Pos_Ordem(Arvore);
            }
            else if(opcao == 3){
                Em_Ordem(Arvore);
            }
            else{
                if(Arvore != NULL){
                    system("cls");

                    ReiniciaIndice(&Arvore);
                    Arvore->Nivel=1;
                    Arvore->Indice=1;
                    ColocaNivel(&Arvore,1);
                    ColocaIndice(&Arvore,0,Arvore);
                    Formato_Arvore(Arvore);


                }
            }
            getch();
        }
        else if( opcao == 5){
            DesalocarArvore(&Arvore);
            printf("\n Arvore desalocada");
            Arvore = NULL;
            getch();
        }
        else if(opcao == 6){
            break;
        }

	}


	return 0;
}
