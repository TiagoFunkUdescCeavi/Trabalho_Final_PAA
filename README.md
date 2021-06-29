### Problema do Auditório

- Dada uma lista de tarefas a serem executadas com um horário de início e um horário de término, determinar qual a quantidade máxima de atividades que podem ser executadas
- Um auditório só pode ser utilizado para um evento por vez. Em um dia com muitos eventos, deseja-se determinar qual é o maior número de eventos que podem ser realizados no auditório, e quais são eles (OBS: pode haver mais de uma solução).

- Imagine o seguinte quadro de reservas

| Evento  | 1 | 2  | 3 | 4 | 5  | 6  | 7 | 8  | 9 | 10 | 11 |
|---------|---|----|---|---|----|----|---|----|---|----|----|
| Inicio  | 3 | 8  | 5 | 1 | 6  | 12 | 0 | 8  | 5 | 2  | 3  |
| Término | 5 | 11 | 7 | 4 | 10 | 14 | 6 | 12 | 9 | 13 | 8  |

- Para encontrar o tamanho de um subconjunto sem sobreposição máximo, poderiamos utilizar:

#### Solução gulosa
- Ordenamos os eventos pelo horário de término (em ordem crescente) e sempre que possível pegamos o evento com menor horário de término.

![](./assets/subcolecao.png)


### Dependencias
- [linux](https://www.linux.org/pages/download/)
- [GCC](https://gcc.gnu.org/install/index.html)
- [make](https://www.unixmen.com/install-ubuntu-make-on-ubuntu-15-04/)

### Como buildar
- Para buildar você deve criar ou modificar o `main.c` no root do projeto

- Execute o comando `make`
__Resultado Esperado__

![](./assets/make.png)

- Deve gerar o arquivo executável `TRABALHO_FINAL_PAA`

### Como Executar
- Após realizar o build do executável com `make`
- Rode o arquivo com a seguinte linha de comando para um exemplo simples
```shell
./TRABALHO_FINAL_PAA
```
- Rode o arquivo com a seguinte linha de comando para gerar valores aleatórios de tamanho qualquer. 
```shell
./TRABALHO_FINAL_PAA <n>
```
> Para limpar, realizar o build e executar o main use `make run`

### Como Limpar
- Limpa todos os `.out` e o `TRABALHO_FINAL_PAA`
- Execute o comando `make clean`

### Script de dados
- Rode `make script.sh`
- Deve excutar 30 vezes para cada um dos seguintes valores: `(270000 810000 2430000 7290000 21870000 65610000)`

### Análise de complexidade
- Foi gerado um gráfico em função do tempo e com a linha de tendência.
![](./assets/make.png)