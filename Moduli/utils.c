void swap(int *a, int *b){
	int temp=*b;
	*b=*a;
	*a=temp;
}

int conta_spazi(char *line){

	int n = 0;
	char *ch = &line[0]; 

	while(*ch!='\0'){
		
		if(*ch==' ')
			++n;


		++ch;
	}

	return n;
}