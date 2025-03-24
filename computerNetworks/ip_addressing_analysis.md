# Análise de Exercícios de Endereçamento IP

<style>
    .correct {
        color: green;
        font-weight: bold;
    }
    .incorrect {
        color: red;
        font-weight: bold;
    }
    .explanation {
        background-color: #f8f8f8;
        padding: 10px;
        border-left: 3px solid #2196F3;
        margin: 10px 0;
    }
    table {
        border-collapse: collapse;
        width: 100%;
        margin: 15px 0;
    }
    th, td {
        border: 1px solid #ddd;
        padding: 8px;
        text-align: left;
    }
    th {
        background-color: #f2f2f2;
    }
    .note {
        font-style: italic;
        color: #666;
    }
</style>

## Revisão de Conceitos

### Classes de Endereço IP

| Classe           | Primeiro Octeto | Range Binário | Faixa de Endereços          | Máscara Padrão      |
| ---------------- | --------------- | ------------- | --------------------------- | ------------------- |
| A                | 0-127           | 0xxxxxxx      | 0.0.0.0 - 127.255.255.255   | 255.0.0.0 (/8)      |
| B                | 128-191         | 10xxxxxx      | 128.0.0.0 - 191.255.255.255 | 255.255.0.0 (/16)   |
| C                | 192-223         | 110xxxxx      | 192.0.0.0 - 223.255.255.255 | 255.255.255.0 (/24) |
| D (Multicast)    | 224-239         | 1110xxxx      | 224.0.0.0 - 239.255.255.255 | N/A                 |
| E (Experimental) | 240-255         | 1111xxxx      | 240.0.0.0 - 255.255.255.255 | N/A                 |

### Endereços Reservados

| Descrição             | Faixa          | Uso                                |
| --------------------- | -------------- | ---------------------------------- |
| Loopback              | 127.0.0.0/8    | Comunicação com o próprio host     |
| Rede privada classe A | 10.0.0.0/8     | Redes internas                     |
| Rede privada classe B | 172.16.0.0/12  | Redes internas                     |
| Rede privada classe C | 192.168.0.0/16 | Redes internas                     |
| Link-local            | 169.254.0.0/16 | Autoconfiguração quando DHCP falha |
| APIPA                 | 169.254.0.0/16 | Autoconfiguração quando DHCP falha |

## Análise dos Exercícios

### Exercício 1: Identificação de Classes

<div class="explanation">
Para determinar a classe de um endereço IP, examine o primeiro octeto:
<ul>
    <li>Classe A: 1-127</li>
    <li>Classe B: 128-191</li>
    <li>Classe C: 192-223</li>
    <li>Classe D: 224-239</li>
    <li>Classe E: 240-255</li>
</ul>
Observação: O endereço 127.x.x.x, embora esteja no range da Classe A, é reservado para loopback.
</div>

### Exercício 2: Determinação de Faixas de Endereços Válidos

<div class="explanation">
Para determinar faixas válidas de endereços:
<ul>
    <li>Endereços de rede: Todos os bits de host são 0</li>
    <li>Endereços de broadcast: Todos os bits de host são 1</li>
    <li>Endereços válidos para host: Todos os demais endereços na sub-rede</li>
</ul>
</div>

### Exercício 3: CIDR e Subnetting

<div class="explanation">
CIDR (Classless Inter-Domain Routing) permite dividir redes independentemente das classes tradicionais.

Para calcular o número de hosts em uma sub-rede:

-   Número de hosts = 2^(32-prefixo) - 2
-   Exemplo: /24 tem 2^8 - 2 = 254 hosts utilizáveis

Para calcular o número de sub-redes:

-   Número de sub-redes = 2^(bits tomados da parte de host)
</div>

## Correções Específicas

### Endereços Incorretamente Classificados

1. <span class="incorrect">192.168.0.1/8</span> → <span class="correct">Este é um endereço Classe C privado, mas a máscara /8 não é a padrão para Classe C (que seria /24)</span>

2. <span class="incorrect">10.0.0.1/24</span> → <span class="correct">Este é um endereço Classe A privado, mas a máscara /24 não é a máscara padrão para Classe A (que seria /8)</span>

### Observações sobre Endereços Especiais

-   O endereço 127.0.0.1 é um endereço de loopback, não utilizável para comunicação na rede.
-   Endereços 169.254.x.x são endereços APIPA (Automatic Private IP Addressing), usados quando um host não consegue obter um endereço via DHCP.
-   Endereços iniciando com 224-239 são endereços multicast (Classe D), não utilizáveis para hosts individuais.

## Resumo dos Endereços Privados

<div class="explanation">
Endereços IPv4 privados (definidos pela RFC 1918):
<ul>
    <li>10.0.0.0 - 10.255.255.255 (10.0.0.0/8)</li>
    <li>172.16.0.0 - 172.31.255.255 (172.16.0.0/12)</li>
    <li>192.168.0.0 - 192.168.255.255 (192.168.0.0/16)</li>
</ul>
Estes endereços não são roteados na Internet pública e podem ser usados em redes internas.
</div>

<div class="note">
Nota: Este documento serve como um guia geral para análise de exercícios de endereçamento IP. Para verificar respostas específicas, compare com as faixas e regras descritas acima. Os exemplos marcados em vermelho foram corrigidos conforme o padrão TCP/IP.
</div>
