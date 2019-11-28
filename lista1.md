# Lista de exercícios para a Prova 1 - PC 2019/02 - Prof Jeremaias

## Questão 1
    Atuar como Máquina Estendida e Gerenciador de Recursos.

## Questão 2
    Esconder detalhes de execução desnecessários ao usuário comum e fornecer ao usuário uma interface mais amigável
    e mais fácil de utilizar.

## Questão 3
    Controle do funcionamento do computador e Fornecer alocação ordenada e controlada de recursos computacionais.

## Questão 4
    No tempo: programas ou usuários aguardando recurso (ex.: programas executando ao mesmo tempo);
    No espaço: programas utilizando parte de um recurso ao mesmo tempo (ex.: memória);

## Questão 5
    Modo núcleo: fornece acesso ao hardware, permitindo controle sobre o mesmo (papel desempenhado pelo SO);
    Modo usuário: subconjunto limitado de instruções (softwares aplicativos, programas de interface com o usuário).

## Questão 6
    Pois limita até onde a atividade do usuário pode interferir nos recursos disponíveis, dado que o controle da máquina em
    mais baixo nível é proibido para o modo usuário.

## Questão 7
    Software comum é utilizado no modo usuário e pode ser substituído a critério do usuário, enquanto os softwares básicos
    não seguem a mesma ideia. Além disso, sistemas operacionais são enormes e complexos, de difícil codificação mas que 
    ainda assim são evoluídos e possuem vida longa devido a ser mais fácil evoluir um SO do que começar um novo do zero.

## Questão 8
    PC (Program Counter) - registrador responsável por indicar o endereço da intrução atualmente em execução.
    SP (Stack Pointer) - registrador responsácel por indicar o topo da pilha de operandos.

## Questão 9
    Instruções que necessitam atuar em recursos restritos a operação pelo sistema operacional. O programa passa o controle
    para o SO que faz o acesso restrito.

## Questão 10
    Mecanismo pelo qual um programa solicita um serviço ao SO.

## Questão 11
    Execução de programas distintos em um mesmo processador através de trocas rápidas. A multiprogramação permite que o processador evite períodos de ociosidade e seja justo quanto ao tempo em que um programa fica em execução.

## Questão 12
    Caching é o ato de trazer para perto aquilo que é mais utilizado. Seu objetivo é melhorar o desempenho no processamento ao reduzir o tempo de acesso ao que é mais utilizado, colocando em memórias com tempo de acesso menor.

## Questão 13
    É o mapeamento da memória principal em disco, a fim de utilizar o disco como memória principal e a memória principal como um tipo de cache. Criada para permitir o compartilhamento de memória entre programas e remover a limitação da memória principal.

## Questão 14
    MMU - Memory Management Unit.

## Questão 15
    Uma interrupção é um evento externo que leva o processador a para a execução do programa corrente e desviar a execução para um bloco de código chamado de Rotina de interrupção.

## Questão 16
    Espera ocupada, Mecanismo de interrupção e DMA (Direct Memory Access).

## Questão 17
    Linhas de Dados: onde os dados são trafegados entre dispositivos;
    Linhas de Endereços: definem origem e destino dos dados e endereça portas dos dispositivos de E/S;
    Linhas de Controle: controla o acesso das linhas de dados endereços e transmite ordens e sinais de temporização.

## Questão 18
    Sistemas operacionais de servidores: compartilha recursos com múltiplos usuários.
    Sistemas de Tempo Real: tempo é o parâmetro chave, logo, exige respostas rápidas. Tipicamente utilizado na áreal industrial.
    Sistemas operacionais embarcados: feitos para hardwares específicos e normalmente não aceitam software de terceiros.

## Questão 19
    Espaço de endereçamento: conjunto de endereços que um processo pode referenciar;
    Arquivos: informações logicamente relacionadas.

## Questão 20
    Não há a necessidade da criação da estrutura de um arquivo real apenas para conectar 2 processos, logo a troca de informações entre os processos não necessita utilizar outros recursos de hardware gerenciados pelo SO.

## Questão 21
    Abstração que permite a um dispositivo de E/S parecer-se com um arquivo.
    Exemplo: Arquivos especiais de bloco - dispositivos com blocos aleatoriamente endereçáveis que utilizam buffer.

## Questão 22
    SO é executado como um único programa em modo núcleo.
    Uma quebra no sistema derruba todo o SO e não apenas partes dele.

## Questão 23
    Dividir o sistema em pequenos módulos bem definidos.

## Questão 24
    Um processo é uma abstração de um programa em execução.

## Questão 25
    Memória: um processo precisa de memória para armazenar instruções e dados;
    CPU: um processo precisa de posse de CPU para executar instruções;
    Dispositivos: um processo precisa/pode realizar alguma tarefa de entrada e saída em dispositivos;
    Arquivos: um processo precisa gravar ou recuperar informações.

## Questão 26
    Contexto de Hardware - é o conteúdo dos registradores do processador;
    Contexto de Software - características de um processo que influenciam na execução de um programa;
    Espaço de Endereçamento - espaço de memória onde o programa será armazenado e também os dados utilizados por ele.

## Questão 27
    É a troca de um processo por outro na CPU. Quando a CPU vavi fazer o chaveamento entre processos A e B, por exemplo, ela salva os valores dos registradores (que correspondem ao contexto) do processo A e carrega os valores do contexto do processo B para os registradores para, assim, executar o processo B.

## Questão 28
    Na inicialização do sistema ou numa requisição do usuário para criar um novo processo.

## Questão 29
    Saída normal (processo termina a sua execução) ou Cancelamento por outro processo (chamada ao SO para cancelar outro processo).

