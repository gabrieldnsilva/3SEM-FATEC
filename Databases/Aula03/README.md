<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Modelo Lógico para Sistema de Biblioteca</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 0 auto;
            max-width: 900px;
            padding: 20px;
        }
        header {
            border-bottom: 1px solid #ccc;
            margin-bottom: 20px;
        }
        section {
            margin-bottom: 30px;
        }
        .entity {
            background-color: #f9f9f9;
            border-left: 4px solid #0066cc;
            margin-bottom: 15px;
            padding: 10px 15px;
        }
        .relationship {
            margin-bottom: 10px;
        }
    </style>
</head>
<body>
    <header>
        <h1>Modelo Lógico para Sistema de Biblioteca</h1>
    </header> 
    <main>
        <section id="descricao">
            <h2>Descrição do Problema</h2>
            <p>Projete um esquema de Entidade Relacionamento (ER) – Modelo lógico para uma Biblioteca que mantém um acervo de itens que podem ser livros, CDs e DVDs.</p>
        </section>
        <section id="entidades">
            <h2>Entidades e Atributos</h2>
            <article class="entity">
                <h3>Item (Superclasse)</h3>
                <ul>
                    <li><strong>codigo</strong> (PK)</li>
                    <li>titulo</li>
                    <li>descricao</li>
                    <li>tipo_item (livro, cd, dvd)</li>
                    <li>estante_numero (FK)</li>
                    <li>fornecedor_codigo (FK)</li>
                </ul>
            </article>
            <article class="entity">
                <h3>Livro</h3>
                <ul>
                    <li><strong>codigo_item</strong> (PK/FK referenciando Item)</li>
                    <li>autores</li>
                    <li>assuntos</li>
                    <li>ano_publicacao</li>
                    <li>editora</li>
                </ul>
            </article>
            <article class="entity">
                <h3>CD</h3>
                <ul>
                    <li><strong>codigo_item</strong> (PK/FK referenciando Item)</li>
                    <li>produtora</li>
                    <li>ano</li>
                </ul>
            </article>
            <article class="entity">
                <h3>DVD</h3>
                <ul>
                    <li><strong>codigo_item</strong> (PK/FK referenciando Item)</li>
                    <li>produtora</li>
                    <li>diretor</li>
                    <li>atores_principais</li>
                </ul>
            </article>
            <article class="entity">
                <h3>Musica</h3>
                <ul>
                    <li><strong>id</strong> (PK)</li>
                    <li>nome</li>
                    <li>cantor</li>
                    <li>codigo_cd (FK referenciando CD)</li>
                </ul>
            </article>
            <article class="entity">
                <h3>Fornecedor</h3>
                <ul>
                    <li><strong>codigo</strong> (PK)</li>
                    <li>nome</li>
                    <li>endereco</li>
                </ul>
            </article>
            <article class="entity">
                <h3>Telefone_Fornecedor</h3>
                <ul>
                    <li><strong>id</strong> (PK)</li>
                    <li>codigo_fornecedor (FK)</li>
                    <li>telefone</li>
                </ul>
            </article>
            <article class="entity">
                <h3>Associado</h3>
                <ul>
                    <li><strong>numero</strong> (PK)</li>
                    <li>nome</li>
                    <li>endereco</li>
                    <li>fone</li>
                </ul>
            </article>
            <article class="entity">
                <h3>Funcionario</h3>
                <ul>
                    <li><strong>numero_cadastro</strong> (PK)</li>
                    <li>nome</li>
                    <li>endereco</li>
                    <li>sexo</li>
                </ul>
            </article>
            <article class="entity">
                <h3>Estante</h3>
                <ul>
                    <li><strong>numero</strong> (PK)</li>
                    <li>andar</li>
                    <li>sala</li>
                </ul>
            </article>
            <article class="entity">
                <h3>Emprestimo</h3>
                <ul>
                    <li><strong>id</strong> (PK)</li>
                    <li>associado_numero (FK)</li>
                    <li>item_codigo (FK)</li>
                    <li>data_emprestimo</li>
                    <li>data_devolucao</li>
                </ul>
            </article>
            <article class="entity">
                <h3>Verificacao</h3>
                <ul>
                    <li><strong>id</strong> (PK)</li>
                    <li>emprestimo_id (FK)</li>
                    <li>funcionario_numero (FK)</li>
                    <li>data</li>
                    <li>horario</li>
                    <li>item_danificado (boolean)</li>
                </ul>
            </article>
            <article class="entity">
                <h3>Responsabilidade</h3>
                <ul>
                    <li><strong>funcionario_numero</strong> (PK/FK)</li>
                    <li><strong>estante_numero</strong> (PK/FK)</li>
                </ul>
            </article>
        </section>
        <section id="relacionamentos">
            <h2>Relacionamentos</h2>
            <ol>
                <li class="relationship">Um <strong>Item</strong> é armazenado em uma única <strong>Estante</strong></li>
                <li class="relationship">Uma <strong>Estante</strong> pode armazenar vários <strong>Itens</strong></li>
                <li class="relationship">Um <strong>Item</strong> é fornecido por um <strong>Fornecedor</strong></li>
                <li class="relationship">Um <strong>Associado</strong> pode fazer vários <strong>Empréstimos</strong></li>
                <li class="relationship">Um <strong>Empréstimo</strong> se refere a um único <strong>Item</strong></li>
                <li class="relationship">Um <strong>Funcionário</strong> verifica um <strong>Empréstimo</strong> durante a devolução</li>
                <li class="relationship">Um <strong>Funcionário</strong> pode ser responsável por várias <strong>Estantes</strong></li>
                <li class="relationship">Um <strong>CD</strong> contém várias <strong>Músicas</strong></li>
            </ol>
        </section>
        <section id="diagrama">
            <h2>Diagrama ER - PlantUML</h2>
            <img src="/Aula03/assets/img/diagrama-er-plantuml.png" width=700px height=700px/>
            <h2>Diagrama ER - dbdiagram.io</h2>
            <img src="/Aula03/assets/img/diagrama-er-dbdiagramIO.png" width=700px height=700px/>
        </section>
    </main>
</body>
</html>
