**Como usar a função Get_Next_line**
(1)  Compilar gcc
gcc -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c /main/main.c 

(2) ./a.out <nome_arquivo> 

**Funcao int	get_next_line(int fd, char **line)**
Função get_next_line => Retorna linha por linha, de um arquivo (file descriptor), retirando nova linha.

Parametros: int fd = File Desciptor para leitura
			**line = a linha lida 

Return = 1: A linha foi lida
		 0: EOF (Fim do arquivo)
		-1: Algum erro ocorreu

**Como a função get_next_line funciona.**

A funcao get_next_line le o numero de bytes configurado no BUFFER_SIZE, enquanto não encontrar \n "nova linha" ou fim do arquivo EOF, vai armazenando concatenando o buff na variável static c_line.  Ao encontrar um \n.  sai do loop, chamada a rotina output: que faz algumas validaçoes, e retornará -1 se encontrar error, se nao  chamará a rotina save_line: que verifica o texto acumulado na c_line, que procurar por /n  ou EOF, se encontrat a /n "nova linha" então o texto será dividido sendo dacpos. 0 até a  marcação /n, será gravando na variável *line que será retornar para a funcao principal (main), e o resto da quebra de linha em diante, será armazando da variável c_line, retornando o valor 1 de linha lida. e os ponteiro *line terá a linha lida sem nova linha, o ponteiro c_line terá o restante da linha que será, utilizado na proxima chamada get_netx_line para concatenar com o restante do texto. Agora se a rotinda save_line encontrar EOF no texto, então retornar o valro (0) fim de arquivo, e o ponteiro *line com a linha lida até o EOF e a variável c_line será vazia.


**Funcoes Utilizadas**
[open]
int open(const char *pathname, int flags);
A função recebe o nome do arquivo como parâmetro juntamente com o flag indicando o modo de abertura e flags informando opções adicionais de abertura e/ou tratamento de arquivo. retonar numero int positivo, em caso sucesso

[`Funcao open`](https://linuxhint.com/posix-open-function-c-programming/)

[read] 
ssize_t read(int fd, void *buf, size_t count);

[`Funcao read`](http://www.br-c.org/doku.php?id=read#:~:text=A%20fun%C3%A7%C3%A3o%20read%20realiza%20a,a%20partir%20da%20posi%C3%A7%C3%A3o%20corrente)

