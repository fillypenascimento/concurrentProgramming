// autor: Amanda Oliveira Alves e Fillype Alves do Nascimento
// arquivo: codigo.c
// atividade: 4.1

#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main(){

	char *fn = "/tmp/output";
	char conteudo[201];
	FILE *fp;
	scanf("%200s", conteudo);
	if (!access(fn, W_OK)) {
		fp = fopen(fn, "a+");
		fwrite(conteudo, sizeof(char), strlen(conteudo), fp);
		fclose(fp);
	} 
	else {
		printf("Sem permissão de escrita no arquivo.\n");
	}
	return 0;
}