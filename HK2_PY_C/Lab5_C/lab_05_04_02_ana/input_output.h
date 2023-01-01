#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

int read(FILE *f, struct product *info);
void result_print(struct product *info, int count);
void record(FILE *f, struct product *info, int count);

#endif