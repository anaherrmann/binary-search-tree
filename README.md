# Travessias em árvores binárias de busca com implementações iterativas e recursivas

Esse projeto foi implementado com o objetivo de comparar implementações recursivas e iterativas em árvores binárias de busca.

Na ciência da computação a travessia é o processo de percorrer uma vez todos os nós de uma árvore. 

Existem três formas de fazer isso:
- Pré-ordem: visita a raiz, o filho esquerdo e depois o filho direito
- Em ordem: visita o filho esquerdo, a raiz e o filho direito
- Pós-ordem: visita o filho esquerdo, o filho direito e a raiz

Neste trabalho foram implementadas as três travessias com as abordagens iterativas e recursivas para comparação no tempo de execução.

Biblioteca utilizada para contabilizar o tempo: *std::chrono::steady_clock::now()* da biblioteca *chrono*.

