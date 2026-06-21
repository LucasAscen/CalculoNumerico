# Segunda Avaliação Calculo Numerico

# CCET - UFMA

## Integrantes :
**_Ana Caroline Santos Almeida_**

**_ Lucas _**

**_ Wendson _**

# CalculoNumerico

## Segunda Implementação - **Interpolação Gregory-Newton**

Este projeto é uma ferramenta de simulação em **C** projetada para monitorar a eficiência térmica e prever temperaturas em sistemas de resfriamento de servidores de data centers. Utilizando o método matemático de **Interpolação Polinomial de Gregory-Newton** através de diferenças finitas avançadas, o sistema é capaz de estimar variações térmicas precisas em intervalos de tempo não registrados por sensores físicos.

## Funcionalidades

- **Alocação Dinâmica de Memória:** O sistema se adapta ao número exato de registros temporais que o usuário deseja inserir ($O(n^2)$ em espaço).
- **Cálculo Automatizado de Diferenças Avançadas:** Geração automática da tabela de diferenças ($\Delta^0, \Delta^1, \dots, \Delta^n$) exibida em tempo de execução para validação analítica.
- **Simulação Interativa:** Loop interativo que permite ao usuário testar múltiplos instantes de tempo ($x_{alvo}$ em minutos) consecutivamente sem a necessidade de reiniciar o programa.

## Análise de Eficiência

| Operação                                             | Complexidade de Tempo | Descrição                                                                                                       |
| :--------------------------------------------------- | :-------------------: | :-------------------------------------------------------------------------------------------------------------- |
| **Cálculo da Tabela (`calcular_diferencas`)**        |       $O(n^2)$        | Executado apenas **uma vez** para montar a matriz triangular de diferenças avançadas.                           |
| **Interpolação de Ponto (`interpolar_temperatura`)** |        $O(n)$         | Executado em tempo linear a cada consulta de minuto informada pelo usuário, garantindo respostas em tempo real. |

---

## Terceira Implementação - Splines Linear e Cubico

Além da abordagem polinomial, o projeto também contempla a técnica de **Interpolação por Splines**, aplicada em cenários onde a suavidade do movimento ou da curva é essencial — como no controle de braços robóticos em cortadoras a laser.

## **Funcionalidades:**

- **SplineLinear:** Conecta pontos consecutivos com segmentos de reta. É rápido e simples, mas pode gerar movimentos bruscos.

* **SplineCubico:** Utiliza polinômios de grau 3 em cada intervalo, garantindo continuidade da primeira e segunda derivada. Ideal para movimentos suaves e precisos.

## Exemplos de aplicação

### Considerando os keyframes:

- Tempo (s): [0.0, 1.0, 2.0, 3.0]
- Posição (cm): [2.5, 4.5, 3.0, 6.0]

## Interpolando para 𝑡 = 1.5:

- **Linear:**𝑦(1.5) = 3.75 cm
- **Linear:**𝑦(1.5) ≈ 3.63 cm

## Quarta Implementação - Ajuste de Curvas – Método dos Mínimos Quadrados (MMQ)

Diferente da interpolação, que força a curva a passar exatamente por todos os pontos, o **Método dos Mínimos Quadrados (MMQ)** busca a reta que melhor representa a tendência dos dados, mesmo quando eles apresentam ruído — como ocorre em medições reais, por exemplo no monitoramento de tráfego de rede.

## **Funcionalidades:**

- **Ajuste Linear (MMQ):** Calcula os coeficientes *a* e *b* da reta P1(x) = ax + b que minimizam a soma dos quadrados dos erros entre a reta e os pontos medidos, encontrando assim a melhor reta de tendência.

## Exemplos de aplicação

### Considerando os dados de tráfego de rede do DEINF/UFMA:

- Hora do dia (x): [8, 9, 10, 11, 12]
- Acessos em milhares (y): [2.1, 2.8, 3.1, 4.0, 4.8]

## Ajustando a reta por MMQ:

- **Equação da reta:** P1(x) = 0.66x − 3.24
- **Previsão para x = 13:** y(13) ≈ 5.34 mil acessos

## Quinta Implementação -  Integração Numérica (Newton-Cotes 3/8)

Após explorar interpolação e ajuste de curvas nas etapas anteriores, o projeto passa agora para a **Integração Numérica**, uma técnica essencial quando precisamos calcular a área sob uma curva (ou seja, resolver uma integral definida) sem conhecer a expressão analítica exata da função — apenas um conjunto de pontos amostrados, como leituras periódicas de um sensor.

Nesta etapa, implementamos a **Fórmula de Quadratura de Newton-Cotes**, especificamente a **Regra 3/8 de Simpson**, que é a variante indicada para conjuntos de exatamente 4 pontos (ou seja, 3 intervalos igualmente espaçados). Diferente da Regra dos Trapézios, que aproxima a curva por segmentos de reta, a Regra 3/8 ajusta um **polinômio de grau 3** aos 4 pontos disponíveis, capturando melhor curvaturas mais acentuadas e reduzindo o erro de aproximação.

## **Funcionalidades:**

- **Newton-Cotes 3/8:** Aproxima a integral definida no intervalo formado pelos 4 pontos, aplicando a fórmula:

                                ∫ f(x) dx ≈ (3h/8) · [y0 + 3y1 + 3y2 + y3]
  
  onde **h** é o espaçamento constante entre os pontos no eixo x, e **y0, y1, y2, y3** são os valores da função (ou os dados amostrados) em cada ponto. Os coeficientes 1, 3, 3, 1 vêm da derivação do polinômio interpolador de grau 3 usado como base da fórmula.

