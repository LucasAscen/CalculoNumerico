# Segunda Avaliação Calculo Numerico

# CCET - UFMA

## Integrantes :

**_ Lucas _**

**_ Wendson _**

# CalculoNumerico

## Segunda Implementação - **Interporlação Gregory-Newton**

Este projeto é uma ferramenta de simulação em **C** projetada para reconstruir trajetórias de voo e prever altitudes de veículos aéreos não tripulados (drones). Utilizando o método matemático de **Interpolação Polinomial de Gregory-Newton** através de diferenças divididas, o sistema é capaz de preencher lacunas de dados capturados por sensores dinâmicos.

## Funcionalidades

- **Alocação Dinâmica de Memória:** O sistema se adapta ao número exato de registros que o usuário deseja inserir ($O(n^2)$ em espaço).
- **Cálculo Automatizado de Coeficientes:** Geração dos coeficientes lógicos ($d_0, d_1, \dots, d_n$) exibidos em tempo de execução.
- **Simulação Interativa:** Loop interativo que permite ao usuário testar múltiplos instantes de tempo ($t_{alvo}$) consecutivamente sem reiniciar o programa.

## Análise de Eficiência

| Operação                                            | Complexidade de Tempo | Descrição                                                                                 |
| :-------------------------------------------------- | :-------------------: | :---------------------------------------------------------------------------------------- |
| **Cálculo da Tabela (`calcular_diferencas`)**       |       $O(n^2)$        | Executado apenas **uma vez** para montar a matriz triangular de coeficientes.             |
| **Interpolação de Ponto (`interpolar_trajetoria`)** |        $O(n)$         | Executado em tempo linear a cada consulta do usuário, garantindo respostas em tempo real. |

---
