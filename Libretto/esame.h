typedef struct esame *Esame;

Esame newExam(char *, char *, int);

char *getName(Esame);
int getMark(Esame);
char *getDate(Esame);