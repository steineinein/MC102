 /* MC102 - Turma O - Professor Julio López
 * Gabriel Paschoal Stein - RA 197466
 *
 * Laboratório 09 - A entrada do meu programa é um programa?
 * Input: Inteiro com o número de linhas do código, seguido do código e comentários.
 * Output: Execução do programa de entrada.
 */

#include <stdio.h>
#include "lab09.h"
#include <string.h>

#define INSTRUCTION_SIZE 50
#define COMMENT_SIZE 50
#define MNEME_SIZE 4

int read_code (char (*code)[INSTRUCTION_SIZE], int n);
int exe_code (char *line, char (*mneme)[MNEME_SIZE], int *reg, int n);
void read_reg (char *line, int *r1);
void read_regreg(char *line, int *r1, int *r2);
void read_regcst (char *line, int *r1, int *cst);
int str_to_int (char *string);

int main()
{
	int n, pc, numero_inst, reg[12], *p_reg;
	char (*p_code)[INSTRUCTION_SIZE], code[MAX_PROGRAMA][INSTRUCTION_SIZE] = {{'\0'}};
	char mnemonico[N_INSTRUCOES][MNEME_SIZE] = INSTRUCOES, (*p_mneme)[MNEME_SIZE];

	p_code =  code;
	p_mneme = mnemonico;
	p_reg = reg;
	scanf ("%d ", &n);
	numero_inst = read_code (p_code, n);
	pc = 0;
	/* enquanto o program counter não for maior que o número de instruções executa o código */
	while (pc < numero_inst){
		pc = exe_code (*p_code, p_mneme, p_reg, pc);
		/* atualiza o apontador para apontar para linha do código de acordo com o program counter */
		p_code = code + pc;
	}
	printf("\n");

	return 0;
}

/* Implementa instrução MOV
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * Não retorna nada
 */
void mov(int *rd, int *ro, int *pc){
	*rd = *ro;
	++*pc;
}

/* Implementa instrução MOC
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */
void moc(int *rd, int n, int *pc){
	*rd = n;
	++*pc;
}

/* Implementa instrução ADD
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * Não retorna nada
 */
void add(int *rd, int *ro, int *pc){
	*rd = *ro + *rd;
	++*pc;
}

/* Implementa instrução ADC
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */
void adc(int *rd, int n, int *pc){
	*rd = *rd + n;
	++*pc;
}

/* Implementa instrução SUB
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * Não retorna nada
 */
void sub(int *rd, int *ro, int *pc){
	*rd = *rd - *ro;
	++*pc;
}

/* Implementa instrução SUC
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */
void suc(int *rd, int n, int *pc){
	*rd = *rd - n;
	++*pc;
}

/* Implementa instrução JMP
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */
void jmp(int *ro, int n, int *pc){
	if (*ro >= 0){
		*pc = *pc + n;
	}
	else{
		++*pc;
	}
}

/* Implementa instrução PTN
 * Recebe um inteiro valor e um apontador para o Program Counter
 * Não retorna nada
 */
void ptn(int valor, int *pc){
	printf("%d ", valor);
	++*pc;
}

/* Implementa instrução PTC
 * Recebe um inteiro valor e um apontador para o Program Counter
 * Não retorna nada
 */
void ptc(int valor, int *pc){
	printf("%c", valor);
	++*pc;
}

/* Função para ĺer as instruções de maquina
 * A função recebe o ponteira onde será armezada as instruções e a quantidade de linha do código
 * ela então le linha a linha do código e apenas armazena as instruções, ignorando os comentários
 * retorna o número total de instruções
 */
int read_code (char (*code)[INSTRUCTION_SIZE], int n){
	char linha[COMMENT_SIZE] = {'\0'}, *p;
	int i, numero_inst;
	/* inicializa o número de instruções com o número de linha */
	numero_inst = n;
	p = linha;
	/* le equanto houve código */
	for (i = 0; i < n; ++i){
		scanf("%[^\n]%*c", p);
		/* armezana a linha se não for comentário */
		if (*p != '#'){
			strcpy(*code++, p);
		}
		else {
			/* decrementa o número de instruções quando houver commentário */
			numero_inst--;
		}
	}	
	return	numero_inst;
}

/* Função para executar instrução da respectiva linha
 * A função recebe a string que contém a linha e o array que contém todos o mnemonicos,
 * o endereço do array de registradores e program counter
 * ela então le linha a linhae indentifica qual instrução deve ser executada
 * executa a função com base nos parametros
 * retorn o program counter atualizado.
 */
