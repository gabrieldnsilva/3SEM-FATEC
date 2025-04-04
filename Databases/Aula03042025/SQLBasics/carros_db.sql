-- Criação do banco de dados
CREATE DATABASE IF NOT EXISTS carros_db;

-- Usando o banco de dados
USE carros_db;

-- Criação da tabela de marcas
CREATE TABLE IF NOT EXISTS marcas (
    id_marca INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    pais_origem VARCHAR(50),
    ano_fundacao INT,
    UNIQUE(nome)
);

-- Criação da tabela de modelos
CREATE TABLE IF NOT EXISTS modelos (
    id_modelo INT AUTO_INCREMENT PRIMARY KEY,
    id_marca INT NOT NULL,
    nome VARCHAR(50) NOT NULL,
    ano_lancamento INT,
    categoria VARCHAR(50),
    FOREIGN KEY (id_marca) REFERENCES marcas(id_marca),
    UNIQUE(id_marca, nome)
);

-- Inserindo dados de exemplo nas marcas
INSERT INTO marcas (nome, pais_origem, ano_fundacao) VALUES
('Volkswagen', 'Alemanha', 1937),
('Fiat', 'Itália', 1899),
('Toyota', 'Japão', 1937),
('Ford', 'Estados Unidos', 1903),
('Chevrolet', 'Estados Unidos', 1911),
('Honda', 'Japão', 1948),
('Hyundai', 'Coreia do Sul', 1967);

-- Inserindo dados de exemplo nos modelos
INSERT INTO modelos (id_marca, nome, ano_lancamento, categoria) VALUES
(1, 'Gol', 1980, 'Hatch'),
(1, 'Golf', 1974, 'Hatch'),
(1, 'Polo', 1975, 'Hatch'),
(2, 'Uno', 1983, 'Hatch'),
(2, 'Strada', 1998, 'Pickup'),
(3, 'Corolla', 1966, 'Sedan'),
(3, 'Hilux', 1968, 'Pickup'),
(4, 'Ka', 1996, 'Hatch'),
(4, 'Ranger', 1983, 'Pickup'),
(5, 'Onix', 2012, 'Hatch'),
(5, 'S10', 1995, 'Pickup'),
(6, 'Civic', 1972, 'Sedan'),
(6, 'Fit', 2001, 'Hatch'),
(7, 'HB20', 2012, 'Hatch'),
(7, 'Tucson', 2004, 'SUV');

-- Consultas úteis

-- Selecionando todos os modelos com suas respectivas marcas
SELECT 
    m.nome AS modelo, 
    ma.nome AS marca, 
    m.ano_lancamento, 
    m.categoria 
FROM 
    modelos m
JOIN 
    marcas ma ON m.id_marca = ma.id_marca
ORDER BY 
    ma.nome, m.nome;

-- Contando quantos modelos cada marca possui
SELECT 
    ma.nome AS marca, 
    COUNT(m.id_modelo) AS quantidade_modelos
FROM 
    marcas ma
LEFT JOIN 
    modelos m ON ma.id_marca = m.id_marca
GROUP BY 
    ma.nome
ORDER BY 
    quantidade_modelos DESC;

-- Obtendo todos os modelos de uma categoria específica (exemplo: Hatch)
SELECT 
    m.nome AS modelo, 
    ma.nome AS marca
FROM 
    modelos m
JOIN 
    marcas ma ON m.id_marca = ma.id_marca
WHERE 
    m.categoria = 'Hatch'
ORDER BY 
    ma.nome, m.nome;
