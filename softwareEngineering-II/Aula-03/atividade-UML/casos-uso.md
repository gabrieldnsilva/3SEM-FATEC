<h1>Caso de Uso: Fazer Pedido</h1>
    <section>
        <h2>Ator(es)</h2>
        <ul>
            <li><strong>Principal:</strong> Cliente</li>
            <li><strong>Secundário:</strong> Sistema de Gerenciamento de Pedidos</li>
        </ul>
    </section>
    <section>
        <h2>Descrição</h2>
        <p>Este caso de uso descreve o processo pelo qual o cliente realiza um pedido de produtos ou serviços. Inclui a seleção dos itens, confirmação de dados e finalização do pedido, com as devidas validações e feedback ao usuário.</p>
    </section>
    <section>
        <h2>Pré-Condições</h2>
        <ul>
            <li>O cliente deve estar autenticado no sistema.</li>
            <li>O catálogo de produtos ou serviços deve estar atualizado.</li>
            <li>O sistema deve estar operacional e configurado para gerenciar pedidos.</li>
            <li>Cliente deve estar visualizando o cardápio de um restaurante.</li>
        </ul>
    </section>
    <section>
        <h2>Fluxo Principal</h2>
        <ol>
            <li>O cliente acessa a funcionalidade "Fazer Pedido" no sistema.</li>
            <li>O sistema apresenta a lista de categorias e/ou itens disponíveis.</li>
            <li>O cliente seleciona os itens desejados e os adiciona ao carrinho.</li>
            <li>O sistema exibe o resumo do pedido, com quantidades e preços.</li>
            <li>O cliente revisa e confirma os itens selecionados.</li>
            <li>O cliente seleciona o endereço de entrega.</li>
            <li>O sistema solicita a confirmação do pedido e informações de pagamento.</li>
            <li>O cliente seleciona a forma de pagamento.</li>
            <li>O cliente confirma os dados e finaliza o pedido.</li>
            <li>O sistema processa a solicitação, grava as informações e retorna uma mensagem de confirmação com o número do pedido.</li>
            <li>O cliente recebe a confirmação do pedido por meio do sistema e, opcionalmente, por e-mail ou SMS.</li>
            <li>O sistema encaminha o pedido para o restaurante.</li>
        </ol>
    </section>
    <section>
        <h2>Fluxos Alternativos</h2>
        <article>
            <h3>A1 – Erro na Autenticação</h3>
            <p>Caso o cliente não esteja autenticado:</p>
            <ol>
                <li>O sistema redireciona o usuário para a tela de login.</li>
                <li>Após a autenticação, o cliente é redirecionado de volta ao processo de pedido.</li>
            </ol>
        </article>
        <article>
            <h3>A2 – Produtos Indisponíveis</h3>
            <p>Se durante a seleção algum item estiver indisponível:</p>
            <ol>
                <li>O sistema informa ao cliente que o item não está disponível.</li>
                <li>O cliente pode remover o item ou selecionar um substituto.</li>
            </ol>
        </article>
        <article>
            <h3>A3 – Problemas no Processamento do Pagamento</h3>
            <p>Se o pagamento for recusado ou houver falha na transação:</p>
            <ol>
                <li>O sistema exibe uma mensagem de erro informando o problema.</li>
                <li>O cliente é solicitado a fornecer outros dados de pagamento ou tentar novamente.</li>
            </ol>
        </article>
        <article>
            <h3>A4 - Restaurante Fechado</h3>
            <p>Quando o restaurante não está aceitando pedidos:</p>
            <ol>
                <li>O sistema notifica que o restaurante não está aceitando pedidos.</li>
                <li>Cliente é informado sobre o horário de funcionamento do restaurante.</li>
            </ol>
        </article>
    </section>
    <section>
        <h2>Pós-Condições</h2>
        <ul>
            <li>O pedido é registrado no sistema, aguardando a confirmação e processamento.</li>
            <li>O estado do pedido atualiza-se para "Aguardando Processamento" até a sua efetivação.</li>
            <li>Pedido é encaminhado para o restaurante.</li>
        </ul>
    </section>
    <section>
        <h2>Requisitos Especiais</h2>
        <ul>
            <li>Interface responsiva para facilitar o uso em diversos dispositivos.</li>
            <li>Validações em tempo real para evitar a inclusão de itens inválidos.</li>
            <li>Segurança dos dados do cliente durante o processo de autenticação e pagamento.</li>
        </ul>
    </section>
    <section>
        <h2>Pontos de Extensão</h2>
        <ul>
            <li>Integração com sistemas de pagamento externos.</li>
            <li>Confirmação por meio de notificações (e-mail, SMS, push notification).</li>
            <li>Rastreamento do status do pedido.</li>
        </ul>
    </section>
