# Lista de exercícios para a Prova 2 - PC 2019/02 - Prof Jeremaias

## Questão 1
    Um conjunto de processos está em Deadlock se cada processo pertencente ao conjunto estiver esperando por um evento que somente um outro processo pertencente ao mesmo conjunto pode fazer ocorrer.

## Questão 2
    Exclusão mútua: cada recurso deve ser alocado de maneira exclusiva;
    Não-preempção: cada recurso só pode ser liberado pelo processo que o detém;
    Posse e espera: um processo que detém recursos pode solicitar novos recursos;
    Espera circular: deve existir um ciclo de processos onde cada processo está esperando por um recurso de um outro processo membro de uma cadeia.

## Questão 3
    Em recursos não-preemtíveis, pois o recurso é alocado de maneira exclusiva e apenas o próprio processo pode liberá-lo por espontânea vontade, não podendo ser retirado do processo por uma entidade externa.

## Questão 4

## Questão 5
    Pois o esforço nececssário para tratar os deadlocks pode ser alto demais para situações que ocorrem com pouca frequência, tornando inviável tratá-los.

## Questão 6
    O sistema operacional constrói um grafo de alocação de recursos para os respectivos processos. Por meio de DFS, pode-se detectar ciclos no grafo, o que indica a existência de ciclos. Se existe um ciclo, todos os processos que fazem parte do ciclo estão em Deadlock.

## Questão 7
    Eliminação de processos - processos envolvidos no deadlock são eliminados gradativamente até que o ciclo seja quebrado.

## Questão 8
    Um estado é seguro se há uma maneira de satisfazer todas as requisições pendentes, partindo dos procecessos em execução.

## Questão 9

## Questão 10

## Questão 11
    Fazer com que os processos solicitem todos os recursos que necessitam antes da sua execução.
    Problema: necessidade de antecipação.

## Questão 12
    Nos livelocks os processos não estão bloqueados mas estão presos em algum ponto de execução.
    Não há a ocorrência de deadlocks mas processos nunca são atendidos (postergação indefinida).

## Questão 13

## Questão 14
    Paralelismo de tarefas: consiste em dividir o problema em várias tarefas que são distribuídas entre os núcleos de processamento.
    Paralelismo de dados: consiste em dividir os dados do problema entre os núcleos, onde cada núcleo executa tarefas similares na sua parte do dado.

## Questão 15
    Comunicação: um ou mais núcleos enviam conteúdo para outros, conversam entre si.
    Balanceamento de carga: partes do trabalho devem ser distribuídas uniformemente para não haver sobrecarga.

## Questão 16
    SIMD (Single Instruction, Multiple Data): uma instrução é aplicada a múltiplos dados ao mesmo tempo. Aplicado em paralelismo de dados, como, por exemplo, multiplicação de matrizes.

## Questão 17
    Memória compartilhada: núcleos compartilham acesso a uma mesma memória. 
    Memória distribuída: núcleos tem sua memória privativa.

## Questão 18
    Medida de desempenho relativa entre dois sistemas que processam o mesmo problema.

## Questão 19
    Serve para medir a melhoria na velocidade de execução de uma tarefa executada em duas arquiteturas semelhantes com recursos diferentes.

## Questão 20

    Speedup é calculado por: TSerial/TParalelo
    Eficiência é calculado por: Speedup/Nº de núcleos

                1 núcleo    2 núcleos   4 núcleos   8 núcleos
    Tempo(s)      800          650         600         550
    Speedup        1           1.23        1.33        1.45
    Eficiência     1           0.61        0.33        0.18

## Questão 21
    Um problema é escalável se ele consegue lidar com tamanhos de problemas crescentes onerando minimamente a eficiência do programa.

## Questão 22
    Forte: capacidade de um programa de manter sua eficiência constante ao aumentar o número de processos/threads para um problema de tamanho fixo.
    Fraca: capacidade de um programa de manter sua eficiência constante ao aumentar o número de processos/threads e aumentando-se proporcionalmente o tamanho do problema.

## Questão 23
    Na memória compartilhada os processadores se comunicam implicitamente através de estruturas de dados compartilhadas;
    Na memória distribuída os processadores se comunicam explicitamente por meio de trocas de mensagens pela rede de interconexão.

## Questão 24
    Enviar(destino, mensagem) - um processo envia uma mensagem a outro processo passando o destinatário e o endereço de onde a mensagem se encontra.
    Receber(origem, mensagem) - um processo recebe uma mensagem de outro processo com parâmetros de origem e o endereço onde a mensagem deve ser armazenada.

## Questão 25
    No momento da troca de mensagens, cada processo envolvido sabe exatamente em que estado da execução se encontra o outro processo. Então, além da troca de mensagens ocorre a troca de informaçoes implícitas sobre o estado de execução.

## Questão 26
    #pragma omp critical - garante a exclusão mútua por sotware ao informar que apenas uma thread por vez irá executar as instruções em seu contexto, mas não ajuda em termos de parelelismo do código.

    #pragma omp atomic - utiliza instruções de hardware para reduzir o overhead envolvendo as operações em seu contexto.

## Questão 27
    O vetor digitos está sendo escrito por todos os processos sem considerar a exclusão mútua. Logo, deveria se utilizar a diretiva #pragma omp critical ou #pragma omp atomic para promover a exclusão mútua para a variável digits.

## Questão 28
    O processo 0 deveria receber a mensagem do último processo, no caso, np - 1. Logo, está faltando a diretiva receber no primeiro condicional que verifica se o rank do processo é igual a 0.