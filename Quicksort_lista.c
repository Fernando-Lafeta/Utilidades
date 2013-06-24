// Criando a estrutura Candidato, correspondente ao conteudo da celula
typedef struct{
	int Inscricao;  //Numero da inscrição
	char Cargo[30]; //Nome do cargo ao qual o candidato concorrerá
	int Pontuacao;  //Pontuação obtida após a correção da prova
	char *Gabarito; //Ponteiro que armazena o gabarito em forma de vetor char
	char Nome[51];  //Nome do candidato
	int NConcurso;  //Numero do concurso ao qual o candidato participa
}Candidato;

// Criando o tipo ApontadorLista, que é um ponteiro que aponta para o tipo celula
typedef struct celula *ApontadorLista;

//Redefine celula e define a estrutura , criando o tipo Celula
typedef struct celula{
	Candidato Item;  //Conteúdo da celula
	ApontadorLista Prox; //ApontadorLista que aponta para a celula seguinte
	ApontadorLista Ant; //ApontadorLista que aponta para a celula anterior
	int Indice;   //Indice da celula (vai de 1 à n celulas), útil para funções do quicksort
}Celula;

//Cria a estrutura TipoLista, que terá dois ApontadorListaes para ter
// a referência do inicio e fim da lista
typedef struct{
	ApontadorLista Primeiro; //Celula sem conteúdo, apenas referência o início da lista
	ApontadorLista Ultimo;
}TipoLista;



// ----------------------------------------------------------------------------------------------------------
// -------------------------------------------- FUNÇÕES PARA QUICKSORT --------------------------------------
// ----------------------------------------------------------------------------------------------------------

//Função Quicksort que ordena lista decrescentemente em relação à pontuação
void QuickSort(TipoLista *Lista){
	//Passando o ponteiro indicador da primeira celula com conteúdo ,e a ultima e também a lista
	Ordena(Lista->Primeiro->Prox,Lista->Ultimo,Lista);
}
//Função Ordena: ela é a responsável pelo gerenciamento da ordenação das partições da lista
void Ordena(ApontadorLista Esquerda,ApontadorLista Direita,TipoLista *Lista){
	ApontadorLista i,j;

	Particao(Esquerda,Direita,&i,&j,Lista);
	//Se o Indice do ApontadorLista Esquerda for menor que o indice do ApontadorLista J
	//significa que ainda falta ordenar uma parte da lista , será feita uma nova
	//particiao a ordenar
	if(Esquerda->Indice < j->Indice){
		//A lista particionada será de Esquerda até J
		Ordena(Esquerda,j,Lista);
	}
	//Se o Indice do ApontadorLista i for menor que o indice do ApontadorLista Direita
	//significa que ainda falta ordenar uma parte da lista , será feita uma nova
	//particiao a ordenar
	if(i->Indice < Direita->Indice){
		//A lista particionada será de i até Direita
		Ordena(i,Direita,Lista);
	}
}

//Função Partição que é onde é feita as trocas dos item das celulas em relação ao pivô
void Particao(ApontadorLista Esquerda, ApontadorLista Direita, ApontadorLista *i, ApontadorLista *j, TipoLista *Lista){
	int Pivo,avancar,cont=1;
	//ApontadorLista Aux utilizado para chegar até a celula pivô
	ApontadorLista Aux;
	//Variavel temporária para auxiliar nas trocas
	Candidato X;

	*i=Esquerda;
	*j=Direita;

	//Encontra o indice que a celula pivô estará
	avancar=((**i).Indice + (**j).Indice)/2;
	//Aux aponta para onde *i aponta , que é o início da partição da lista
	Aux=*i;
	cont=(**i).Indice;
	//Avança aux até a posição da celula pivô
	while(cont<avancar){
		Aux=Aux->Prox;
		cont++;
	}
	//Pivo recebe a pontuação da celula pivo
	Pivo=Aux->Item.Pontuacao;
	do{
		//Caso a pontuação da celula que o ApontadorLista i aponta for maior que a pontuaçao do pivo
		//Então a celula está na posição temporariamente correta e o ApontadorLista i irá passar para celula seguinte
		//Quando houver uma celula com pontuação menor do que a do pivo, o loop é finalizado
		//e ApontadorLista i estará apontando para uma celula que terá seu item trocado posteriormente
		while(Pivo < (**i).Item.Pontuacao){
			*i = (**i).Prox;
		}
		//Caso a pontuação da celula que o ApontadorLista j aponta for menor que a pontuaçao do pivo
		//Então a celula está na posição temporariamente correta e o ApontadorLista j irá passar para celula anterior
		//Quando houver uma celula com pontuação maior do que a do pivo, o loop é finalizado
		//e ApontadorLista j estará apontando para uma celula que terá seu item trocado posteriormente
		while(Pivo > (**j).Item.Pontuacao){
			*j = (**j).Ant;
		}

		//Caso o Indice dos ApontadorListaes i e j não se cruzaram então é feita a troca dos itens
		//e o ApontadorLista i apontará para celula seguinte e o ApontadorLista j apontará para celula anterior
		if((**i).Indice <= (**j).Indice){
			X = (**i).Item;
			(**i).Item = (**j).Item;
			(**j).Item = X;
			//Caso o próximo de i seja NULL então o i chegou ao fim da lista e a funcao particao deve ser finalizada
			if((**i).Prox == NULL)
				return;
			else
				*i = (**i).Prox;

			//Caso o anterior de j seja O Lista->Primeiro então o j chegou a celula cabeça e a funcao particao deve ser finalizada
			if((**j).Ant == Lista->Primeiro)
				return;
			else
				*j = (**j).Ant;
		}
		//Loop irá "rodar" até que os ApontadorListaes se cruzem
	}while((**i).Indice <= (**j).Indice);

	return;
}

//Função que coloca índice nas celulas de 1 a n
//Esse índice é utilizado pelo algoritmo de ordenação quicksort

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
