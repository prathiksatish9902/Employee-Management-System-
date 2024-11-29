#ifndef SAVE_AND_LOAD_FILE_H
#define SAVE_AND_LOAD_FILE_H
void saveToFile(Employee *employees, int count, const char *filename);
void loadFromFile(Employee **employees, int *count, const char *filename);
#endif // SAVE_AND_LOAD_FILE_H
