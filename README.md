# Segunda Avaliação Calculo Numerico

# CCET - UFMA

## Integrantes :

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
