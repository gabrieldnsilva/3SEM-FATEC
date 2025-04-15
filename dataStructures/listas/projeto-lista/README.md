Os primeiros conceitos foram criados baseados nos requisitos do arquivo "Aula 04 - Projeto.pdf".

De início, comecei pensando na base do programa, apenas a função de criação (CREATE) e a função de leitura (READ).
Assim, foram escritas as funções: criarLista, adicionarPessoa e imprimirPessoa.

No main, apenas as funções básicas, utilizando um ENUM para definir os tipos de operações e um loop para o menu utilizando switch case.
Porém, na tentativa de criar um main.c mais limpo, identifiquei certas dificuldades para manter o código organizado e somente importar funções de outros arquivos, tendo a princípio a ideia de implementar o que fosse necessário no próprio main.c .

Mas para evitar essa "má pratica" considerei utilizar de alguns conceitos vistos em POO, como encapsulamento e abstração, para criar uma estrutura de dados que representasse a lista de pessoas, utilizando controllers e interface para manipular essa lista.

Controller trabalharia com a lógica de manipulação da lista, enquanto a interface seria responsável por interagir com o usuário, recebendo entradas e exibindo saídas. Assim, o main.c poderia se concentrar em chamar essas funções e manter o fluxo do programa.