- A regra exige que os pontos estejam **igualmente espaçados** (espaçamento **h** constante) e que existam **exatamente 4 pontos** (3 intervalos), por isso ela é aplicada de forma pontual a um pequeno trecho dos dados, e não de forma repetida ao longo de um intervalo maior.

## Exemplos de aplicação

### Contexto: monitoramento de rede

Um monitor de rede capturou a taxa de transferência (banda) de um servidor a cada 2 segundos. Como o dado é discreto (amostrado em instantes específicos), usamos a integração numérica para estimar o **total de dados transferidos** no intervalo observado. Já que a quantidade total transferida é, matematicamente, a integral da taxa de transferência ao longo do tempo.

### Dados utilizados:

- Tempo (s): [0, 2, 4, 6], com espaçamento constante h = 2
- Banda (MB/s): [10, 15, 12, 8]

## Calculando o total de dados transferidos:

Aplicando a fórmula da Regra 3/8:

Total = (3 × 2 / 8) · [10 + 3(15) + 3(12) + 8]
      = 0.75 · [10 + 45 + 36 + 8]
      = 0.75 · 99

- **Resultado (Newton-Cotes 3/8):** Total ≈ **74.25 MB** transferidos no intervalo de 0 a 6 segundos.

## Sexta Implementação -  Trapézios e Simpson

Dando sequência à Integração Numérica, agora trabalho com dois métodos que, ao contrário da Regra 3/8 (que exige exatamente 4 pontos), podem ser aplicados a qualquer quantidade de pontos igualmente espaçados: a **Regra dos Trapézios (Repetida)** e a **Regra de 1/3 de Simpson**. Os dois aproximam a área sob a curva, mas de formas diferentes — o que permite comparar a precisão de cada abordagem sobre o mesmo conjunto de dados.

## **Funcionalidades:**

- **Trapézios (Repetida):** Aproxima cada intervalo entre dois pontos consecutivos por um trapézio (uma reta ligando os pontos), somando a área de todos os trapézios formados ao longo do intervalo total:

 
                                     ∫ f(x) dx ≈ (h/2) · [y0 + 2(y1 + y2 + ... + yn-2) + yn-1]
 

- **Simpson 1/3:** Em vez de retas, ajusta parábolas a cada par de intervalos, capturando melhor a curvatura dos dados. Exige um número par de intervalos:

  
                                    ∫ f(x) dx ≈ (h/3) · [y0 + 4(y1 + y3 + ...) + 2(y2 + y4 + ...) + yn-1]
  

## Exemplos de aplicação

### Contexto: distância percorrida por um carro elétrico

Recebi os dados de velocidade de um carro elétrico registrados ao longo do tempo, já que o odômetro do veículo quebrou e não é mais possível ler a distância total percorrida diretamente. Como a distância é a integral da velocidade em relação ao tempo, apliquei os dois métodos de integração numérica sobre os mesmos pontos para estimar a distância total e comparar os resultados.

### Dados utilizados:

- Tempo (h): [0.0, 0.5, 1.0, 1.5, 2.0], com espaçamento constante h = 0.5
- Velocidade (km/h): [0, 40, 65, 80, 90]

## Calculando a distância total percorrida:

- **Trapézios (Repetida):** ≈ **115.0 km**
- **Simpson 1/3:** ≈ **116.667 km**

## Sétima Implementação - Quadratura de Gauss

Para concluir a etapa de Integração Numérica, implementei a **Fórmula de Quadratura de Gauss**, um método diferente dos anteriores: em vez de usar pontos igualmente espaçados ao longo do intervalo, ela escolhe pontos específicos (raízes de polinômios de Legendre) e pesos associados, que juntos minimizam o erro da aproximação. Com poucos pontos, a Quadratura de Gauss consegue integrar com exatidão polinômios de grau relativamente alto — algo que os métodos anteriores só alcançariam usando muito mais pontos.

## **Funcionalidades:**

- **`quadratura_gauss(funcao, a, b, n_pontos)`:** Função que recebe a função a ser integrada, os limites de integração `[a, b]` e a quantidade de pontos (`n_pontos = 2` ou `n_pontos = 3`), com as raízes e os pesos já fixados para o intervalo padrão `[-1, 1]`:


  ∫ f(x) dx ≈ Σ wi · f(xi)
  

  - **n = 2:** raízes = ±1/√3, pesos = 1, 1
  - **n = 3:** raízes = −√(3/5), 0, +√(3/5), pesos = 5/9, 8/9, 5/9

  Quando o intervalo de integração não é `[-1, 1]`, a função faz a mudança de variável necessária para reaproveitar essas mesmas raízes e pesos tabelados.

## Exemplos de aplicação

### Contexto: torque de um motor

Recebi a função que descreve o torque de um motor ao longo de um intervalo de operação e precisei calcular o trabalho total realizado, que corresponde à integral dessa função no intervalo dado. Usei a Quadratura de Gauss com apenas 2 pontos para obter o resultado.

### Dados utilizados:

- Função: f(x) = 5x³ + x² − 12x + 4
- Limites de integração: a = −1, b = 1

## Calculando o trabalho total:

- **Gauss (n = 2):** ≈ **8.667**
- **Gauss (n = 3):** ≈ **8.667**

Os dois resultados são idênticos porque a Quadratura de Gauss com apenas 2 pontos já integra com exatidão qualquer polinômio até grau 3 — e como os termos ímpares da função (5x³ e −12x) se anulam no intervalo simétrico [-1, 1], o valor exato da integral é 26/3 ≈ 8.667, confirmando, assim, a precisão do método mesmo com poucos pontos.
