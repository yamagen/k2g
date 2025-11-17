#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    return 1;
  }

  char *input = argv[1];
  size_t len = strlen(input);
  char *reversed = malloc(len + 1);

  if (!reversed) {
    perror("Failed to allocate memory");
    return 1;
  }

  for (size_t i = 0; i < len; i++) {
    reversed[i] = input[len - i - 1];
  }
  reversed[len] = '\0';

  printf("Reversed string: %s\n", reversed);
  free(reversed);

  return 0;
}
