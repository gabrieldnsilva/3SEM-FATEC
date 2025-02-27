<h1>Modelagem Lógica de Banco de Dados</h1>

<h2 align="center">Introdução</h2>

<div>
<p>A modelagem lógica de banco de dados é uma etapa crucial no desenvolvimento de sistemas de informação. Ela envolve a criação de um modelo que representa a estrutura lógica dos dados, utilizando conceitos como MER (Modelo Entidade-Relacionamento) e DER (Diagrama Entidade-Relacionamento)
<div align="center">    
<img src="https://leonardofonseca.com.br/wp-content/uploads/2021/04/image.png" alt = "Modelo Entidade Relacionamento" width = 50% height= 45%/>.
<img src="https://arquivo.devmedia.com.br/artigos/Joel_Rodrigues/mer/image001.png" alt = "Diagrama Entidade Relacionamento" width= 40% height= 45%/>.
</div></p>
</div>
<h2 align="center">Componentes de uma Modelagem Lógica</h2>

<div>
    <h3>Entidades</h3>
        <p>Entidades são objetos ou conceitos do mundo real que possuem existência independente. Elas são representadas por retângulos no diagrama ER.</p>
</div>

<div>
    <h3>Atributos</h3>
        <p>Atributos são propriedades ou características das entidades. Eles são representados por elipses no diagrama ER.</p>
</div>

<div>
    <ul>
    <li><b>Atributo Multivalorado</b>: Um atributo que pode ter múltiplos valores. Representado por uma elipse dupla.</li>
    <li><b>Atributo Composto</b>: Um atributo que pode ser subdividido em outros atributos. Representado por uma elipse com subdivisões.</li>
    <li><b>Atributo Derivado</b>: Um atributo cujo valor pode ser derivado de outros atributos. Representado por uma elipse tracejada.</li>
    </ul>
</div>

<div>
    <h3>Chaves</h3>
        <ul>
            <li><b>Chave Primária</b>: Um atributo ou conjunto de atributos que identifica unicamente uma entidade. Representado por um sublinhado.</li>
            <li><b>Chave Estrangeira</b>: Um atributo que cria um vínculo entre duas entidades. Representado por uma linha que conecta duas entidades.</li>
        </ul>
</div>

<div>
    <h3>Domínios</h3>
        <p>Domínios são conjuntos de valores possíveis que um atributo pode assumir.</p>
</div>

<div>
    <h3>Relacionamentos</h3>
        <p>Relacionamentos descrevem como as entidades estão associadas umas às outras. Eles são representados por losangos no diagrama ER.
        </p>
</div>

<div>
    <ul>
        <li><b>Relacionamento com Identificação</b>: Relacionamento que depende da existência de outra entidade.</li>
        <li><b>Relacionamento sem Identificação</b>: Relacionamento que não depende da existência de outra entidade.</li>
        <li><b>Atributo de Relacionamento</b>: Atributos que pertencem ao relacionamento e não às entidades.</li>
    </ul>
</div>

<div>
    <h3>Graus de Relacionamento</h3>
        <p>O grau de um relacionamento indica o número de entidades envolvidas no relacionamento.</p>
</div>

<div>
    <h3>Entidades Fortes e Fracas</h3>
        <ul>
            <li><b>Entidade Forte</b>: Entidade que possui uma chave primária própria.</li>
            <li><b>Entidade Fraca</b>: Entidade que depende de outra entidade para sua identificação. Representada por um retângulo duplo.</li>
        </ul>
</div>

<h2>Exemplos de Símbolos do Modelo ER</h2>

<p><img src="https://example.com/entity.png" alt="Entidade" style="width: 100px;"></p>
<p><img src="https://example.com/attribute.png" alt="Atributo" style="width: 100px;"></p>
<p><img src="https://example.com/relationship.png" alt="Relacionamento" style="width: 100px;"></p>

<h2>Cardinalidade</h2>

<p>A cardinalidade define o número de ocorrências de uma entidade que podem estar associadas a uma ocorrência de outra entidade.</p>

<ul>
  <li><b>1:1 (Um para Um)</b>: Uma ocorrência de uma entidade está associada a uma ocorrência de outra entidade.</li>
  <li><b>1:N (Um para Muitos)</b>: Uma ocorrência de uma entidade está associada a várias ocorrências de outra entidade.</li>
  <li><b>N:M (Muitos para Muitos)</b>: Várias ocorrências de uma entidade estão associadas a várias ocorrências de outra entidade.</li>
</ul>

<hr>

<p>Esta documentação cobre os conceitos básicos de modelagem lógica de banco de dados até o ponto de cardinalidade. Sinta-se à vontade para ajustar e expandir conforme necessário.</p>
