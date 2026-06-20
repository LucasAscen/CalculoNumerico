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
