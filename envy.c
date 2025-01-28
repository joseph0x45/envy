#include "envy.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim_whitespace(char *line) {
  if (!line) {
    return;
  }
  char *end;
  while (isspace(*line)) {
    printf("Line %s", line);
    line++;
  }
  end = line + strlen(line) - 1;
  while (end > line && isspace(*end)) {
    end--;
  }
  end[1] = '\0';
};

ParsedEnv *envy_parse(char *env_file_path) {
  FILE *f;
  char *line = NULL;
  ssize_t read;
  size_t len = 0;
  if (env_file_path == NULL) {
    env_file_path = ".env";
  }
  f = fopen(env_file_path, "r");
  if (f == NULL) {
    perror("fopen");
    return NULL;
  }
  while ((read = getline(&line, &len, f)) != -1) {
    printf("Before trim %s", line);
    trim_whitespace(line);
    printf("After trim '%s'", line);
  }
  return NULL;
}
