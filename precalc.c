#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define PROCESS_BINARY_OP(op) if (strcmp(buf, #op) == 0) { return accept() op accept(); }

/* allocate a new string. return null on EOF. */
char * scan() {
	int capacity = 10; /* including null */
	int size = 0;
	char *buf = malloc(capacity * sizeof(char));
	int c;
	while (1) {
		c = getchar();
		if (c == EOF) goto exit;
		if (!isspace(c)) {
			ungetc(c, stdin);
			break;
		}
	}
	while (1) {
		c = getchar();
		if (c == EOF || isspace(c)) break;
		if (size + 2 > capacity) {
			capacity = (size + 1) * 2 + 1;
			buf = realloc(buf, capacity * sizeof(char));
		}
		buf[size] = c;
		size++;
	}
exit:
	if (size == 0) {
		free(buf);
		return NULL;
	}
	buf[size] = 0;
	return buf;
}

double accept() {
	char * buf = scan();
	if (!buf) exit(0);
	PROCESS_BINARY_OP(+)
	PROCESS_BINARY_OP(-)
	PROCESS_BINARY_OP(*)
	PROCESS_BINARY_OP(/)
	if (strcmp(buf, "sqrt") == 0) { return sqrt(accept()); }
	if (strcmp(buf, "expt") == 0) { return pow(accept(), accept()); }
	double r = atof(buf);
	free(buf);
	return r;
}

int main(int argc, char * argv[]) {
	puts("Prefix calculator ("__DATE__ ", " __TIME__ ")");
	puts("Tokens are separated by whitespaces.");
	puts("Operators:");
	puts("  Unary: sqrt");
	puts("  Binary: + - * / expt");
	while (1) {
		printf("> ");
		printf("%.16g\n", accept());
	}
	return 0;
}