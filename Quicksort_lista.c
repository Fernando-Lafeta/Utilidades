// Criando a estrutura Candidato, correspondente ao conteudo da celula
typedef struct{
	int Inscricao;  //Numero da inscri��o
	char Cargo[30]; //Nome do cargo ao qual o candidato concorrer�
	int Pontuacao;  //Pontua��o obtida ap�s a corre��o da prova
	char *Gabarito; //Ponteiro que armazena o gabarito em forma de vetor char
	char Nome[51];  //Nome do candidato
	int NConcurso;  //Numero do concurso ao qual o candidato participa
}Candidato;

// Criando o tipo ApontadorLista, que � um ponteiro que aponta para o tipo celula
typedef struct celula *ApontadorLista;

//Redefine celula e define a estrutura , criando o tipo Celula
typedef struct celula{
	Candidato Item;  //Conte�do da celula
	ApontadorLista Prox; //ApontadorLista que aponta para a celula seguinte
	ApontadorLista Ant; //ApontadorLista que aponta para a celula anterior
	int Indice;   //Indice da celula (vai de 1 � n celulas), �til para fun��es do quicksort
}Celula;

//Cria a estrutura TipoLista, que ter� dois ApontadorListaes para ter
// a refer�ncia do inicio e fim da lista
typedef struct{
	ApontadorLista Primeiro; //Celula sem conte�do, apenas refer�ncia o in�cio da lista
	ApontadorLista Ultimo;
}TipoLista;



// ----------------------------------------------------------------------------------------------------------
// -------------------------------------------- FUN��ES PARA QUICKSORT --------------------------------------
// ----------------------------------------------------------------------------------------------------------

//Fun��o Quicksort que ordena lista decrescentemente em rela��o � pontua��o
void QuickSort(TipoLista *Lista){
	//Passando o ponteiro indicador da primeira celula com conte�do ,e a ultima e tamb�m a lista
	Ordena(Lista->Primeiro->Prox,Lista->Ultimo,Lista);
}
//Fun��o Ordena: ela � a respons�vel pelo gerenciamento da ordena��o das parti��es da lista
void Ordena(ApontadorLista Esquerda,ApontadorLista Direita,TipoLista *Lista){
	ApontadorLista i,j;

	Particao(Esquerda,Direita,&i,&j,Lista);
	//Se o Indice do ApontadorLista Esquerda for menor que o indice do ApontadorLista J
	//significa que ainda falta ordenar uma parte da lista , ser� feita uma nova
	//particiao a ordenar
	if(Esquerda->Indice < j->Indice){
		//A lista particionada ser� de Esquerda at� J
		Ordena(Esquerda,j,Lista);
	}
	//Se o Indice do ApontadorLista i for menor que o indice do ApontadorLista Direita
	//significa que ainda falta ordenar uma parte da lista , ser� feita uma nova
	//particiao a ordenar
	if(i->Indice < Direita->Indice){
		//A lista particionada ser� de i at� Direita
		Ordena(i,Direita,Lista);
	}
}

//Fun��o Parti��o que � onde � feita as trocas dos item das celulas em rela��o ao piv�
void Particao(ApontadorLista Esquerda, ApontadorLista Direita, ApontadorLista *i, ApontadorLista *j, TipoLista *Lista){
	int Pivo,avancar,cont=1;
	//ApontadorLista Aux utilizado para chegar at� a celula piv�
	ApontadorLista Aux;
	//Variavel tempor�ria para auxiliar nas trocas
	Candidato X;

	*i=Esquerda;
	*j=Direita;

	//Encontra o indice que a celula piv� estar�
	avancar=((**i).Indice + (**j).Indice)/2;
	//Aux aponta para onde *i aponta , que � o in�cio da parti��o da lista
	Aux=*i;
	cont=(**i).Indice;
	//Avan�a aux at� a posi��o da celula piv�
	while(cont<avancar){
		Aux=Aux->Prox;
		cont++;
	}
	//Pivo recebe a pontua��o da celula pivo
	Pivo=Aux->Item.Pontuacao;
	do{
		//Caso a pontua��o da celula que o ApontadorLista i aponta for maior que a pontua�ao do pivo
		//Ent�o a celula est� na posi��o temporariamente correta e o ApontadorLista i ir� passar para celula seguinte
		//Quando houver uma celula com pontua��o menor do que a do pivo, o loop � finalizado
		//e ApontadorLista i estar� apontando para uma celula que ter� seu item trocado posteriormente
		while(Pivo < (**i).Item.Pontuacao){
			*i = (**i).Prox;
		}
		//Caso a pontua��o da celula que o ApontadorLista j aponta for menor que a pontua�ao do pivo
		//Ent�o a celula est� na posi��o temporariamente correta e o ApontadorLista j ir� passar para celula anterior
		//Quando houver uma celula com pontua��o maior do que a do pivo, o loop � finalizado
		//e ApontadorLista j estar� apontando para uma celula que ter� seu item trocado posteriormente
		while(Pivo > (**j).Item.Pontuacao){
			*j = (**j).Ant;
		}

		//Caso o Indice dos ApontadorListaes i e j n�o se cruzaram ent�o � feita a troca dos itens
		//e o ApontadorLista i apontar� para celula seguinte e o ApontadorLista j apontar� para celula anterior
		if((**i).Indice <= (**j).Indice){
			X = (**i).Item;
			(**i).Item = (**j).Item;
			(**j).Item = X;
			//Caso o pr�ximo de i seja NULL ent�o o i chegou ao fim da lista e a funcao particao deve ser finalizada
			if((**i).Prox == NULL)
				return;
			else
				*i = (**i).Prox;

			//Caso o anterior de j seja O Lista->Primeiro ent�o o j chegou a celula cabe�a e a funcao particao deve ser finalizada
			if((**j).Ant == Lista->Primeiro)
				return;
			else
				*j = (**j).Ant;
		}
		//Loop ir� "rodar" at� que os ApontadorListaes se cruzem
	}while((**i).Indice <= (**j).Indice);

	return;
}

//Fun��o que coloca �ndice nas celulas de 1 a n
//Esse �ndice � utilizado pelo algoritmo de ordena��o quicksort

void ColocaIndice(TipoLista *Lista){
	ApontadorLista aux;
	int i=1;

	if (TesteListaVazia(*Lista)){
		return;
	}

	aux = Lista->Primeiro->Prox;
	while (aux != NULL){
		aux->Indice=i;
		aux = aux->Prox;
		i++;
	}
}