## Questão 30
    CPU-Bound: passa a maior parte do tempo utilizando a CPU;
    I/O-Bound: passas a maior parte do tempo utilizando operações de entrada e saída.

## Questão 31
    Em execução: utilizando a CPU naquele momento;
    Pronto: temporariamente parado e outro processo está executando;
    Bloqueado: incapaz de ser executado até ocorrência de um evento externo;

## Questão 32
    Quantidade de processos = 4;
    Tempo esperando por E/S = 50%;
    Utilização = 1 - (p^n);

    Utilização = 1 - (0.5^4) = 0.9375 = 93%;

## Questão 33
             P0
            / |
          P0  P1
         / |  |
       P0  P2 P1
      / |  |  |
    P0  P3 P2 P1

## Questão 34
    ##include <stdio.h>
    ##include <unistd.h>
    ##include <sys/types.h>
    ##include <stdlib.h>
    ##include <sys/wait.h>

    int main() {

        int n;
        pid_t pid;

        scanf("%d",&n);

        for(int i=0;i<n;i++){
            pid = fork();
            printf("Sou o processo %ld.\n", pid);
        }

        return 0;
    }

## Questão 35
    É a alternância de processos em execução no processador. A troca é realizada pelo Escalonador de Processos que escolhe qual será o próximo processo a ser executado, através de um algorítmo de escalonamento. 

## Questão 36
    Um algoritmo de escalonamento deve ser justo dando a um processo a porção justa de CPU; deve ser aplicador de política ao manter a política de escalonamento funcionando; deve ser mantenedor de equilíbrio ao garantir que todas as partes do sistema estejam ocupadas.

## Questão 37
    P1   P2   P3   P4   P5
    12   10   7    7    24

    Ordem de execução: P3 -> P4 -> P2 -> P1 -> P5
    Turnaround:         7    14    24    36    60

    Turnaround total: 141
    Turnaround médio: 28.2

## Questão 38
    Quantum é a fatia de tempo de execução que um processo terá na CPU definido pelo algorítmo de escalonamento. O quantum é igual para todos os processos.

## Questão 39
    Uma thread é uma linha de execução de um processo. Um processo pode ter várias linhas de execução (threads) o que o permite ser distribuído por diferentes CPU's. Em aplicações existem atividades que podem ser decompostas em atividades paralelas e executadas em linhas de execução diferentes. As threads são mais rápidas de criar e destruir que processos.

## Questão 40
    Memória compartilhada: é estabelecida uma área de memória compartilhada para que os processos possam ler e escrever.
    Memória distribuída: comunicação feita por troca de mensagens.

## Questão 41
    São situações onde dois ou mais processos estão acessando dados compartilhados. É uma falha grave pois o resultado final do processamento depende de quem executa e quando executa alguma operação, podendo levar a resultados errados e inesperados.

## Questão 42
    Exclusão mútua: impedir que dois ou mais processos acessem o mesmo recurso ao mesmo tempo.
    Região Crítica: parte do código onde é feito o acesso à memória compartilhada, o que pode levar a condições de corrida.

## Questão 43
    Dois ou mais processos não podem estar simultaneamente dentro de suas regiões críticas;
    nenhuma consideração pode ser feita a respeito da velocidade relativa dos processos ou dos processadores disponíveis;
    nenhum processo que esteja fora de sua região crítica pode bloquear a execução de outro processo;
    nenhum processo pode ser obrigado a esperar indefinidamente para entrar em sua região crítica.

## Questão 44
    É a espera indefinida de um processo para poder utilizar recursos que ele precisa.

## Questão 45
    É a técnica em que um processo verifica uma condição repetidamente até que ela seja verdadeira. A principal desvantagem é consumir continuamente o processador.

## Questão 46
    Dar poder ao processo de interferir nas interrupções, algo que deve ser gerenciado pelo SO.

## Questão 47
    Um lock é uma variável única compartilhada que pode assumir o valor 0 ou 1 e é utilizada como mecanismo de sincronização entre processos de forma que os mesmos são programados baseados na verificação dessa variável quando do acesso à região crítica.

## Questão 48
    Um processo P1 de prioridade baixa entra na região crítica;
    Um processo P2 de prioridade alta tenta acessar mas não consegue;
    A verificação não causou o bloqueio do processo P2 e ele ainda vai continuar executando o teste (espera ocupada) até que seu quantum se esgote;
    Um processo com prioridade igual ou maior que a de P2 será escolhido pelo escalonador para usar a CPU;
    P1 nunca mais será executado pois sua prioridade será sempre menor...

## Questão 49
    Faltam os decrementos corretos da variável cont e a verificação se o buffer acabou de ficar "não-cheio".

    cont = cont - 1;
    if ( cont == N - 1)

## Questão 50
    Uma transação atômica é uma transação indivisível. Sempre que uma transação atômica começa, ela termina pois é indivisível, inquebrável.

## Questão 51
    Um mutex é uma versão simplificada de um semáforo. No semáforo, pode-se controlar vários processos que querem acessar a região crítica, enquanto no mutex, que é binário, apenas dois processos podem acessar por exclusão mútua: quando não for um é o outro.

## Questão 52
    Fica a cargo do programador a correta implementação e gerenciamento dos sinais de condição. Nem sempre é trivial utilizar corretamente as estruturas que permitem acessar regiões críticas por exclusão mútua e gerenciar os sinais de variáveis condicionais.

## Questão 53
    Um monitor é um conjunto de procedimentos e dados agrupados por módulos. Cada módulo é um monitor. Os processos só podem chamar os procedimentos, nunca acessando os dados diretamente. A principal vantagem reside em retirar do programador a responsabilidade por garantir a exclusão mútua e passar para o compilador.