int exe_code(char line[], char (*mneme)[MNEME_SIZE], int *reg, int n){
	int reg1_num, reg2_num, cst, pc = n;
	char current_mneme[MNEME_SIZE];
	/* Indentifica qual operação deve ser realizada. */
	strncpy (current_mneme, line, 3);
	/* MOV */
	if (strcmp(current_mneme, *mneme++) == 0){
		read_regreg (line, &reg1_num, &reg2_num);
		mov (reg + reg1_num, reg + reg2_num, &pc);
	}
	/* MOC */
	else if (strcmp(current_mneme, *mneme++) == 0){
		read_regcst (line, &reg1_num, &cst);
		moc (reg + reg1_num, cst, &pc);
	}
	/* ADD */
	else if (strcmp(current_mneme, *mneme++) == 0){
		read_regreg (line, &reg1_num, &reg2_num);
		add (reg + reg1_num, reg + reg2_num, &pc);
	}
	/* ADC */
	else if (strcmp(current_mneme, *mneme++) == 0){
		read_regcst (line, &reg1_num, &cst);
		adc (reg + reg1_num, cst, &pc);
	}
	/* SUB */
	else if (strcmp(current_mneme, *mneme++) == 0){
		read_regreg (line, &reg1_num, &reg2_num);
		sub (reg + reg1_num, reg + reg2_num, &pc);
	}
	/* SUC */
	else if (strcmp(current_mneme, *mneme++) == 0){
		read_regcst (line, &reg1_num, &cst);
		suc (reg + reg1_num, cst, &pc);
	}
	/* JMP */
	else if (strcmp(current_mneme, *mneme++) == 0){
		read_regcst (line, &reg1_num, &cst);
		jmp (reg + reg1_num, cst, &pc);
	}
	/* PTN */
	else if (strcmp(current_mneme, *mneme++) == 0){
		read_reg (line, &reg1_num);
		ptn (*(reg + reg1_num), &pc);
	}
	/* PTC */
	else if (strcmp(current_mneme, *mneme++) == 0){
		read_reg (line, &reg1_num);
		ptc (*(reg + reg1_num), &pc);
	}
	return pc;
}

/* função para idetificar qual registrador vai ser usado para PTN e PTC 
 * recebe a linha de código e o endereço de onde vai ser armazenado o número
 * que identifica o registrador. */
void read_reg (char *line, int *r1){
	char reg1[3], *p_reg;
	p_reg = reg1;
	/* incrementa o ponteiro até chegar no R */
	while (*line++ != 'R' && *line != '\0');
	/* armazena o número */
	*p_reg++ = *line++;
	/* checa se tem 1 ou 2 digitos*/
	if (*line == ' '){
	*p_reg = '\0';	
	}
	else{
	*p_reg++ = *line++;
	*p_reg = '\0';
	}
	/* transforma em int*/
	*r1 = str_to_int (reg1);
}

/* função para idetificar quais registradores vão ser usados para MOV, ADD e SUB 
 * recebe a linha de código e os endereços de onde vão ser armazenado os números
 * que identificam os registradores. */
void read_regreg(char *line, int *r1, int *r2){
	char reg1[3], reg2[3], *p_reg;
	p_reg = reg1;
	/* incrementa o ponteiro até chegar no R */
	while (*line++ != 'R' && *line != '\0');
	/* armazena o número */
	*p_reg++ = *line++;
	/* checa se tem 1 ou 2 digitos*/
	if (*line == ' '){
	*p_reg = '\0';	
	}
	else{
	*p_reg++ = *line++;
	*p_reg = '\0';
	}
	/* transforma em int*/
	*r1 = str_to_int (reg1);
	p_reg = reg2;
	/* incrementa o ponteiro até chegar no segundo R */
	line = line + 2;
	/* armazena o número */
	*p_reg++ = *line++;
	/* checa se tem 1 ou 2 digitos*/
	if (*line == ' '){
	*p_reg = '\0';
	}
	else{
	*p_reg++ = *line++;
	*p_reg = '\0';
	}
	/* transforma em int*/
	*r2 = str_to_int (reg2);
}

/* função para idetificar qual registrador e qual constanto vão ser usados para MOC, ADC e SUC 
 * recebe a linha de código, o endereço de onde vai ser armazenado o número
 * que identifica o registrador e o que identifca a constante */
void read_regcst (char *line, int *r1, int *cst){
	char reg1[3], num[11], *p;
	p = reg1;
	/* incrementa o ponteiro até chegar no R */
	while (*line++ != 'R' && *line != '\0');
	/* armazena o número */
	*p++ = *line++;
	/* checa se tem 1 ou 2 digitos*/
	if (*line == ' '){
	*p = '\0';	
	}
	else{
	*p++ = *line++;
	*p = '\0';
	}
	/* transforma em int*/
	*r1 = str_to_int (reg1);
	p = num;
	/* incrementa o ponteiro até chegar na constante */
	line = line + 1;
	/* amarzena equanto for número */
	*p++ = *line++;
	while (*line != '\0' && *line >= '0' && *line <= '9'){
	*p++ = *line++;
	}
	*p++ = '\0';
	/* transforma em int*/
	*cst = str_to_int (num);
}

/* função para converter string em inteiro
 * recebe uma string, que seja uma número
 * retorna o inteiro correspondente */
int str_to_int (char *num){
	int a = 0;
	/* checa se o número é positivo ou negativo */
	if (*num == '-'){
		num++;
		/* converte digito a digito */
		while (*num != '\0'){
			a = a * 10 + (*num - '0');
			num ++;
		}
		a = a * -1;
	}
	else{
		while (*num != '\0'){
			a = a * 10 + (*num - '0');
			num++;
		}
	}
	return a;
}
