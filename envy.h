#ifndef ENVY_H
#define ENVY_H

// Represents a key value pair
// of an environment variable
typedef struct {
  char *key;
  char *value;
} EnvVariable;

// Returned by envy_parse
// Contains a pointer to all the
// parsed environment variables
// and the length of the array
typedef struct {
  // An array of key value pair
  // of environment variables
  EnvVariable *variables;
  // The length of the `variables` field
  int lengh;
} ParsedEnv;

// Parses the .env file and loads
// variables into the current process
int envy_load(char *env_file_path, int override);

// Parses the .env file and returns
// the environment variables as a
// pointer to a ParsedEnv struct
ParsedEnv *envy_parse(char *env_file_path);

#endif // !ENVY_H
