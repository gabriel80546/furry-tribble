typedef struct String
{
	char* array;
	int size;
	int (*tamanho)(struct String);
	int (*equals)(struct String,struct String);

}String;

int StringTamanho(String string)
{
	int i = 0;
	while(*(string.array + i) != '\0')
	{i++;}

	return i;
}

int StringEquals(String a,String b)
{
	int i;
	if(a.size != b.size)
	{return 0;}

	for(i=0;i<a.size;i++)
	{
		if(a.array[i] != b.array[i])
		{return 0;}
	}

	return 1;
}

void newString(String* string, char* msg)
{
	string->array = msg;
	string->tamanho = &StringTamanho;
	string->equals = &StringEquals;
	string->size = string->tamanho(*string);
	return;
}

void newString2(String* string)
{
	string->array = "";
	string->tamanho = &StringTamanho;
	string->equals = &StringEquals;
	string->size = string->tamanho(*string);
	return;
}
