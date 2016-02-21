#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PROCESS_BINARY_OP(op) if (strcmp(buf, #op) == 0) { return accept() op accept(); }

double accept() {
	char buf[80];
	scanf_s("%s", buf, _countof(buf));
	if (feof(stdin)) exit(0);
	PROCESS_BINARY_OP(+)
	PROCESS_BINARY_OP(-)
	PROCESS_BINARY_OP(*)
	PROCESS_BINARY_OP(/)
	if (strcmp(buf, "sqrt") == 0) { return sqrt(accept()); }
	if (strcmp(buf, "expt") == 0) { return pow(accept(), accept()); }
	return atof(buf);
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