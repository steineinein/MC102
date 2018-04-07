/* Cabeçalho a ser incluído no laboratório 10
 */

#include<stdio.h>

typedef struct {
    int instante;
    int instrumento;
    int nota;
    int intensidade;
} TpEvento;

/*  Objetivo: Transcreve um vetor de eventos para a saída padrão,
 *          formatado para leitura por humanos ou tocadores de MIDI.
 *  Entrada:
 *			- modo: 0 para impressão de texto legível por humanos
 *                  1 para formato binário de arquivo MIDI
 *			- numEventos: tamanho do vetor de eventos
 *			- eventos: vetor cujos elementos são do tipo TpEvento
 *
 *  Saída:
 *			- Função sem retorno, os dados são lançados na saída padrão.
 */
void saida(int modo, int numEventos, TpEvento eventos[]){
    unsigned long int i;
    const char MThd[] = "MThd";
    /* Formato 0; track único; semínima dura 24 'durações mínimas' */
    const unsigned char headerChunk[] = {0, 0, 0, 6, 0, 0, 0, 1, 0, 24};
    const char MTrk[] = "MTrk";
    const unsigned long int comprimento = 15 + 7 * numEventos + 4;
    /* Três colcheias por compasso, 12 'durações mínimas' por tempo, oito fusas por semínima */
    const unsigned char timeSignature[] = {0, 0xFF, 0x58, 4, 3, 3, 0x0C, 8};
    /* Andamento */
    const unsigned char tempo[] = {0, 0xFF, 0x51, 03, 5, 152, 75};
    const unsigned char endOfTrack[] = {0, 0xFF, 0x2F, 0};
    int momentoAnterior = 0;
 
    /* Lança na saída padrão o conteúdo de um arquivo MIDI do tipo 0 (track única) */
    if (modo){
        /* Cabeçalho seguindo protocolo para arquivo MIDI */
        for (i = 0; i < 4; i++)
            putchar(MThd[i]);
        for (i = 0; i < 10; i++)
            putchar(headerChunk[i]);
        for (i = 0; i < 4; i++)
            putchar(MTrk[i]);
        for ( i = 3; i < 4; i--)
            putchar((unsigned char)(((comprimento) >> (8 * i)) % (1 << 8)));
        for (i = 0; i < 8; i++)
            putchar(timeSignature[i]);
        for (i = 0; i < 7; i++)
            putchar(tempo[i]);

        /* Eventos */
        for (i = 0; i < numEventos; i++){
            putchar((unsigned char) 0);
            putchar((unsigned char) (192));
            putchar((unsigned char) (eventos[i]).instrumento - 1);
            putchar((unsigned char) ((eventos[i]).instante - momentoAnterior));
            putchar((unsigned char) 144);
            putchar((eventos[i]).nota);
            putchar((eventos[i]).intensidade);
            momentoAnterior = (eventos[i]).instante;
        }

        /* Fim */
        for (i = 0; i < 4; i++)
            putchar(endOfTrack[i]);
    }

    /* Impressão formatada do vetor de eventos */
    else{
        printf("╔════════╦═══════════╦════╦═══════════╗\n");
        printf("║Instante║Instrumento║Nota║Intensidade║\n");
        printf("╠════════╬═══════════╬════╬═══════════╣\n");
        for (i = 0; i < numEventos; i++)
            printf("║%7d ║%10d ║%3d ║%10d ║\n", eventos[i].instante, (int) eventos[i].instrumento, (int) eventos[i].nota, (int) eventos[i].intensidade);
        printf("╚════════╩═══════════╩════╩═══════════╝\n");
    }

    return;
}
